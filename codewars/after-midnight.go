/*

Instructions
Write a function that takes a negative or positive integer, which represents the number of minutes before (-) or after (+) Sunday midnight, and returns the current day of the week and the current time in 24hr format ('hh:mm') as a string.

Examples
      0  =>  should return 'Sunday 00:00'
     -3  =>  should return 'Saturday 23:57'
     45  =>  should return 'Sunday 00:45'
    759  =>  should return 'Sunday 12:39'
   1236  =>  should return 'Sunday 20:36'
   1447  =>  should return 'Monday 00:07'
   7832  =>  should return 'Friday 10:32'
  18876  =>  should return 'Saturday 02:36'
 259180  =>  should return 'Thursday 23:40'
-349000  =>  should return 'Tuesday 15:20'

*/

package main

import (
	"time"
)

func main() {
	assert(daytime(0) == "Sunday 00:00")
	assert(daytime(-3) == "Saturday 23:57")
	assert(daytime(45) == "Sunday 00:45")
	assert(daytime(759) == "Sunday 12:39")
	assert(daytime(1236) == "Sunday 20:36")
	assert(daytime(1447) == "Monday 00:07")
	assert(daytime(7832) == "Friday 10:32")
	assert(daytime(18876) == "Saturday 02:36")
	assert(daytime(259180) == "Thursday 23:40")
	assert(daytime(-349000) == "Tuesday 15:20")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func daytime(n int) string {
	t := time.Date(2023, time.August, 6, 0, n, 0, 0, time.UTC)
	return t.Format("Monday 15:04")
}
