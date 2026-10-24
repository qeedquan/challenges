/*

Tim is quite a bookworm. Each Saturday he goes to the local library and spends the whole day reading old books.
He is mostly interested in ancient history, but from time to time he also reads scientific books.
Last weekend he found a series of books called "The Elements" written by some old Greek called Euclid.
Tim had never heard of him. All 12 books were filled with definitions, propositions and proofs concerning elementary geometry.

Tim read all books very carefully, but one handwritten note just stuck in his mind. Someone wrote just after Book 4, Proposition 4:

Using Heron's formula, one can easily derive that the following formula holds for a triangle with incircle radius r, area A, and lengths a,b,c of the three sides.

A = r * (a+b+c)/2

Since Tim is not a very trusting person, he doesn't believe that this formula is correct.
However, Tim remembers from school that Heron's formula states a relationship between the area of a triangle and the lengths of its three sides.
And of course he trusts this formula. After all, we can trust teachers, right?

A = 1/4 * sqrt(4*a^2*b^2 - (a^2 + b^2 - c^2)^2)

To check the formula he found in the book, he has constructed a lot of triangles on paper, inscribed their incircles and measured their radius.
Now he wants to check the formula against his measurements, but he is already quite tired from constructing all those triangles on paper.
He asks you to write a program that, given the coordinates of the triangle's vertices,
computes the incircle radius according to the formula he found in the book and outputs the difference to the value he measured in percent.

Input
The i (1≤i≤3)-th of the first three lines contains two integers xi and yi (-10^3≤xi,yi≤10^3), where (xi,yi) are the coordinates of the i-th triangle's vertex;

Next line contains one real number r (0.1≤r≤10^6) — the incircle radius that Tim measured when he constructed the triangle on paper.

The three points will never be collinear. The triangle's area will always be greater or equal to 0.1.

Output
Output the difference between the measured incircle radius and the radius computed according to the formula as a percentage value,
where the measured radius corresponds to 100%.
The output is positive if the computed radius is larger than the measured one, 0 if they are equal, or negative otherwise.
The answer should be output with three decimal places.

Examples

Input #1
0 0
10 0
0 10
5.0

Answer #1
-41.421

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Printf("%.3f\n", solve(0, 0, 10, 0, 0, 10, 5))
}

func solve(x1, y1, x2, y2, x3, y3, r float64) float64 {
	a := dist(x1, y1, x2, y2)
	b := dist(x1, y1, x3, y3)
	c := dist(x2, y2, x3, y3)
	A := 0.25 * math.Sqrt(4*a*a*b*b-sqr(a*a+b*b-c*c))
	R := A * 2 / (a + b + c)
	return (R/r - 1) * 100
}

func dist(x1, y1, x2, y2 float64) float64 {
	return math.Hypot(x1-y1, x2-y2)
}

func sqr(x float64) float64 {
	return x * x
}
