/*

Find the lines that are parallel to the given line and at a distance r from it.

Input
Four integers are given: the coefficients a, b, c of the line equation ax+by+c=0 and the value r.
The absolute value of each input integer does not exceed 10000.

Output
Print six numbers: the coefficients a, b, c of the equations of two lines, each parallel to the given line and at a distance r (r=0) from it.
Print three numbers per line. The coefficients must be printed with at least six decimal places of precision. The order of the lines does not matter.

Examples

Input #1
0 -1 1 1

Answer #1
0.0000 -1.0000 2.0000
0.0000 -1.0000 0.0000

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	solve(0, -1, 1, 1)
}

func solve(A, B, C, R float64) {
	L := R * math.Hypot(A, B)
	fmt.Printf("%v %v %v\n", A, B, C+L)
	fmt.Printf("%v %v %v\n", A, B, C-L)
}
