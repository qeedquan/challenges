/*

Given a birthday date, and another date, write a function that return the resulting age.

age("05/25/2000","04/03/2016") = 15
age("05/25/2000","05/25/2016") = 16
The entries must have this format : "mm/dd/yyyy" and be valid dates (month between 01 and 12, day between 01 and 31) and you need to round down the age like in the first example.

and the birthday date must be prior to the tested date

elsewhere the function return -1

*/

package main

import (
	"time"
)

func main() {
	assert(age("05/25/2000", "04/03/2016") == 15)
	assert(age("05/25/2000", "05/25/2016") == 16)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func age(birthday, date string) int {
	const layout = "01/02/2006"

	t0, err := time.Parse(layout, birthday)
	t1, xerr := time.Parse(layout, date)
	if err != nil || xerr != nil || t1.Before(t0) {
		return -1
	}

	var t time.Time
	dt := t1.Sub(t0)
	t = t.Add(dt)
	return t.Year() - 1
}
