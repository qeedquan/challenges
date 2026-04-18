/*

Solve the equation:
p∗exp(-x) + q∗sin(x) + r∗cos(x) + s∗tan(x) + t∗x^2 + u = 0 where 0 ≤ x ≤ 1.

Input
Input consists of multiple test cases and terminated by an EOF. Each test case consists of 6 integers in
a single line: p, q, r, s, t and u (where 0 ≤ p, r ≤ 20 and −20 ≤ q, s, t ≤ 0). There will be maximum 2100 lines in the input file.

Output
For each set of input, there should be a line containing the value of x, correct up to 4 decimal places,
or the string ‘No solution’, whichever is applicable.

Sample Input
0 0 0 0 -2 1
1 0 0 0 -1 2
1 -1 1 -1 -1 1

Sample Output
0.7071
No solution
0.7554

*/

package main

import (
	"fmt"
	"math"
)

type fn func(float64) float64

func main() {
	fmt.Println(solve(0, 0, 0, 0, -2, 1))
	fmt.Println(solve(1, 0, 0, 0, -1, 2))
	fmt.Println(solve(1, -1, 1, -1, -1, 1))
}

func solve(p, q, r, s, t, u float64) (float64, bool) {
	f := mkfn(p, q, r, s, t, u)
	if f(0)*f(1) > 0 {
		return 0, false
	}
	x := bisect(f)
	return x, true
}

func bisect(f fn) float64 {
	const eps = 1e-7

	lo, hi := 0.0, 1.0
	for lo+eps < hi {
		x := lo + (hi-lo)/2
		if f(lo)*f(x) <= 0 {
			hi = x
		} else {
			lo = x
		}
	}
	return lo + (hi-lo)/2
}

func mkfn(p, q, r, s, t, u float64) fn {
	return func(x float64) float64 {
		return p*math.Exp(-x) + q*math.Sin(x) + r*math.Cos(x) + s*math.Tan(x) + t*x*x + u
	}
}
