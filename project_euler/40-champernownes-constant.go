/*

An irrational decimal fraction is created by concatenating the positive integers:

0.123456789101112131415161718192021...

It can be seen that the 12th digit of the fractional part is 1.

If dn represents the nth digit of the fractional part, find the value of the following expression.

d1 × d10 × d100 × d1000 × d10000 × d100000 × d1000000

*/

package main

import (
	"bytes"
	"fmt"
)

func main() {
	fmt.Println(solve())
}

func solve() int {
	r := 1
	p := 1
	c := champernowne(1e6)
	for i := 0; i < 7; i++ {
		r *= int(c[p-1] - '0')
		p *= 10
	}
	return r
}

// https://oeis.org/A033307
func champernowne(n int) string {
	w := new(bytes.Buffer)
	for i := 1; i <= n; i++ {
		fmt.Fprint(w, i)
	}
	return w.String()
}
