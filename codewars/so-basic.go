/*

Summary: In this kata we want to communiate with a Mayan accountant.

Scenario: You work for the IRS and have been sent the 1040 form for a local Mayan retailer. The Mayan apparently speaks perfect English but has accidentally filled out his Adjusted Gross Income (AGI) in Mayan.

Task: Generate a javascript method that converts a base-20 value into its decimal equivalent. If it cannot be done, return -1.

*/

package main

import (
	"strconv"
)

func main() {
	assert(mayan2dec("10") == 20)
	assert(mayan2dec("20") == 40)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func mayan2dec(s string) int64 {
	i, err := strconv.ParseInt(s, 20, 64)
	if err != nil {
		return -1
	}
	return i
}
