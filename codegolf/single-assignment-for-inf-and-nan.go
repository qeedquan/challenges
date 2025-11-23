/*

Using one single statement, numerically assign the IEEE 754 :

+INF to variable a

— inf also acceptable

-INF to variable b

+NaN to variable c

— a sign-less nan being displayed is acceptable as long as the code demonstrates how it arrives at a positive nan

-NaN to variable d

— a sign-less nan being displayed is acceptable as long as the code demonstrates how it arrives at a negative nan

The assignment must be without using string concat

The assignment must be interconnected, ie. — the assignment of any 3 out of 4 must be via any combo of each other's value(s) instead of performing 4 independent assigns into a 4-way tuple

casing is irrelevant.

Single v. double v. quadruple floating point precision is also irrelevant.

Full spellings of infinity | not-a-number, or their hex representations (e.g. FFF0000000000000 for -INF), are also acceptable

Shortest code wins. — reference solution exists

Good Luck Everyone

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	a, b, c, d := math.Inf(1), math.Inf(-1), math.NaN(), -math.NaN()
	fmt.Println(a, b, c, d)
}
