/*

In Bloons Tower Defense 6, the strength of different bloons can be measured by their Red Bloon Equivalent (RBE), or the number of single pops it takes to completely defeat the bloon.

The RBE for the bloon types are as follows (sourced from the wiki)

Bloon	RBE
red	1
blue	2
green	3
yellow	4
pink	5
black	11
white	11
purple	11
lead	23
zebra	23
rainbow	47
ceramic	104
moab	616
bfb	3164
zomg	16656
ddt	816
bad	55760
The Challenge
Given a run-length encoded list of bloon types, calculate the total RBE. More specifically, find the RBE of each bloon type according to the table, multiply by the given count, and sum them all.

Notes
Input can be taken in any reasonable format (comma-separated string, list of tuples, etc.)
You must output a single integer
Assume that input will never be invalid
Bloon types must be given exactly as shown in the table above, in lowercase
This is code-golf, so the lowest score in bytes wins!
Test Cases
Input: 1 red
Output: 1

Input: 7 green
Output: 21

Input: 5 bfb, 11 moab
Output: 22596

Input: 1 red, 2 yellow, 3 white, 4 zebra, 5 moab, 6 ddt
Output: 8110

Input: 1 moab, 1 bfb, 1 zomg, 1 ddt, 1 bad, 1 red, 1 blue, 1 green, 1 yellow, 1 pink, 1 black, 1 white, 1 purple, 1 lead, 1 zebra, 1 rainbow, 1 ceramic
Output: 77257

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	assert(rbe("1 red") == 1)
	assert(rbe("7 green") == 21)
	assert(rbe("5 bfb, 11 moab") == 22596)
	assert(rbe("1 red, 2 yellow, 3 white, 4 zebra, 5 moab, 6 ddt") == 8110)
	assert(rbe("1 moab, 1 bfb, 1 zomg, 1 ddt, 1 bad, 1 red, 1 blue, 1 green, 1 yellow, 1 pink, 1 black, 1 white, 1 purple, 1 lead, 1 zebra, 1 rainbow, 1 ceramic") == 77257)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func rbe(s string) int {
	tab := map[string]int{
		"red":     1,
		"blue":    2,
		"green":   3,
		"yellow":  4,
		"pink":    5,
		"black":   11,
		"white":   11,
		"purple":  11,
		"lead":    23,
		"zebra":   23,
		"rainbow": 47,
		"ceramic": 104,
		"moab":    616,
		"bfb":     3164,
		"zomg":    16656,
		"ddt":     816,
		"bad":     55760,
	}

	r := 0
	t := strings.Split(s, ",")
	for _, t := range t {
		var k string
		var v int

		t = strings.TrimSpace(t)
		fmt.Sscan(t, &v, &k)
		r += v * tab[k]
	}
	return r
}
