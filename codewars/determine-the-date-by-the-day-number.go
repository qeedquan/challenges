/*

What date corresponds to the nth day of the year?
The answer depends on whether the year is a leap year or not.

Write a function that will help you determine the date if you know the number of the day in the year, as well as whether the year is a leap year or not.
The function accepts the day number and a boolean value isLeap as arguments, and returns the corresponding date of the year as a string "Month, day".
Only valid combinations of a day number and isLeap will be tested.

Examples:
getDay(41, false)   =>  "February, 10"  //  41st day of non-leap year is February, 10
getDay(60, false)   =>  "March, 1"      //  60th day of non-leap year is March, 1
getDay(60, true)    =>  "February, 29"  //  60th day of leap year is February, 29
getDay(365, false)  =>  "December, 31"  //  365th day of non-leap year is December, 31
getDay(366, true)   =>  "December, 31"  //  366th day of leap year is December, 31

*/

package main

import (
	"time"
)

func main() {
	assert(getday(15, false) == "January, 15")
	assert(getday(41, false) == "February, 10")
	assert(getday(59, false) == "February, 28")
	assert(getday(60, false) == "March, 1")
	assert(getday(60, true) == "February, 29")
	assert(getday(365, false) == "December, 31")
	assert(getday(366, true) == "December, 31")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func getday(day int, leap bool) string {
	year := 1999
	if leap {
		year = 2000
	}
	date := time.Date(year, time.January, day, 0, 0, 0, 0, time.UTC)
	return date.Format("January, 2")
}
