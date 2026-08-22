/*

Challenge
Given ASCII-encoded text input of any size, detect numbers between -1,000,000,000,000,000,000 and 1,000,000,000,000,000,000 exclusive and rewrite them with thousands separators. Use commas only and ignore leading zeroes. Leave the rest of the input unchanged.

Test cases
Input	Output	Description
123	123
1234	1,234
-12345	-12,345
x12345y	x12,345y	ignore surrounding characters
1234 xyz 56789	1,234 xyz 56,789
1234,56789	1,234,56,789	1,234 and 56,789 are separate numbers
0001234	0001,234	zeroes are not part of the number
10000000	10,000,000	only leading zeroes are ignored
1234567891234567890	1234567891234567890	1,234,567,891,234,567,890 is outside the range
0123456789123456789	0123,456,789,123,456,789

Standard loopholes apply. Shortest code in bytes wins.

*/

package main

import (
	"bytes"
	"strconv"
)

func main() {
	assert(numfmt("123") == "123")
	assert(numfmt("1234") == "1,234")
	assert(numfmt("-12345") == "-12,345")
	assert(numfmt("x12345y") == "x12,345y")
	assert(numfmt("1234 xyz 56789") == "1,234 xyz 56,789")
	assert(numfmt("1234,56789") == "1,234,56,789")
	assert(numfmt("0001234") == "0001,234")
	assert(numfmt("10000000") == "10,000,000")
	assert(numfmt("1234,56789") == "1,234,56,789")
	assert(numfmt("1234567891234567890") == "1234567891234567890")
	assert(numfmt("0123456789123456789") == "0123,456,789,123,456,789")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func numfmt(s string) string {
	w := new(bytes.Buffer)
	for i := 0; i < len(s); i++ {
		switch {
		case !isnat(s[i]):
			w.WriteByte(s[i])

		default:
			j, sep := getnum(s, i)
			writenum(w, s[i:j], sep)
			i = j - 1
		}
	}
	return w.String()
}

func getnum(s string, i int) (j int, sep string) {
	sep = ","
	j = i + 1
	for j < len(s) && isdigit(s[j]) {
		j++
	}

	v, err := strconv.ParseInt(s[i:j], 10, 64)
	if err == nil && v >= 1e18 {
		sep = ""
	}

	return
}

func writenum(w *bytes.Buffer, s, sep string) {
	n := len(s)
	l := (3 - n%3) % 3
	for i := range s {
		w.WriteByte(s[i])
		if l++; l == 3 && i+1 < n {
			w.WriteString(sep)
			l = 0
		}
	}
}

func isnat(c byte) bool {
	return '1' <= c && c <= '9'
}

func isdigit(c byte) bool {
	return '0' <= c && c <= '9'
}
