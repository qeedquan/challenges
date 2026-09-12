/*

You are given two non-increasing 0-indexed integer arrays nums1 and nums2.

A pair of indices (i, j), where 0 <= i < nums1.length and 0 <= j < nums2.length, is valid if both i <= j and nums1[i] <= nums2[j]. The distance of the pair is j - i.

Return the maximum distance of any valid pair (i, j). If there are no valid pairs, return 0.

An array arr is non-increasing if arr[i-1] >= arr[i] for every 1 <= i < arr.length.

Example 1:

Input: nums1 = [55,30,5,4,2], nums2 = [100,20,10,10,5]
Output: 2
Explanation: The valid pairs are (0,0), (2,2), (2,3), (2,4), (3,3), (3,4), and (4,4).
The maximum distance is 2 with pair (2,4).
Example 2:

Input: nums1 = [2,2,2], nums2 = [10,10,1]
Output: 1
Explanation: The valid pairs are (0,0), (0,1), and (1,1).
The maximum distance is 1 with pair (0,1).
Example 3:

Input: nums1 = [30,29,19,5], nums2 = [25,25,25,25,25]
Output: 2
Explanation: The valid pairs are (2,2), (2,3), (2,4), (3,3), and (3,4).
The maximum distance is 2 with pair (2,4).

Constraints:

1 <= nums1.length, nums2.length <= 10^5
1 <= nums1[i], nums2[j] <= 10^5
Both nums1 and nums2 are non-increasing.

Hint 1
Since both arrays are sorted in a non-increasing way this means that for each value in the first array.
We can find the farthest value smaller than it using binary search.

Hint 2
There is another solution using a two pointers approach since the first array is non-increasing the farthest j such that nums2[j] ≥ nums1[i]
is at least as far as the farthest j such that nums2[j] ≥ nums1[i-1]

*/

package main

func main() {
	assert(maxdistance([]int{55, 30, 5, 4, 2}, []int{100, 20, 10, 10, 5}) == 2)
	assert(maxdistance([]int{2, 2, 2}, []int{10, 10, 1}) == 1)
	assert(maxdistance([]int{30, 29, 19, 5}, []int{25, 25, 25, 25, 25}) == 2)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func maxdistance(a, b []int) int {
	r := 0
	for i, j := 0, 0; i < len(a) && j < len(b); {
		if a[i] > b[j] {
			i += 1
		} else {
			r = max(r, j-i)
			j += 1
		}
	}
	return r
}
