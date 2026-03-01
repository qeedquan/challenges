/*

A message containing letters from A-Z can be encoded into numbers using the following mapping:

'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:

"AAJF" with the grouping (1 1 10 6)
"KJF" with the grouping (11 10 6)
Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".

Given a string s containing only digits, return the number of ways to decode it.

The test cases are generated so that the answer fits in a 32-bit integer.



Example 1:

Input: s = "12"
Output: 2
Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).
Example 2:

Input: s = "226"
Output: 3
Explanation: "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
Example 3:

Input: s = "06"
Output: 0
Explanation: "06" cannot be mapped to "F" because of the leading zero ("6" is different from "06").


Constraints:

1 <= s.length <= 100
s contains only digits and may contain leading zero(s).

*/

package main

func main() {
	assert(decodings("") == 0)
	assert(decodings("1") == 1)
	assert(decodings("12") == 2)
	assert(decodings("226") == 3)
	assert(decodings("06") == 0)
	assert(decodings("25114") == 6)
	assert(decodings("1111111111") == 89)
	assert(decodings("3333333333") == 1)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://cheonhyangzhang.gitbooks.io/leetcode-solutions/content/91_decode_ways__medium.html
func decodings(s string) int {
	n := len(s)
	if n == 0 {
		return 0
	}

	w := make([]int, n+1)
	w[n] = 1
	if s[n-1] > '0' {
		w[n-1] = 1
	}

	for i := n - 2; i >= 0; i-- {
		if s[i] == '0' {
			w[i] = 0
		} else {
			v := (s[i]-'0')*10 + (s[i+1] - '0')
			if v > 26 {
				w[i] = w[i+1]
			} else {
				w[i] = w[i+1] + w[i+2]
			}
		}
	}
	return w[0]
}
