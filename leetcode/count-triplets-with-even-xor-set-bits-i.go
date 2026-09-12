/*

Given three integer arrays a, b, and c, return the number of triplets (a[i], b[j], c[k]),
such that the bitwise XOR of the elements of each triplet has an even number of set bits.

Example 1:

Input: a = [1], b = [2], c = [3]

Output: 1

Explanation:

The only triplet is (a[0], b[0], c[0]) and their XOR is: 1 XOR 2 XOR 3 = 002.

Example 2:

Input: a = [1,1], b = [2,3], c = [1,5]

Output: 4

Explanation:

Consider these four triplets:

(a[0], b[1], c[0]): 1 XOR 3 XOR 1 = 0112
(a[1], b[1], c[0]): 1 XOR 3 XOR 1 = 0112
(a[0], b[0], c[1]): 1 XOR 2 XOR 5 = 1102
(a[1], b[0], c[1]): 1 XOR 2 XOR 5 = 1102


Constraints:

1 <= a.length, b.length, c.length <= 100
0 <= a[i], b[i], c[i] <= 100

*/

package main

import "math/bits"

func main() {
	assert(triplet([]uint{1}, []uint{2}, []uint{3}) == 1)
	assert(triplet([]uint{1, 1}, []uint{2, 3}, []uint{1, 5}) == 4)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func triplet(a, b, c []uint) int {
	ea, oa := count(a)
	eb, ob := count(b)
	ec, oc := count(c)
	return ea*ob*oc + oa*eb*oc + oa*ob*ec + ea*eb*ec
}

func count(a []uint) (int, int) {
	c := 0
	for i := range a {
		c += bits.OnesCount(a[i]) & 1
	}
	return len(a) - c, c
}
