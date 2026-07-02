/*

You are given an array original of length n and a 2D array bounds of length n x 2, where bounds[i] = [ui, vi].

You need to find the number of possible arrays copy of length n such that:

(copy[i] - copy[i - 1]) == (original[i] - original[i - 1]) for 1 <= i <= n - 1.
ui <= copy[i] <= vi for 0 <= i <= n - 1.
Return the number of such arrays.

Example 1:

Input: original = [1,2,3,4], bounds = [[1,2],[2,3],[3,4],[4,5]]

Output: 2

Explanation:

The possible arrays are:

[1, 2, 3, 4]
[2, 3, 4, 5]

Example 2:

Input: original = [1,2,3,4], bounds = [[1,10],[2,9],[3,8],[4,7]]

Output: 4

Explanation:

The possible arrays are:

[1, 2, 3, 4]
[2, 3, 4, 5]
[3, 4, 5, 6]
[4, 5, 6, 7]

Example 3:

Input: original = [1,2,1,2], bounds = [[1,1],[2,3],[3,3],[2,3]]

Output: 0

Explanation:

No array is possible.

Constraints:

2 <= n == original.length <= 10^5
1 <= original[i] <= 10^9
bounds.length == n
bounds[i].length == 2
1 <= bounds[i][0] <= bounds[i][1] <= 10^9

Hint 1
copy[0] uniquely determines all other values.

Hint 2
Possible values for copy[0] are in [u[0], v[0]].

Hint 3
From left to right, compute valid ranges for each index by intersecting bounds with the previous range.

Hint 4
The answer is the size of the valid range for the last index.

*/

package main

func main() {
	assert(count([]int{1, 2, 3, 4}, [][2]int{{1, 2}, {2, 3}, {3, 4}, {4, 5}}) == 2)
	assert(count([]int{1, 2, 3, 4}, [][2]int{{1, 10}, {2, 9}, {3, 8}, {4, 7}}) == 4)
	assert(count([]int{1, 2, 1, 2}, [][2]int{{1, 1}, {2, 3}, {3, 3}, {2, 3}}) == 0)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func count(original []int, bounds [][2]int) int {
	left := bounds[0][0]
	right := bounds[0][1]
	result := right - left + 1
	for i := 1; i < len(original); i++ {
		diff := original[i] - original[i-1]
		left = max(left+diff, bounds[i][0])
		right = min(right+diff, bounds[i][1])
		result = min(result, max(right-left+1, 0))
	}
	return result
}
