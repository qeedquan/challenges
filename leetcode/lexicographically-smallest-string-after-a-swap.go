/*

Given a string s containing only digits, return the lexicographically smallest string that can be obtained after swapping adjacent digits in s with the same parity at most once.

Digits have the same parity if both are odd or both are even. For example, 5 and 9, as well as 2 and 4, have the same parity, while 6 and 9 do not.

Example 1:

Input: s = "45320"

Output: "43520"

Explanation:

s[1] == '5' and s[2] == '3' both have the same parity, and swapping them results in the lexicographically smallest string.

Example 2:

Input: s = "001"

Output: "001"

Explanation:

There is no need to perform a swap because s is already the lexicographically smallest.

Constraints:

2 <= s.length <= 100
s consists only of digits.

Hint 1
Try all possible swaps satisfying the constraints and find the one that results in the lexicographically smallest string.

*/

package main

import (
	"bytes"
	"fmt"
)

func main() {
	assert(smallest("45320") == "43520")
	assert(smallest("001") == "001")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func smallest(s string) string {
	r := make([]int, len(s))
	for i := range r {
		r[i] = int(s[i]) - '0'
	}

	for i := range len(s) - 1 {
		if r[i]%2 != r[i+1]%2 {
			continue
		}
		if r[i] > r[i+1] {
			r[i], r[i+1] = r[i+1], r[i]
			break
		}
	}

	w := new(bytes.Buffer)
	for i := range r {
		fmt.Fprintf(w, "%d", r[i])
	}
	return w.String()
}
