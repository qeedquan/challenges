/*

Your challenge is to write a program which, given a year, outputs the number of "Friday 13ths" in it.

Rules & Details:

    You can take input via STDIN, or as an argument passed to your program.
    You should output the result to STDOUT.
    You may assume that input will be a valid year, and does not pre-date the Gregorian calendar (undefined behaviour is permitted in these cases).
    Calendar/Date libraries are allowed.

This is a code-golf, so the shortest code (in bytes) wins.

(Related challenge link)

*/

package main

import (
	"time"
)

func main() {
	tab := []int{2, 1, 3, 1, 2, 2, 2, 2, 1, 1, 2, 2, 1, 3, 1, 1, 2, 2, 1, 2, 1, 2, 2, 1, 3, 1, 1, 3, 2, 1, 3, 1, 2, 2, 2, 2, 1, 1, 2, 2, 1, 3, 1, 1, 2, 2, 1, 2, 1, 2, 2, 1, 3, 1, 1, 3, 2, 1, 3, 1, 2, 2, 2, 2, 1, 1, 2, 2, 1, 3, 1, 1, 2, 2, 1, 2, 1, 2, 2, 1, 3, 1, 1, 3, 2, 1, 3, 1, 2, 2, 2, 2, 1, 1, 2, 2, 1, 3, 1, 1, 2, 2, 1, 2, 1}

	assert(fridays(1776) == 2)
	assert(fridays(2012) == 3)
	assert(fridays(2013) == 2)
	assert(fridays(2014) == 1)
	for i := range tab {
		assert(fridays(1901+i) == tab[i])
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A101312
func fridays(y int) int {
	c := 0
	for m := time.January; m <= time.December; m++ {
		t := time.Date(y, m, 13, 0, 0, 0, 0, time.UTC)
		if t.Weekday() == time.Friday {
			c++
		}
	}
	return c
}
