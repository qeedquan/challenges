/*

You are given an array apple of size n and an array capacity of size m.

There are n packs where the ith pack contains apple[i] apples. There are m boxes as well, and the ith box has a capacity of capacity[i] apples.

Return the minimum number of boxes you need to select to redistribute these n packs of apples into boxes.

Note that, apples from the same pack can be distributed into different boxes.

Example 1:

Input: apple = [1,3,2], capacity = [4,3,1,5,2]
Output: 2
Explanation: We will use boxes with capacities 4 and 5.
It is possible to distribute the apples as the total capacity is greater than or equal to the total number of apples.

Example 2:

Input: apple = [5,5,5], capacity = [2,4,2,7]
Output: 4
Explanation: We will need to use all the boxes.

Constraints:

1 <= n == apple.length <= 50
1 <= m == capacity.length <= 50
1 <= apple[i], capacity[i] <= 50
The input is generated such that it's possible to redistribute packs of apples into boxes.

Hint 1
Sort array capacity in non-decreasing order.

Hint 2
Greedily select boxes with the largest capacities to redistribute apples optimally.

*/

package main

import "sort"

func main() {
	assert(boxes([]int{1, 3, 2}, []int{4, 3, 1, 5, 2}) == 2)
	assert(boxes([]int{5, 5, 5}, []int{2, 4, 2, 7}) == 4)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func boxes(apple, capacity []int) int {
	sort.Slice(capacity, func(i, j int) bool {
		return capacity[i] > capacity[j]
	})

	total := 0
	for _, value := range apple {
		total += value
	}

	for i := range capacity {
		total -= capacity[i]
		if total <= 0 {
			return i + 1
		}
	}
	return -1
}
