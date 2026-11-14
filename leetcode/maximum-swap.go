/*

You are given an integer num. You can swap two digits at most once to get the maximum valued number.

Return the maximum valued number you can get.



Example 1:

Input: num = 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.

Example 2:

Input: num = 9973
Output: 9973
Explanation: No swap.



Constraints:

    0 <= num <= 10^8

*/

package main

import (
	"fmt"
	"strconv"
)

func main() {
	assert(maxswap(2736) == 7236)
	assert(maxswap(9973) == 9973)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func maxswap(n int) int {
	s := []byte(fmt.Sprint(n))
	l := 0
	r := 0
	j := len(s) - 1
	for i := j; i >= 0; i-- {
		if s[i] > s[j] {
			j = i
		} else if s[j] > s[i] {
			l = i
			r = j
		}
	}
	s[l], s[r] = s[r], s[l]

	x, _ := strconv.Atoi(string(s))
	return x
}
