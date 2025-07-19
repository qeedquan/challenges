/*

In this Kata, you will be given an array of unique elements, and your task is to rearrange the values so that the first max value is followed by the first minimum, followed by second max value then second min value, etc.

For example:

solve([15,11,10,7,12]) = [15,7,12,10,11]
The first max is 15 and the first min is 7. The second max is 12 and the second min is 10 and so on.

More examples in the test cases.

Good luck!

*/

package main

import (
	"fmt"
	"reflect"
	"sort"
)

func main() {
	test([]int{15, 11, 10, 7, 12}, []int{15, 7, 12, 10, 11})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a, r []int) {
	p := solve(a)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func solve(a []int) []int {
	r := make([]int, len(a))
	s := append([]int{}, a...)

	sort.Ints(s)
	for i, j, k := 0, 0, len(a)-1; i < len(a); i++ {
		switch i & 1 {
		case 1:
			r[i], j = s[j], j+1
		case 0:
			r[i], k = s[k], k-1
		}
	}
	return r
}
