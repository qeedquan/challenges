/*

Number n is given in the decimal system. Convert it into base 13.

Input
One integer n (1≤n≤1000).

Output
Print number n in base 13.

Examples

Input #1
1

Answer #1
1

Input #2
10

Answer #2
A

*/

package main

import (
	"strconv"
	"strings"
)

func main() {
	assert(solve(1) == "1")
	assert(solve(10) == "A")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(n int64) string {
	return strings.ToUpper(strconv.FormatInt(n, 13))
}
