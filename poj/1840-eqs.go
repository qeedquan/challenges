/*

Description

Consider equations having the following form:
a1*x1^3+ a2*x2^3+ a3*x3^3+ a4*x4^3+ a5*x5^3=0
The coefficients are given integers from the interval [-50,50].
It is consider a solution a system (x1, x2, x3, x4, x5) that verifies the equation, xi∈[-50,50], xi != 0, any i∈{1,2,3,4,5}.

Determine how many solutions satisfy the given equation.
Input

The only line of input contains the 5 coefficients a1, a2, a3, a4, a5, separated by blanks.
Output

The output will contain on the first line the number of the solutions for the given equation.

Sample Input

37 29 41 43 47

Sample Output

654

Source

Romania OI 2002

*/

package main

func main() {
	assert(solve(50, 37, 29, 41, 43, 47) == 654)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(n, a, b, c, d, e int) int {
	m := make(map[int]int)
	for x1 := -n; x1 <= n; x1++ {
		for x2 := -n; x2 <= n; x2++ {
			if !(x1 == 0 || x2 == 0) {
				v := a*x1*x1*x1 + b*x2*x2*x2
				m[v]++
			}
		}
	}

	r := 0
	for x3 := -n; x3 <= n; x3++ {
		for x4 := -n; x4 <= n; x4++ {
			for x5 := -n; x5 <= n; x5++ {
				if !(x3 == 0 || x4 == 0 || x5 == 0) {
					v := c*x3*x3*x3 + d*x4*x4*x4 + e*x5*x5*x5
					r += m[-v]
				}
			}
		}
	}
	return r
}
