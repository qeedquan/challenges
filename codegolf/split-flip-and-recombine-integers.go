/*

Background
It's well known in mathematics that integers can be put into a one-to-one correspondence with pairs of integers. There are many possible ways of doing this, and in this challenge, you'll implement one of them and its inverse operation.

The task
Your input is a positive integer n > 0. It is known that there exist unique non-negative integers a, b ≥ 0 such that n == 2a * (2*b + 1). Your output is the "flipped version" of n, the positive integer 2b * (2*a + 1).

You can assume that the input and output fit into the standard unsigned integer datatype of your language.

Rules and scoring
You can write either a full program or a function. The lowest byte count wins, and standard loopholes are disallowed.

Test cases
These are given in the format in <-> out, since the function to be implemented is its own inverse: if you feed the output back to it, you should get the original input.

1 <-> 1
2 <-> 3
4 <-> 5
6 <-> 6
7 <-> 8
9 <-> 16
10 <-> 12
11 <-> 32
13 <-> 64
14 <-> 24
15 <-> 128
17 <-> 256
18 <-> 48
19 <-> 512
20 <-> 20
28 <-> 40
30 <-> 384
56 <-> 56
88 <-> 224
89 <-> 17592186044416

*/

package main

func main() {
	test(0, 0)
	test(1, 1)
	test(2, 3)
	test(4, 5)
	test(6, 6)
	test(7, 8)
	test(9, 16)
	test(10, 12)
	test(11, 32)
	test(13, 64)
	test(14, 24)
	test(15, 128)
	test(17, 256)
	test(18, 48)
	test(19, 512)
	test(20, 20)
	test(28, 40)
	test(30, 384)
	test(56, 56)
	test(88, 224)
	test(89, 17592186044416)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(n, m uint64) {
	assert(sfri(n) == m)
	assert(sfri(m) == n)
}

func sfri(n uint64) uint64 {
	if n == 0 {
		return 0
	}

	m := uint64(0)
	for ; (n&1)-1 != 0; n >>= 1 {
		m++
	}
	return ((m << 1) + 1) << (n >> 1)
}
