/*

Circle area inside square
Turn an area of a square in to an area of a circle that fits perfectly inside the square.

You get the square area and need to calculate the circle area.

Your function gets a number which represents the area of the square and should return the area of the circle. The tests are rounded by 8 decimals to make sure multiple types of solutions work.

You don't have to worry about error handling or negative number input: area >= 0.

This kata might be simpler than you expect, but good luck!

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	for i := float64(0); i <= 10; i++ {
		fmt.Println(s2c(i))
	}
}

func s2c(x float64) float64 {
	r := math.Sqrt(x) / 2
	return r * r * math.Pi
}
