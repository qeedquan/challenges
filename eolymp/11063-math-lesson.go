/*

Today Krosh learned about the geometric mean of numbers.
The geometric mean of two positive numbers x and y is sqrt(x*y).
Denote the geometric mean of the numbers x and y as g(x,y).

Krosh had three positive real numbers a, b and c.
He used them to practice calculating geometric averages.
He calculated and wrote down the numbers g(a,b), g(a,c) and g(b,c).

Some time later, Krosh saw the recorded values of the geometric mean.
And now he wants to remember what numbers a, b and c he had.
Help him find any suitable positive numbers a, b and c.

Input
The first line contains the value of the geometric mean of numbers a and b, in other words - g(a,b).
The second line contains the number g(a,c).
The third line contains the number g(b,c).

All three numbers are real, positive, do not exceed 10^9 and contain no more than 6 digits after the decimal point.

Output
Print any suitable positive numbers a, b and c.
The jury will calculate the geometric mean of your numbers.
The answer will be considered correct if the absolute or relative error of each of the averages does not exceed 10^-6.

It can be proved that for any input that satisfies the constraints, a solution exists.

Examples

Input #1
12
20
15

Answer #1
16.000000000000000
9.000000000000000
25.000000000000000

Input #2
1.234567
2.345678
3.456789

Answer #2
0.837741803571465
1.819362088642601
6.567901060000794

Input #3
0.000001
0.000001
0.000001

Answer #3
0.000001000000000
0.000001000000000
0.000001000000000

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	test(12, 20, 15)
	test(1.234567, 2.345678, 3.456789)
	test(0.000001, 0.000001, 0.000001)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(gab, gac, gbc float64) {
	const eps = 1e-12
	a, b, c := solve(gab, gac, gbc)
	fmt.Println(a, b, c)
	assert(gab-math.Sqrt(a*b) < eps)
	assert(gac-math.Sqrt(a*c) < eps)
	assert(gbc-math.Sqrt(b*c) < eps)
}

/*

Define the following variables X, Y, Z as:

g(a, b) = sqrt(a*b) = X
g(a, c) = sqrt(a*c) = Y
g(b, c) = sqrt(b*c) = Z

Square both sides to get rid of square root
a*b = X^2
a*c = Y^2
b*c = Z^2

Multiply all of the terms together to get:

a*a * b*b * c*c = X^2 * Y^2 * Z^2

Square root both sides to get abc

a*b*c = XYZ

Now we can solve for a, b, c separately
a = XYZ/Z^2
b = XYZ/Y^2
c = XYZ/X^2

*/

func solve(gab, gac, gbc float64) (a, b, c float64) {
	X := gab
	Y := gac
	Z := gbc
	a = (X * Y * Z) / (Z * Z)
	b = (X * Y * Z) / (Y * Y)
	c = (X * Y * Z) / (X * X)
	return
}
