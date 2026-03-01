/*

In the United States, Daylight Savings Time starts on the second Sunday of March, and ends on the first Sunday of November.

Write the shortest full program, function, or code snippet that does the following:

Takes a year as input.
Outputs two dates: the date when DST starts, and the date when DST ends.
I/O can be with any reasonable method.
Behavior with 0 or negative years is undefined for this challenge.

Test cases
Year -> Start, End
2021 -> Mar 14, Nov 07
2022 -> Mar 13, Nov 06
2023 -> Mar 12, Nov 05
2024 -> Mar 10, Nov 03
2025 -> Mar 09, Nov 02
2026 -> Mar 08, Nov 01
2027 -> Mar 14, Nov 07
1    -> Mar 11, Nov 04
1234 -> Mar 12, Nov 05
9999 -> Mar 14, Nov 07

*/

package main

import (
	"fmt"
	"time"
)

func main() {
	assert(daylight(2021) == "Mar 14, Nov 07")
	assert(daylight(2022) == "Mar 13, Nov 06")
	assert(daylight(2023) == "Mar 12, Nov 05")
	assert(daylight(2024) == "Mar 10, Nov 03")
	assert(daylight(2025) == "Mar 09, Nov 02")
	assert(daylight(2026) == "Mar 08, Nov 01")
	assert(daylight(2027) == "Mar 14, Nov 07")
	assert(daylight(1) == "Mar 11, Nov 04")
	assert(daylight(1234) == "Mar 12, Nov 05")
	assert(daylight(9999) == "Mar 14, Nov 07")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func daylight(year int) string {
	layout := "Jan 02"
	offset := []int{0, 6, 5, 4, 3, 2, 1}

	start := time.Date(year, time.March, 1, 0, 0, 0, 0, time.UTC)
	end := time.Date(year, time.November, 1, 0, 0, 0, 0, time.UTC)

	index0 := start.Weekday()
	index1 := end.Weekday()

	start = start.AddDate(0, 0, offset[index0]+7)
	end = end.AddDate(0, 0, offset[index1])

	return fmt.Sprintf("%s, %s", start.Format(layout), end.Format(layout))
}
