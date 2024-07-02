/*

Given two positive integers n and k, the binary string Sn is formed as follows:

S1 = "0"
Si = Si - 1 + "1" + reverse(invert(Si - 1)) for i > 1
Where + denotes the concatenation operation, reverse(x) returns the reversed string x, and invert(x) inverts all the bits in x (0 changes to 1 and 1 changes to 0).

For example, the first four strings in the above sequence are:

S1 = "0"
S2 = "011"
S3 = "0111001"
S4 = "011100110110001"
Return the kth bit in Sn. It is guaranteed that k is valid for the given n.

Example 1:

Input: n = 3, k = 1
Output: "0"
Explanation: S3 is "0111001".
The 1st bit is "0".

Example 2:

Input: n = 4, k = 11
Output: "1"
Explanation: S4 is "011100110110001".
The 11th bit is "1".

Constraints:

1 <= n <= 20
1 <= k <= 2^n - 1

*/

package main

import (
	"bytes"
)

func main() {
	assert(kthbit(3, 1) == "0")
	assert(kthbit(4, 11) == "1")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func kthbit(n, k int) string {
	s := binary(n)
	if k < 1 || k > len(s) {
		return "-1"
	}
	return string(s[k-1])
}

func binary(n int) string {
	s := "0"
	for i := 1; i < n; i++ {
		s = s + "1" + reverse(invert(s))
	}
	return s
}

func invert(s string) string {
	w := new(bytes.Buffer)
	for _, r := range s {
		if r == '1' {
			r = '0'
		} else if r == '0' {
			r = '1'
		}
		w.WriteRune(r)
	}
	return w.String()
}

func reverse(s string) string {
	r := []rune(s)
	w := new(bytes.Buffer)
	for i := len(r) - 1; i >= 0; i-- {
		w.WriteRune(r[i])
	}
	return w.String()
}
