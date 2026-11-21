/*

Given an integer array num sorted in non-decreasing order.

You can perform the following operation any number of times:

Choose two indices, i and j, where nums[i] < nums[j].
Then, remove the elements at indices i and j from nums. The remaining elements retain their original order, and the array is re-indexed.
Return the minimum length of nums after applying the operation zero or more times.

Example 1:
Input: nums = [1,2,3,4]
Output: 0
Explanation:
https://assets.leetcode.com/uploads/2024/05/18/tcase1.gif

Example 2:
Input: nums = [1,1,2,2,3,3]
Output: 0
Explanation:
https://assets.leetcode.com/uploads/2024/05/19/tcase2.gif

Example 3:
Input: nums = [1000000000,1000000000]
Output: 2
Explanation:
Since both numbers are equal, they cannot be removed.

Example 4:
Input: nums = [2,3,4,4,4]
Output: 1
Explanation:
https://assets.leetcode.com/uploads/2024/05/19/tcase3.gif

Constraints:

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9
nums is sorted in non-decreasing order.

Hint 1
To minimize the length of the array, we should maximize the number of operations performed.

Hint 2
To perform k operations, it is optimal to use the smallest k values and the largest k values in nums.

Hint 3
What is the best way to make pairs from the smallest k values and the largest k values so it is possible to remove all the pairs?

Hint 4
If we consider the smallest k values and the largest k values as two separate sorted 0-indexed arrays, a and b, It is optimal to pair a[i] and b[i].
So, a k is valid if a[i] < b[i] for all i in the range [0, k - 1].

Hint 5
The greatest possible valid k can be found using binary search.

Hint 6
The answer is nums.length - 2*k.

*/

package main

func main() {
	assert(removals([]int{1, 2, 3, 4}) == 0)
	assert(removals([]int{1, 1, 2, 2, 3, 3}) == 0)
	assert(removals([]int{1000000000, 1000000000}) == 2)
	assert(removals([]int{2, 3, 4, 4, 4}) == 1)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func removals(a []int) int {
	c := make(map[int]int)
	for _, v := range a {
		c[v] += 1
	}

	r := 0
	for _, v := range c {
		r = max(r, v)
	}

	n := len(a)
	if r > n-r {
		return r - (n - r)
	}
	return n % 2
}
