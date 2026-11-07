/*

Task similar to this one: https://codegolf.stackexchange.com/questions/44830/string-to-binary
Take a string of ASCII characters and convert it to base-3 equivalents separated by a space.

For example:

Hello, world!
Should be converted to

02200 10202 11000 11000 11010 01122 01012 11102 11010 11020 11000 10201 01020
The output should only contain numbers with the same number of digits. Which separator to use is up to you.

This is a code-golf challenge so the shortest solution wins.

*/

package main

import (
	"bytes"
	"fmt"
	"strconv"
	"strings"
)

func main() {
	assert(base3("Hello, world!") == "02200 10202 11000 11000 11010 01122 01012 11102 11010 11020 11000 10201 01020")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func base3(s string) string {
	return conv(s, maxpad(s))
}

func conv(s string, p int) string {
	if len(s) == 0 {
		return ""
	}

	w := new(bytes.Buffer)
	for _, r := range s {
		t := strconv.FormatInt(int64(r), 3)
		fmt.Fprintf(w, "%v%v ", strings.Repeat("0", p-len(t)), t)
	}
	u := w.String()
	return u[:len(u)-1]
}

func maxpad(s string) int {
	m := 0
	for _, r := range s {
		t := strconv.FormatInt(int64(r), 3)
		m = max(m, len(t))
	}
	return m
}
