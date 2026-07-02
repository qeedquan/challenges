/*

You are given an array of positive integers nums and want to erase a subarray containing unique elements.
The score you get by erasing the subarray is equal to the sum of its elements.

Return the maximum score you can get by erasing exactly one subarray.

An array b is called to be a subarray of a if it forms a contiguous subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r).

Example 1:
Input: nums = [4,2,4,5,6]
Output: 17
Explanation: The optimal subarray here is [2,4,5,6].

Example 2:
Input: nums = [5,2,1,2,5,2,1,2,5]
Output: 8
Explanation: The optimal subarray here is [5,2,1] or [1,2,5].

Constraints:

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^4

Hint 1
The main point here is for the subarray to contain unique elements for each index. Only the first subarrays starting from that index have unique elements.

Hint 2
This can be solved using the two pointers technique

*/

package main

func main() {
	assert(maxerasure([]int{4, 2, 4, 5, 6}) == 17)
	assert(maxerasure([]int{5, 2, 1, 2, 5, 2, 1, 2, 5}) == 8)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func maxerasure(a []int) int {
	p := make(map[int]int)
	m := 0
	s := 0
	j := 0
	for i := range a {
		if _, f := p[a[i]]; f {
			m = max(m, s)
			for ; j <= p[a[i]]; j++ {
				s -= a[j]
				delete(p, a[j])
			}
		}
		s, p[a[i]] = s+a[i], i
	}
	return max(m, s)
}
