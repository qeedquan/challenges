/*

From SO.
https://stackoverflow.com/questions/4897280/given-an-array-of-positive-and-negative-integers-re-arrange-it-so-that-you-have

You are given an array with positive and negative integers. Write a function to change the elements order in the array such that negative integers are at the beginning, the positive integers are at the end and two integers that have the same sign don't change order.

Example:

Input 1,7,-5,9,-12,15
Output -5,-12,1,7,9,15
Input 1,-2,-1,2
Output -2, -1, 1, 2
Constraints: O(n) time limit and O(1) extra memory.

*/

package main

import (
	"fmt"
	"reflect"
	"sort"
)

func main() {
	test([]int{1, 7, -5, 9, -12, 15}, []int{-5, -12, 1, 7, 9, 15})
	test([]int{1, -2, -1, 2}, []int{-2, -1, 1, 2})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a, r []int) {
	spssort(a)
	fmt.Println(a)
	assert(reflect.DeepEqual(a, r))
}

func spssort(a []int) []int {
	sort.SliceStable(a, func(i, j int) bool {
		return sign(a[i]) < sign(a[j])
	})
	return a
}

func sign(x int) int {
	if x < 0 {
		return -1
	}
	return 1
}
