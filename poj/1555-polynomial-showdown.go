/*

Description

Given the coefficients of a polynomial from degree 8 down to 0, you are to format the polynomial in a readable format with unnecessary characters removed. For instance, given the coefficients 0, 0, 0, 1, 22, -333, 0, 1, and -1, you should generate an output line which displays x^5 + 22x^4 - 333x^3 + x - 1.
The formatting rules which must be adhered to are as follows:

1. Terms must appear in decreasing order of degree.

2. Exponents should appear after a caret `"^".

3. The constant term appears as only the constant.

4. Only terms with nonzero coefficients should appear, unless all terms have zero coefficients in which case the constant term should appear.

5. The only spaces should be a single space on either side of the binary + and - operators.

6. If the leading term is positive then no sign should precede it; a negative leading term should be preceded by a minus sign, as in -7x^2 + 30x + 66.

7. Negated terms should appear as a subtracted unnegated term (with the exception of a negative leading term which should appear as described above). That is, rather than x^2 + -3x, the output should be x^2 - 3x.

8. The constants 1 and -1 should appear only as the constant term. That is, rather than -1x^3 + 1x^2 + 3x^1 - 1, the output should appear as-x^3 + x^2 + 3x - 1.

Input

The input will contain one or more lines of coefficients delimited by one or more spaces. There are nine coefficients per line, each coefficient being an integer with a magnitude of less than 1000.

Output

The output should contain the formatted polynomials, one per line.

Sample Input

0 0 0 1 22 -333 0 1 -1
0 0 0 0 0 0 -55 5 0

Sample Output

x^5 + 22x^4 - 333x^3 + x - 1
-55x^2 + 5x

Source

Mid-Central USA 1996

*/

package main

import (
	"bytes"
	"fmt"
)

func main() {
	assert(polynomial([]int{0, 0, 0, 1, 22, -333, 0, 1, -1}) == "x^5 + 22x^4 - 333x^3 + x - 1")
	assert(polynomial([]int{0, 0, 0, 0, 0, 0, -55, 5, 0}) == "-55x^2 + 5x")
	assert(polynomial([]int{-3}) == "-3")
	assert(polynomial([]int{-6, -3}) == "-6x - 3")
	assert(polynomial([]int{-6, 0, 203}) == "-6x^2 + 203")
	assert(polynomial([]int{0, 0, 0}) == "0")
	assert(polynomial([]int{0}) == "0")
	assert(polynomial([]int{0, 4}) == "4")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func polynomial(a []int) string {
	p := sparse(a)
	n := len(p)
	if n == 0 {
		return "0"
	}

	w := new(bytes.Buffer)
	for i := 0; i < n; i++ {
		t := p[i][0]
		x := p[i][1]
		if i == 0 && x < 0 {
			fmt.Fprint(w, "-")
		}

		u := abs(x)
		if t == 0 || u != 1 {
			fmt.Fprint(w, u)
		}

		if t > 1 {
			fmt.Fprintf(w, "x^%d", t)
		} else if t == 1 {
			fmt.Fprintf(w, "x")
		}

		if i+1 < n {
			if p[i+1][1] < 0 {
				fmt.Fprintf(w, " - ")
			} else {
				fmt.Fprintf(w, " + ")
			}
		}
	}
	return w.String()
}

func sparse(a []int) [][2]int {
	p := [][2]int{}
	n := len(a)
	for i, c := range a {
		if c != 0 {
			p = append(p, [2]int{n - i - 1, c})
		}
	}
	return p
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}
