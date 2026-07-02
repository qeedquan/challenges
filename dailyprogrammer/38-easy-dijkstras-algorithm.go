/*

Implement Dijkstra's algorithm in any way you can :)

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	graph := [][]int{
		{0, 4, 0, 0, 0, 0, 0, 8, 0},
		{4, 0, 8, 0, 0, 0, 0, 11, 0},
		{0, 8, 0, 7, 0, 4, 0, 0, 2},
		{0, 0, 7, 0, 9, 14, 0, 0, 0},
		{0, 0, 0, 9, 0, 10, 0, 0, 0},
		{0, 0, 4, 14, 10, 0, 2, 0, 0},
		{0, 0, 0, 0, 0, 2, 0, 1, 6},
		{8, 11, 0, 0, 0, 0, 1, 0, 7},
		{0, 0, 2, 0, 0, 0, 6, 7, 0},
	}

	for index, value := range dijkstra(graph, 0) {
		fmt.Println(index, value)
	}
}

// https://brilliant.org/wiki/dijkstras-short-path-finder/
// https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/
func dijkstra(graph [][]int, source int) []int {
	nodes := len(graph)
	seen := make([]bool, nodes)
	distance := make([]int, nodes)
	for index := range nodes {
		distance[index] = math.MaxInt
	}

	distance[source] = 0
	for range nodes - 1 {
		u := mindistance(distance, seen)
		seen[u] = true
		for v := range nodes {
			if !seen[v] && graph[u][v] != 0 && distance[u] != math.MaxInt && distance[u]+graph[u][v] < distance[v] {
				distance[v] = distance[u] + graph[u][v]
			}
		}
	}
	return distance
}

func mindistance(distance []int, seen []bool) int {
	index := 0
	minimal := math.MaxInt
	for v := range distance {
		if !seen[v] && distance[v] <= minimal {
			minimal = distance[v]
			index = v
		}
	}
	return index
}
