/*

A husband and wife went to the store to buy a new TV.

"Let's get this one, the white one," the wife suggested. "No!" the husband replied. "It's smaller than the one we have at home! We agreed to buy a bigger TV!" "How can that be?" the wife was puzzled. "I distinctly remember our TV is 32 inches, and this one is 36."

"That's correct," the husband said, "but our TV has a different aspect ratio, so its screen area is still larger. It seems we need a special app to help with this."

Input
The first line contains three positive integers describing the first TV. The first number is the diagonal length in inches. Following this number is a space, then the second and third numbers, which are the numerator and denominator of the fraction representing the horizontal to vertical ratio, separated by a colon. The second line contains three natural numbers describing the second TV in the same format. All numbers do not exceed 1000.

Output
On the first and only line, output 1 if the area of the first TV is larger, 2 if the area of the second TV is larger, and 0 if the areas of the TVs are equal.

Examples
Input #1
32 16:9
37 4:3
Answer #1
2

*/

package main

import (
	"math"
)

func main() {
	assert(solve(32, 16, 9, 37, 4, 3) == 2)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(d1, h1, v1, d2, h2, v2 float64) int {
	a1 := area(d1, h1, v1)
	a2 := area(d2, h2, v2)
	if a1 > a2 {
		return 1
	}
	if a1 < a2 {
		return 2
	}
	return 0
}

/*

Let a and b be the sides of the rectangle
Let r be the aspect ratio

Use Pythagorean theorem

a^2 + b^2 = d
b^2 = r^2*a^2

a^2 + a^2*r^2 = d
a^2 * (1 + r^2) = d

a = sqrt(d / (1 + r^2))
b = r * a

*/

func area(d, h, v float64) float64 {
	r := v / h
	a := math.Sqrt(d / (1 + r*r))
	b := r * a
	return a * b
}
