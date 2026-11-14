/*

You are given an array of integers distance.

You start at the point (0, 0) on an X-Y plane, and you move distance[0] meters to the north,
then distance[1] meters to the west, distance[2] meters to the south, distance[3] meters to the east, and so on.
In other words, after each move, your direction changes counter-clockwise.

Return true if your path crosses itself or false if it does not.

Example 1:
https://assets.leetcode.com/uploads/2022/12/21/11.jpg
Input: distance = [2,1,1,2]
Output: true
Explanation: The path crosses itself at the point (0, 1).

Example 2:
https://assets.leetcode.com/uploads/2022/12/21/22.jpg
Input: distance = [1,2,3,4]
Output: false
Explanation: The path does not cross itself at any point.

Example 3:
https://assets.leetcode.com/uploads/2022/12/21/33.jpg
Input: distance = [1,1,1,2,1]
Output: true
Explanation: The path crosses itself at the point (0, 0).

Constraints:

1 <= distance.length <= 10^5
1 <= distance[i] <= 10^5

*/

package main

func main() {
	assert(selfcross([]int{2, 1, 1, 2}) == true)
	assert(selfcross([]int{1, 2, 3, 4}) == false)
	assert(selfcross([]int{1, 1, 1, 2, 1}) == true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func selfcross(x []int) bool {
	n := len(x)
	if n >= 5 && x[3] == x[1] && x[4]+x[0] >= x[2] {
		return true
	}

	for i := 3; i < n; i++ {
		if x[i] >= x[i-2] && x[i-3] >= x[i-1] {
			return true
		}
		if i >= 5 && x[i-4] <= x[i-2] && x[i]+x[i-4] >= x[i-2] && x[i-1] <= x[i-3] && x[i-5]+x[i-1] >= x[i-3] {
			return true
		}
	}
	return false
}
