/*

Given the time in 24 hour format (2359 = 11:59pm) return the angle between the minute and hour hands on a standard clock (on the face plane, so don't just output 0).

Angles are to be returned in the unit of your choice, should be the smallest possible, and should be a positive number (negative angle converted to a positive value), i.e. you will never have an answer greater than 180 degrees or pi radians.

Some examples to check against (in degrees)

0000 = 0.0
0010 = 55.0
0020 = 110.0
0030 = 165.0
0040 = 140.0
0050 = 85.0
0150 = 115.0
0240 = 160.0
0725 = 72.5
1020 = 170.0
1350 = 115.0
1725 = 12.5

Note: There are a few that have rounding errors, I'm not sure how that should be handled; if we should force consistency across all values.

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	test(0, 0)
	test(10, 55)
	test(20, 110)
	test(30, 165)
	test(40, 140)
	test(50, 85)
	test(150, 115)
	test(240, 160)
	test(725, 72.5)
	test(1020, 170)
	test(1350, 115)
	test(1725, 12.5)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(t int, r float64) {
	v := angle(t)
	fmt.Printf("%.2f\n", v)
	assert(math.Abs(v-r) < 1e-3)
}

/*

@Toby Speight

Explanation
We convert sexagesimal seconds to centihours by adding t%100/1.5 (so 0030 becomes 0050 etc), and divide by 100 to get hours. Coincidence of hands occurs 11 times every 12 hours, so multiply by 11 and divide by 12; we take the remainder in the range [-6,+6], and return its absolute value.

*/

func angle(t int) float64 {
	x := float64(t) + float64(t%100)/1.5
	return 30 * math.Abs(math.Remainder(x*0.11, 12))
}
