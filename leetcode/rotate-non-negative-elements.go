/*

Description
You are given an integer array nums and an integer k.

Rotate only the non-negative elements of the array to the left by k positions, in a cyclic manner.

All negative elements must stay in their original positions and must not move.

After rotation, place the non-negative elements back into the array in the new order, filling only the positions that originally contained non-negative values and skipping all negative positions.

Return the resulting array.

Example 1:

Input: nums = [1,-2,3,-4], k = 3

Output: [3,-2,1,-4]

Explanation:

The non-negative elements, in order, are [1, 3].
Left rotation with k = 3 results in:
[1, 3] -> [3, 1] -> [1, 3] -> [3, 1]
Placing them back into the non-negative indices results in [3, -2, 1, -4].

Example 2:

Input: nums = [-3,-2,7], k = 1

Output: [-3,-2,7]

Explanation:

The non-negative elements, in order, are [7].
Left rotation with k = 1 results in [7].
Placing them back into the non-negative indices results in [-3, -2, 7].

Example 3:

Input: nums = [5,4,-9,6], k = 2

Output: [6,5,-9,4]

Explanation:

The non-negative elements, in order, are [5, 4, 6].
Left rotation with k = 2 results in [6, 5, 4].
Placing them back into the non-negative indices results in [6, 5, -9, 4].


Constraints:

1 <= nums.length <= 10^5
-105 <= nums[i] <= 10^5
0 <= k <= 10^5

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test([]int{1, -2, 3, -4}, 3, []int{3, -2, 1, -4})
	test([]int{-3, -2, 7}, 1, []int{-3, -2, 7})
	test([]int{5, 4, -9, 6}, 2, []int{6, 5, -9, 4})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a []int, k int, r []int) {
	rotate(a, k)
	fmt.Println(a)
	assert(reflect.DeepEqual(a, r))
}

func rotate(a []int, k int) []int {
	t := make([]int, 0)
	for _, x := range a {
		if x >= 0 {
			t = append(t, x)
		}
	}

	m := len(t)
	d := make([]int, m)
	for i, x := range t {
		d[((i-k)%m+m)%m] = x
	}

	j := 0
	for i, x := range a {
		if x >= 0 {
			a[i], j = d[j], j+1
		}
	}
	return a
}
