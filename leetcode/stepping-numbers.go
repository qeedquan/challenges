/*

A Stepping Number is an integer such that all of its adjacent digits have an absolute difference of exactly 1. For example, 321 is a Stepping Number while 421 is not.

Given two integers low and high, find and return a sorted list of all the Stepping Numbers in the range [low, high] inclusive.

Example 1:

Input: low = 0, high = 21
Output: [0,1,2,3,4,5,6,7,8,9,10,12,21]


Constraints:

0 <= low <= high <= 2 * 10^9

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test(0, 21, []int{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 21})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(lo, hi int, r []int) {
	p := steppings(lo, hi)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

// https://oeis.org/A033075
func steppings(lo, hi int) []int {
	q := []int{1, 2, 3, 4, 5, 6, 7, 8, 9}
	r := []int{}
	if lo == 0 {
		r = append(r, 0)
	}

	var v int
	for len(q) > 0 {
		v, q = q[0], q[1:]
		if v > hi {
			continue
		}
		if v >= lo {
			r = append(r, v)
		}

		d := v % 10
		if d > 0 {
			q = append(q, v*10+d-1)
		}
		if d < 9 {
			q = append(q, v*10+d+1)
		}
	}
	return r
}
