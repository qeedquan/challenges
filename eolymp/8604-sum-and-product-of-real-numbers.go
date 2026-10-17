/*

Three real numbers are given. Find their sum and product.

Input
Three real numbers x,y,z.

Output
Print the sum and the product of three numbers with 4 decimal places on a single line.

Examples
Input #1
1.2345 3.4566 -0.1236

Answer #1
4.5675 -0.5274

*/

package main

import "fmt"

func main() {
	fmt.Println(solve(1.2345, 3.4566, -0.1236))
}

func solve(x, y, z float64) (float64, float64) {
	return x + y + z, x * y * z
}
