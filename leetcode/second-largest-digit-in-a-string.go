/*

Given an alphanumeric string s, return the second largest numerical digit that appears in s, or -1 if it does not exist.

An alphanumeric string is a string consisting of lowercase English letters and digits.

Example 1:

Input: s = "dfa12321afd"
Output: 2
Explanation: The digits that appear in s are [1, 2, 3]. The second largest digit is 2.

Example 2:

Input: s = "abc1111"
Output: -1
Explanation: The digits that appear in s are [1]. There is no second largest digit.

Constraints:

    1 <= s.length <= 500
    s consists of only lowercase English letters and/or digits.

*/

package main

func main() {
	assert(secondhighest("dfa12321afd") == 2)
	assert(secondhighest("abc1111") == -1)
	assert(secondhighest("123459876") == 8)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func secondhighest(s string) int {
	m0, m1 := -1, -1
	for _, r := range s {
		v := int(r - '0')
		if !(0 <= v && v <= 9) {
			continue
		}

		switch {
		case m1 < v:
			m0, m1 = m1, v
		case m0 < v && v < m1:
			m0 = v
		}
	}
	return m0
}
