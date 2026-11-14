/*

You are given a string time in the form of  hh:mm, where some of the digits in the string are hidden (represented by ?).

The valid times are those inclusively between 00:00 and 23:59.

Return the latest valid time you can get from time by replacing the hidden digits.

Example 1:

Input: time = "2?:?0"
Output: "23:50"
Explanation: The latest hour beginning with the digit '2' is 23 and the latest minute ending with the digit '0' is 50.
Example 2:

Input: time = "0?:3?"
Output: "09:39"
Example 3:

Input: time = "1?:22"
Output: "19:22"


Constraints:

time is in the format hh:mm.
It is guaranteed that you can produce a valid time from the given string.

*/

package main

import "fmt"

func main() {
	assert(latesttime("2?:?0") == "23:50")
	assert(latesttime("0?:3?") == "09:39")
	assert(latesttime("1?:22") == "19:22")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func latesttime(s string) string {
	for i := 1439; i >= 0; i-- {
		t := fmt.Sprintf("%02d:%02d", i/60, i%60)
		if cmp(s, t) {
			return t
		}
	}
	return ""
}

func cmp(s, t string) bool {
	if len(s) != len(t) {
		return false
	}
	for i := range s {
		if s[i] != '?' && s[i] != t[i] {
			return false
		}
	}
	return true
}
