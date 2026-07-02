/*

You are given two strings. In a single move, you can choose any of them, and delete the first (i.e. leftmost) character.

For Example:

By applying a move to the string "where", the result is the string "here".
By applying a move to the string "a", the result is an empty string "".
Implement a function that calculates the minimum number of moves that should be performed to make the given strings equal.

Notes
Both strings consist of lowercase latin letters.
If the string is already empty, you cannot perform any more delete operations.

*/

package main

func main() {
	assert(shiftleft("test", "west") == 2)
	assert(shiftleft("test", "yes") == 7)
	assert(shiftleft("b", "ab") == 1)
	assert(shiftleft("abacabadabacaba", "abacabadacaba") == 18)
	assert(shiftleft("aaabc", "bc") == 3)
	assert(shiftleft("ahmedaly", "aly") == 5)
	assert(shiftleft("dadc", "dddc") == 4)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func shiftleft(s1, s2 string) int {
	c := 0
	for s1 != s2 && len(s1) > 0 && len(s2) > 0 {
		switch {
		case len(s1) == len(s2):
			c, s1, s2 = c+2, s1[1:], s2[1:]
		default:
			c += 1
			if len(s1) > len(s2) {
				s1 = s1[1:]
			} else {
				s2 = s2[1:]
			}
		}
	}
	if len(s1) == 0 || len(s2) == 0 {
		c += len(s1) + len(s2)
	}
	return c
}
