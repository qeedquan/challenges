/*

You're re-designing a blog, and the blog's posts have the Weekday Month Day, time format for showing the date and time when a post was made, e.g., Friday May 2, 7pm.

You're running out of screen real estate, and on some pages you want to display a shorter format, Weekday Month Day
that omits the time.

Write a function that takes the website date/time in its original string format and returns the shortened format.

## Input

Input will always be a string, e.g., "Friday May 2, 7pm".

## Output

Output will be the shortened string, e.g., "Friday May 2".

*/

package main

import "strings"

func main() {
	assert(shorten("Friday May 2, 9am") == "Friday May 2")
	assert(shorten("Tuesday January 29, 10pm") == "Tuesday January 29")
	assert(shorten("Monday December 25, 10pm") == "Monday December 25")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func shorten(date string) string {
	index := strings.Index(date, ",")
	if index >= 0 {
		date = date[:index]
	}
	return date
}
