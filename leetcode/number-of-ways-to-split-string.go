/*

Given a binary string s, you can split s into 3 non-empty strings s1, s2, and s3 where s1 + s2 + s3 = s.

Return the number of ways s can be split such that the number of ones is the same in s1, s2, and s3. Since the answer may be too large, return it modulo 109 + 7.

Example 1:

Input: s = "10101"
Output: 4
Explanation: There are four ways to split s in 3 parts where each part contain the same number of letters '1'.
"1|010|1"
"1|01|01"
"10|10|1"
"10|1|01"
Example 2:

Input: s = "1001"
Output: 0
Example 3:

Input: s = "0000"
Output: 3
Explanation: There are three ways to split s in 3 parts.
"0|0|00"
"0|00|0"
"00|0|0"

Constraints:

3 <= s.length <= 10^5
s[i] is either '0' or '1'.

Hint 1
There is no way if the sum (number of '1's) is not divisible by the number of splits. So sum%3 should be 0.

Hint 2
Preffix s1 , and suffix s3 should have sum/3 characters '1'.


Hint 3
Follow up: Can you generalize the problem with numbers between [-10^9, 10^9] such the sum between subarrays s1, s2, s3 are the same?

*/

package main

func main() {
	assert(ways("10101") == 4)
	assert(ways("1001") == 0)
	assert(ways("0000") == 3)
	assert(ways("100100010100110") == 12)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func ways(s string) int {
	m := 1000000007
	n := len(s)
	P := make([]int, n)
	S := make([]int, n)
	L := make([]int, n)

	c := 0
	for i := range n {
		if s[i] == '1' {
			c += 1
		}
		P[i] = c
	}
	if c%3 != 0 {
		return 0
	}

	k := c / 3
	c = 0
	for i := n - 1; i >= 0; i-- {
		if s[i] == '1' {
			c += 1
		}
		S[i] = c
	}

	c = 0
	for i := n - 1; i >= 0; i-- {
		if S[i] == k {
			c += 1
		}
		L[i] = c
	}

	r := 0
	for i := range n - 1 {
		if P[i] == k {
			r += L[i+1]
			if k == 0 {
				r -= 1
			}
			r %= m
		}
	}
	return r
}
