/*

You have an amount of money `a0 > 0` and you deposit it with a constant interest rate of `p% > 0` per **year** on the
`1st of January 2016`. You want to have an amount `a >= a0`.

## Task

The function `date_nb_days` (or dateNbDays...) with parameters `a0, a, p` will return, as a string, the date on which you
have just reached `a`.

## Example:

`date_nb_days(100, 101, 0.98) --> "2017-01-01" (366 days)`

`date_nb_days(100, 150, 2.00) --> "2035-12-26" (7299 days)`

## Notes:

- The return format of the date is `"YYYY-MM-DD"`
- The deposit is always on the `"2016-01-01"`
- If `p%` is the rate for a year the rate for a day is `p divided by
  36000` since banks consider that there are `360` days in a year.
- You have: `a0 > 0, p% > 0, a >= a0`

*/

package main

import (
	"math"
	"time"
)

func main() {
	assert(datenbdays(100, 101, 0.98) == "2017-01-01")
	assert(datenbdays(100, 150, 2.00) == "2035-12-26")
	assert(datenbdays(4281, 5087, 2) == "2024-07-03")
	assert(datenbdays(4620, 5188, 2) == "2021-09-19")
	assert(datenbdays(9999, 11427, 6) == "2018-03-13")
	assert(datenbdays(3525, 4822, 3) == "2026-04-18")
	assert(datenbdays(5923, 6465, 6) == "2017-06-10")
	assert(datenbdays(4254, 4761, 8) == "2017-05-22")
	assert(datenbdays(1244, 2566, 4) == "2033-11-04")
	assert(datenbdays(6328, 7517, 5) == "2019-05-25")
	assert(datenbdays(2920, 3834, 2) == "2029-06-03")
	assert(datenbdays(7792, 8987, 4) == "2019-07-09")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func datenbdays(a0, a, p float64) string {
	p0 := math.Log(a / a0)
	p1 := math.Log(p/36000 + 1)
	d := int(p0/p1 + 1)
	t := time.Date(2016, time.January, 1, 0, 0, 0, 0, time.UTC)
	t = t.AddDate(0, 0, d)
	return t.Format("2006-01-02")
}
