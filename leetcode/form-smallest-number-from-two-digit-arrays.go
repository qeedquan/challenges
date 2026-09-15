/*

Given two arrays of unique digits nums1 and nums2, return the smallest number that contains at least one digit from each array.

Example 1:

Input: nums1 = [4,1,3], nums2 = [5,7]
Output: 15
Explanation: The number 15 contains the digit 1 from nums1 and the digit 5 from nums2. It can be proven that 15 is the smallest number we can have.

Example 2:

Input: nums1 = [3,5,2,6], nums2 = [3,1,7]
Output: 3
Explanation: The number 3 contains the digit 3 which exists in both arrays.

Constraints:

1 <= nums1.length, nums2.length <= 9
1 <= nums1[i], nums2[i] <= 9
All digits in each array are unique.

Hint 1
How many digits will the resulting number have at most?

Hint 2
The resulting number will have either one or two digits. Try to find when each case is possible.

*/

package main

import (
	"math"
	"slices"
)

func main() {
	assert(minimize([]int{4, 1, 3}, []int{5, 7}) == 15)
	assert(minimize([]int{3, 5, 2, 6}, []int{3, 1, 7}) == 3)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func minimize(numbers1, numbers2 []int) int {
	lookup := make(map[int]bool)
	for _, number := range numbers1 {
		lookup[number] = true
	}

	minimum := math.MaxInt
	for _, number := range numbers2 {
		if lookup[number] {
			minimum = min(minimum, number)
		}
	}
	if minimum != math.MaxInt {
		return minimum
	}

	digit1 := slices.Min(numbers1)
	digit2 := slices.Min(numbers2)
	if digit1 > digit2 {
		digit1, digit2 = digit2, digit1
	}
	return 10*digit1 + digit2
}
