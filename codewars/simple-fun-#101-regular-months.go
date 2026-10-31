/*

Task
In an effort to be more innovative, your boss introduced a strange new tradition: the first day of every month you're allowed to work from home. You like this rule when the day falls on a Monday, because any excuse to skip rush hour traffic is great!

You and your colleagues have started calling these months regular months. Since you're a fan of working from home, you decide to find out how far away the nearest regular month is, given that the currMonth has just started.

For your convenience, here is a list of month lengths (from January to December, respectively):

 Month lengths: 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31. Please, note that in leap years February has 29 days.

Example
For currMonth = "02-2016", the output should be "08-2016".

February of 2016 year is regular, but it doesn't count since it has started already, so the next regular month is August of 2016 - which is the answer.

Input/Output
[input] string currMonth

A string representing the correct month in the format mm-yyyy, where mm is the number of the month (1-based, i.e. 01 for January, 02 for February and so on) and yyyy is the year.

Constraints:

1 ≤ int(mm) ≤ 12,

1970 ≤ int(yyyy) ≤ 2100.

[output] a string

The earliest regular month after the given one in the same format as currMonth.

*/

package main

import (
	"time"
)

func main() {
	assert(regularmonth("02-2016") == "08-2016")
	assert(regularmonth("05-2027") == "11-2027")
	assert(regularmonth("09-2099") == "02-2100")
	assert(regularmonth("01-1970") == "06-1970")
	assert(regularmonth("07-2024") == "09-2025")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func regularmonth(current string) string {
	date, err := time.Parse("01-2006", current)
	if err != nil {
		return "invalid"
	}
	for {
		date = date.AddDate(0, 1, 0)
		if date.Weekday() == time.Monday {
			break
		}
	}
	return date.Format("01-2006")
}
