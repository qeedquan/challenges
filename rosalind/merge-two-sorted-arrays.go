/*

Problem
The merging procedure is an essential part of “Merge Sort” (which is considered in one of the next problems).

Given: A positive integer n≤10^5 and a sorted array A[1..n] of integers from -10^5 to 10^5, a positive integer m≤10^5 and a sorted array B[1..m] of integers from -10^5 to 10^5.

Return: A sorted array C[1..n+m] containing all the elements of A and B.

Sample Dataset
4
2 4 10 18
3
-5 11 12
Sample Output
-5 2 4 10 11 12 18

Hint
The very first element of C is either A[1] or B[1], whichever is smaller. The rest of C can then be constructed recursively.

Source: Algorithms by Dasgupta, Papadimitriou, Vazirani. McGraw-Hill. 2006.

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test([]int{2, 4, 10, 18}, []int{-5, 11, 12}, []int{-5, 2, 4, 10, 11, 12, 18})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a, b, r []int) {
	p := merge(a, b)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func merge(a, b []int) []int {
	r := []int{}
	for i, j := 0, 0; i < len(a) || j < len(b); {
		switch {
		case i >= len(a):
			r, j = append(r, b[j:]...), len(b)
		case j >= len(b):
			r, i = append(r, a[i:]...), len(a)
		case a[i] >= b[j]:
			r, j = append(r, b[j]), j+1
		default:
			r, i = append(r, a[i]), i+1
		}
	}
	return r
}
