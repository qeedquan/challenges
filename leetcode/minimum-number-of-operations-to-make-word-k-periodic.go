/*

You are given a string word of size n, and an integer k such that k divides n.

In one operation, you can pick any two indices i and j, that are divisible by k, then replace the substring of length k starting at i with the substring of length k starting at j. That is, replace the substring word[i..i + k - 1] with the substring word[j..j + k - 1].

Return the minimum number of operations required to make word k-periodic.

We say that word is k-periodic if there is some string s of length k such that word can be obtained by concatenating s an arbitrary number of times. For example, if word == “ababab”, then word is 2-periodic for s = "ab".

Example 1:

Input: word = "leetcodeleet", k = 4

Output: 1

Explanation:

We can obtain a 4-periodic string by picking i = 4 and j = 0. After this operation, word becomes equal to "leetleetleet".

Example 2:

Input: word = "leetcoleet", k = 2

Output: 3

Explanation:

We can obtain a 2-periodic string by applying the operations in the table below.

i	j	word
0	2	etetcoleet
4	0	etetetleet
6	0	etetetetet

Constraints:

1 <= n == word.length <= 10^5
1 <= k <= word.length
k divides word.length.
word consists only of lowercase English letters.

Hint 1
Calculate the frequency of each substring of length k that starts at an index that is divisible by k.

Hint 2
The period of the final string will be the substring with the highest frequency.

*/

package main

func main() {
	assert(periodic("leetcodeleet", 4) == 1)
	assert(periodic("leetcoleet", 2) == 3)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func periodic(w string, k int) int {
	if k < 1 {
		return 0
	}

	c := make(map[string]int)
	m := 0
	for i := 0; i < len(w); i += k {
		z := w[i : i+k]
		c[z] += 1
		m = max(m, c[z])
	}
	return len(w)/k - m
}
