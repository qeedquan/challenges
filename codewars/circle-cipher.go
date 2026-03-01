/*

Imagine a circle. To encode the word codewars, we could split the circle into 8 parts (as codewars has 8 letters):

https://www.codewars.com/kata/634d0723075de3f97a9eb604

If we read the result from left to right, we get csordaew.

Decoding is the same process in reverse. If we decode csordaew, we get codewars.

Examples:

encode "codewars" -> "csordaew"
decode "csordaew" -> "codewars"

encode "white" -> "wehti"
decode "wehti" -> "white"

*/

package main

import "bytes"

func main() {
	assert(encode("codewars") == "csordaew")
	assert(decode("csordaew") == "codewars")

	assert(encode("white") == "wehti")
	assert(decode("wehti") == "white")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func encode(s string) string {
	n := len(s)
	if n == 0 {
		return s
	}

	w := new(bytes.Buffer)
	w.WriteByte(s[0])
	for i := 0; i < (n>>1)-((n&1)^1); i++ {
		w.WriteByte(s[n-i-1])
		w.WriteByte(s[i+1])
	}

	r := w.String()
	if len(r) != n {
		r += string(s[n/2])
	}
	return r
}

func decode(s string) string {
	l, r := "", ""
	for i := range len(s) {
		if i&1 != 0 {
			r = string(s[i]) + r
		} else {
			l += string(s[i])
		}
	}
	return l + r
}
