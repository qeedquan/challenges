/*

We all love fridays, and even better if it is the last day of the month!

In this kata you should write a function that will receive 2 parameters. Both are years, and indicates a range.

Your work is to return the number of times a month ends with a Friday.

If there is only one year provided, return the number of times a month ends on Friday on that year. Range bounds are inclusive in every case!

For example, between 1901 and 2000, a month ends on Friday 171 times.

*/

package main

import (
	"time"
)

func main() {
	assert(fridays(1901, 2000) == 171)
	assert(fridays(1901, 2017) == 200)
	assert(fridays(1991, 1991) == 1)
	assert(fridays(2017, 2017) == 2)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func fridays(y0, y1 int) int {
	c := 0
	for y := y0; y <= y1; y++ {
		for m := time.January; m <= time.December; m++ {
			t := time.Date(y, m+1, 0, 0, 0, 0, 0, time.UTC)
			if t.Weekday() == time.Friday {
				c++
			}
		}
	}
	return c
}
