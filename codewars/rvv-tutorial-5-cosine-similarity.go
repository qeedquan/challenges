/*

(This kata is a part of the RVV Tutorial series, where you can learn to write assembly code using RISC-V V extension and vectorize your loops. Familiarity with C and (scalar) RISC-V assembly is assumed. See more in the RVV Tutorial collection.)

Goal: Find the cosine similarity between two vectors:

cos(theta) = (A*B)/|A|*|B| = Sum[i] a[i]*b[i] / [ sqrt(Sum[i] a[i]*a[i]) * sqrt(Sum[i] b[i]*b[i]) ]

(The for summation, i goes from 0 to len - 1.)

Signature in C as follows:

float cos_similarity(size_t len, const float *a, const float *b);
You can assume that there will be no divison by zero problems.

(Note: This term comes from the geometric definition of the dot product of two vectors

A*B = |A|*|B|*cos(theta)

The cosine of angle between the two vectors shows how close or far apart their directions are. 1 means same direction, 0 means perpendicular, and -1 means opposite directions.)

Reductions
Aha, this functions returns a scalar result! Interesting.

The thing we want to do here is a reduction. Specifically, a summation. The general idea is that we keep a vector accumulator. For each iteration, we add each element v[i] to the i-th element at the accumulator, acc[i]. (i here is the index within each iteration.) At the end, we sum up every element of the accumulator. For example, suppose that each register can contain 4 elements, then the loop will be like:

# Start
acc[0] = 0; acc[1] = 0; acc[2] = 0; acc[3] = 0;

# Iter 0
acc[0] += a[0]; acc[1] += a[1]; acc[2] += a[2]; acc[3] += a[3];

# Iter 2
acc[0] += a[0]; acc[1] += a[1]; acc[2] += a[2]; acc[3] += a[3];

...

# End
result = acc[0] + acc[1] + acc[2] + acc[3];
Only doing the reduction at the last steps allows for maximum parallelism within an iteration. For example, if the processor can do four independent additions in parallel, each iteration can be completely parallelized and achieve 4x the speed of an equivalent scalar loop. If we do the reduction for each iteration, the speed will be limited.

For the final reduction, there's this 'unordered reduction summation' instruction:

# EEW = SEW
vfredusum.vs vd, vs2, vs1, vm
s stands for 'scalar', which means the low EEW bits of a single vector register (EMUL = 1) as a single scalar. The same goes for the result vd which is also used as a 'scalar'. These scalar operands always access one vector register and don't use register groups.

What the instuction does is:

// Without vm
vd[0] = vs1[0]
  + vs2[0]
  + vs2[1]
  ...
  + vs2[vl-1]

// With vm
vd[0] = vs1[0]
  + (vm[0] ? vs2[0] : 0)
  + (vm[1] ? vs2[1] : 0)
  ...
  + (vm[vl-1] ? vs2[vl-1] : 0)
But for efficiency purposes, it may group together elements in different ways, not necessarily left associative one-by-one.

So basically, sum all the elements and an extra scalar, or if a mask specified, sum all the active elements and an extra scalar. If you don't need that extra scalar, just use 0. By the way, floating point 0.0 is also all zeros in binary representation.

(Note: The analogous vfredosum.vs instruction requires the computation to be exactly left associative to avoid changing the floating point result. Reduction instructions exist for integers and other operations — Check out the spec! :P)

(Note: There's a minor problem with adding 0 for floating points. The additive identity should only be +0.0 when rounding down (towards -∞) or -0.0 for all other rounding modes. Again, check the spec for details.)

Moving data between scalar registers and v[0]
A few instructions are available to move between the scalar integer/float registers and the low EEW bits of a single vector register, i.e. element index 0, i.e. 'scalar'.

# EEW = SEW
vmv.x.s rd, vs2   # x[rd] = vs2[0]
vmv.s.x vd, rs1   # vd[0] = x[rs1]
vfmv.f.s rd, vs2  # f[rd] = vs2[0]
vfmv.s.f vd, rs1  # vd[0] = f[rs1]
As with vfred*sum.vs, the 'scalar' operands and destinations don't care about vl and always accesses one single vector register, as if EMUL = 1.

A tale of tails
A basic summation loop will look something like this.

(For simplicity we only deal with one accumulator, but solving this kata may require a few. You may also want to replace vfadd.vv for the kata solution.)

  # Clear accumulator v8 to 0

  # TODO: One instruction is missing here! See first hint.
  vmv.v.x v8, zero

1:
  vsetvli t0, a0, e32, m1, ta, ma

  # TODO

  # Add this iter's result to accumulator
  vfadd.vv v8, v8, v16
  bnez a0, 1b

  # Final reduction step, sum everything in accumulator

  # TODO: One instruction is missing here! See first hint.
  vmv.s.x v16, zero
  vfredusum.vs v16, v8, v16
  vfmv.f.s fa0, v16

  ret
But there's a small problem with the last iterations where vl is small: The vadd.vv instruction is allowed to trash the elements after vl! Like for example, if len = 42 this could happen at the last iteration:

# Last iter, vl = 2
acc[0] += a[40]; acc[1] += a[41]; acc[2] = trashed; acc[3] = trashed;
We haven't dealt with this problem before since we've never used elements after vl. These elements are called tail.

Just like inactive elements for masked instructions can be processed under either mask-agnostic (ma) or mask-undisturbed policies (mu), tail elements have analogous ta and tu policies. To ensure that elements in the accumulator beyond vl are preserved, we can switch to the tu policy:

  # Please don't trash the tail elements when adding to accumulator
  vsetvli zero, zero, e32, m1, tu, ma
  # Add this iter's result to accumulator
  vadd.vv v8, v8, v16
Just to spell it out, element indices vl through (VLEN / EEW) * EMUL - 1 are tail elements. The t_ piece in vsetvli means to set the current tail policy to:

ta: Tail agnostic, the tail elements in the destination vector either remain unchanged or are overwritten with all 1s, or even a combination.
tu: Tail undisturbed, the tail elements in the destination vector are unchanged.
As before with masks, forcing processor to preserve tail elements may prevent some hardware optimizations, so it's best to only tu use when necessary.

(Note: For scalar destinations, any element beyond the first are considered 'tail'. For mask destinations, mask tails are always tail-agnostic for simplicity.)

Instructions to use for this kata
I know I've shown you this before, but here you are, just to recap. You don't necessarily need all of these.

# Floating-point multiply
vfmul.vv vd, vs2, vs1, vm   # vector * vector
vfmul.vf vd, vs2, rs1, vm   # vector * scalar

# Floating-point add
vfadd.vv vd, vs2, vs1, vm   # vector + vector
vfadd.vf vd, vs2, rs1, vm   # vector + scalar

# FP multiply-accumulate, overwrites addend
vfmacc.vv vd, vs1, vs2, vm    # vd[i] = +(vs1[i] * vs2[i]) + vd[i]
vfmacc.vf vd, rs1, vs2, vm    # vd[i] = +(f[rs1] * vs2[i]) + vd[i]

# FP multiply-add, overwrites multiplicand
vfmadd.vv vd, vs1, vs2, vm    # vd[i] = +(vs1[i] * vd[i]) + vs2[i]
vfmadd.vf vd, rs1, vs2, vm    # vd[i] = +(f[rs1] * vd[i]) + vs2[i]
Hints
What's missing in the example? What value should vl be when you set the accumulator to all zeros? What about when doing the final reduction? How do you achieve that?
Perhaps go back and review the scalar floating point instructions too.
Note on vl and reductions
For reductions, if vl = 0, no operation is performed and vd is not updated. This is unlike vmv.s.x and vfmv.s.f, which writes vd[0] regardless of vl. However, for our purposes, vl will never be 0 for reduction operations.

References
The RISC-V Vector extension specification at: https://github.com/riscv/riscv-v-spec/blob/master/v-spec.adoc

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(cossim([]float64{1, 2, 3}, []float64{4, 5, 6}))
	fmt.Println(cossim([]float64{9, 62, 0, 3}, []float64{25, 3, 6, 0}))
	fmt.Println(cossim([]float64{1, 0, 0}, []float64{0, 0, 1}))
	fmt.Println(cossim([]float64{1, 1, 1}, []float64{1, 1, 1}))
}

func cossim(a, b []float64) float64 {
	x, y, z := 0.0, 0.0, 0.0
	for i := range a {
		x += a[i] * b[i]
		y += a[i] * a[i]
		z += b[i] * b[i]
	}
	return x / math.Sqrt(y*z)
}
