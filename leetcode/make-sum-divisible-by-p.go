/*

Given an array of positive integers nums, remove the smallest subarray (possibly empty) such that the sum of the remaining elements is divisible by p. It is not allowed to remove the whole array.

Return the length of the smallest subarray that you need to remove, or -1 if it's impossible.

A subarray is defined as a contiguous block of elements in the array.

Example 1:

Input: nums = [3,1,4,2], p = 6
Output: 1
Explanation: The sum of the elements in nums is 10, which is not divisible by 6. We can remove the subarray [4], and the sum of the remaining elements is 6, which is divisible by 6.

Example 2:

Input: nums = [6,3,5,2], p = 9
Output: 2
Explanation: We cannot remove a single element to get a sum divisible by 9. The best way is to remove the subarray [5,2], leaving us with [6,3] with sum 9.

Example 3:

Input: nums = [1,2,3], p = 3
Output: 0
Explanation: Here the sum is 6. which is already divisible by 3. Thus we do not need to remove anything.

Constraints:

    1 <= nums.length <= 10^5
    1 <= nums[i] <= 10^9
    1 <= p <= 10^9

Hint 1
Use prefix sums to calculate the subarray sums.

Hint 2
Suppose you know the remainder for the sum of the entire array. How does removing a subarray affect that remainder? What remainder does the subarray need to have in order to make the rest of the array sum up to be divisible by k?

Hint 3
Use a map to keep track of the rightmost index for every prefix sum % p.

*/

package main

func main() {
	assert(minsubarray([]int{3, 1, 4, 2}, 6) == 1)
	assert(minsubarray([]int{6, 3, 5, 2}, 9) == 2)
	assert(minsubarray([]int{1, 2, 3}, 3) == 0)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func minsubarray(numbers []int, modulus int) int {
	if modulus == 0 {
		return 0
	}

	residue := 0
	for _, number := range numbers {
		residue = (residue + number) % modulus
	}
	if residue == 0 {
		return 0
	}

	result := len(numbers)
	current := 0
	table := map[int]int{0: -1}
	for index, number := range numbers {
		current = (current + number) % modulus
		table[current] = index

		key := (current - residue + modulus) % modulus
		if _, found := table[key]; found {
			result = min(result, index-table[key])
		}
	}

	if result < len(numbers) {
		return result
	}
	return -1
}
