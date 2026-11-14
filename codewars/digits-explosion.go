/*

Given a string made of digits [0-9], return a string where each digit is repeated a number of times equals to its value.

Examples
explode("312")
should return :

"333122"
explode("102269")
should return :

"12222666666999999999"

*/

package main

import (
	"bytes"
	"fmt"
)

func main() {
	assert(explode("312") == "333122")
	assert(explode("102269") == "12222666666999999999")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func explode(s string) string {
	w := new(bytes.Buffer)
	for _, r := range s {
		n := 1
		if '0' <= r && r <= '9' {
			n = int(r - '0')
		}

		for range n {
			fmt.Fprintf(w, "%c", r)
		}
	}
	return w.String()
}
