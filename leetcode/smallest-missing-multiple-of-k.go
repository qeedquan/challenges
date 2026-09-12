/*

Given an integer array nums and an integer k, return the smallest positive multiple of k that is missing from nums.

A multiple of k is any positive integer divisible by k.

Example 1:

Input: nums = [8,2,3,4,6], k = 2

Output: 10

Explanation:

The multiples of k = 2 are 2, 4, 6, 8, 10, 12... and the smallest multiple missing from nums is 10.

Example 2:

Input: nums = [1,4,7,10,15], k = 5

Output: 5

Explanation:

The multiples of k = 5 are 5, 10, 15, 20... and the smallest multiple missing from nums is 5.



Constraints:

    1 <= nums.length <= 100
    1 <= nums[i] <= 100
    1 <= k <= 100

Hint 1
Add the values in nums to a hash set

Hint 2
Iterate through the positive multiples of k and return the first one not in the hash set

*/

package main

func main() {
	assert(missing([]int{8, 2, 3, 4, 6}, 2) == 10)
	assert(missing([]int{1, 4, 7, 10, 15}, 5) == 5)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func missing(a []int, k int) int {
	m := make(map[int]bool)
	for _, v := range a {
		m[v] = true
	}
	for i := 1; i <= len(m); i++ {
		if !m[i*k] {
			return i * k
		}
	}
	return (len(m) + 1) * k
}
