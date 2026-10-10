/*

The anti-divisors are numbers that do not divide a given number by the largest possible margin, and they can be found following a simple set of rules:

Every number greater than 1 and lower than n is checked.
Every checked number must not be a divisor of n.
If the checked number is odd and it is a divisor of n * 2 - 1 or n * 2 + 1 it's an anti-divisor.
If the checked number is even and it is a divisor of n * 2, it's an anti-divisor.
Given an integer n, implement a function that returns an array containing the anti-divisors of n sorted in ascending order.

Examples
antiDivisors(10) ➞ [3, 4, 7]
// 3 is a divisor of 21 (10 * 2 + 1)
// 4 is a divisor of 20 (10 * 2)
// 7 is a divisor of 21

antiDivisors(12) ➞ [5, 8]
// 5 is a divisor of 25 (12 * 2 + 1)
// 8 is a divisor of 24 (12 * 2)

antiDivisors(20) ➞ [3, 8, 13]
// 3 is a divisor of 39 (20 * 2 - 1)
// 8 is a divisor of 40 (20 * 2)
// 13 is a divisor of 39

Notes
The given n can be any integer, either positive, negative or 0.

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test(10, []int{3, 4, 7})
	test(12, []int{5, 8})
	test(20, []int{3, 8, 13})
	test(1, []int{})
	test(31, []int{2, 3, 7, 9, 21})
	test(55, []int{2, 3, 10, 22, 37})
	test(0, []int{})
	test(105, []int{2, 6, 10, 11, 14, 19, 30, 42, 70})
	test(666, []int{4, 11, 12, 31, 36, 43, 121, 148, 444})
	test(9999, []int{2, 6, 7, 18, 22, 66, 198, 202, 606, 1818, 2222, 2857, 6666})
	test(-33, []int{})
	test(0, []int{})
	test(100, []int{3, 8, 40, 67})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(n int, r []int) {
	p := antidivisors(n)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

// https://oeis.org/A066272/a066272a.html
func antidivisors(n int) []int {
	r := []int{}
	for i := 2; i < n; i++ {
		if n%i == 0 {
			continue
		}

		p := i & 1
		if (n*2-p)%i == 0 || (n*2+p)%i == 0 {
			r = append(r, i)
		}
	}
	return r
}
