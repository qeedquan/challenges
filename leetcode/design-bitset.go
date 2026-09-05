/*

A Bitset is a data structure that compactly stores bits.

Implement the Bitset class:

Bitset(int size) Initializes the Bitset with size bits, all of which are 0.
void fix(int idx) Updates the value of the bit at the index idx to 1. If the value was already 1, no change occurs.
void unfix(int idx) Updates the value of the bit at the index idx to 0. If the value was already 0, no change occurs.
void flip() Flips the values of each bit in the Bitset. In other words, all bits with value 0 will now have value 1 and vice versa.
boolean all() Checks if the value of each bit in the Bitset is 1. Returns true if it satisfies the condition, false otherwise.
boolean one() Checks if there is at least one bit in the Bitset with value 1. Returns true if it satisfies the condition, false otherwise.
int count() Returns the total number of bits in the Bitset which have value 1.
String toString() Returns the current composition of the Bitset. Note that in the resultant string, the character at the ith index should coincide with the value at the ith bit of the Bitset.


Example 1:

Input
["Bitset", "fix", "fix", "flip", "all", "unfix", "flip", "one", "unfix", "count", "toString"]
[[5], [3], [1], [], [], [0], [], [], [0], [], []]
Output
[null, null, null, null, false, null, null, true, null, 2, "01010"]

Explanation
Bitset bs = new Bitset(5); // bitset = "00000".
bs.fix(3);     // the value at idx = 3 is updated to 1, so bitset = "00010".
bs.fix(1);     // the value at idx = 1 is updated to 1, so bitset = "01010".
bs.flip();     // the value of each bit is flipped, so bitset = "10101".
bs.all();      // return False, as not all values of the bitset are 1.
bs.unfix(0);   // the value at idx = 0 is updated to 0, so bitset = "00101".
bs.flip();     // the value of each bit is flipped, so bitset = "11010".
bs.one();      // return True, as there is at least 1 index with value 1.
bs.unfix(0);   // the value at idx = 0 is updated to 0, so bitset = "01010".
bs.count();    // return 2, as there are 2 bits with value 1.
bs.toString(); // return "01010", which is the composition of bitset.


Constraints:

1 <= size <= 10^5
0 <= idx <= size - 1
At most 10^5 calls will be made in total to fix, unfix, flip, all, one, count, and toString.
At least one call will be made to all, one, count, or toString.
At most 5 calls will be made to toString.

*/

package main

import (
	"bytes"
	"math"
	"math/bits"
)

func main() {
	z := newbitset(5)

	z.Fix(3)
	assert(z.String() == "00010")
	assert(z.Count() == 1)
	assert(z.All() == false)
	assert(z.One() == true)

	z.Fix(1)
	assert(z.String() == "01010")
	assert(z.Count() == 2)
	assert(z.All() == false)
	assert(z.One() == true)

	z.Flip()
	assert(z.String() == "10101")
	assert(z.Count() == 3)
	assert(z.All() == false)
	assert(z.One() == true)

	z.Unfix(0)
	assert(z.String() == "00101")
	assert(z.Count() == 2)
	assert(z.All() == false)
	assert(z.One() == true)

	z.Flip()
	assert(z.String() == "11010")
	assert(z.Count() == 3)
	assert(z.All() == false)
	assert(z.One() == true)

	z.Unfix(0)
	assert(z.String() == "01010")
	assert(z.Count() == 2)

	z.Unfix(1)
	z.Unfix(3)
	z.Flip()
	assert(z.String() == "11111")
	assert(z.Count() == 5)
	assert(z.All() == true)
	assert(z.One() == true)

	z.Flip()
	assert(z.String() == "00000")
	assert(z.Count() == 0)
	assert(z.All() == false)
	assert(z.One() == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

type Bits struct {
	b []uint64
	n int
}

func newbitset(n int) *Bits {
	return &Bits{
		b: make([]uint64, (n+63)/64),
		n: n,
	}
}

func (z *Bits) Fix(n int) {
	z.b[n/64] |= 1 << (n & 63)
}

func (z *Bits) Unfix(n int) {
	z.b[n/64] &^= 1 << (n & 63)
}

func (z *Bits) Flip() {
	for i := range z.b {
		z.b[i] = ^z.b[i]
	}
}

func (z *Bits) All() bool {
	for i := 0; i < z.n/64; i++ {
		if z.b[i] != math.MaxUint64 {
			return false
		}
	}

	if z.n&63 != 0 {
		m := uint64(1)<<(z.n&63) - 1
		if z.b[z.n/64]&m != m {
			return false
		}
	}

	return true
}

func (z *Bits) One() bool {
	for i := 0; i < z.n/64; i++ {
		if z.b[i] != 0 {
			return true
		}
	}

	if z.n&63 != 0 {
		m := uint64(1)<<(z.n&63) - 1
		if z.b[z.n/64]&m != 0 {
			return true
		}
	}

	return false
}

func (z *Bits) Count() int {
	r := 0
	for i := 0; i < z.n/64; i++ {
		r += bits.OnesCount64(z.b[i])
	}

	if z.n&63 != 0 {
		m := uint64(1)<<(z.n&63) - 1
		r += bits.OnesCount64(z.b[z.n/64] & m)
	}

	return r
}

func (z *Bits) String() string {
	w := new(bytes.Buffer)
	for i := 0; i < z.n; i++ {
		if z.b[i/64]&(1<<(i&63)) != 0 {
			w.WriteRune('1')
		} else {
			w.WriteRune('0')
		}
	}
	return w.String()
}
