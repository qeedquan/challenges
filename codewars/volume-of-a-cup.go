/*

Your job is to return the volume of a cup when given the diameter of the top, the diameter of the bottom and the height.

You know that there is a steady gradient from the top to the bottom.

You want to return the volume rounded to 2 decimal places.

Exmples:

cupVolume(1, 1, 1);
//returns 0.79

cupVolume(10, 8, 10);
//returns 638.79

cupVolume(1000, 1000, 1000);
//returns 785398163.4

cupVolume(13.123, 123.12, 1);
//returns 4436.57

cupVolume(5, 12, 31);
//returns 1858.51
You will only be passed positive numbers.

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	test(1, 1, 1, 0.79)
	test(10, 8, 10, 638.78)
	test(1000, 1000, 1000, 785398163.4)
	test(13.123, 123.12, 1, 4436.57)
	test(5, 12, 31, 1858.51)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(top, bottom, height, expected float64) {
	value := volume(top, bottom, height)
	fmt.Println(value)
	assert(math.Abs(value-expected) < 1e-1)
}

func volume(top, bottom, height float64) float64 {
	return math.Pi * height / 12 * (top*top + top*bottom + bottom*bottom)
}
