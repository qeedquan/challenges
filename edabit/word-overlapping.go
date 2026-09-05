/*

Given two words, overlap them in such a way, morphing the last few letters of the first word with the first few letters of the second word. Return the shortest overlapped word possible.

Examples
overlap("sweden", "denmark") ➞ "swedenmark"

overlap("edabit", "iterate") ➞ "edabiterate"

overlap("honey", "milk") ➞ "honeymilk"

overlap("dodge", "dodge") ➞ "dodge"

Notes
All words will be given in lowercase.
If no overlap is possible, return both words one after the other (example #3).

*/

package main

import (
	"strings"
)

func main() {
	assert(overlap("sweden", "denmark") == "swedenmark")
	assert(overlap("edabit", "iterate") == "edabiterate")
	assert(overlap("honey", "milk") == "honeymilk")
	assert(overlap("dodge", "dodge") == "dodge")
	assert(overlap("colossal", "alligator") == "colossalligator")
	assert(overlap("leave", "eavesdrop") == "leavesdrop")
	assert(overlap("joshua", "osha") == "joshuaosha")
	assert(overlap("diction", "dictionary") == "dictionary")
	assert(overlap("massive", "mass") == "massivemass")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func overlap(s, t string) string {
	for i := len(t); i > 0; i-- {
		if strings.HasSuffix(s, t[:i]) {
			return s + t[i:]
		}
	}
	return s + t
}
