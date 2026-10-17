/*

Guess the function F.

Known values:
F("123") = "07b432d25170b469b57095ca269bc202"
F("example") = "335ea833e623b5e8e8176ed06d4a97a1"
F("Hello, world!") = "93897493c4b060acb45ad0bed6553dc6"
F("") = "e7248fce8990089e402b00f89dc8d14d"
F("@#$%!") = "9d986675f0edbed1494f279eb74620e3"
F("Привет, мир!") = ""
F("test string\n") = ""

*/

package main

import (
	"crypto/md5"
	"fmt"
	"io"
	"slices"
	"unicode"
)

func main() {
	assert(f("") == "e7248fce8990089e402b00f89dc8d14d")
	assert(f("123") == "07b432d25170b469b57095ca269bc202")
	assert(f("@#$%!") == "9d986675f0edbed1494f279eb74620e3")
	assert(f("example") == "335ea833e623b5e8e8176ed06d4a97a1")
	assert(f("Hello, world!") == "93897493c4b060acb45ad0bed6553dc6")
	assert(f(".YlKP9g6=<)]Zd/(iT'?i:,B&,") == "41c5843d59073188fd03ce806c8e7f40")
	assert(f("√16 = 4") == "")
	assert(f("Hello, мир!") == "")
	assert(f("Привет, мир!") == "")
	assert(f("test string\n") == "")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func f(s string) string {
	h := md5.New()
	for _, r := range s {
		if r >= 0x80 || !unicode.IsPrint(r) {
			return ""
		}
		io.WriteString(h, string(r))
	}

	p := []rune(fmt.Sprintf("%x", h.Sum(nil)))
	slices.Reverse(p)
	return string(p)
}
