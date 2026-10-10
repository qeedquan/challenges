/*

Given a non-negative integer Excel-style date code, return the corresponding "date" in any reasonable form that clearly shows year, month, and "day".

Trivial, you may think. Did you notice the "scare quotes"? I used those because Excel has some quirks. Excel counts days with number 1 for January 1st, 1900, but as if 1900 had a January 0th and a February 29th, so be very careful to try all test cases:

 Input → Output (example format)
     0 → 1900-01-00    Note: NOT 1899-12-31
     1 → 1900-01-01
     2 → 1900-01-02
    59 → 1900-02-28
    60 → 1900-02-29    Note: NOT 1900-03-01
    61 → 1900-03-01
   100 → 1900-04-09
  1000 → 1902-09-26
 10000 → 1927-05-18
100000 → 2173-10-14

*/

package main

import (
	"time"
)

func main() {
	assert(excel2date(0) == "1900-01-00")
	assert(excel2date(1) == "1900-01-01")
	assert(excel2date(2) == "1900-01-02")
	assert(excel2date(59) == "1900-02-28")
	assert(excel2date(60) == "1900-02-29")
	assert(excel2date(61) == "1900-03-01")
	assert(excel2date(100) == "1900-04-09")
	assert(excel2date(1000) == "1902-09-26")
	assert(excel2date(10000) == "1927-05-18")
	assert(excel2date(100000) == "2173-10-14")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func excel2date(n int) string {
	switch {
	case n < 0:
		return "negative number not supported"
	case n == 0:
		return "1900-01-00"
	case n < 60:
		n -= 1
	case n == 60:
		return "1900-02-29"
	default:
		n -= 2
	}

	t := time.Date(1900, time.January, 1, 0, 0, 0, 0, time.UTC)
	t = t.AddDate(0, 0, n)
	return t.Format("2006-01-02")
}
