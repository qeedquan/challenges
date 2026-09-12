package main

import (
	"fmt"
	"time"
)

func main() {
	assert(y3k(1, 31, 12, 2999) == "1 1 3000")
	assert(y3k(40, 1, 2, 2004) == "12 3 2004")
	assert(y3k(60, 31, 12, 1999) == "29 2 2000")
	assert(y3k(60, 31, 12, 2999) == "1 3 3000")
	assert(y3k(146097, 31, 12, 1999) == "31 12 2399")
	assert(y3k(999999, 1, 1, 2000) == "27 11 4737")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func y3k(n, d, m, y int) string {
	t := time.Date(y, time.Month(m), d, 0, 0, 0, 0, time.UTC)
	t = t.AddDate(0, 0, n)
	return fmt.Sprintf("%d %d %d", t.Day(), t.Month(), t.Year())
}
