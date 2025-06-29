/*

Your function will receive two positive integers ( integers ranging from 1 upward), and return an array. There's logic in there, but all you get are the example test cases to find it.
Below overview for your convenience. (And, alright: the function name is a strong hint of what to do.)

(s, d) => array

(1, 1) => [1]
(2, 1) => [2]
(3, 1) => [2, 1]
(4, 1) => [2, 2]
(5, 1) => [2, 2, 1]

(1, 2) => [1]
(2, 2) => [4]
(3, 2) => [8, 1]
(4, 2) => [12, 4]
(5, 2) => [16, 8, 1]

(1, 3) => [1]
(2, 3) => [8]
(3, 3) => [26, 1]
(4, 3) => [56, 8]
(5, 3) => [98, 26, 1]

(1, 4) => [1]
(2, 4) => [16]
(3, 4) => [80, 1]
(4, 4) => [240, 16]
(5, 4) => [544, 80, 1]

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test(1, 1, []int{1})
	test(2, 1, []int{2})
	test(3, 1, []int{2, 1})
	test(4, 1, []int{2, 2})
	test(5, 1, []int{2, 2, 1})
	test(6, 1, []int{2, 2, 2})

	test(1, 2, []int{1})
	test(2, 2, []int{4})
	test(3, 2, []int{8, 1})
	test(4, 2, []int{12, 4})
	test(5, 2, []int{16, 8, 1})

	test(1, 3, []int{1})
	test(2, 3, []int{8})
	test(3, 3, []int{26, 1})
	test(4, 3, []int{56, 8})
	test(5, 3, []int{98, 26, 1})

	test(1, 4, []int{1})
	test(2, 4, []int{16})
	test(3, 4, []int{80, 1})
	test(4, 4, []int{240, 16})
	test(5, 4, []int{544, 80, 1})

	test(1, 4, []int{1})
	test(2, 4, []int{16})
	test(3, 4, []int{80, 1})
	test(4, 4, []int{240, 16})
	test(5, 4, []int{544, 80, 1})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(s, d int, r []int) {
	p := peel(s, d)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func peel(s, d int) []int {
	r := make([]int, (s+1)/2)
	for i := range r {
		n1 := ipow(s-2*i, d)
		n2 := ipow(max(s-2*(i+1), 0), d)
		r[i] = n1 - n2
	}
	return r
}

func ipow(x, p int) int {
	r := 1
	for i := 0; i < p; i++ {
		r *= x
	}
	return r
}
