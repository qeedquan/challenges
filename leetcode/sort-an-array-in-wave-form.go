/*

Given an unsorted array of integers, sort the array into a wave array. An array arr[0..n-1] is sorted in wave form if:
arr[0] >= arr[1] <= arr[2] >= arr[3] <= arr[4] >= …..

Examples:

Input:  arr[] = {10, 5, 6, 3, 2, 20, 100, 80}
Output: arr[] = {10, 5, 6, 2, 20, 3, 100, 80}
Explanation:
here you can see {10, 5, 6, 2, 20, 3, 100, 80} first element is larger than the second and the same thing is repeated again and again. large element – small element-large element -small element and so on .it can be small element-larger element – small element-large element -small element too. all you need to maintain is the up-down fashion which represents a wave. there can be multiple answers.

Input: arr[] = {20, 10, 8, 6, 4, 2}
Output: arr[] = {20, 8, 10, 4, 6, 2}

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test([]int{10, 5, 6, 3, 2, 20, 100, 80}, []int{10, 5, 6, 2, 20, 3, 100, 80})
	test([]int{20, 10, 8, 6, 4, 2}, []int{20, 8, 10, 4, 6, 2})
	test([]int{10, 90, 49, 2, 1, 5, 23}, []int{90, 10, 49, 1, 5, 2, 23})
	test([]int{3, 1, 7, 2, 8}, []int{3, 1, 7, 2, 8})
	test([]int{1, 7, 2, 8, 3}, []int{7, 1, 8, 2, 3})
	test([]int{1, 2, 3}, []int{2, 1, 3})
	test([]int{1, 2}, []int{2, 1})
	test([]int{1}, []int{1})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func verify(a []int) bool {
	for i := 0; i < len(a)-1; i++ {
		switch {
		case i&1 == 0 && a[i] < a[i+1]:
			fallthrough
		case i&1 == 1 && a[i] > a[i+1]:
			return false
		}
	}
	return true
}

func test(a, r []int) {
	wavesort(a)
	fmt.Println(a)
	assert(verify(a))
	assert(reflect.DeepEqual(a, r))
}

// https://www.geeksforgeeks.org/sort-array-wave-form-2/
func wavesort(a []int) {
	n := len(a)
	for i := 0; i < n; i += 2 {
		if i > 0 && a[i-1] > a[i] {
			a[i], a[i-1] = a[i-1], a[i]
		}

		if i < n-1 && a[i] < a[i+1] {
			a[i], a[i+1] = a[i+1], a[i]
		}
	}
}
