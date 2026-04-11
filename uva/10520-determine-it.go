/*

Consider that a[i, j] is defined as:

a[i, j] = max[i < k <= n](a[k, 1] + a[k, j]), i < n      max[1 <= k < j](a[i, k] + a[n, k]), j > 0,   i >= j
          0                                 , i = n  +   0                                 , j = 0,   i <  j
          max[i <= k < j](a[i, k] + a[k + 1, j])

You are to calculate the value of a1,n on the basis of the values of n and an,1.

Input
The input consists of several test cases. Each Test case consists of two integers n (0 < n < 20) and a[n, 1]
(0 < a[n, 1] < 500).

Output
For each test case your correct program should print the value of a1,n in a separate line.

Sample Input
5 10
4 1
6 13

Sample Output
1140
42
3770

*/

package main

func main() {
	assert(solve(5, 10) == 1140)
	assert(solve(4, 1) == 42)
	assert(solve(6, 13) == 3770)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(n, v int) int {
	p := make([][]int, n+1)
	for i := range p {
		p[i] = make([]int, n+1)
	}

	p[n][1] = v
	for i := n; i >= 1; i-- {
		for j := 1; j <= n; j++ {
			if j == 1 && i == n {
				continue
			}

			if i >= j {
				l, r := 0, 0
				for k := i + 1; k <= n; k++ {
					l = max(p[k][1]+p[k][j], l)
				}
				for k := 1; k < j; k++ {
					r = max(p[i][k]+p[n][k], r)
				}
				p[i][j] = l + r
			} else {
				for k := i; k < j; k++ {
					p[i][j] = max(p[i][k]+p[k+1][j], p[i][j])
				}
			}
		}
	}
	return p[1][n]
}
