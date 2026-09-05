/*

You are given a 0-indexed string word.

In one operation, you can pick any index i of word and change word[i] to any lowercase English letter.

Return the minimum number of operations needed to remove all adjacent almost-equal characters from word.

Two characters a and b are almost-equal if a == b or a and b are adjacent in the alphabet.

Example 1:

Input: word = "aaaaa"
Output: 2
Explanation: We can change word into "acaca" which does not have any adjacent almost-equal characters.
It can be shown that the minimum number of operations needed to remove all adjacent almost-equal characters from word is 2.

Example 2:

Input: word = "abddez"
Output: 2
Explanation: We can change word into "ybdoez" which does not have any adjacent almost-equal characters.
It can be shown that the minimum number of operations needed to remove all adjacent almost-equal characters from word is 2.

Example 3:

Input: word = "zyxyxyz"
Output: 3
Explanation: We can change word into "zaxaxaz" which does not have any adjacent almost-equal characters.
It can be shown that the minimum number of operations needed to remove all adjacent almost-equal characters from word is 3.

Constraints:

1 <= word.length <= 100
word consists only of lowercase English letters.

Hint 1
For i > 0, if word[i] and word[i - 1] are adjacent, we will change word[i] to another character.
Which character should we change it to?

Hint 2
We will change word[i] to some character that is not adjacent to word[i - 1] nor word[i + 1] (if it exists).
Such a character always exists. However, since the problem does not ask for the final state of the string,
It is enough to prove that the character exists and we do not need to find it.

*/

package main

func main() {
	assert(solve("aaaaa") == 2)
	assert(solve("abddez") == 2)
	assert(solve("zyxyxyz") == 3)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(s string) int {
	r := 0
	for i := 0; r+i+1 < len(s); i++ {
		if abs(int(s[r+i+1])-int(s[i+r])) <= 1 {
			r++
		}
	}
	return r
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}
