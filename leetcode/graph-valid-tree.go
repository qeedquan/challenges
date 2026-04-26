/*

Given n nodes labeled from 0 to n-1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.

Example 1:

Input: n = 5, and edges = [[0,1], [0,2], [0,3], [1,4]]
Output: true

Example 2:

Input: n = 5, and edges = [[0,1], [1,2], [2,3], [1,3], [1,4]]
Output: false

Note: you can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0,1] is the same as [1,0] and thus will not appear together in edges.

*/

package main

func main() {
	assert(valid(5, [][2]int{{0, 1}, {0, 2}, {0, 3}, {1, 4}}) == true)
	assert(valid(5, [][2]int{{0, 1}, {1, 2}, {2, 3}, {1, 3}, {1, 4}}) == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func valid(size int, edges [][2]int) bool {
	if len(edges) != size-1 {
		return false
	}

	neighbors := make(map[int][]int)
	for _, edge := range edges {
		neighbors[edge[0]] = append(neighbors[edge[0]], edge[1])
		neighbors[edge[1]] = append(neighbors[edge[1]], edge[0])
	}

	queue := []int{0}
	visited := map[int]bool{0: true}
	for len(queue) > 0 {
		index := queue[0]
		queue = queue[1:]
		for _, node := range neighbors[index] {
			if !visited[node] {
				visited[node] = true
				queue = append(queue, node)
			}
		}
	}

	return len(visited) == size
}
