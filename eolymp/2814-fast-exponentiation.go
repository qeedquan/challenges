/*

Very often arises the problem of efficient calculation of x^n for given x and n, where n is a positive integer.

For example, suppose it is necessary to calculate x^16. You can simply start with x and multiply it by x 15 times.
However, the same result can be obtained with just four multiplications by repeatedly squaring the result, consecutively calculating
x^2, x^4, x^8, x^16.

The same idea can generally be applied to any value of n as follows.
Write n in binary form (removing leading zeros).
Then, replace each 1 with the pair of characters SX, each 0 with the character S, and remove the leftmost pair SX.
The result is a rule for calculating x^n, where S denotes squaring, and X denotes multiplying by x.
For example, n=23 has binary representation 10111.
Thus, we form the sequence SXSSXSXSX.
Removing the initial pair SX gives the final rule SSXSXSX.
This means: "square, square, multiply by x, square, multiply by x, square, and multiply by x"; that is, consecutively calculate
x^2, x^4, x^5, x^10, x^11, x^22, x^23.

You need to construct the rule for fast exponentiation of x to the power n for a given n.

Input
One positive integer n, not greater than 2⋅10^9.

Output
Print the string representing the rule for raising x to the power n to calculate x^n.

Examples
Input #1
23

Answer #1
SSXSXSX

*/

package main

import (
	"bytes"
	"fmt"
)

func main() {
	assert(solve(23) == "SSXSXSX")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(n uint) string {
	s := []uint{}
	for {
		s = append(s, n&1)
		if n >>= 1; n == 0 {
			break
		}
	}

	w := new(bytes.Buffer)
	for i := len(s) - 2; i >= 0; i-- {
		fmt.Fprintf(w, "S")
		if s[i] != 0 {
			fmt.Fprintf(w, "X")
		}
	}
	return w.String()
}
