/*

A directed graph is called **semi-complete** if there is at least one edge between any pair of its distinct vertices.

For a graph given by a list of edges, check if it is semi-complete.

Input
Contains the number of vertices n (1≤n≤100) and the number of edges m (1≤m≤n⋅(n−1)) in the graph. Then follows m pairs of numbers - the edges of the graph.

Output
Print **YES** if the graph is semi-complete and **NO** otherwise.

Examples
Input #1
5 10
1 2
1 3
1 5
2 3
2 5
3 2
4 1
4 3
4 5
5 3

Answer #1
NO

*/

package main

func main() {
	assert(solve(5, [][2]int{
		{1, 2},
		{1, 3},
		{1, 5},
		{2, 3},
		{2, 5},
		{3, 2},
		{4, 1},
		{4, 3},
		{4, 5},
		{5, 3},
	}) == "NO")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(n int, v [][2]int) string {
	m := make([][]byte, n)
	for i := range m {
		m[i] = make([]byte, n)
	}

	for _, p := range v {
		a, b := p[0]-1, p[1]-1
		m[a][b] = 1
		m[b][a] = 1
	}

	for i := range m {
		for j := range m[i] {
			if m[i][j] == 0 && i != j {
				return "NO"
			}
		}
	}
	return "YES"
}
