/*

F# solutions known inside 140 chars, and this is a Rosetta Code problem.

Required result on stdout or in a string variable for input year 2014:

2014-01-26 2014-02-23 2014-03-30 2014-04-27 2014-05-25 2014-06-29 2014-07-27 2014-08-31 2014-09-28 2014-10-26 2014-11-30 2014-12-28
As it was requested, for 1900:

1900-01-28 1900-02-25 1900-03-25 1900-04-29 1900-05-27 1900-06-24 1900-07-29 1900-08-26 1900-09-30 1900-10-28 1900-11-25 1900-12-30
And 2000:

2000-01-30 2000-02-27 2000-03-26 2000-04-30 2000-05-28 2000-06-25 2000-07-30 2000-08-27 2000-09-24 2000-10-29 2000-11-26 2000-12-31
Posed because dates seem to bring out awkwardness in most languages. More than permitting date libraries, I hope to see them! But if external to the base language, declare in the name of the post (e.g. C# + Jon Skeet's NodaTime).

Clarifications:

Year range 1900 to 3015
Gregorian calendar
If it otherwise matters, whatever is conventional for UK/London.
A program taking a commandline switch or stdin is fine, producing the result to stdout
A function taking a value for the year and returning a string is also fine.
Standard loopholes excluded. Looking forward to the APL, J, K solutions, and seeing some new date libraries.

*/

package main

import (
	"fmt"
	"time"
)

func main() {
	fmt.Println(lastsundays(2014))
	fmt.Println(lastsundays(1900))
	fmt.Println(lastsundays(2000))
}

func lastsundays(y int) []time.Time {
	var r []time.Time
	for m := time.January; m <= time.December; m++ {
		t := time.Date(y, m, 1, 0, 0, 0, 0, time.UTC)
		t = t.AddDate(0, 1, -1)
		t = t.AddDate(0, 0, int(-t.Weekday()))
		r = append(r, t)
	}
	return r
}
