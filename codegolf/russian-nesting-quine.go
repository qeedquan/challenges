/*

A Russian nesting doll, more commonly known as a Matryoshka doll, is a doll which contains a smaller version of itself, which then contains another smaller version of itself, which contains a smaller version of itself, which contains a smaller version of itself, which contains a smaller version of itself... - until finally, the last one is empty.

Today your goal is to emulate this Russian tradition by writing a program or function that, when it contains itself N times, will print itself containing N-1 copies of itself times.

For example, the doll program abcd will have the N=3 program abababcdcdcd, which will print the N=2 program ababcdcd, which prints the original N=1 program abcd, which finally prints N=0, which is empty. This should theoretically work for any reasonable value of N.

Rules:

Here is a TIO program to help generate doll programs based on your program
Standard Quine Rules apply
Standard Loopholes apply
'Contains' means directly in the center of the previous version, so your solution must have a positive even number of bytes. A program of length 10 will have a copy of the original inserted after the fifth byte, then another after the tenth byte etc.
A single trailing whitespace is allowed in the output
As this is code-golf, your goal is to make your N=1 program as short as possible.
An explanation of your code would be appreciated

*/

package main

func main() {
	tab := []string{"", "abcd", "ababcdcd", "abababcdcdcd"}
	for i := range tab {
		assert(nest("abcd", i) == tab[i])
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func nest(s string, n int) string {
	if n < 1 {
		return ""
	}

	p := s
	l := len(s)
	for i := 1; i < n; i++ {
		p = s[:l/2] + p + s[l/2:]
	}
	return p
}
