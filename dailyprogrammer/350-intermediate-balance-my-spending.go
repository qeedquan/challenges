/*

Description
Given my bank account transactions - debits and credits - as a sequence of integers, at what points do my behaviors show the same sub-sums of all transactions before or after. Basically can you find the equilibria points of my bank account?

Input Description
You'll be given input over two lines. The first line tells you how many distinct values to read in the following line. The next line is sequence of integers showing credits and debits. Example:

8
0 -3 5 -4 -2 3 1 0
Output Description
Your program should emit the positions (0-indexed) where the sum of the sub-sequences before and after the position are the same. For the above:

0 3 7
Meaning the zeroeth, third and seventh positions have the same sum before and after.

Challenge Input
11
3 -2 2 0 3 4 -6 3 5 -4 8
11
9 0 -5 -4 1 4 -4 -9 0 -7 -1
11
9 -7 6 -8 3 -9 -5 3 -6 -8 5

Challenge Output
5
8
6

Bonus
See if you can find the O(n) solution and not the O(n^2) solution.

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test(
		[]int{0, -3, 5, -4, -2, 3, 1, 0},
		[]int{0, 3, 7},
	)

	test(
		[]int{3, -2, 2, 0, 3, 4, -6, 3, 5, -4, 8},
		[]int{5},
	)

	test(
		[]int{9, 0, -5, -4, 1, 4, -4, -9, 0, -7, -1},
		[]int{8},
	)

	test(
		[]int{9, -7, 6, -8, 3, -9, -5, 3, -6, -8, 5},
		[]int{6},
	)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(numbers, expected []int) {
	result := balance(numbers)
	fmt.Println(result)
	assert(reflect.DeepEqual(result, expected))
}

func balance(numbers []int) []int {
	result := []int{}
	left := 0
	right := sum(numbers)
	for index, value := range numbers {
		right -= value
		if left == right {
			result = append(result, index)
		}
		left += value
	}
	return result
}

func sum(numbers []int) int {
	result := 0
	for _, number := range numbers {
		result += number
	}
	return result
}
