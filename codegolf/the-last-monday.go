/*

Monday, October 31st, is Halloween. And it got me thinking -- I wonder what other months have the last day of the month also be a Monday?

Input
A positive integer in any convenient format representing a year, 10000 > y > 0.
The input can be padded with zeros (e.g., 0025 for year 25) if required.
Output
A list of the months of that year where the last day of the month is a Monday.
This can be as month names (e.g., January, March, October), or shortnames (Jan, Mar, Oct), or numbers (1, 3, 10), as separate lines or a list or delimited, etc., just so long as it's unambiguous to the reader.
The output format must be consistent:
For all years input (meaning, you can't output month names for some inputs, and month numbers for other inputs)
As well as consistent per output (meaning, you can't output 1 for January in the same output as Jul for July)
Basically, pick one format and stick to it.
Rules
Assume the Gregorian calendar for input/output, even down to y = 1.
Leap years must be properly accounted for (as a reminder: every year divisible by 4, except not years divisible by 100, unless also divisible by 400 -- 1700, 1800, 1900 all weren't leap years, but 2000 was).
You may use any built-ins or other date calculation tools you like.
Either a full program or a function are acceptable. If a function, you can return the output rather than printing it.
Standard loopholes are forbidden.
This is code-golf so all usual golfing rules apply, and the shortest code (in bytes) wins.

Examples
   1 --> Apr, Dec
 297 --> May
1776 --> Sep
2000 --> Jan, Jul
2016 --> Feb, Oct
3385 --> Jan, Feb, Oct

*/

package main

import (
	"fmt"
	"reflect"
	"time"
)

func main() {
	test(1, []string{"Apr", "Dec"})
	test(297, []string{"May"})
	test(1776, []string{"Sep"})
	test(2000, []string{"Jan", "Jul"})
	test(2016, []string{"Feb", "Oct"})
	test(3385, []string{"Jan", "Feb", "Oct"})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(year int, expected []string) {
	result := mondays(year)
	fmt.Println(result)
	assert(reflect.DeepEqual(result, expected))
}

func mondays(year int) []string {
	var abbrev = []string{
		"Jan", "Feb", "Mar", "Apr", "May", "June", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec",
	}

	var result []string
	for month := time.January; month <= time.December; month++ {
		t := time.Date(year, month+1, 0, 0, 0, 0, 0, time.UTC)
		if t.Weekday() == time.Monday {
			result = append(result, abbrev[month-1])
		}
	}
	return result
}
