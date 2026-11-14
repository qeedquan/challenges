/*

Let us define the "multiplicative deltas" of values [a0,⋯aN,] as:

[a1/a0,⋯,ai+1/ai,⋯,aN/aN−1]

The reverse operation - namely "multiplicative undelta" - returns values such that the above operation results in the given values.

Example
Given values [1,5,3,2] a general solution to the "multiplicative undelta" operation is:

[a0, a0*1, a1*5, a2*3, a3*2]

A particular solution can be obtained by setting a0 to any value other than zero, for example by setting a0:=1 we would get:

[1,1,5,15,30]

Challenge
Your task for this challenge is to implement the operation "multiplicative undelta" as defined above.

Rules
Inputs are:

a non-zero value a0
a non-empty list/array/vector/... of non-zero "multiplicative deltas"
Output is a list/array/vector/... of values such that the first element is a0 and for which the "multiplicative deltas" are the input.

Note: If your language has no support of negative integers you may replace non-zero by positive.

Test cases
2 [21] -> [2,42]
1 [1,5,3,2] -> [1,1,5,15,30]
-1 [1,5,3,2] -> [-1,-1,-5,-15,-30]
7 [1,-5,3,2] -> [7,7,-35,-105,-210]
2 [-12,3,-17,1311] -> [2,-24,-72,1224,1604664]
-12 [7,-1,-12,4] -> [-12,-84,84,-1008,-4032]
1 [2,2,2,2,2,2,2,2] -> [1,2,4,8,16,32,64,128,256]

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test(2, []int{21}, []int{2, 42})
	test(1, []int{1, 5, 3, 2}, []int{1, 1, 5, 15, 30})
	test(-1, []int{1, 5, 3, 2}, []int{-1, -1, -5, -15, -30})
	test(7, []int{1, -5, 3, 2}, []int{7, 7, -35, -105, -210})
	test(2, []int{-12, 3, -17, 1311}, []int{2, -24, -72, 1224, 1604664})
	test(-12, []int{7, -1, -12, 4}, []int{-12, -84, 84, -1008, -4032})
	test(1, []int{2, 2, 2, 2, 2, 2, 2, 2}, []int{1, 2, 4, 8, 16, 32, 64, 128, 256})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a0 int, a, r []int) {
	p := undelta(a0, a)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func undelta(a0 int, a []int) []int {
	r := []int{a0}
	for i := range a {
		r = append(r, r[i]*a[i])
	}
	return r
}
