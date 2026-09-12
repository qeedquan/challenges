/*

You are given an m x n 2D array grid of positive integers.

Your task is to traverse grid in a zigzag pattern while skipping every alternate cell.

Zigzag pattern traversal is defined as following the below actions:

Start at the top-left cell (0, 0).
Move right within a row until the end of the row is reached.
Drop down to the next row, then traverse left until the beginning of the row is reached.
Continue alternating between right and left traversal until every row has been traversed.
Note that you must skip every alternate cell during the traversal.

Return an array of integers result containing, in order, the value of the cells visited during the zigzag traversal with skips.

Example 1:
Input: grid = [[1,2],[3,4]]
Output: [1,4]
Explanation:
https://assets.leetcode.com/uploads/2024/11/23/4012_example0.png

Example 2:
Input: grid = [[2,1],[2,1],[2,1]]
Output: [2,1,2]
Explanation:
https://assets.leetcode.com/uploads/2024/11/23/4012_example1.png

Example 3:
Input: grid = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,3,5,7,9]
Explanation:
https://assets.leetcode.com/uploads/2024/11/23/4012_example2.png

Constraints:

2 <= n == grid.length <= 50
2 <= m == grid[i].length <= 50
1 <= grid[i][j] <= 2500

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test(
		[][]int{{1, 2}, {3, 4}},
		[]int{1, 4},
	)

	test(
		[][]int{{2, 1}, {2, 1}, {2, 1}},
		[]int{2, 1, 2},
	)

	test(
		[][]int{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
		[]int{1, 3, 5, 7, 9},
	)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(m [][]int, r []int) {
	p := zigzag(m)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func zigzag(m [][]int) []int {
	r := []int{}
	for i := range m {
		n := len(m[i])
		if i%2 == 0 {
			for j := 0; j < n; j += 2 {
				r = append(r, m[i][j])
			}
		} else {
			for j := n - n%2 - 1; j >= 0; j -= 2 {
				r = append(r, m[i][j])
			}
		}
	}
	return r
}
