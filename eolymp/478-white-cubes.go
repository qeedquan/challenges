/*

Engineer Klepka decided to make cubes from white bars. Each cube has a side length of 1 dm.
After making the cubes, the engineer decided to make all the cubes white as well.
How many cubes of side 1 dm can the engineer make from one bar, and how many faces need to be painted,
given that the dimensions of the bar are integers and are given in decimetres?

Input
Three integers — the dimensions of the bar in dm, each not exceeding 10^6.

Output
Print two integers: the number of cubes obtained and the number of faces that need to be painted.

Examples

Input #1
1 2 3

Answer #1
6 14

*/

package main

import "fmt"

func main() {
	fmt.Println(solve(1, 2, 3))
}

func solve(a, b, c int) (int, int) {
	x := a * b * c
	y := x*6 - 2*(a*b+b*c+a*c)
	return x, y
}
