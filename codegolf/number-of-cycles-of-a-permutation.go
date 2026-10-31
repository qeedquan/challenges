/*

Consider a permutation of the integers 1, ..., n, such as this one for n = 6:

[5,2,4,3,6,1]
If you view the permutation as a mapping from [1,2,3,4,5,6] to [5,2,4,3,6,1], the permutation can be decomposed into disjoint cycles. A cycle is a subset of elements that map to each other. For example, 1 gets mapped to 5, which gets mapped to 6, which gets mapped back to 1. So one cycle is [1,5,6]. The other cycles are [2] and [3,4]. Thus the number of cycles for this permutation is 3.

In general, the cycles of a permutation are unique (up to order), and the number of cycles for a permutation of size n varies from 1 to n.

The challenge
Given a non-empty permutation, output its number of cycles.

Input is an array formed by the n integers 1, 2, ..., n, where n > 0. Each integer occurs exactly once. The order in which they appear defines the permutation, as in the example above.

Instead of an array you can use a list, a string with a separator between the numbers, a separate input for each number, or anything that's reasonable.

For a permutation of size n, instead of the 1-based set of integers 1, ..., n you can consistently use the 0-based set 0, ..., n-1. If so, please indicate it in your answer.

The code should work for n up to 20 in a reasonable time, say less than one minute.

Code golf. All builtins allowed.

Test cases
This assumes 1-based, array input.

 [1] -> 1
 [3,2,1] -> 2
 [2,3,4,5,1] -> 1
 [5,2,4,3,6,1] -> 3
 [8,6,4,5,2,1,7,3] -> 2
 [4,5,11,12,7,1,3,9,10,6,8,2] -> 1
 [4,2,5,11,12,7,1,3,9,10,6,8] -> 5
 [5,8,6,18,16,9,14,10,11,12,4,20,15,19,2,17,1,13,7,3] -> 3
 [14,5,17,15,10,18,1,3,4,13,11,16,2,12,9,7,20,6,19,8] -> 7

Related
This related challenge asks for the actual cycles of the permutation, not the number of them. Requiring only the number of cycles can lead to shorter algorithms that sidestep generating the actual cycles.

https://codegolf.stackexchange.com/questions/1668/decompose-a-permutation-into-cycles

*/

package main

func main() {
	assert(cycles([]int{1}) == 1)
	assert(cycles([]int{3, 2, 1}) == 2)
	assert(cycles([]int{2, 3, 4, 5, 1}) == 1)
	assert(cycles([]int{5, 2, 4, 3, 6, 1}) == 3)
	assert(cycles([]int{8, 6, 4, 5, 2, 1, 7, 3}) == 2)
	assert(cycles([]int{4, 5, 11, 12, 7, 1, 3, 9, 10, 6, 8, 2}) == 1)
	assert(cycles([]int{4, 2, 5, 11, 12, 7, 1, 3, 9, 10, 6, 8}) == 5)
	assert(cycles([]int{5, 8, 6, 18, 16, 9, 14, 10, 11, 12, 4, 20, 15, 19, 2, 17, 1, 13, 7, 3}) == 3)
	assert(cycles([]int{14, 5, 17, 15, 10, 18, 1, 3, 4, 13, 11, 16, 2, 12, 9, 7, 20, 6, 19, 8}) == 7)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// ported from @kamoroso94 solution
func cycles(array []int) int {
	hash := make(map[int]bool)
	index := 0
	count := 0
	for index < len(array) {
		start := index
		for !hash[index] {
			hash[index] = true
			index = array[index] - 1
		}
		count += 1

		index = start + 1
		for hash[index] {
			index += 1
		}
	}
	return count
}
