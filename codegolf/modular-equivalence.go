/*

Given two numbers x,y>2,x≠y output all integers m such that
x+y ≡ x*y (mod m)
x*y > m > 2

Two integers

Output
A list of integers

Test cases
3, 4 -> 5
5, 8 -> 3, 9, 27
29, 9 -> 223
26, 4 -> 37, 74
13, 11 -> 7, 17, 119
6258, 571 -> 463, 7703, 3566489

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test(3, 4, []int{5})
	test(5, 8, []int{3, 9, 27})
	test(29, 9, []int{223})
	test(26, 4, []int{37, 74})
	test(13, 11, []int{7, 17, 119})
	test(6258, 571, []int{463, 7703, 3566489})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(x, y int, r []int) {
	p := modequiv(x, y)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func modequiv(x, y int) []int {
	r := []int{}
	for m := 3; m <= x*y; m++ {
		if (x+y)%m == (x*y)%m {
			r = append(r, m)
		}
	}
	return r
}
