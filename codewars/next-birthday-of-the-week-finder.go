/*

Can you find after how many years will a person's birthday fall on the same day of the week that he was born?

For example, Joy's birthday is on 16th October, 1990 which falls on Friday. After how many years will his birthday fall on Friday again? (That would be 11 years)

Note
Month is zero-indexed

nextBirthdayOfTheWeek(new Date(1990, 9, 16)) //11
nextBirthdayOfTheWeek(new Date(2012, 5, 20))  //6
nextBirthdayOfTheWeek(new Date(1975, 2, 22))  //5

*/

package main

import (
	"math"
	"time"
)

func main() {
	assert(nbotw(1990, 9, 16) == 11)
	assert(nbotw(2012, 5, 20) == 6)
	assert(nbotw(1975, 2, 22) == 5)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func nbotw(y int, m time.Month, d int) int {
	t := time.Date(y, m+1, d, 0, 0, 0, 0, time.UTC)
	w := t.Weekday()
	for i := 1; i < math.MaxInt; i++ {
		t = t.AddDate(1, 0, 0)
		if t.Weekday() == w {
			return i
		}
	}
	return -1
}
