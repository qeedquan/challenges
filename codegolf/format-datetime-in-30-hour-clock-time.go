/*

Input a datetime, format the datetime in YYYY-MM-DD HH:mm:ss format using 30-hour clock time.

The 30-hour clock time works as:

After 6 a.m., it is same as 24-hour clock time
Before 6 a.m., it use date for previous day, and plus Hours by 24.
For more examples, you may checkout the testcases.

Rules
To simplify the question
You may choose to use client timezone or UTC timezone by your prefer;
You may assume the client timezone don't have DST;
You may assume no leap second.
This is code-golf.
Input can be in any convenience format. Although certainly, you cannot take input in 30-hour clock time.
Output need to be a string, displayed on screen, or other similar replacements with exactly specified format.

Testcases
Input               -> Output
2023-12-01 00:00:00 -> 2023-11-30 24:00:00
2023-12-01 01:23:45 -> 2023-11-30 25:23:45
2023-12-01 05:59:59 -> 2023-11-30 29:59:59
2023-12-01 06:00:00 -> 2023-12-01 06:00:00 or 2023-11-30 30:00:00
2023-12-01 06:00:01 -> 2023-12-01 06:00:01
2023-12-01 12:34:56 -> 2023-12-01 12:34:56
2023-12-01 23:59:59 -> 2023-12-01 23:59:59
2024-01-01 02:00:00 -> 2023-12-31 26:00:00
2024-03-01 00:00:00 -> 2024-02-29 24:00:00

*/

package main

import (
	"fmt"
	"time"
)

func main() {
	assert(datetime30("2023-12-01 00:00:00") == "2023-11-30 24:00:00")
	assert(datetime30("2023-12-01 01:23:45") == "2023-11-30 25:23:45")
	assert(datetime30("2023-12-01 05:59:59") == "2023-11-30 29:59:59")
	assert(datetime30("2023-12-01 06:00:00") == "2023-12-01 06:00:00")
	assert(datetime30("2023-12-01 06:00:01") == "2023-12-01 06:00:01")
	assert(datetime30("2023-12-01 12:34:56") == "2023-12-01 12:34:56")
	assert(datetime30("2023-12-01 23:59:59") == "2023-12-01 23:59:59")
	assert(datetime30("2024-01-01 02:00:00") == "2023-12-31 26:00:00")
	assert(datetime30("2024-03-01 00:00:00") == "2024-02-29 24:00:00")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func datetime30(s string) string {
	t, err := time.Parse("2006-01-02 15:04:05", s)
	if err != nil {
		return s
	}

	h := 0
	if t.Hour() < 6 {
		t = t.AddDate(0, 0, -1)
		h = 24
	}

	return fmt.Sprintf("%04d-%02d-%02d %02d:%02d:%02d",
		t.Year(), t.Month(), t.Day(), t.Hour()+h, t.Minute(), t.Second())
}
