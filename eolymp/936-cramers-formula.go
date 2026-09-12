/*

Solve the system of two linear equations with two variables using Cramer's rule.

The system of equations in the example has the form:

a1*x + b1*y = c1
a2*x + b2*y = c2

It is known that the system always has a unique solution.

Input
The first line contains the coefficients of the first equation, and the second line contains the coefficients of the second equation.
All numbers are separated by a space and do not exceed 100 in absolute value.

Output
Print the first root on the first line and the second root on the second line, with an accuracy of 0.001.

Examples

Input #1
5 8 11
-3 6 15

Answer #1
-1.000
2.000

*/

package main

import "fmt"

func main() {
	fmt.Println(solve(5, 8, 11, -3, 6, 15))
}

func solve(a1, b1, c1, a2, b2, c2 float64) (float64, float64) {
	D := a1*b2 - b1*a2
	X := c1*b2 - b1*c2
	Y := a1*c2 - a2*c1
	return X / D, Y / D
}
