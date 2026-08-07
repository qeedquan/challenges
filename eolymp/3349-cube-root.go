/*

Your task is to calculate the cube root of a given positive integer.
We can not remember why exactly we need this, but it has something in common with a princess,
a young peasant, kissing and half of a kingdom (a huge one, we can assure you).

Write a program to solve this crucial task.

Input
The input consists of large positive integers of up to 150 decimal digits.
Each number is on its own separate line of the input file.
No line exceeds 255 characters except some whitespaces.

Output
For each number in the input your program should output a line consisting of two values separated by single space.
The second value is the cube root of the given number, truncated (not rounded!) after the 10th decimal place.
First value is a checksum of all printed digits of the cube root, calculated as the sum of the printed digits modulo 10.

Examples

Input #1
1
8
1000
2
33076161

Answer #1
1 1.0000000000
2 2.0000000000
1 10.0000000000
0 1.2599210498
6 321.0000000000

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	for i := -100000.0; i <= 100000; i++ {
		assert(math.Abs(cbrt(i)-math.Cbrt(i)) < 1e-12)
	}

	fmt.Println(cbrt(1))
	fmt.Println(cbrt(8))
	fmt.Println(cbrt(1000))
	fmt.Println(cbrt(2))
	fmt.Println(cbrt(33076161))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://en.wikipedia.org/wiki/Halley%27s_method
func cbrt(n float64) float64 {
	if n == 0 {
		return 0
	}

	x := n
	for range 100 {
		x = x * (x*x*x + 2*n) / (2*x*x*x + n)
	}
	return x
}
