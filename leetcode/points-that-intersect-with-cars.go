/*

You are given a 0-indexed 2D integer array nums representing the coordinates of the cars parking on a number line. For any index i, nums[i] = [starti, endi] where starti is the starting point of the ith car and endi is the ending point of the ith car.

Return the number of integer points on the line that are covered with any part of a car.

Example 1:

Input: nums = [[3,6],[1,5],[4,7]]
Output: 7
Explanation: All the points from 1 to 7 intersect at least one car, therefore the answer would be 7.

Example 2:

Input: nums = [[1,3],[5,8]]
Output: 7
Explanation: Points intersecting at least one car are 1, 2, 3, 5, 6, 7, 8. There are a total of 7 points, therefore the answer would be 7.

Constraints:

1 <= nums.length <= 100
nums[i].length == 2
1 <= starti <= endi <= 100

Hint 1
Sort the array according to first element and then starting from the 0th index remove the overlapping parts and return the count of non-overlapping points.

*/

package main

import (
	"sort"
)

func main() {
	assert(count([][2]int{{3, 6}, {1, 5}, {4, 7}}) == 7)
	assert(count([][2]int{{1, 3}, {5, 8}}) == 7)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func count(points [][2]int) int {
	if len(points) == 0 {
		return 0
	}

	sort.Slice(points, func(i, j int) bool {
		if points[i][0] == points[j][0] {
			return points[i][0] < points[j][0]
		}
		return points[i][1] < points[j][1]
	})

	result := 0
	current := points[0]
	for i := 1; i < len(points); i++ {
		if points[i][0] <= current[1] {
			current[1] = max(current[1], points[i][1])
		} else {
			result += current[1] - current[0] + 1
			current = points[i]
		}
	}
	result += current[1] - current[0] + 1
	return result
}
