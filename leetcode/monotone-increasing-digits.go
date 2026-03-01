/*

An integer has monotone increasing digits if and only if each pair of adjacent digits x and y satisfy x <= y.

Given an integer n, return the largest number that is less than or equal to n with monotone increasing digits.

Example 1:

Input: n = 10
Output: 9
Example 2:

Input: n = 1234
Output: 1234
Example 3:

Input: n = 332
Output: 299

Constraints:

0 <= n <= 10^9

Hint 1
Build the answer digit by digit, adding the largest possible one that would make the number still less than or equal to N.

*/

package main

import (
	"fmt"
	"strconv"
)

func main() {
	assert(monotone(10) == 9)
	assert(monotone(1234) == 1234)
	assert(monotone(332) == 299)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func monotone(n int) int {
	if n < 0 {
		return 0
	}

	s := []byte(fmt.Sprint(n))
	l := len(s)
	for i := l - 1; i > 0; i-- {
		if s[i-1] > s[i] {
			l = i
			s[i-1] -= 1
		}
	}

	for i := l; i < len(s); i++ {
		s[i] = '9'
	}

	r, _ := strconv.Atoi(string(s))
	return r
}
