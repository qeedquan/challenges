/*

Given a string s, partition the string into one or more substrings such that the characters in each substring are unique.
That is, no letter appears in a single substring more than once.

Return the minimum number of substrings in such a partition.

Note that each character should belong to exactly one substring in a partition.

Example 1:

Input: s = "abacaba"
Output: 4
Explanation:
Two possible partitions are ("a","ba","cab","a") and ("ab","a","ca","ba").
It can be shown that 4 is the minimum number of substrings needed.

Example 2:

Input: s = "ssssss"
Output: 6
Explanation:
The only valid partition is ("s","s","s","s","s","s").

Constraints:

1 <= s.length <= 10^5
s consists of only English lowercase letters.

Hint 1
Try to come up with a greedy approach.

Hint 2
From left to right, extend every substring in the partition as much as possible.

*/

package main

func main() {
	assert(partition("abacaba") == 4)
	assert(partition("ssssss") == 6)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func partition(s string) int {
	r := 1
	l := 0
	m := make(map[rune]int)
	for i, x := range s {
		_, f := m[x]
		if f && m[x] >= l {
			l = i
			r += 1
		}
		m[x] = i
	}
	return r
}
