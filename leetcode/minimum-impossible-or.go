/*

You are given a 0-indexed integer array nums.

We say that an integer x is expressible from nums if there exist some integers 0 <= index1 < index2 < ... < indexk < nums.length for which nums[index1] | nums[index2] | ... | nums[indexk] = x. In other words, an integer is expressible if it can be written as the bitwise OR of some subsequence of nums.

Return the minimum positive non-zero integer that is not expressible from nums.

Example 1:

Input: nums = [2,1]
Output: 4
Explanation: 1 and 2 are already present in the array. We know that 3 is expressible, since nums[0] | nums[1] = 2 | 1 = 3. Since 4 is not expressible, we return 4.

Example 2:

Input: nums = [5,3,2]
Output: 1
Explanation: We can show that 1 is the smallest number that is not expressible.

Constraints:

    1 <= nums.length <= 10^5
    1 <= nums[i] <= 10^9

Hint 1
Think about forming numbers in the powers of 2 using their bit representation.

Hint 2
The minimum power of 2 not present in the array will be the first number that could not be expressed using the given operation.

*/

package main

func main() {
	assert(solve([]int{2, 1}) == 4)
	assert(solve([]int{5, 3, 2}) == 1)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(numbers []int) int {
	lookup := make(map[int]bool)
	for _, number := range numbers {
		lookup[number] = true
	}

	base := 1
	for lookup[base] {
		base <<= 1
	}
	return base
}
