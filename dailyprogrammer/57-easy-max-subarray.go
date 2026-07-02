/*

Input: A sequence of integers either +ve or -ve

Output: a part of the sequence in the list with the maximum sum.

*/

package main

import "fmt"

func main() {
	fmt.Println(max_subarray([]int{1, 2, -5, 4, -3, 2}))
	fmt.Println(max_subarray([]int{-1, -2, -3}))
	fmt.Println(max_subarray([]int{31, -41, 59, 26, -53, 58, 97, -93, -23, 84}))
	fmt.Println(max_subarray([]int{1, 2, 3, -4, 5, -20}))
	fmt.Println(max_subarray([]int{-10, -9, -8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}))
}

// https://en.wikipedia.org/wiki/Maximum_subarray_problem
// Kadane Algorithm
func max_subarray(a []int) ([]int, int) {
	x0, x1, lo, hi := 0, 0, 0, 0
	for i, x := range a {
		if x > x1+x {
			x1, lo = x, i
		} else {
			x1 += x
		}
		if x1 > x0 {
			x0, hi = x1, i
		}
	}
	if lo >= hi+1 {
		return []int{}, 0
	}
	return a[lo : hi+1], x0
}
