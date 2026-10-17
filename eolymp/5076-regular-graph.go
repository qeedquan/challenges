/*

An undirected graph is called regular if all its vertices have the same degree.

Given the list of edges of a graph, determine whether the graph is regular.

Input
The first line contains two integers:
n (1≤n≤100) - the number of vertices, and m (0 ≤ m ≤ n*(n-1)/2) - the number of edges in the graph.
Each of the next m lines contains two integers — the endpoints of an edge.

Output
Print "YES" if the graph is regular, and "NO" otherwise.

https://static.e-olymp.com/content/dc/dcd4c29100bedb8c5e5e23e4516b5f260f9aae44.gif

Examples

Input #1
3 3
1 2
1 3
2 3

Answer #1
YES

Input #2
3 2
1 2
2 3

Answer #2
NO

*/

package main

func main() {
	assert(solve(3, [][2]int{
		{1, 2},
		{1, 3},
		{2, 3},
	}) == "YES")

	assert(solve(3, [][2]int{
		{1, 2},
		{2, 3},
	}) == "NO")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(vertices int, edges [][2]int) string {
	graph := make(map[int]int)
	for _, edge := range edges {
		u, v := edge[0], edge[1]
		graph[u] += 1
		graph[v] += 1
	}
	for i := 1; i < vertices; i++ {
		if graph[i] != graph[i+1] {
			return "NO"
		}
	}
	return "YES"
}
