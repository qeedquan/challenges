/*

A wonderful string is a string where at most one letter appears an odd number of times.

For example, "ccjjc" and "abab" are wonderful, but "ab" is not.
Given a string word that consists of the first ten lowercase English letters ('a' through 'j'), return the number of wonderful non-empty substrings in word. If the same substring appears multiple times in word, then count each occurrence separately.

A substring is a contiguous sequence of characters in a string.

Example 1:

Input: word = "aba"
Output: 4
Explanation: The four wonderful substrings are underlined below:
- "aba" -> "a"
- "aba" -> "b"
- "aba" -> "a"
- "aba" -> "aba"

Example 2:

Input: word = "aabb"
Output: 9
Explanation: The nine wonderful substrings are underlined below:
- "aabb" -> "a"
- "aabb" -> "aa"
- "aabb" -> "aab"
- "aabb" -> "aabb"
- "aabb" -> "a"
- "aabb" -> "abb"
- "aabb" -> "b"
- "aabb" -> "bb"
- "aabb" -> "b"

Example 3:

Input: word = "he"
Output: 2
Explanation: The two wonderful substrings are underlined below:
- "he" -> "h"
- "he" -> "e"


Constraints:

1 <= word.length <= 10^5
word consists of lowercase English letters from 'a' to 'j'.

Hint:
For each prefix of the string, check which characters are of even frequency and which are not and represent it by a bitmask.
Find the other prefixes whose masks differs from the current prefix mask by at most one bit.

*/

package main

func main() {
	assert(occurences("aba") == 4)
	assert(occurences("aabb") == 9)
	assert(occurences("he") == 2)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func occurences(word string) int {
	count := map[int]int{0: 1}
	prefix := 0
	total := 0
	for _, c := range word {
		prefix ^= 1 << (c - 'a')
		total += count[prefix]
		for i := 0; i < 10; i++ {
			total += count[prefix^(1<<i)]
		}
		count[prefix]++
	}
	return total
}
