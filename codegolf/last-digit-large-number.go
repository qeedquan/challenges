/*

For a given list of number [x1,x2,x3,...,xn] find the last digit of x1^(x2^(x3^(...x^n)))

Example:

[3, 4, 2] == 1
[4, 3, 2] == 4
[4, 3, 1] == 4
[5, 3, 2] == 5
Because 3^(4^2)=3^16=43046721.

Because 4^(3^2)=4^9=262144.

Because 4^(3^1)=4^3=64.

Because 5^(3^2)=5^9=1953125.

Rules:

This is code golf, so the answer with the fewest bytes wins.

If your language has limits on integer size (ex. 2^32-1) n will be small enough that the sum will fit in the integer.

Input can be any reasonable form (stdin, file, command line parameter, integer, string, etc).

Output can be any reasonable form (stdout, file, graphical user element that displays the number, etc).

Saw on code wars.

*/

package main

import (
	"math/big"
)

func main() {
	assert(lastdigit([]int64{3, 4, 2}) == 1)
	assert(lastdigit([]int64{4, 3, 2}) == 4)
	assert(lastdigit([]int64{4, 3, 1}) == 4)
	assert(lastdigit([]int64{5, 3, 2}) == 5)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func lastdigit(a []int64) int64 {
	n := len(a)
	if n == 0 {
		return 0
	}

	x := big.NewInt(a[n-1])
	for i := n - 2; i >= 0; i-- {
		y := big.NewInt(a[i])
		x.Exp(y, x, nil)
	}

	s := x.String()
	return int64(s[len(s)-1] - '0')
}
