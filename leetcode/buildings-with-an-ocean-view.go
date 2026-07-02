/*

Description
There are n buildings in a line. You are given an integer array heights of size n that represents the heights of the buildings in the line.

The ocean is to the right of the buildings. A building has an ocean view if the building can see the ocean without obstructions. Formally, a building has an ocean view if all the buildings to its right have a smaller height.

Return a list of indices (0-indexed) of buildings that have an ocean view, sorted in increasing order.

Example 1:

Input: heights = [4,2,3,1]

Output: [0,2,3]

Explanation: Building 1 (0-indexed) does not have an ocean view because building 2 is taller.

Example 2:

Input: heights = [4,3,2,1]

Output: [0,1,2,3]

Explanation: All the buildings have an ocean view.

Example 3:

Input: heights = [1,3,2,4]

Output: [3]

Explanation: Only building 3 has an ocean view.

Example 4:

Input: heights = [2,2,2,2]

Output: [3]

Explanation: Buildings cannot see the ocean if there are buildings of the same height to its right.

Constraints:

1 <= heights.length <= 10^5
1 <= heights[i] <= 10^9

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test([]int{4, 2, 3, 1}, []int{0, 2, 3})
	test([]int{4, 3, 2, 1}, []int{0, 1, 2, 3})
	test([]int{1, 3, 2, 4}, []int{3})
	test([]int{2, 2, 2, 2}, []int{3})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(h, r []int) {
	p := buildings(h)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func buildings(h []int) []int {
	r := []int{}
	m := 0
	for i := len(h) - 1; i >= 0; i-- {
		if v := h[i]; m < v {
			r, m = append(r, i), v
		}
	}

	for i, j := 0, len(r)-1; i < j; i, j = i+1, j-1 {
		r[i], r[j] = r[j], r[i]
	}

	return r
}
