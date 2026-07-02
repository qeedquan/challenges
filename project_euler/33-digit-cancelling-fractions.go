/*

The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting to simplify it may incorrectly believe that 49/98 = 4/8, which is correct, is obtained by cancelling the 9s.

We shall consider fractions like, 30/50 = 3/5, to be trivial examples.

There are exactly four non-trivial examples of this type of fraction, less than one in value, and containing two digits in the numerator and denominator.

If the product of these four fractions is given in its lowest common terms, find the value of the denominator.

*/

package main

import "fmt"

func main() {
	fmt.Println(solve())
}

/*

https://www.xarg.org/puzzle/project-euler/problem-33/

All solutions are of the form:
n < d < c
(10*n + c) / (10c + d) = n / d

Rearrange the equation to get:
(10*n + c)*d = (10*c + d)*n

*/

func solve() int {
	a, b := 1, 1
	for c := 1; c < 10; c++ {
		for d := 1; d < c; d++ {
			for n := 1; n < d; n++ {
				if (10*n+c)*d == (10*c+d)*n {
					a, b = a*n, b*d
				}
			}
		}
	}
	return b / gcd(a, b)
}

func gcd(a, b int) int {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}
