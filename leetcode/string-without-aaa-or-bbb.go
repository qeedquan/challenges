/*

Given two integers a and b, return any string s such that:

s has length a + b and contains exactly a 'a' letters, and exactly b 'b' letters,
The substring 'aaa' does not occur in s, and
The substring 'bbb' does not occur in s.


Example 1:

Input: a = 1, b = 2
Output: "abb"
Explanation: "abb", "bab" and "bba" are all correct answers.
Example 2:

Input: a = 4, b = 1
Output: "aabaa"


Constraints:

0 <= a, b <= 100
It is guaranteed such an s exists for the given a and b.

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	test(1, 2)
	test(4, 1)

	for a := 1; a <= 100; a++ {
		for b := a; b <= a+3; b++ {
			test(a, b)
			test(b, a)
		}
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a, b int) {
	s := strx3a3b(a, b)
	fmt.Println(a, b, s)
	na, nb := count(s)
	assert(len(s) == a+b)
	assert(strings.Index(s, "aaa") < 0)
	assert(strings.Index(s, "bbb") < 0)
	assert(a == na && b == nb)
}

func strx3a3b(a, b int) string {
	return recurse(a, b, "a", "b")
}

func recurse(a, b int, c0, c1 string) string {
	if a < b {
		return recurse(b, a, c1, c0)
	}
	if b == 0 {
		return strings.Repeat(c0, min(a, 2))
	}

	ua := min(a, 2)
	ub := truth(a-ua >= b)
	return strings.Repeat(c0, ua) + strings.Repeat(c1, ub) + recurse(a-ua, b-ub, c0, c1)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func truth(x bool) int {
	if x {
		return 1
	}
	return 0
}

func count(s string) (na, nb int) {
	for _, r := range s {
		if r == 'a' {
			na++
		} else if r == 'b' {
			nb++
		}
	}
	return
}
