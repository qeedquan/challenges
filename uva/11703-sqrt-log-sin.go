/*

An evil professor has just assigned
you the following problem.
A sequence is defined by the following recurrence:
x0 = 1
xi = x⌊i−sqrt(i)⌋ + x⌊ln(i)⌋ + x⌊i*sin^2(i)⌋
Determine x1000000.

Input
Input consists of a number of lines,
each containing one integer, a value
of i, no less than zero and no
greater than one million. Input is
followed by a single line containing
the integer ‘-1’. This last line is
not a value of i and should not be
processed.

Output
For each value of i in the input
(but not the final ‘-1’), output the
corresponding value of xi modulo 1000000.

Sample Input
0
-1

Sample Output
1

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(solve(0))
	fmt.Println(solve(1000000))
}

var memo = make(map[int]int)

func solve(n int) int {
	if n < 0 {
		return 0
	}

	if n == 0 {
		return 1
	}

	if r, f := memo[n]; f {
		return r
	}

	x := float64(n)
	a := math.Floor(x - math.Sqrt(x))
	b := math.Floor(math.Log(x))
	c := math.Floor(x * math.Sin(x) * math.Sin(x))
	r := solve(int(a)) + solve(int(b)) + solve(int(c))

	memo[n] = r % 1000000
	return memo[n]
}
