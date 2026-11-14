/*

You are given a positive integer n and an integer target.

Return the

array of integers of size n such that:

    The sum of its elements equals target.
    The absolute values of its elements form a permutation of size n.

If no such array exists, return an empty array.

A permutation of size n is a rearrangement of integers 1, 2, ..., n.

Example 1:

Input: n = 3, target = 0

Output: [-3,1,2]

Explanation:

The arrays that sum to 0 and whose absolute values form a permutation of size 3 are:

    [-3, 1, 2]
    [-3, 2, 1]
    [-2, -1, 3]
    [-2, 3, -1]
    [-1, -2, 3]
    [-1, 3, -2]
    [1, -3, 2]
    [1, 2, -3]
    [2, -3, 1]
    [2, 1, -3]
    [3, -2, -1]
    [3, -1, -2]

The lexicographically smallest one is [-3, 1, 2].

Example 2:

Input: n = 1, target = 10000000000

Output: []

Explanation:

There are no arrays that sum to 10000000000 and whose absolute values form a permutation of size 1. Therefore, the answer is [].

Constraints:

    1 <= n <= 10^5
    -10^10 <= target <= 10^10

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test(3, 0, []int64{-3, 1, 2})
	test(1, 10000000000, []int64{})
}

func assert(x bool) {
	if !x {
		panic("ssertion failed")
	}
}

func test(number, target int64, expected []int64) {
	result := solve(number, target)
	fmt.Println(result)
	assert(reflect.DeepEqual(result, expected))
}

func solve(number, target int64) []int64 {
	total := triangular(number)
	if abs(target) > total || (target-total)%2 != 0 {
		return []int64{}
	}

	result := make([]int64, number)
	left := 0
	right := number - 1
	for index := number; index >= 1; index-- {
		if target+index <= triangular(index-1) {
			target += index
			result[left] = -index
			left += 1
		} else {
			target -= index
			result[right] = index
			right -= 1
		}
	}
	return result
}

func triangular(n int64) int64 {
	return n * (n + 1) / 2
}

func abs(x int64) int64 {
	if x < 0 {
		x = -x
	}
	return x
}
