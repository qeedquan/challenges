/*

Length of a Longest Path in the Manhattan Tourist Problem
Find the length of a longest path in a rectangular city.

Given: Integers n and m, followed by an n × (m+1) matrix Down and an (n+1) × m matrix Right. The two matrices are separated by the "-" symbol.

Return: The length of a longest path from source (0, 0) to sink (n, m) in the n × m rectangular grid whose edges are defined by the matrices Down and Right.

Sample Dataset
4 4
1 0 2 4 3
4 6 5 2 1
4 4 5 2 1
5 6 8 5 3
-
3 2 4 0
3 2 4 2
0 7 3 3
3 3 0 2
1 3 2 2
Sample Output
34

*/

package main

func main() {
	assert(longestpath(
		4, 4,
		[][]int{{1, 0, 2, 4, 3}, {4, 6, 5, 2, 1}, {4, 4, 5, 2, 1}, {5, 6, 8, 5, 3}},
		[][]int{{3, 2, 4, 0}, {3, 2, 4, 2}, {0, 7, 3, 3}, {3, 3, 0, 2}, {1, 3, 2, 2}},
	) == 34)

	assert(longestpath(
		18, 10,
		[][]int{
			{1, 3, 4, 3, 1, 4, 0, 1, 0, 4, 2},
			{0, 0, 3, 3, 0, 4, 2, 4, 3, 3, 3},
			{3, 2, 3, 0, 3, 3, 2, 4, 3, 3, 1},
			{2, 2, 4, 4, 3, 4, 1, 1, 1, 3, 4},
			{4, 2, 1, 0, 0, 0, 4, 0, 4, 0, 2},
			{0, 2, 0, 2, 1, 1, 1, 3, 1, 0, 3},
			{1, 1, 3, 2, 0, 0, 4, 1, 0, 3, 2},
			{0, 2, 0, 0, 0, 4, 1, 3, 3, 3, 3},
			{2, 0, 2, 2, 2, 0, 0, 0, 1, 0, 0},
			{4, 0, 4, 0, 1, 0, 3, 0, 4, 4, 4},
			{1, 4, 4, 3, 1, 1, 1, 0, 0, 2, 4},
			{1, 1, 2, 0, 4, 4, 3, 0, 1, 2, 3},
			{2, 0, 1, 0, 4, 1, 1, 2, 2, 0, 4},
			{0, 2, 4, 1, 0, 4, 1, 0, 1, 2, 0},
			{2, 0, 1, 0, 2, 3, 1, 3, 3, 3, 2},
			{4, 3, 1, 2, 1, 3, 4, 0, 1, 0, 0},
			{4, 4, 1, 2, 4, 2, 1, 2, 0, 2, 0},
			{3, 3, 0, 1, 2, 2, 0, 2, 3, 3, 2},
		},
		[][]int{
			{3, 1, 2, 1, 2, 4, 3, 4, 3, 3},
			{4, 0, 2, 3, 4, 0, 2, 3, 1, 4},
			{1, 0, 2, 4, 1, 2, 1, 4, 2, 0},
			{0, 3, 4, 2, 0, 1, 4, 2, 3, 1},
			{0, 2, 1, 4, 2, 0, 2, 4, 2, 0},
			{1, 0, 1, 3, 0, 0, 4, 0, 4, 1},
			{0, 0, 1, 1, 3, 2, 2, 0, 3, 4},
			{0, 1, 1, 4, 1, 2, 3, 4, 4, 3},
			{2, 4, 0, 3, 0, 1, 2, 3, 4, 0},
			{0, 0, 2, 2, 2, 3, 4, 0, 1, 1},
			{1, 0, 2, 2, 3, 3, 4, 2, 3, 0},
			{1, 2, 4, 4, 1, 0, 1, 2, 3, 1},
			{2, 1, 1, 1, 4, 4, 3, 2, 2, 3},
			{1, 4, 1, 2, 3, 0, 1, 0, 4, 2},
			{2, 1, 0, 2, 4, 1, 4, 4, 4, 4},
			{2, 4, 3, 0, 1, 2, 4, 1, 2, 1},
			{1, 4, 2, 3, 2, 0, 3, 1, 1, 0},
			{1, 3, 4, 0, 2, 1, 1, 1, 2, 3},
			{0, 4, 0, 3, 0, 0, 2, 3, 1, 1},
		},
	) == 78)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func longestpath(n, m int, d, r [][]int) int {
	p := make([][]int, n+1)
	for i := range p {
		p[i] = make([]int, m+1)
	}
	for i := 1; i <= n; i++ {
		p[i][0] = p[i-1][0] + d[i-1][0]
	}
	for j := 1; j <= m; j++ {
		p[0][j] = p[0][j-1] + r[0][j-1]
	}
	for i := 1; i <= n; i++ {
		for j := 1; j <= m; j++ {
			p[i][j] = max(p[i-1][j]+d[i-1][j], p[i][j-1]+r[i][j-1])
		}
	}
	return p[n][m]
}
