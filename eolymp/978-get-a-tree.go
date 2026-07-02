/*

A connected undirected graph without loops or multiple edges is given.
It is allowed to delete edges from the graph.
The goal is to obtain a tree.

Input
The first line contains two integers n (1≤n≤100) and m — the number of vertices and the number of edges in the graph.
The next m pairs of integers represent the edges. It is guaranteed that the graph is connected.

Output
Print n−1 pairs of integers — the edges that form a tree. The edges can be printed in any order.

https://static.e-olymp.com/content/e8/e8ab8d33f8ce8ed2a66e9e43a10062f13ffa71b6.gif

Examples
Input #1
4 4
1 2
2 3
3 4
4 1

Answer #1
1 2
2 3
3 4

*/

package main

import "fmt"

func main() {
	fmt.Println(solve(4, [][2]int{
		{1, 2},
		{2, 3},
		{3, 4},
		{4, 1},
	}))
}

func solve(size int, edges [][2]int) [][2]int {
	used := make([]int, size+1)
	graph := make([][]int, size+1)
	for i := range graph {
		graph[i] = make([]int, size+1)
	}

	for _, edge := range edges {
		u, v := edge[0], edge[1]
		graph[u][v] = 1
		graph[v][u] = 1
	}

	result := [][2]int{}
	dfs(graph, used, 1, &result)
	return result
}

func dfs(graph [][]int, used []int, i int, result *[][2]int) {
	used[i] = 1
	for j := 1; j < len(graph); j++ {
		if graph[i][j] == 1 && used[j] == 0 {
			*result = append(*result, [2]int{i, j})
			dfs(graph, used, j, result)
		}
	}
}
