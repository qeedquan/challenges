/*

This is a fairly simple code golf challenge. Your program, given an ASCII string, is to parse that string into two strings, which it will evaluate.
If the second string is "later" than the first one, it will return a 1, if it is "earlier" than the first one, it will return a -1, and if they are the same, it will return 0.
To clarify what "later" and "earlier" mean, let's take a look at ASCII character codes. You need to compare each character of the string, treating each of them as digits of a number.
Later refers to a larger number, occurring after a smaller number. Strings will be formatted with a hyphen character to separate the two input groups.

Take a look at this example:

7-9 as an input should return 1.

7 converts to ASCII code 55, and 9 converts to ASCII code 57.

As 57 occurs numerically after 55, 9 is later than 7.

Another example:

LKzb-LKaj as an input should return -1

The ASCII code sequences for this are 76-75-122-98 and 76-75-97-106

This is a code golf challenge, and byte count is how entries will be scored.

Any input from the 95 printable ASCII characters is accepted, excluding spaces, and hyphens for anything but separating the input. In addition, strings are not guaranteed to be the same length.

Good luck!

EDIT: To be more clear, each character is to be treated like a digit in a number.
In the example LKzb-LKaj, though j is later than b, z is later than a, and since it is a more significant digit, it takes precedence.
A string supplied will always be at minimum 3 characters, eliminating empty strings from the scope of this problem.

EDIT: Here are some more test cases, for your help:

A-9 -> -1
11-Z -> -1
3h~J*-3h~J* -> 0
Xv-Y0 -> 1

*/

package main

import (
	"strings"
)

func main() {
	assert(cmp("7-9") == 1)
	assert(cmp("LKzb-LKaj") == -1)
	assert(cmp("A-9") == -1)
	assert(cmp("11-Z") == -1)
	assert(cmp("3h~J*-3h~J*") == 0)
	assert(cmp("Xv-Y0") == 1)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func cmp(s string) int {
	i := strings.IndexByte(s, '-')
	x := s
	y := ""
	if i >= 0 {
		x, y = s[:i], s[i+1:]
	}

	n := len(y) - len(x)
	switch {
	case n < 0:
		return -1
	case n > 0:
		return 1
	}
	return strings.Compare(y, x)
}
