/*

A minifloat is a binary representation of a floating-point number that has very few bits.
https://en.wikipedia.org/wiki/Minifloat

The minifloat in this question will be defined as an 6-bit number m, which has the following representation:

1 bit to repesent the sign of the number. This bit will be 0 if the number is positive, and 1 if the number is negative.

3 bits to represent the exponent of the number, offset by 3 (i.e. an exponent of 110 actually represents a factor of 23, not 26).

An exponent of 000 refers to a subnormal number. The mantissa refers to the fractional part of a number with an integer part of 0 multiplied by a factor of the lowest possible exponent (in this case, 2-2).
2 bits to represent the mantissa of the number. If the exponent is anything other than 000 or 111, the 2 bits represent the fractional part after a 1.

An exponent of 111 represents infinity if the mantissa is 0, and NaN (not a number) otherwise.
In the Wikipedia article, this would be referred to as a (1.3.2.3) minifloat.

Some examples of this minifloat's representation:

000000 =  0.00 = 0
000110 =  1.10 × 2^(1-3) = 0.375
001100 =  1.00 × 2^(3-3) = 1
011001 =  1.01 × 2^(6-3) = 10
011100 = infinity
011101 = NaN
100000 = -0.00 = -0
100011 = -0.11 × 2^(1-3) = -0.1875 (subnormal)
101011 = -1.11 × 2^(2-3) = -0.875
110100 = -1.00 × 2^(5-3) = -4
111100 = -infinity
111111 = NaN
Your task is to build a network of two-input NAND gates that takes 6 inputs representing a minifloat a and 6 inputs representing a minifloat b, and returns 6 outputs representing the minifloat a + b.

Your network must properly add subnormals. For example, 000001 + 000010 must equal 000011, and 001001 + 000010 = 001010.

Your network must add and subtract infinities properly. Anything finite added to an infinity is the same infinity. Positive infinity plus negative infinity is NaN.

A NaN plus anything must equal a NaN, although which NaN it equals is up to you.

How you handle adding positive zero and negative zero to each other is up to you, although zero plus zero must equal zero.

Your network can implement any of the following rounding rules depending on convenience:

Round down (toward negative infinity)
Round up (toward positive infinity)
Round toward zero
Round away from zero
Round to nearest, with halves rounded according to any of the above rules
To simplify things, you may use AND, OR, NOT, and XOR gates in your diagram, with the following corresponding scores:

NOT: 1
AND: 2
OR: 3
XOR: 4
Each of these scores corresponds to the number of NAND gates that it takes to construct the corresponding gate.

The logic circuit that uses the fewest NAND gates to correctly implement all the above requirements wins.

*/

package main

import (
	"fmt"
)

func main() {
	fmt.Printf("%v\n", mfadd([6]int{0, 0, 0, 0, 0, 1}, [6]int{0, 0, 0, 0, 1, 0}))
	fmt.Printf("%v\n", mfadd([6]int{0, 0, 1, 0, 0, 1}, [6]int{0, 0, 0, 0, 1, 0}))
}

/*

@KSab

It uses 24 NOTs, 145 ANDs, 128 ORs, 33 XORs. It always rounds towards zero, it may return either -0 or +0 for zero values, and I believe it treats Infinities and NaNs correctly:

± INF ± INF = ± INF
± INF + NaN = ± INF
± INF ∓ INF = NaN
± INF + number = ± INF
NaN + NaN = NaN
NaN + number = NaN
Below I have a coded representation of the circuit. I have little experience annotating these types of things, so I don't really know what the typical way to do this is, but every variable is a Boolean so it's clear to see that it describes a circuit. Another thing, I have neither the know-how nor probably the tenacity to try and make a diagram of this, but if there is any easy to use software out there anyone wants to point out I would be interested in taking a look.

*/

