/*

Create a progress bar indicating year progress
Your code has to output the percentage of the year already passed form 1st of January of the current year.

You have to display a progress bar and the figure.

Input
You may use builtins to get the current date, if your language doesen't have it you can get date as input but it would be added to your byte count (has to ba a reasonable input format like 2017-05-12)

Output
Bar status: At least 10 different status relating to figure.

Figure: can be rounded or float, has to represent current (or input) day of the year / 365(366) * 100

Example
Today 2017-05-12

Output

▓▓▓▓▓░░░░░░░░░░ 36%

Take into account leap years informal definition (occurring evey 4 years) progess of the year for 12-Feb is 12% on leap years.

*/

package main

import (
	"bytes"
	"fmt"
	"math"
	"strings"
	"time"
)

func main() {
	assert(progressbar(date(2017, time.May, 12)) == "▓▓▓▓▓░░░░░░░░░░ 36%")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func progressbar(t time.Time) string {
	const length = 15

	yd := t.YearDay()
	yt := 365
	if isleap(t.Year()) {
		yt += 1
	}

	p := math.Round(float64(yd) / float64(yt) * 100)
	l := int(p * length / 100)

	w := new(bytes.Buffer)
	fmt.Fprint(w, strings.Repeat("▓", l))
	fmt.Fprint(w, strings.Repeat("░", length-l))
	fmt.Fprintf(w, " %.0f%%", p)

	return w.String()
}

func date(y int, m time.Month, d int) time.Time {
	return time.Date(y, m, d, 0, 0, 0, 0, time.UTC)
}

func isleap(y int) bool {
	if y%4 != 0 {
		return false
	}

	if y%100 == 0 && y%400 != 0 {
		return false
	}

	return true
}
