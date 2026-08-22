/*

This cipher involves taking each character of a string and multiplying their char codes by 6.

For example, `Hello World!` would become `ưɞʈʈʚÀȊʚʬʈɘÆ`.

You must write two functions:
`encode` to encode a given string,
`decode` to decode a given string.

*/

package main

import (
	"bytes"
)

func main() {
	test("Hello World!", "ưɞʈʈʚÀȊʚʬʈɘÆ")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(in, out string) {
	enc := encode(in)
	assert(enc == out)
	assert(decode(enc) == in)
}

func encode(src string) string {
	out := new(bytes.Buffer)
	for _, sym := range src {
		out.WriteRune(sym * 6)
	}
	return out.String()
}

func decode(src string) string {
	out := new(bytes.Buffer)
	for _, sym := range src {
		out.WriteRune(sym / 6)
	}
	return out.String()
}
