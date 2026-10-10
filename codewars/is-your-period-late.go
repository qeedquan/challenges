/*

In this kata, we will make a function to test whether a period is late.

Our function will take three parameters:

last - The Date object with the date of the last period

today - The Date object with the date of the check

cycleLength - Integer representing the length of the cycle in days

Return true if the number of days passed from last to today is greater than cycleLength. Otherwise, return false.

*/

package main

import (
	"time"
)

func main() {
	assert(late(makedate(2016, 6, 13), makedate(2016, 7, 16), 28) == true)
	assert(late(makedate(2016, 6, 13), makedate(2016, 7, 16), 35) == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func late(last, today time.Time, cycle int) bool {
	date := today.AddDate(0, 0, -cycle)
	return date.After(last)
}

func makedate(year, month, day int) time.Time {
	return time.Date(year, time.Month(month), day, 0, 0, 0, 0, time.UTC)
}
