/*

Inputs:

Two single digits (let's call them m and n) and two chars (let's call them a and b) in your input format of choice.

Output:

For the walkthrough, pretend m=2, n=5, a='a', b='b'.

Your output will be a string built from your four inputs. Let's call the string result, with value "". First, concatenate a onto result m times, so concatenate a onto result 2 times. result now equals aa. Second, concatenate b onto result m times, so concatenate b onto result 2 times. result now equals aabb. Lastly, if result is already longer than n, truncate result so that it has length n. Otherwise, continue alternating with m length runs of a and b until result has length n. The final result is aabba, which has length 5.

Test Cases:

Input: m = 2, n = 4, a = A, b = B

Output: AABB

Input: m = 3, n = 8, a = A, b = B

Output: AAABBBAA

Input: m = 4, n = 3, a = A, b = B

Output: AAA

Input: m = 2, n = 10, a = A, b = B

Output: AABBAABBAA
As all knows, lesser one will rule the world, so the smallest programs, in bytes, win! :)

*/

package main

import (
	"strings"
)

func main() {
	assert(pattern(2, 4, 'A', 'B') == "AABB")
	assert(pattern(3, 8, 'A', 'B') == "AAABBBAA")
	assert(pattern(4, 3, 'A', 'B') == "AAA")
	assert(pattern(2, 10, 'A', 'B') == "AABBAABBAA")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func pattern(m, n int, a, b rune) string {
	p := []string{string(a), string(b)}
	s := ""
	for i := 0; len(s) < n; i ^= 1 {
		s += strings.Repeat(p[i], m)
	}
	return s[:n]
}
