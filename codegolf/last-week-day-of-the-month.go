/*

Introduction
This challenge was inspired by a seemingly simple task requested at work that couldn't easily be done in Microsoft Teams. At least not from what we could find!

Task
Your task, if you choose to accept it, is to output the last working day of any month in any year.

Input
You can input the desired month/year in whatever format you like, but it must take in an input. Having these hard-coded into the calculations doesn't count!

Input examples include but are not limited to:

08/2023
October 1678
1/2067

Output
Your output must be the last working day of the month in the below format:

Tuesday 31st

Test cases
Input	Output
10/2023	Tuesday 31st
February 2017	Tuesday 28th
09/1674	Friday 28th
1/2043	Friday 30th

Assumptions / Stipulations
You can assume the inputs are always in a workable format and not null
Calendar is the Gregorian Calendar
Monday, Tuesday, Wednesday, Thursday and Friday are all working days. Saturday and Sunday are NOT valid working days for this task
Don't take into account public holidays

PS. I got the test cases from timeanddate.com (Beware, by default it is using Julian calendar which does not match Gregorian)

*/

package main

import (
	"time"
)

func main() {
	assert(lastworkday("08/2023") == "Thursday 31st")
	assert(lastworkday("1/2067") == "Monday 31st")
	assert(lastworkday("10/2023") == "Tuesday 31st")
	assert(lastworkday("February 2017") == "Tuesday 28th")
	assert(lastworkday("09/1674") == "Friday 28th")
	assert(lastworkday("1/2043") == "Friday 30th")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func lastworkday(s string) string {
	t, err := time.Parse("1/2006", s)
	if err != nil {
		t, err = time.Parse("January 2006", s)
	}
	if err != nil {
		return "invalid date format"
	}

	t = t.AddDate(0, 1, -1)
	switch t.Weekday() {
	case time.Sunday:
		t = t.AddDate(0, 0, -2)
	case time.Saturday:
		t = t.AddDate(0, 0, -1)
	}

	sf := "th"
	switch t.Day() % 10 {
	case 1:
		sf = "st"
	case 2:
		sf = "nd"
	case 3:
		sf = "rd"
	}
	return t.Format("Monday 2") + sf
}
