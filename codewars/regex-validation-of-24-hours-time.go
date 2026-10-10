/*

Write a regex to validate a 24 hours time string. See examples to figure out what you should check for:

Accepted: 01:00 - 1:00

Not accepted:

24:00

You should check for correct length and no spaces.

*/

package main

import "regexp"

func main() {
	assert(retime.MatchString("01:00") == true)
	assert(retime.MatchString("1:00") == true)
	assert(retime.MatchString("24:00") == false)
	assert(retime.MatchString("23:549") == false)
	assert(retime.MatchString("01:00") == true)
	assert(retime.MatchString("1:00") == true)
	assert(retime.MatchString("1:00") == true)
	assert(retime.MatchString("00:00") == true)
	assert(retime.MatchString("13:1") == false)
	assert(retime.MatchString("12:60") == false)
	assert(retime.MatchString("12: 60") == false)
	assert(retime.MatchString("24:00") == false)
	assert(retime.MatchString("24o:00") == false)
	assert(retime.MatchString("24:000") == false)
	assert(retime.MatchString("") == false)
	assert(retime.MatchString("2400") == false)
	assert(retime.MatchString("foo12:00bar") == false)
	assert(retime.MatchString("010:00") == false)
	assert(retime.MatchString("1;00") == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

var retime = regexp.MustCompile(`^([01]?\d|2[0-3]):[0-5]\d$`)
