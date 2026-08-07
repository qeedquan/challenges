/*

Trinomial ax+by+c of two variables x and y is uniquely determined by the constant term c and the coefficients a and b.
Write a program that, given a, b and c, displays the corresponding trinomial recorded using algebraic rules:

the coefficient of the term containing the variable is omitted if it is equal to one;

a term whose coefficient is equal to zero is omitted;

the "+" sign is omitted if it is followed by a negative coefficient;

the "+" sign is omitted if it is at the beginning (the so-called unary plus);

the multiplication sign between the coefficient and the variable is omitted.

At the same time, it is not allowed to swap terms.

Input
The input file contains three integers a, b and c (−9≤a,b,c≤9).

Output
Print a string containing the trinomial, written according to these rules.

Examples

Input #1
1 2 3

Answer #1
x+2y+3

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	fmt.Println(solve(1, 2, 3))
	fmt.Println(solve(0, 0, 0))
	fmt.Println(solve(-2, 3, -5))
}

func solve(a, b, c int) string {
	s := term(a, "x") + term(b, "y") + term(c, "z")
	s = strings.TrimPrefix(s, "+")
	if s == "" {
		return "0"
	}
	return s
}

func term(n int, p string) string {
	if n == 0 {
		return ""
	}
	if n == 1 {
		return fmt.Sprintf("%s", p)
	}
	return fmt.Sprintf("%+d%s", n, p)
}
