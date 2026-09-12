/*

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);


Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
Example 3:

Input: s = "A", numRows = 1
Output: "A"


Constraints:

1 <= s.length <= 1000
s consists of English letters (lower-case and upper-case), ',' and '.'.
1 <= numRows <= 1000

*/

package main

import "bytes"

func main() {
	assert(convert("PAYPALISHIRING", 3) == "PAHNAPLSIIGYIR")
	assert(convert("PAYPALISHIRING", 4) == "PINALSIGYAHRPI")
	assert(convert("A", 1) == "A")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://redquark.org/leetcode/0006-zigzag-conversion/
func convert(s string, r int) string {
	n := len(s)
	if n == 0 || r < 0 {
		return ""
	}
	if r == 1 {
		return s
	}

	w := new(bytes.Buffer)
	l := 2*r - 2
	for i := 0; i < r; i++ {
		for j := i; j < n; j += l {
			w.WriteByte(s[j])
			p := j + l - 2*i
			if i != 0 && i != r-1 && p < n {
				w.WriteByte(s[p])
			}
		}
	}
	return w.String()
}
