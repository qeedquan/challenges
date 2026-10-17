/*

An integer x is a good if after rotating each digit individually by 180 degrees, we get a valid number that is different from x.
Each digit must be rotated - we cannot choose to leave it alone.

A number is valid if each digit remains a digit after rotation. For example:

0, 1, and 8 rotate to themselves,
2 and 5 rotate to each other (in this case they are rotated in a different direction, in other words, 2 or 5 gets mirrored),
6 and 9 rotate to each other, and
the rest of the numbers do not rotate to any other number and become invalid.
Given an integer n, return the number of good integers in the range [1, n].

Example 1:

Input: n = 10
Output: 4
Explanation: There are four good numbers in the range [1, 10] : 2, 5, 6, 9.
Note that 1 and 10 are not good numbers, since they remain unchanged after rotating.
Example 2:

Input: n = 1
Output: 0
Example 3:

Input: n = 2
Output: 1

Constraints:

1 <= n <= 10^4

*/

package main

import (
	"strconv"
)

func main() {
	assert(rotated(10) == 4)
	assert(rotated(1) == 0)
	assert(rotated(2) == 1)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func rotated(n int) int {
	s := strconv.Itoa(n)
	m := len(s)
	f := make([][2]int, m)
	for i := range f {
		f[i] = [2]int{-1, -1}
	}
	return dfs(s, m, f, 0, 0, true)
}

func dfs(s string, m int, f [][2]int, i, ok int, l bool) int {
	if i >= m {
		return ok
	}

	if !l && f[i][ok] != -1 {
		return f[i][ok]
	}

	up := 9
	if l {
		up = int(s[i] - '0')
	}

	r := 0
	for j := 0; j <= up; j++ {
		if j == 0 || j == 1 || j == 8 {
			r += dfs(s, m, f, i+1, ok, l && j == up)
		} else if j == 2 || j == 5 || j == 6 || j == 9 {
			r += dfs(s, m, f, i+1, 1, l && j == up)
		}
	}
	if !l {
		f[i][ok] = r
	}
	return r
}