func mfadd(a, b [6]int) [6]int {
	a0, a1, a2, a3, a4, a5 := a[0], a[1], a[2], a[3], a[4], a[5]
	b0, b1, b2, b3, b4, b5 := b[0], b[1], b[2], b[3], b[4], b[5]

	neg := XOR(a0, b0)
	nneg := NOT(neg)

	na1 := NOT(a1)
	na2 := NOT(a2)
	na3 := NOT(a3)

	a2_a3 := AND(a2, a3)
	a2_na3 := AND(a2, na3)
	na2_a3 := AND(na2, a3)
	na2_na3 := AND(na2, na3)

	a123 := AND(a1, a2_a3)
	l0 := AND(a1, a2_na3)
	l1 := AND(a1, na2_a3)
	l2 := AND(a1, na2_na3)
	l3 := AND(na1, a2_a3)
	l4 := AND(na1, a2_na3)
	l5 := AND(na1, na2_a3)
	l6 := AND(na1, na2_na3)

	a45 := OR(a4, a5)
	a_nan := AND(a123, a45)
	a_inf := AND(a123, NOT(a45))

	m0 := l0
	m1 := OR(l1, AND(l0, a4))
	m2 := OR(l2, OR(AND(l1, a4), AND(l0, a5)))
	m3 := OR(l3, OR(AND(l2, a4), AND(l1, a5)))
	m4 := OR(l4, OR(AND(l3, a4), AND(l2, a5)))
	m5 := OR(l5, OR(AND(l4, a4), AND(l3, a5)))
	l5_l6 := OR(l5, l6)
	m6 := OR(AND(l4, a5), AND(l5_l6, a4))
	m7 := AND(l5_l6, a5)

	nb1 := NOT(b1)
	nb2 := NOT(b2)
	nb3 := NOT(b3)

	b2_b3 := AND(b2, b3)
	b2_nb3 := AND(b2, nb3)
	nb2_b3 := AND(nb2, b3)
	nb2_nb3 := AND(nb2, nb3)

	b123 := AND(b1, b2_b3)
	k0 := AND(b1, b2_nb3)
	k1 := AND(b1, nb2_b3)
	k2 := AND(b1, nb2_nb3)
	k3 := AND(nb1, b2_b3)
	k4 := AND(nb1, b2_nb3)
	k5 := AND(nb1, nb2_b3)
	k6 := AND(nb1, nb2_nb3)

	b45 := OR(b4, b5)
	b_nan := AND(b123, b45)
	b_inf := AND(b123, NOT(b45))

	n0 := k0
	n1 := OR(k1, AND(k0, b4))
	n2 := OR(k2, OR(AND(k1, b4), AND(k0, b5)))
	n3 := OR(k3, OR(AND(k2, b4), AND(k1, b5)))
	n4 := OR(k4, OR(AND(k3, b4), AND(k2, b5)))
	n5 := OR(k5, OR(AND(k4, b4), AND(k3, b5)))
	k5_k6 := OR(k5, k6)
	n6 := OR(AND(k4, b5), AND(k5_k6, b4))
	n7 := AND(k5_k6, b5)

	i7 := n7
	i6 := XOR(n6, n7)
	carry_6 := OR(n6, n7)
	i5 := XOR(n5, carry_6)
	carry_5 := OR(n5, carry_6)
	i4 := XOR(n4, carry_5)
	carry_4 := OR(n4, carry_5)
	i3 := XOR(n3, carry_4)
	carry_3 := OR(n3, carry_4)
	i2 := XOR(n2, carry_3)
	carry_2 := OR(n2, carry_3)
	i1 := XOR(n1, carry_2)
	carry_1 := OR(n1, carry_2)
	i0 := XOR(n0, carry_1)
	i_sign := OR(n0, carry_1)

	n7 = OR(AND(nneg, n7), AND(neg, i7))
	n6 = OR(AND(nneg, n6), AND(neg, i6))
	n5 = OR(AND(nneg, n5), AND(neg, i5))
	n4 = OR(AND(nneg, n4), AND(neg, i4))
	n3 = OR(AND(nneg, n3), AND(neg, i3))
	n2 = OR(AND(nneg, n2), AND(neg, i2))
	n1 = OR(AND(nneg, n1), AND(neg, i1))
	n0 = OR(AND(nneg, n0), AND(neg, i0))
	n_sign := AND(neg, i_sign)

	r7 := XOR(m7, n7)
	carry_7 := AND(m7, n7)
	hr6 := XOR(m6, n6)
	hcarry_6 := AND(m6, n6)
	r6 := XOR(hr6, carry_7)
	carry_6 = OR(hcarry_6, AND(hr6, carry_7))
	hr5 := XOR(m5, n5)
	hcarry_5 := AND(m5, n5)
	r5 := XOR(hr5, carry_6)
	carry_5 = OR(hcarry_5, AND(hr5, carry_6))
	hr4 := XOR(m4, n4)
	hcarry_4 := AND(m4, n4)
	r4 := XOR(hr4, carry_5)
	carry_4 = OR(hcarry_4, AND(hr4, carry_5))
	hr3 := XOR(m3, n3)
	hcarry_3 := AND(m3, n3)
	r3 := XOR(hr3, carry_4)
	carry_3 = OR(hcarry_3, AND(hr3, carry_4))
	hr2 := XOR(m2, n2)
	hcarry_2 := AND(m2, n2)
	r2 := XOR(hr2, carry_3)
	carry_2 = OR(hcarry_2, AND(hr2, carry_3))
	hr1 := XOR(m1, n1)
	hcarry_1 := AND(m1, n1)
	r1 := XOR(hr1, carry_2)
	carry_1 = OR(hcarry_1, AND(hr1, carry_2))
	hr0 := XOR(m0, n0)
	hcarry_0 := AND(m0, n0)
	r0 := XOR(hr0, carry_1)
	carry_0 := OR(hcarry_0, AND(hr0, carry_1))
	r_sign := XOR(n_sign, carry_0)

	s7 := r7
	s6 := XOR(r6, r7)
	carry_6 = OR(r6, r7)
	s5 := XOR(r5, carry_6)
	carry_5 = OR(r5, carry_6)
	s4 := XOR(r4, carry_5)
	carry_4 = OR(r4, carry_5)
	s3 := XOR(r3, carry_4)
	carry_3 = OR(r3, carry_4)
	s2 := XOR(r2, carry_3)
	carry_2 = OR(r2, carry_3)
	s1 := XOR(r1, carry_2)
	carry_1 = OR(r1, carry_2)
	s0 := XOR(r0, carry_1)

	n_r_sign := NOT(r_sign)
	r0 = OR(AND(n_r_sign, r0), AND(r_sign, s0))
	r1 = OR(AND(n_r_sign, r1), AND(r_sign, s1))
	r2 = OR(AND(n_r_sign, r2), AND(r_sign, s2))
	r3 = OR(AND(n_r_sign, r3), AND(r_sign, s3))
	r4 = OR(AND(n_r_sign, r4), AND(r_sign, s4))
	r5 = OR(AND(n_r_sign, r5), AND(r_sign, s5))
	r6 = OR(AND(n_r_sign, r6), AND(r_sign, s6))
	r7 = OR(AND(n_r_sign, r7), AND(r_sign, s7))

	h0 := r0
	rest := h0
	h1 := AND(r1, NOT(rest))
	rest = OR(rest, h1)
	h2 := AND(r2, NOT(rest))
	rest = OR(rest, h2)
	h3 := AND(r3, NOT(rest))
	rest = OR(rest, h3)
	h4 := AND(r4, NOT(rest))
	rest = OR(rest, h4)
	h5 := AND(r5, NOT(rest))
	rest = OR(rest, h5)
	h6 := AND(r6, NOT(rest))
	rest = OR(rest, h6)

	e0 := OR(h0, OR(h1, h2))
	e1 := OR(h0, OR(h3, h4))
	e2 := OR(h1, OR(h3, h5))

	ne0 := NOT(e0)
	ne1 := NOT(e1)
	ne2 := NOT(e2)

	e0e1 := AND(e0, e1)
	e0ne1 := AND(e0, ne1)
	ne0e1 := AND(ne0, e1)
	ne0ne1 := AND(ne0, ne1)

	x0 := AND(e0e1, ne2)
	x1 := AND(e0ne1, e2)
	x2 := AND(e0ne1, ne2)
	x3 := AND(ne0e1, e2)
	x4 := AND(ne0e1, ne2)
	x5 := AND(ne0ne1, e2)
	x6 := AND(ne0ne1, ne2)

	u0 := AND(x0, r1)
	u1 := AND(x1, r2)
	u2 := AND(x2, r3)
	u3 := AND(x3, r4)
	u4 := AND(x4, r5)
	u5 := AND(x5, r6)
	u6 := AND(x6, r6)

	v0 := AND(x0, r2)
	v1 := AND(x1, r3)
	v2 := AND(x2, r4)
	v3 := AND(x3, r5)
	v4 := AND(x4, r6)
	v5 := AND(x5, r7)
	v6 := AND(x6, r7)

	f0 := OR(u0, OR(u1, OR(u2, OR(u3, OR(u4, OR(u5, u6))))))
	f1 := OR(v0, OR(v1, OR(v2, OR(v3, OR(v4, OR(v5, v6))))))
	sign := XOR(a0, r_sign)

	either_nan := OR(a_nan, b_nan)
	either_inf := OR(a_inf, b_inf)
	ans_nan := OR(AND(AND(a_inf, b_inf), XOR(a0, b0)), AND(NOT(either_inf), either_nan))
	nans_nan := NOT(ans_nan)
	ans_inf := AND(nans_nan, OR(either_nan, either_inf))
	ans_none := AND(nans_nan, NOT(ans_inf))
	nans_none := NOT(ans_none)

	result0 := OR(OR(AND(a_inf, a0), AND(b_inf, b0)), AND(ans_none, sign))
	result1 := OR(nans_none, AND(ans_none, e0))
	result2 := OR(nans_none, AND(ans_none, e1))
	result3 := OR(nans_none, AND(ans_none, e2))
	result4 := OR(ans_nan, AND(ans_none, f0))
	result5 := OR(ans_nan, AND(ans_none, f1))

	return [6]int{result0, result1, result2, result3, result4, result5}
}

func XOR(a, b int) int {
	return a ^ b
}

func AND(a, b int) int {
	return a & b
}

func OR(a, b int) int {
	return a | b
}

func NOT(a int) int {
	if a != 0 {
		return 0
	}
	return 1
}
