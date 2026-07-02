/*

Create a function that returns an array containing the first l numbers from the nth diagonal of Pascal's triangle.

n = 0 should generate the first diagonal of the triangle (the ones).
The first number in each diagonal should be 1.
If l = 0, return an empty array.
Both n and l will be non-negative integers in all test cases.

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test(0, 5, []int{1, 1, 1, 1, 1})
	test(1, 5, []int{1, 2, 3, 4, 5})
	test(2, 5, []int{1, 3, 6, 10, 15})
	test(3, 5, []int{1, 4, 10, 20, 35})
	test(0, 10, []int{1, 1, 1, 1, 1, 1, 1, 1, 1, 1})
	test(1, 10, []int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10})
	test(2, 10, []int{1, 3, 6, 10, 15, 21, 28, 36, 45, 55})
	test(3, 10, []int{1, 4, 10, 20, 35, 56, 84, 120, 165, 220})
	test(4, 10, []int{1, 5, 15, 35, 70, 126, 210, 330, 495, 715})
	test(3, 7, []int{1, 4, 10, 20, 35, 56, 84})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(n, l int, r []int) {
	p := diagonal(n, l)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func diagonal(n, l int) []int {
	if n < 0 || l < 0 {
		return []int{}
	}

	r := make([]int, l)
	for i := range l {
		r[i] = binomial(n+i, i)
	}
	return r
}

func binomial(n, k int) int {
	if k < 0 || k > n {
		return 0
	}
	if k == 0 || k == n {
		return 1
	}

	k = min(k, n-k)
	c := 1
	for i := 0; i < k; i++ {
		c = c * (n - i) / (i + 1)
	}
	return c
}
