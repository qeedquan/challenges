/*

Given the array houses where houses[i] is the location of the ith house along a street and an integer k, allocate k mailboxes in the street.

Return the minimum total distance between each house and its nearest mailbox.

The test cases are generated so that the answer fits in a 32-bit integer.

Example 1:
https://assets.leetcode.com/uploads/2020/05/07/sample_11_1816.png
Input: houses = [1,4,8,10,20], k = 3
Output: 5
Explanation: Allocate mailboxes in position 3, 9 and 20.
Minimum total distance from each houses to nearest mailboxes is |3-1| + |4-3| + |9-8| + |10-9| + |20-20| = 5

Example 2:
https://assets.leetcode.com/uploads/2020/05/07/sample_2_1816.png
Input: houses = [2,3,5,12,18], k = 2
Output: 9
Explanation: Allocate mailboxes in position 3 and 14.
Minimum total distance from each houses to nearest mailboxes is |2-3| + |3-3| + |5-3| + |12-14| + |18-14| = 9.

Constraints:

1 <= k <= houses.length <= 100
1 <= houses[i] <= 10^4
All the integers of houses are unique.

Hint 1
If k =1, the minimum distance is obtained allocating the mailbox in the median of the array houses.

Hint 2
Generalize this idea, using dynamic programming allocating k mailboxes.

*/

package main

import "sort"

func main() {
	assert(distance([]int{1, 4, 8, 10, 20}, 3) == 5)
	assert(distance([]int{2, 3, 5, 12, 18}, 2) == 9)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func distance(h []int, k int) int {
	n := len(h)
	if n == 0 {
		return 0
	}

	sort.Ints(h)

	p := make([]int, n+1)
	for i := range h {
		p[i+1] = p[i] + h[i]
	}

	c := make([]int, n)
	for j := range h {
		c[j] = cost(p, 0, j)
	}

	for m := 1; m < k; m++ {
		for j := n - 1; j >= 0; j-- {
			for i := m; i <= j; i++ {
				c[j] = min(c[j], c[i-1]+cost(p, i, j))
			}
		}
	}
	return c[n-1]
}

func cost(p []int, i, j int) int {
	return (p[j+1] - p[(i+j+1)/2]) - (p[(i+j)/2+1] - p[i])
}
