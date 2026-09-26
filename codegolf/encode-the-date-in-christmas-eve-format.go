/*

The day this post was published was Christmas Eve. Tomorrow will be Christmas. Yesterday was Christmas Eve Eve. In two days it will be

Christmas Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve
.

Your job is to take the date the program is run and encode it in Christmas Eve format.

If your program is run on Christmas, it should output the string "Christmas".
If your program is not run on Christmas, it should output the string "Christmas", followed by the string " Eve" repeated n times, where n is the number of days until Christmas.
Note that this must be based on the next Christmas. For example, if the day is April 26, 2019, you must do your calculation based on December 25, 2019, not any other Christmas.
Remember to count leap days.
Christmas is December 25th of every year.
This is code-golf, so the shortest code wins! Note though that the goal is not to find the shortest program in any language, but to find the shortest program in every particular language.
For example, if you find the shortest C++ program, then it wins this contest for C++, even if someone finds a shorter program in Python.

*/

package main

import (
	"bytes"
	"fmt"
	"time"
)

func main() {
	t0 := time.Date(1970, time.December, 24, 0, 0, 0, 0, time.UTC)
	t1 := t0.AddDate(0, 0, 1)
	t2 := t0.AddDate(0, 0, -1)
	t3 := t0.AddDate(0, 0, 2)

	assert(christmas(t0) == "Christmas Eve")
	assert(christmas(t1) == "Christmas")
	assert(christmas(t2) == "Christmas Eve Eve")
	assert(christmas(t3) == "Christmas Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func christmas(t time.Time) string {
	w := new(bytes.Buffer)
	c := time.Date(t.Year(), time.December, 25, 0, 0, 0, 0, time.UTC)
	if t.After(c) {
		c = c.AddDate(1, 0, 0)
	}

	fmt.Fprintf(w, "Christmas ")
	for t.Before(c) {
		fmt.Fprintf(w, "Eve ")
		t = t.AddDate(0, 0, 1)
	}

	s := w.String()
	s = s[:len(s)-1]
	return s
}
