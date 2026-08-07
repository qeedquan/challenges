/*

You are given an array A of n strictly positive integers, with n ≥ 2.

Your task is to map each entry Ai to:

1 if Aj mod Ai is odd for each j such that 1 ≤ j ≤ n and j ≠ i
2 if Aj mod Ai is even for each j such that 1 ≤ j ≤ n and j ≠ i
0 otherwise (mixed parities)

Example
For A = [ 73, 50, 61 ], we have:

50 mod 73 = 50, 61 mod 73 = 61 → mixed
73 mod 50 = 23, 61 mod 50 = 11 → all odd
73 mod 61 = 12, 50 mod 61 = 50 → all even
Therefore, the expected output is [ 0, 1, 2 ].

Rules
You may use any three distinct values (of any type) instead of 0, 1 and 2 as long as they're consistent. Please specify your mapping if you're not using the one described in the challenge.
Should there be any doubt about that, zero is even.
This is code-golf, so the shortest answer in bytes wins!

Test cases
[ 1, 2 ] --> [ 2, 1 ]
[ 3, 4 ] --> [ 1, 1 ]
[ 1, 2, 3 ] --> [ 2, 1, 0 ]
[ 4, 4, 4 ] --> [ 2, 2, 2 ]
[ 73, 50, 61 ] --> [ 0, 1, 2 ]
[ 941, 459, 533 ] --> [ 1, 0, 0 ]
[ 817, 19, 928, 177 ] --> [ 1, 2, 1, 1 ]
[ 312, 463, 336, 729, 513 ] --> [ 0, 2, 0, 0, 0 ]
[ 53, 47, 33, 87, 81, 3, 17 ] --> [ 0, 0, 0, 1, 0, 2, 0 ]

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test([]int{1, 2}, []int{2, 1})
	test([]int{3, 4}, []int{1, 1})
	test([]int{1, 2, 3}, []int{2, 1, 0})
	test([]int{4, 4, 4}, []int{2, 2, 2})
	test([]int{73, 50, 61}, []int{0, 1, 2})
	test([]int{941, 459, 533}, []int{1, 0, 0})
	test([]int{817, 19, 928, 177}, []int{1, 2, 1, 1})
	test([]int{312, 463, 336, 729, 513}, []int{0, 2, 0, 0, 0})
	test([]int{53, 47, 33, 87, 81, 3, 17}, []int{0, 0, 0, 1, 0, 2, 0})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a, r []int) {
	p := modparity(a)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func modparity(a []int) []int {
	r := []int{}
	for _, x := range a {
		v := 1
		for _, y := range a {
			if x != 0 {
				v += y % x % 2
			}
		}

		c := 0
		if v < len(a) {
			c++
		}
		if v < 2 {
			c++
		}
		if c < 2 {
			c ^= 1
		}

		r = append(r, c)
	}
	return r
}
