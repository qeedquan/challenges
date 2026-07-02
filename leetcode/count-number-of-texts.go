/*

Alice is texting Bob using her phone. The mapping of digits to letters is shown in the figure below.

In order to add a letter, Alice has to press the key of the corresponding digit i times, where i is the position of the letter in the key.

For example, to add the letter 's', Alice has to press '7' four times. Similarly, to add the letter 'k', Alice has to press '5' twice.
Note that the digits '0' and '1' do not map to any letters, so Alice does not use them.
However, due to an error in transmission, Bob did not receive Alice's text message but received a string of pressed keys instead.

For example, when Alice sent the message "bob", Bob received the string "2266622".
Given a string pressedKeys representing the string received by Bob, return the total number of possible text messages Alice could have sent.

Since the answer may be very large, return it modulo 10^9 + 7.



Example 1:

Input: pressedKeys = "22233"
Output: 8
Explanation:
The possible text messages Alice could have sent are:
"aaadd", "abdd", "badd", "cdd", "aaae", "abe", "bae", and "ce".
Since there are 8 possible messages, we return 8.
Example 2:

Input: pressedKeys = "222222222222222222222222222222222222"
Output: 82876089
Explanation:
There are 2082876103 possible text messages Alice could have sent.
Since we need to return the answer modulo 10^9 + 7, we return 2082876103 % (10^9 + 7) = 82876089.


Constraints:

1 <= pressedKeys.length <= 10^5
pressedKeys only consists of digits from '2' - '9'.

Hint:
For a substring consisting of the same digit, how can we count the number of texts it could have originally represented?
How can dynamic programming help us calculate the required answer?

*/

package main

func main() {
	assert(texts("22233") == 8)
	assert(texts("222222222222222222222222222222222222") == 82876089)
	assert(texts("123456789") == 1)
	assert(texts("79797979") == 1)
	assert(texts("2266622") == 16)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://walkccc.me/LeetCode/problems/2266/
func texts(s string) int {
	const mod = 1000000007

	n := len(s)
	p := make([]int, n+1)
	p[n] = 1

	for i := n - 1; i >= 0; i-- {
		p[i] = p[i+1]
		if same(s, i, 2) {
			p[i] += p[i+2]
		}
		if same(s, i, 3) {
			p[i] += p[i+3]
		}
		if (s[i] == '7' || s[i] == '9') && same(s, i, 4) {
			p[i] += p[i+4]
		}
		p[i] %= mod
	}
	return p[0]
}

func same(s string, i, k int) bool {
	if i+k > len(s) {
		return false
	}
	for j := i + 1; j < i+k; j++ {
		if s[j] != s[i] {
			return false
		}
	}
	return true
}
