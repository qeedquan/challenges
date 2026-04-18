/*

Let ⌊x⌋ be the floor of x. Count the number of permutations (a1, a2, . . . , an) of (1, 2, . . . , n) such that
|a1-1| + |a2-2| + · · · + |an-n| = ⌊n^2/2⌋

Input
A number of of inputs (≤ 1000), each start with the number of value of integer n (1 ≤ n ≤ 1000000).

Output
Output the number of permutations modulo 1000000007.

Sample Input
1
2
3

Sample Output
1
1
3

*/

package main

func main() {
	tab := []int{1, 1, 1, 3, 4, 20, 36, 252, 576, 5184, 14400, 158400, 518400, 6739200, 25401600}

	assert(solve(1) == 1)
	assert(solve(2) == 1)
	assert(solve(3) == 3)
	for i := range tab {
		assert(solve(i) == tab[i])
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A062870
func solve(n int) int {
	const mod = 1_000_000_007

	if n < 0 {
		return 0
	}

	if n == 0 {
		return 1
	}

	f := make([]int, n+1)
	r := make([]int, n+1)
	f[0] = 1
	for i := 1; i <= n; i++ {
		f[i] = (f[i-1] * i) % mod
		if i&1 != 0 {
			r[i] = (((f[(i-1)/2] * f[(i-1)/2]) % mod) * i) % mod
		} else {
			r[i] = (f[i/2] * f[i/2]) % mod
		}
	}
	return r[n]
}
