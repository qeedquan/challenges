/*

You are given an array of strings message and an array of strings bannedWords.

An array of words is considered spam if there are at least two words in it that exactly match any word in bannedWords.

Return true if the array message is spam, and false otherwise.

Example 1:

Input: message = ["hello","world","leetcode"], bannedWords = ["world","hello"]

Output: true

Explanation:

The words "hello" and "world" from the message array both appear in the bannedWords array.

Example 2:

Input: message = ["hello","programming","fun"], bannedWords = ["world","programming","leetcode"]

Output: false

Explanation:

Only one word from the message array ("programming") appears in the bannedWords array.

Constraints:

1 <= message.length, bannedWords.length <= 10^5
1 <= message[i].length, bannedWords[i].length <= 15
message[i] and bannedWords[i] consist only of lowercase English letters.

Hint 1
Use hash set.

*/

package main

func main() {
	test(
		[]string{"hello", "world", "leetcode"}, []string{"world", "hello"},
		true,
	)

	test(
		[]string{"hello", "programming", "fun"}, []string{"world", "programming", "leetcode"},
		false,
	)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(messages, bannedwords []string, expected bool) {
	result := spam(messages, bannedwords)
	assert(result == expected)
}

func spam(messages, bannedwords []string) bool {
	const threshold = 2

	lookup := make(map[string]bool)
	for _, word := range bannedwords {
		lookup[word] = true
	}

	count := 0
	for _, message := range messages {
		if !lookup[message] {
			continue
		}
		if count++; count >= threshold {
			break
		}
	}
	return count == threshold
}
