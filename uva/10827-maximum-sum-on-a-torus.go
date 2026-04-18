/*

A grid that wraps both horizontally and vertically is called a torus.
Given a torus where each cell contains an integer, determine the subrectangle with the largest sum. The sum of a sub-rectangle is the sum
of all the elements in that rectangle. The grid below shows a torus
where the maximum sub-rectangle has been shaded.

Input
The first line in the input contains the number of test cases (at most
18). Each case starts with an integer N (1 ≤ N ≤ 75) specifying the
size of the torus (always square). Then follows N lines describing the
torus, each line containing N integers between -100 and 100, inclusive.

Output
For each test case, output a line containing a single integer: the maximum sum of a sub-rectangle within
the torus.

Sample Input
2
5
1 -1 0 0 -4
2 3 -2 -3 2
4 1 -1 5 0
3 -2 1 -3 2
-3 2 4 1 -4
3
1 2 3
4 5 6
7 8 9

Sample Output
15
45

*/

package main

import "math"

func main() {
	assert(solve([][]int{
		{1, -1, 0, 0, -4},
		{2, 3, -2, -3, 2},
		{4, 1, -1, 5, 0},
		{3, -2, 1, -3, 2},
		{-3, 2, 4, 1, -4},
	}) == 15)

	assert(solve([][]int{
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9},
	}) == 45)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(m [][]int) int {
	n := len(m)
	p := make([][]int, n*2+1)
	for i := range p {
		p[i] = make([]int, n*2+1)
	}

	for i := 1; i <= n; i++ {
		for j := 1; j <= n; j++ {
			p[i][j] = m[i-1][j-1]
			p[i][j+n], p[i+n][j], p[i+n][j+n] = p[i][j], p[i][j], p[i][j]
		}
	}

	for i := 1; i <= 2*n; i++ {
		for j := 1; j <= 2*n; j++ {
			p[i][j] += (p[i][j-1] + p[i-1][j] - p[i-1][j-1])
		}
	}

	r := math.MinInt
	for i := 1; i <= n; i++ {
		for j := 1; j <= n; j++ {
			for k := i; k < i+n; k++ {
				for l := j; l < j+n; l++ {
					r = max(r, p[k][l]-p[i-1][l]-p[k][j-1]+p[i-1][j-1])
				}
			}
		}
	}
	return r
}
