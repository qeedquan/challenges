/*

Given an integer array arr, remove a subarray (can be empty) from arr such that the remaining elements in arr are non-decreasing.

Return the length of the shortest subarray to remove.

A subarray is a contiguous subsequence of the array.

Example 1:
Input: arr = [1,2,3,10,4,2,3,5]
Output: 3
Explanation: The shortest subarray we can remove is [10,4,2] of length 3. The remaining elements after that will be [1,2,3,3,5] which are sorted.
Another correct solution is to remove the subarray [3,10,4].

Example 2:
Input: arr = [5,4,3,2,1]
Output: 4
Explanation: Since the array is strictly decreasing, we can only keep a single element. Therefore we need to remove a subarray of length 4, either [5,4,3,2] or [4,3,2,1].

Example 3:
Input: arr = [1,2,3]
Output: 0
Explanation: The array is already non-decreasing. We do not need to remove any elements.

Constraints:

1 <= arr.length <= 10^5
0 <= arr[i] <= 10^9


Hint 1
The key is to find the longest non-decreasing subarray starting with the first element or ending with the last element, respectively.

Hint 2
After removing some subarray, the result is the concatenation of a sorted prefix and a sorted suffix,
where the last element of the prefix is smaller than the first element of the suffix.

*/

package main

func main() {
	assert(find([]int{1, 2, 3, 10, 4, 2, 3, 5}) == 3)
	assert(find([]int{5, 4, 3, 2, 1}) == 4)
	assert(find([]int{1, 2, 3}) == 0)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func find(a []int) int {
	j := len(a) - 1
	for ; j >= 1; j-- {
		if a[j-1] > a[j] {
			break
		}
	}
	if j == 0 {
		return 0
	}

	r := j
	for i := range a {
		if i > 0 && a[i-1] > a[i] {
			break
		}

		for j < len(a) && a[i] > a[j] {
			j++
		}

		r = min(r, (j-i+1)-2)
	}
	return r
}
