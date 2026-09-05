/*

Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order.

You must write an algorithm that runs in O(n) time and uses O(1) extra space.

Example 1:

Input: n = 13
Output: [1,10,11,12,13,2,3,4,5,6,7,8,9]
Example 2:

Input: n = 2
Output: [1,2]


Constraints:

1 <= n <= 5 * 10^4

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test(13, []int{1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9})
	test(2, []int{1, 2})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(n int, r []int) {
	p := gen(n)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func gen(n int) []int {
	r := []int{}
	for c := 1; len(r) < n; {
		r = append(r, c)

		if 10*c <= n {
			c *= 10
			continue
		}

		for c%10 == 9 || c == n {
			c /= 10
		}
		c++
	}
	return r
}
