/*

Tonight, 31 January 2020, Brexit will happen and the United Kingdom will leave the European Union, the first time that the number of EU member states will decrease.

Your job is to take a date and output the number of EU1 members on that date, according to the following table:

| Start      | End        | Number of members
| 0          | 1957-12-31 | 0
| 1958-01-01 | 1972-12-31 | 6
| 1973-01-01 | 1980-12-31 | 9
| 1981-01-01 | 1985-12-31 | 10
| 1986-01-01 | 1994-12-31 | 12
| 1995-01-01 | 2004-04-30 | 15
| 2004-05-01 | 2006-12-31 | 25
| 2007-01-01 | 2013-06-30 | 27
| 2013-07-01 | 2020-01-31 | 28
| 2020-02-01 | Inf        | 27
Input may take one of the following forms:

your language's date format
any ordering of integers for year, month and day with any separator (e.g. YYYYMMDD or DD/MM/YYYY)
number of days lapsed since some epoch.
This is code-golf, so shortest code wins!

1. or EEC before 1993

*/

package main

import (
	"time"
)

func main() {
	assert(countries("2000-02-27") == 15)
	assert(countries("2015-03-15") == 28)
	assert(countries("2021-02-27") == 27)
}

func assert(x bool) {
	if !x {
		panic("asserrtion failed")
	}
}

func countries(date string) int {
	var histories = []struct {
		start   time.Time
		end     time.Time
		members int
	}{
		{mkdate("0"), mkdate("1957-12-31"), 0},
		{mkdate("1958-01-01"), mkdate("1972-12-31"), 6},
		{mkdate("1973-01-01"), mkdate("1980-12-31"), 9},
		{mkdate("1981-01-01"), mkdate("1985-12-31"), 10},
		{mkdate("1986-01-01"), mkdate("1994-12-31"), 12},
		{mkdate("1995-01-01"), mkdate("2004-04-30"), 15},
		{mkdate("2004-05-01"), mkdate("2006-12-31"), 25},
		{mkdate("2007-01-01"), mkdate("2013-06-30"), 27},
		{mkdate("2013-07-01"), mkdate("2020-01-31"), 28},
		{mkdate("2020-02-01"), mkdate("1957-12-31"), 27},
	}

	n := len(histories)
	t := mkdate(date)
	for _, h := range histories {
		x := t.Compare(h.start)
		y := t.Compare(h.end)
		if x >= 0 && y <= 0 {
			return h.members
		}
	}
	return histories[n-1].members
}

func mkdate(s string) time.Time {
	if s == "0" || s == "Inf" {
		return time.Time{}
	}
	t, err := time.Parse("2006-01-02", s)
	if err != nil {
		panic(err)
	}
	return t
}
