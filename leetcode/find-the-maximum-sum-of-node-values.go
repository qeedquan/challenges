/*

There exists an undirected tree with n nodes numbered 0 to n - 1.
You are given a 0-indexed 2D integer array edges of length n - 1, where edges[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the tree.
You are also given a positive integer k, and a 0-indexed array of non-negative integers nums of length n, where nums[i] represents the value of the node numbered i.

Alice wants the sum of values of tree nodes to be maximum, for which Alice can perform the following operation any number of times (including zero) on the tree:

Choose any edge [u, v] connecting the nodes u and v, and update their values as follows:
nums[u] = nums[u] XOR k
nums[v] = nums[v] XOR k
Return the maximum possible sum of the values Alice can achieve by performing the operation any number of times.

Example 1:
https://assets.leetcode.com/uploads/2023/11/09/screenshot-2023-11-10-012513.png
Input: nums = [1,2,1], k = 3, edges = [[0,1],[0,2]]
Output: 6
Explanation: Alice can achieve the maximum sum of 6 using a single operation:
- Choose the edge [0,2]. nums[0] and nums[2] become: 1 XOR 3 = 2, and the array nums becomes: [1,2,1] -> [2,2,2].
The total sum of values is 2 + 2 + 2 = 6.
It can be shown that 6 is the maximum achievable sum of values.

Example 2:
https://assets.leetcode.com/uploads/2024/01/09/screenshot-2024-01-09-220017.png
Input: nums = [2,3], k = 7, edges = [[0,1]]
Output: 9
Explanation: Alice can achieve the maximum sum of 9 using a single operation:
- Choose the edge [0,1]. nums[0] becomes: 2 XOR 7 = 5 and nums[1] become: 3 XOR 7 = 4, and the array nums becomes: [2,3] -> [5,4].
The total sum of values is 5 + 4 = 9.
It can be shown that 9 is the maximum achievable sum of values.

Example 3:
https://assets.leetcode.com/uploads/2023/11/09/screenshot-2023-11-10-012641.png
Input: nums = [7,7,7,7,7,7], k = 3, edges = [[0,1],[0,2],[0,3],[0,4],[0,5]]
Output: 42
Explanation: The maximum achievable sum is 42 which can be achieved by Alice performing no operations.

Constraints:

2 <= n == nums.length <= 2 * 10^4
1 <= k <= 10^9
0 <= nums[i] <= 10^9
edges.length == n - 1
edges[i].length == 2
0 <= edges[i][0], edges[i][1] <= n - 1
The input is generated such that edges represent a valid tree.

Hint 1
Select any node as the root.

Hint 2
Let dp[x][c] be the maximum sum we can get for the subtree rooted at node x,
where c is a boolean representing whether the edge between node x and its parent (if any) is selected or not.

Hint 3
dp[x][c] = max(sum(dp[y][cy]) + v(nums[x], sum(cy) + c)) where cy is 0 or 1. When sum(cy) + c is odd, v(nums[x], sum(cy) + c) = nums[x] XOR k.
When sum(cy) + c is even, v(nums[x], sum(cy) + c) = nums[x].

Hint 4
There’s also an easier solution - does the parity of the number of elements where nums[i] XOR k > nums[i] help?


*/

package main

import (
	"fmt"
	"math"
)

func main() {
	test(
		[]int{1, 2, 1}, 3, [][2]int{{0, 1}, {0, 2}},
		6,
	)

	test(
		[]int{2, 3}, 7, [][2]int{{0, 1}},
		9,
	)

	test(
		[]int{7, 7, 7, 7, 7, 7}, 3, [][2]int{{0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}},
		42,
	)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(numbers []int, k int, edges [][2]int, expected int) {
	result := solve(numbers, k, edges)
	fmt.Println(result)
	assert(result == expected)
}

func solve(numbers []int, k int, edges [][2]int) int {
	result := 0
	diff := math.MaxInt
	parity := 0
	for _, x := range numbers {
		y := x ^ k
		result += max(x, y)
		if x < y {
			parity ^= 1
		}
		diff = min(diff, abs(x-y))
	}
	return result - parity*diff
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}
