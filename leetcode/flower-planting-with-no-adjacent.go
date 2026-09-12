/*

You have n gardens, labeled from 1 to n, and an array paths where paths[i] = [xi, yi] describes a bidirectional path between garden xi to garden yi. In each garden, you want to plant one of 4 types of flowers.

All gardens have at most 3 paths coming into or leaving it.

Your task is to choose a flower type for each garden such that, for any two gardens connected by a path, they have different types of flowers.

Return any such a choice as an array answer, where answer[i] is the type of flower planted in the (i+1)th garden. The flower types are denoted 1, 2, 3, or 4. It is guaranteed an answer exists.

Example 1:

Input: n = 3, paths = [[1,2],[2,3],[3,1]]
Output: [1,2,3]
Explanation:
Gardens 1 and 2 have different types.
Gardens 2 and 3 have different types.
Gardens 3 and 1 have different types.
Hence, [1,2,3] is a valid answer. Other valid answers include [1,2,4], [1,4,2], and [3,2,1].

Example 2:

Input: n = 4, paths = [[1,2],[3,4]]
Output: [1,2,1,2]

Example 3:

Input: n = 4, paths = [[1,2],[2,3],[3,4],[4,1],[1,3],[2,4]]
Output: [1,2,3,4]

Constraints:

1 <= n <= 10^4
0 <= paths.length <= 2 * 10^4
paths[i].length == 2
1 <= xi, yi <= n
xi != yi
Every garden has at most 3 paths coming into or leaving it.

Hint 1
Since each garden is connected to at most 3 gardens, there's always an available color for each garden. For example, if one garden is next to gardens with colors 1, 3, 4, then color #2 is available.

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test(3, [][]int{{1, 2}, {2, 3}, {3, 1}}, []int{1, 2, 3})
	test(4, [][]int{{1, 2}, {3, 4}}, []int{1, 2, 1, 2})
	test(4, [][]int{{1, 2}, {2, 3}, {3, 4}, {4, 1}, {1, 3}, {2, 4}}, []int{1, 2, 3, 4})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(n int, p [][]int, r []int) {
	g := nonadjacent(n, p)
	fmt.Println(g)
	assert(reflect.DeepEqual(g, r))
}

func nonadjacent(n int, p [][]int) []int {
	g := make([][]int, n)
	for _, p := range p {
		x, y := p[0]-1, p[1]-1
		g[x] = append(g[x], y)
		g[y] = append(g[y], x)
	}

	r := make([]int, n)
	for x := 0; x < n; x++ {
		u := make(map[int]bool)
		for _, y := range g[x] {
			u[r[y]] = true
		}
		for c := 1; c < 5; c++ {
			if !u[c] {
				r[x] = c
				break
			}
		}
	}
	return r
}
