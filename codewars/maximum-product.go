/*

Task
Given an array of integers , Find the maximum product obtained from multiplying 2 adjacent numbers in the array.

Notes
Array/list size is at least 2.

Array/list numbers could be a mixture of positives, negatives also zeroes .

Input >> Output Examples
adjacentElementsProduct([1, 2, 3]); ==> return 6
Explanation:
The maximum product obtained from multiplying 2 * 3 = 6, and they're adjacent numbers in the array.
adjacentElementsProduct([9, 5, 10, 2, 24, -1, -48]); ==> return 50
Explanation:
Max product obtained from multiplying 5 * 10  =  50 .

adjacentElementsProduct([-23, 4, -5, 99, -27, 329, -2, 7, -921])  ==>  return -14
Explanation:
The maximum product obtained from multiplying -2 * 7 = -14, and they're adjacent numbers in the array.

*/

package main

import "math"

func main() {
	assert(product([]int{1, 2, 3}) == 6)
	assert(product([]int{9, 5, 10, 2, 24, -1, -48}) == 50)
	assert(product([]int{-23, 4, -5, 99, -27, 329, -2, 7, -921}) == -14)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func product(a []int) int {
	m := math.MinInt
	for i := 1; i < len(a); i++ {
		m = max(m, a[i]*a[i-1])
	}
	return m
}
