/*

Description

For hundreds of years Fermat's Last Theorem, which stated simply that for n > 2 there exist no integers a, b, c > 1 such that a^n = b^n + c^n, has remained elusively unproven. (A recent proof is believed to be correct, though it is still undergoing scrutiny.) It is possible, however, to find integers greater than 1 that satisfy the "perfect cube" equation a^3 = b^3 + c^3 + d^3 (e.g. a quick calculation will show that the equation 12^3 = 6^3 + 8^3 + 10^3 is indeed true). This problem requires that you write a program to find all sets of numbers {a,b,c,d} which satisfy this equation for a <= N.

Input

One integer N (N <= 100).

Output

The output should be listed as shown below, one perfect cube per line, in non-decreasing order of a (i.e. the lines should be sorted by their a values). The values of b, c, and d should also be listed in non-decreasing order on the line itself. There do exist several values of a which can be produced from multiple distinct sets of b, c, and d triples. In these cases, the triples with the smaller b values should be listed first.

Sample Input

24

Sample Output

Cube = 6, Triple = (3,4,5)
Cube = 12, Triple = (6,8,10)
Cube = 18, Triple = (2,12,16)
Cube = 18, Triple = (9,12,15)
Cube = 19, Triple = (3,10,18)
Cube = 20, Triple = (7,14,17)
Cube = 24, Triple = (12,16,20)

Source

Mid-Central USA 1995

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(find(24))
}

func find(n int) [][4]int {
	var r [][4]int
	for a := 6; a <= n; a++ {
		for b := 2; b < math.MaxInt; b++ {
			if cubes(a) <= cubes(b) {
				break
			}
			for c := b + 1; c < math.MaxInt; c++ {
				if cubes(a) <= cubes(b, c) {
					break
				}
				for d := c + 1; d < math.MaxInt; d++ {
					if cubes(a) < cubes(b, c, d) {
						break
					}
					if cubes(a) == cubes(b, c, d) {
						r = append(r, [4]int{a, b, c, d})
					}
				}
			}
		}
	}
	return r
}

func cubes(x ...int) int {
	r := 0
	for _, v := range x {
		r += v * v * v
	}
	return r
}
