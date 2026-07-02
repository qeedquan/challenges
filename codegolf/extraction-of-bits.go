/*

Your task is to devise a programme that extracts the bits, in order, represented by the first argument based on the set bits represented by the second argument (the mask).

Formal Definition:

Let the first argument x represent the binary string S=(xn)(xn-1)...(x1) with n>=0 and x1 being the least significant digit and xn = 1.

Let the second argument y represent the binary string T=(ym)(ym-1)...(y1) with m>=0 and y1 being the least significant digit and ym = 1.

Let the result represent 0 if x represents 0 or y represents 0.

Let the number of 1 digits in T be p. Let {di}, i in [1, p] be the set of binary strings of the form (dim)(di(m-1))...(d1) defined by (for all i, (for all k, |{dik such that dik = 1}| = 1)) and (if 1 <= i < j <= p then 0 < di < dj) and (dp | dp-1 | ... | d1 = T). In other words, {di} is the ordered set of strings with a single 1 digit that makes up the string T when | is applied.

Let the result of the programme represent the following binary string:

((dp & S) << (p - 1))| ... | ((d2 & S) << 1) | (d1 & S)

Examples:

1111, 110 -> 11
1010, 110 -> 01
1010, 10110 -> 01
1101010111, 11111000 -> 01010
Input and Output:

The two arguments may be taken in any way
The two arguments need not be binary strings. They can also be integers which represent binary strings.
Answers which do not take input representing binary strings of arbitrary length are permitted.
Winning: Shortest code wins.

Clarifications:

If your output gives a bit string, order of bits is not important. Simply state the order in your answer. As stated before, the output of your programme need only represent the bits required.

*/

package main

import (
	"bytes"
	"strings"
)

func main() {
	assert(extract("1111", "110") == "11")
	assert(extract("1010", "110") == "01")
	assert(extract("1010", "10110") == "001")
	assert(extract("1101010111", "11111000") == "01010")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func extract(s, t string) string {
	n, m := len(s), len(t)
	s = zeropad(s, n, m)
	t = zeropad(t, m, n)
	w := new(bytes.Buffer)
	for i := 0; i < n; i++ {
		if t[i] == '1' {
			w.WriteByte(s[i])
		}
	}
	return w.String()
}

func zeropad(s string, n, m int) string {
	if n < m {
		s = strings.Repeat("0", m-n) + s
	}
	return s
}
