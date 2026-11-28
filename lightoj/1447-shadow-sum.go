/*

Shadow Sum of an array is defined by adding all elements from left to right with the condition that each element will shadow (remove) any element seen so far with the same magnitude.

For example, the shadow sum of [5 -5 8 2 -5 9 8] is (2 + -5 + 9 + 8) = 14. Here's how:

[]                | initial empty result.
[5]               | first element is 5.
[-5]              | second element is -5, which shadows 5, as they have the same magnitude.
[-5, 8]           | third element is 8.
[-5, 8, 2]        | fourth element 2.
[8, 2, -5]        | fifth element is -5, which shadows the previous -5.
[8, 2, -5, 9]     | sixth element is 9.
[2, -5, 9, 8]     | seventh element is 8, which shadows the previous 8.

So, the sum is 2 + -5 + 9 + 8 = 14.
Given an array, you have to compute the Shadow Sum of the array.

Input
Input starts with an integer T (≤ 25), denoting the number of test cases.

Each case starts with an integer N (1 ≤ N ≤ 20000) denoting the size of the array. The next line contains N integers. The absolute value of any integer will not be greater than 20000.

Output
For each case, print the case number and the Shadow Sum of the array.

Sample
Input	Output
3
7
5 -5 8 2 -5 9 8
2
1 2
8
1 -1 -1 1 -1 1 8 1

Case 1: 14
Case 2: 3
Case 3: 9

*/

package main

func main() {
	assert(solve([]int{5, -5, 8, 2, -5, 9, 8}) == 14)
	assert(solve([]int{1, 2}) == 3)
	assert(solve([]int{1, -1, -1, 1, -1, 1, 8, 1}) == 9)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(array []int) int {
	count := make(map[int]bool)
	for index := len(array) - 1; index >= 0; index-- {
		value := array[index]
		if !count[value] && !count[-value] {
			count[value] = true
		}
	}

	sum := 0
	for value := range count {
		sum += value
	}
	return sum
}
