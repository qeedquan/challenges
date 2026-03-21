/*

You are given a network of n nodes, labeled from 1 to n.
You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi),
where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal.
If it is impossible for all the n nodes to receive the signal, return -1.

Example 1:
Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2

Example 2:
Input: times = [[1,2,1]], n = 2, k = 1
Output: 1

Example 3:
Input: times = [[1,2,1]], n = 2, k = 2
Output: -1


Constraints:

1 <= k <= n <= 100
1 <= times.length <= 6000
times[i].length == 3
1 <= ui, vi <= n
ui != vi
0 <= wi <= 100
All the pairs (ui, vi) are unique. (i.e., no multiple edges.)

Hint 1
We visit each node at some time, and if that time is better than the fastest time we've reached this node, we travel along outgoing edges in sorted order.
Alternatively, we could use Dijkstra's algorithm.

*/

package main

import "math"

func main() {
	assert(delaytime([][3]int{{2, 1, 1}, {2, 3, 1}, {3, 4, 1}}, 4, 2) == 2)
	assert(delaytime([][3]int{{1, 2, 1}}, 2, 1) == 1)
	assert(delaytime([][3]int{{1, 2, 1}}, 2, 2) == -1)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm
func delaytime(times [][3]int, n, k int) int {
	const INF = math.MaxInt >> 1

	p := make([][]int, n+1)
	for i := range p {
		p[i] = make([]int, n+1)
		for j := range p[i] {
			p[i][j] = INF
		}
	}

	for _, t := range times {
		p[t[0]][t[1]] = t[2]
	}

	for i := 1; i <= n; i++ {
		p[i][i] = 0
	}

	for k := 1; k <= n; k++ {
		for i := 1; i <= n; i++ {
			for j := 1; j <= n; j++ {
				if p[i][k]+p[k][j] < p[i][j] {
					p[i][j] = p[i][k] + p[k][j]
				}
			}
		}
	}

	r := -1
	for v := 1; v <= n; v++ {
		if p[k][v] == INF {
			return -1
		}
		r = max(r, p[k][v])
	}
	return r
}
