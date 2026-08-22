/*

For this challenge, we are writing the time in the following form: hh:mm:ss

Some examples:

12:34:08

06:05:30

23:59:00

The challenge is to output the time after an amount of hours, minutes and seconds have elapsed, with as starting time 00:00:00. You can compare this with a timer that started at 00:00:00.

Here is an example of inputs (using STDIN) and outputs:

Input: 1h20m5s
Output: 01:20:05

Input: 0h100m0s
Output: 01:40:00
After 24 hours, the timer resets itself:

Input: 25h0m0s
Output: 01:00:00
The form of the input is always the same: XhYmZs, with X hours, Y minutes and Z seconds (assume that X, Y and Z are whole integers less than 100000 and never negative)

This is code-golf, so least amount of bytes wins this challenge

*/

package main

import (
	"time"
)

func main() {
	assert(after(1*time.Hour+20*time.Minute+5*time.Second) == "01:20:05")
	assert(after(100*time.Minute) == "01:40:00")
	assert(after(25*time.Hour) == "01:00:00")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func after(d time.Duration) string {
	var t time.Time
	t = t.Add(d)
	return t.Format("03:04:05")
}
