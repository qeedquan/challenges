/*

You're given two numbers a and b in base 31 numeral system and number k with no more than 10000 decimal digits. It is known that b is divisor of a. The task is to find last k 31-based-digits of quotient a/b.

The solution with fastest proved asymptotics in length of max(a,b) wins. I'll put a bound of 10^5 on length of a and b.

Test example:

INPUT: a = IBCJ, b = OG, k = 5

OUTPUT: 000N7

*/

package main

import (
	"math/big"
	"strings"
)

func main() {
	assert(quo31("IBCJ", "OG", 5) == "000N7")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func quo31(s, t string, k int) string {
	const base = 31

	x := new(big.Int)
	y := new(big.Int)

	x.SetString(s, base)
	y.SetString(t, base)
	x.Quo(x, y)

	r := x.Text(base)
	return strings.Repeat("0", max(0, k-len(r))) + strings.ToUpper(r)
}
