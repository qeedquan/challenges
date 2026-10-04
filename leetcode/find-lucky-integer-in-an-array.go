/*

Given an array of integers arr, a lucky integer is an integer that has a frequency in the array equal to its value.

Return the largest lucky integer in the array. If there is no lucky integer return -1.

Example 1:

Input: arr = [2,2,3,4]
Output: 2
Explanation: The only lucky number in the array is 2 because frequency[2] == 2.
Example 2:

Input: arr = [1,2,2,3,3,3]
Output: 3
Explanation: 1, 2 and 3 are all lucky numbers, return the largest of them.
Example 3:

Input: arr = [2,2,2,3,3]
Output: -1
Explanation: There are no lucky numbers in the array.

Constraints:

1 <= arr.length <= 500
1 <= arr[i] <= 500

Hint 1
Count the frequency of each integer in the array.

Hint 2
Get all lucky numbers and return the largest of them.

*/

package main

func main() {
	assert(lucky([]int{2, 2, 3, 4}) == 2)
	assert(lucky([]int{1, 2, 2, 3, 3, 3}) == 3)
	assert(lucky([]int{2, 2, 2, 3, 3}) == -1)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func lucky(a []int) int {
	c := make(map[int]int)
	for _, v := range a {
		c[v] += 1
	}

	r := -1
	for k, v := range c {
		if k == v {
			r = max(r, k)
		}
	}
	return r
}
