/*

In mathematics, a Diophantine equation is a polynomial equation, usually with two or more unknowns, such that only the integer solutions are sought or studied.

In this kata we want to find all integers x, y (x >= 0, y >= 0) solutions of a diophantine equation of the form:

x^2 - 4 * y^2 = n
(where the unknowns are x and y, and n is a given positive number) in decreasing order of the positive xi.

If there is no solution return [] or "[]" or "". (See "RUN SAMPLE TESTS" for examples of returns).

Examples:
solEquaStr(90005) --> "[[45003, 22501], [9003, 4499], [981, 467], [309, 37]]"
solEquaStr(90002) --> "[]"

Hint:
x^2 - 4 * y^2 = (x - 2*y) * (x + 2*y)

*/

package main

import (
	"fmt"
	"math"
	"reflect"
)

func main() {
	test(17, [][2]int{{9, 4}})
	test(12, [][2]int{{4, 1}})
	test(13, [][2]int{{7, 3}})
	test(16, [][2]int{{4, 0}})
	test(90005, [][2]int{{45003, 22501}, {9003, 4499}, {981, 467}, {309, 37}})
	test(90002, [][2]int{})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(n int, r [][2]int) {
	p := solve(n)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

/*

https://mathworld.wolfram.com/DiophantineEquation2ndPowers.html

x - 2y = i
x + 2y = j

*/

func solve(n int) [][2]int {
	r := [][2]int{}
	l := isqrt(n) + 1
	for i := 1; i <= l; i++ {
		if n%i != 0 {
			continue
		}

		j := n / i
		y := (j - i) / 4
		x := i + 2*y
		if x >= 0 && y >= 0 && j == x+2*y && i == x-2*y {
			r = append(r, [2]int{x, y})
		}
	}
	return r
}

func isqrt(n int) int {
	return int(math.Sqrt(float64(n)))
}
