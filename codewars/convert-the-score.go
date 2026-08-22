/*

You are working at a lower league football stadium and you've been tasked with automating the scoreboard.

The referee will shout out the score, you have already set up the voice recognition module which turns the ref's voice into a string, but the spoken score needs to be converted into a pair for the scoreboard!

e.g. "The score is four nil" should return [4,0]

Either teams score has a range of 0-9, and the ref won't say the same string every time e.g.

"new score: two three"

"two two"

"Arsenal just conceded another goal, two nil"
Note:

Please return an array

Please rate and enjoy!

*/

package main

import "strings"

func main() {
	assert(conv("The score is four nil") == [2]int{4, 0})
	assert(conv("new score: two three") == [2]int{2, 3})
	assert(conv("two two") == [2]int{2, 2})
	assert(conv("Arsenal just conceded another goal, two nil") == [2]int{2, 0})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func conv(s string) [2]int {
	m := map[string]int{
		"nil":   0,
		"one":   1,
		"two":   2,
		"three": 3,
		"four":  4,
		"five":  5,
		"six":   6,
		"seven": 7,
		"eight": 8,
		"nine":  9,
	}

	r := [2]int{-1, -1}
	i := 0
	for _, t := range strings.Split(s, " ") {
		t = strings.ToLower(t)
		if v, f := m[t]; f {
			r[i], i = v, i+1
			if i >= len(r) {
				break
			}
		}
	}
	return r
}
