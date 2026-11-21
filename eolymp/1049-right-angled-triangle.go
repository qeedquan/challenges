/*

A triangle is one of the basic geometric shapes: a polygon with three vertices, not lying on a straight line, and three sides, which are its line segments.
A triangle with vertices A, B, and C is denoted as △ABC.

Triangles can be classified by their internal angles as follows:

A right-angled triangle has one angle of 90∘.
The side opposite the right angle is called the hypotenuse and is the longest side.
The other two sides are called the legs. For right-angled triangles, the Pythagorean theorem holds:
the sum of the squares of the legs equals the square of the hypotenuse, i.e. a^2 + b^2 = c^2, where a and b are the legs and c is the hypotenuse.

An oblique triangle is a triangle with no interior angle of 90∘.

An obtuse triangle is an oblique triangle with one angle greater than 90∘ (this is called an obtuse angle).

An acute triangle is an oblique triangle with all interior angles less than 90∘ (three acute angles).
An equilateral triangle is an example of an acute triangle, but not all acute triangles are equilateral.

https://static.e-olymp.com/content/dc/dc55f49d80932740439ea9931ed04db1fc2f1d73.jpg

Your task is very simple. For a given natural number L, count how many different right-angled triangles satisfy a+b+c≤L,
where a and b are the legs and c is the hypotenuse. Note that a, b, and c must all be integers.

Input
Multiple test cases. Each test consists of a single integer L (12≤L≤2×10^6).

Output
For each test, output on a separate line the number of different right-angled triangles for which a+b+c≤L.

Examples

Input #1
12
40

Answer #1
1
5

Note
There are 5 different right-angled triangles with a+b+c≤40. Their side lengths are:

a=3, b=4, c=5
a=6, b=8, c=10
a=5, b=12, c=13
a=9, b=12, c=15
a=8, b=15, c=17

*/

package main

import (
	"math"
)

func main() {
	assert(solve(12) == 1)
	assert(solve(40) == 5)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(L int) int {
	if L < 1 {
		return 0
	}

	r := 0
	x := int(math.Sqrt(float64(L) / 2))
	for n := 1; n <= x; n++ {
		for m := 1; m < n; m++ {
			if gcd(n, m) == 1 && (n-m)%2 == 1 {
				p := 2 * n * (n + m)
				r += L / p
			}
		}
	}
	return r
}

func gcd(a, b int) int {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}
