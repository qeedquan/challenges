/*


Given natural numbers P (0<P<10000) and N (0<N<1000), compute the square root of P with exactly N decimal digits of precision.

Input
The first line contains the number of test cases M.
Each test case consists of two subsequent lines: the first line contains the number P, and the second line contains the number N.

All input data are guaranteed to be correct.

Output
For each test case, output the result on a separate line. Each result must be a decimal fraction with exactly N digits after the decimal point.

Examples

Input #1
3
2
5
10
10
100
30

Answer #1
1.41421
3.1622776601
10.000000000000000000000000000000

*/

package main

import (
	"math/big"
	"strings"
)

func main() {
	assert(solve(2, 5) == "1.41421")
	assert(solve(10, 10) == "3.1622776601")
	assert(solve(100, 30) == "10.000000000000000000000000000000")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(p int64, n int) string {
	z := new(big.Float)
	z.SetInt64(p)
	z.Sqrt(z)

	s := z.Text('f', n*10)
	i := strings.IndexRune(s, '.')
	if i >= 0 {
		i = min(i+n+1, len(s))
		s = s[:i]
	}
	return s
}
