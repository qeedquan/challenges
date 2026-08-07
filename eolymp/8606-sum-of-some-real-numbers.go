/*

Four real numbers are given. Find the sum of first two, of first three and of all four numbers.

Input
Four real numbers.

Output
Print in the first line the sum of first two numbers.
Print in the second line the sum of first three numbers.
Print in the third line the sum of all four numbers.
All sums must be printed with 4 decimal digits.

Examples

Input #1
3.678 1.2345 3.4566 -0.1236

Answer #1
4.9125
8.3691
8.2455

*/

package main

import "fmt"

func main() {
	fmt.Println(solve(3.678, 1.2345, 3.4566, -0.1236))
}

func solve(a, b, c, d float64) (float64, float64, float64) {
	return a + b, a + b + c, a + b + c + d
}
