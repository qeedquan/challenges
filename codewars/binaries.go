/*

Let us take a string composed of decimal digits: "10111213". We want to code this string as a string of 0 and 1 and after that be able to decode it.

To code we decompose the given string in its decimal digits (in the above example: 1 0 1 1 1 2 1 3) and we will code each digit.

Coding process to code a number n expressed in base 10:
For each digit d of n

a) Let k be the number of bits of d

b) Write k-1 times the digit 0 followed by the digit 1

c) Write digit d as a binary string, with the rightmost bit being the least significant

d) Concat the result of b) and c) to get the coding of d

At last concatenate all the results got for the digits of n.

An example
So we code 0 as 10, 1 as 11, 2 as 0110, 3 as 0111 ... etc...

With the given process, the initial string "10111213" becomes: "11101111110110110111" resulting of concatenation of 11 10 11 11 11 0110 11 0111.

Task:
Given strng a string of digits representing a decimal number the function code(strng) should return the coding of strng as explained above.

Given a string strng resulting from the previous coding, decode it to get the corresponding decimal string.

Examples:
code("77338855") --> "001111001111011101110001100000011000001101001101"
code("77338")  --> "0011110011110111011100011000"
code("0011121314") --> "1010111111011011011111001100"

decode("001111001111011101110001100000011000001101001101") -> "77338855"
decode("0011110011110111011100011000") -> "77338"
decode("1010111111011011011111001100") -> "0011121314"
Notes
SHELL: The only tested function is decode.
Please could you ask before translating.

*/

package main

import (
	"bytes"
	"fmt"
	"io"
	"math/bits"
	"strconv"
	"strings"
)

func main() {
	test("10111213", "11101111110110110111")
	test("77338855", "001111001111011101110001100000011000001101001101")
	test("77338", "0011110011110111011100011000")
	test("0011121314", "1010111111011011011111001100")
}

func test(d, e string) {
	E := encode(d)
	D, err := decode(e)
	assert(err == nil)
	assert(e == E)
	assert(d == D)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func encode(s string) string {
	w := new(bytes.Buffer)
	for _, r := range s {
		d := uint(r - '0')
		k := bits.UintSize - bits.LeadingZeros(d)
		fmt.Fprintf(w, "%s1%b", repeat("0", k-1), d)
	}
	return w.String()
}

func decode(s string) (string, error) {
	w := new(bytes.Buffer)
	n := len(s)
	for i := 0; i < n; {
		j := strings.IndexByte(s[i:], '1')
		if j < 0 {
			return "", io.ErrUnexpectedEOF
		}
		i += j + 1

		n, err := strconv.ParseInt(s[i:i+j+1], 2, 64)
		if err != nil {
			return "", err
		}

		fmt.Fprint(w, n)
		i += j + 1
	}
	return w.String(), nil
}

func repeat(s string, n int) string {
	if n < 1 {
		return ""
	}
	return strings.Repeat(s, n)
}
