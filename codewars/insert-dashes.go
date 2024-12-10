/*

Write a function that takes an integer num (num >= 0) and inserts dashes ('-') between each two odd digits in num.

Examples
454793 ---> "4547-9-3"
     0 ---> "0"
     1 ---> "1"
13579  ---> "1-3-5-7-9"
 86420 ---> "86420"

*/

package main

import (
	"bytes"
	"fmt"
)

func main() {
	assert(dashes(454793) == "4547-9-3")
	assert(dashes(0) == "0")
	assert(dashes(1) == "1")
	assert(dashes(13579) == "1-3-5-7-9")
	assert(dashes(86420) == "86420")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func dashes(n uint) string {
	w := new(bytes.Buffer)
	s := fmt.Sprint(n)
	for i := range s {
		w.WriteByte(s[i])
		if i+1 < len(s) && isodd(s[i]) && isodd(s[i+1]) {
			w.WriteByte('-')
		}
	}
	return w.String()
}

func isodd(c byte) bool {
	return (c-'0')&1 != 0
}
