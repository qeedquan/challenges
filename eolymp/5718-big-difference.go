/*

Positive integer n is given. You are allowed to make an infinite number of permutations of its significant bits, thus obtaining new numbers.

What is the greatest difference between two such numbers that can be obtained as a result of these operations?

Input
One positive integer n, 1≤n≤2⋅10^9.

Output
One number — the "big difference".

Examples

Input #1
19

Answer #1
21

Input #2
1

Answer #2
0

Input #3
1024

Answer #3
1023

*/

package main

func main() {
	tab := []int{
		0, 0, 1, 0, 3, 3, 3, 0, 7, 9, 9, 7, 9, 7, 7, 0, 15, 21, 21, 21, 21, 21,
		21, 15, 21, 21, 21, 15, 21, 15, 15, 0, 31, 45, 45, 49, 45, 49, 49, 45,
		45, 49, 49, 45, 49, 45, 45, 31, 45, 49, 49, 45, 49, 45, 45, 31, 49, 45,
		45, 31, 45, 31, 31, 0, 63, 93, 93, 105, 93, 105, 105, 105, 93, 105, 105,
	}

	assert(solve(19) == 21)
	assert(solve(1) == 0)
	assert(solve(1024) == 1023)

	for i := range tab {
		assert(solve(i) == tab[i])
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A164884
func solve(n int) int {
	k0, k1 := 0, 0
	for ; n != 0; n >>= 1 {
		if (n & 1) != 0 {
			k1++
		} else {
			k0++
		}
	}

	a, b := 0, 0
	for ; k1 > 0; k1-- {
		a = (a << 1) + 1
		b = (b << 1) + 1
	}

	for ; k0 > 0; k0-- {
		a = (a << 1)
	}

	return a - b
}
