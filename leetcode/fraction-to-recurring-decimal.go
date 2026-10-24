/*

Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

If multiple answers are possible, return any of them.

It is guaranteed that the length of the answer string is less than 10^4 for all the given inputs.

Example 1:

Input: numerator = 1, denominator = 2
Output: "0.5"
Example 2:

Input: numerator = 2, denominator = 1
Output: "2"
Example 3:

Input: numerator = 4, denominator = 333
Output: "0.(012)"


Constraints:

-2^31 <= numerator, denominator <= 2^31 - 1
denominator != 0

*/

package main

import "fmt"

func main() {
	assert(frac2dec(1, 2) == "0.5")
	assert(frac2dec(2, 1) == "2")
	assert(frac2dec(2, 3) == "0.(6)")
	assert(frac2dec(4, 333) == "0.(012)")
	assert(frac2dec(1, 3) == "0.(3)")
	assert(frac2dec(1, 7) == "0.(142857)")
	assert(frac2dec(0, 2) == "0")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func frac2dec(n, d int) string {
	if d == 0 {
		return "NAN"
	}

	s := fmt.Sprint(n / d)
	n = abs(n)
	d = abs(d)
	if n %= d; n != 0 {
		s += "."
	}

	m := make(map[int]int)
	for n != 0 {
		if i, f := m[n]; f {
			s = s[:i] + "(" + s[i:] + ")"
			break
		}
		m[n] = len(s)

		s += fmt.Sprint((n * 10) / d)
		n = (n * 10) % d
	}

	return s
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}
