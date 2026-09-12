/*

Fermat's Last Theorem, mod n
It is a well known fact that for all integers p>2, there exist no integers x,y,z>0 such that x^p+y^p=z^p.
However, this statement is not true in general if we consider the integers modulo n.

You will be given n and p, which are two positive integers with n>1.
Your task will be to write a function or program to compute all positive integers x,y,z<n such that (xp+yp) and zp give the same remainder when divided by n.

Input
Any reasonable method of input is allowed. E.g. two separate user inputs, ordered pair, two function parameters, etc.

Output
Any reasonable method of output is valid, it may be produced by a function or output to the screen.
The order the triples are listed does not matter.
Triples such as (1, 2, 3) and (2, 1, 3) are considered distinct, and all distinct triples should be listed exactly once.
No invalid/trivial triples such as (0, 0, 0) should be output.

The numbers x,y,z may have any ordering within each of the triples, but that order should be consistent. For example if 2^p+2^p and 3^p have the same remainder when divided by n, you may list this triple as (2, 2, 3) or (3, 2, 2).

Examples
n p -> Possible Output
----------------------------------------------------------------
2 3 -> []
3 3 -> [(1,1,2),(2,2,1)]
3 4 -> []
4 3 -> [(1,2,1),(1,3,2),(2,1,1),(2,2,2),(2,3,3),(3,1,2),(3,2,3)]

Scoring
Shortest code in bytes with no standard loopholes wins.

*/

package main

import (
	"fmt"
	"math"
	"reflect"
)

func main() {
	test(2, 3, [][3]int{})
	test(3, 3, [][3]int{{1, 1, 2}, {2, 2, 1}})
	test(3, 4, [][3]int{})
	test(4, 3, [][3]int{{1, 2, 1}, {1, 3, 2}, {2, 1, 1}, {2, 2, 2}, {2, 3, 3}, {3, 1, 2}, {3, 2, 3}})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(n, p int, r [][3]int) {
	v := fltm(n, p)
	fmt.Println(v)
	assert(reflect.DeepEqual(v, r))
}

func fltm(n, p int) [][3]int {
	r := [][3]int{}
	for x := 1; x < n; x++ {
		for y := 1; y < n; y++ {
			for z := 1; z < n; z++ {
				if (ipow(x, p)+ipow(y, p))%n == ipow(z, p)%n {
					r = append(r, [3]int{x, y, z})
				}
			}
		}
	}
	return r
}

func ipow(x, p int) int {
	return int(math.Pow(float64(x), float64(p)))
}
