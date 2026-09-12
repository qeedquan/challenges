/*

Task
Given a string of digits, return the longest substring with alternating odd/even or even/odd digits. If two or more substrings have the same length, return the substring that occurs first.

Examples
longest_substring("225424272163254474441338664823") ➞ "272163254"
# substrings = 254, 272163254, 474, 41, 38, 23

longest_substring("594127169973391692147228678476") ➞ "16921472"
# substrings = 94127, 169, 16921472, 678, 476

longest_substring("721449827599186159274227324466") ➞ "7214"
# substrings = 7214, 498, 27, 18, 61, 9274, 27, 32
# 7214 and 9274 have same length, but 7214 occurs first.

longest_substring("20") ➞ "2"

longest_substring("") ➞ ""

Input Constraints
0 <= len(digits) <= 10^5

*/

package main

func main() {
	assert(longest("225424272163254474441338664823") == "272163254")
	assert(longest("594127169973391692147228678476") == "16921472")
	assert(longest("721449827599186159274227324466") == "7214")
	assert(longest("20") == "2")
	assert(longest("") == "")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func longest(s string) string {
	i := 0
	j := 0
	k := 0
	p := rune(-1)
	for l, c := range s {
		q := c & 1
		if q == p {
			if l-i > j-k {
				k, j = i, l
			}
			i = l
		}
		p = q
	}
	if len(s)-i > j-k {
		k, j = i, len(s)
	}
	return s[k:j]
}
