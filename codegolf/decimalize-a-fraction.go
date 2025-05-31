/*

Preamble
A common pain-point when working with rational numbers and decimals is how infrequently one can represent their rational number as a clean, non-repeating decimal. Let's solve this by writing a program to decimalize (not to be confused with decimate) them for us!

The Challenge
Given a fraction, check if it can be represented perfectly by a finite decimal number. If it can, output the decimal representation of this fraction. Otherwise, output the input fraction.

Specifics
Input will be provided as two integers within the range of [1, 32767] (Positive Signed Shorts), representing both the Numerator and Denominator. Numbers may be taken in any convenient format or order, including built-in Fraction formats, a single pre-divided floating point number (of a precision that can accurately represent all possible fractions), a deliminated string, an imagine number, etc. The Input is not guaranteed to be in simplified form.

A given Input is "Decimalizable" if the Denominator of the Simplified Fraction contains no prime factors other than 2 or 5.

The Output, given a Decimalizable Input, must be a decimal number. This may be as any convenient format, including a string, char array, or float. It may not be a Fraction type. (Floats are allowed as it is generally trivial to stringify.) Trailing Zeroes are not allowed, though leading zeroes are.

Otherwise, The Output must be Two Numbers signifying the Numerator and Denominator, in any convenient format. The output may not be a decimal number, nor a floating point number. Output may optionally be Simplified.

Test Cases
16327 /     4 = 4081.75
  186 /   400 = 0.465
23164 /   100 = 231.64
32604 / 20000 = 1.6302
22764 / 16384 = 1.389404296875
    1 /     3 = 1/3
 3598 /  2261 = 514/323
 7725 / 18529 = 7725/18529
21329 /  3774 = 21329/3774
12213 /  2113 = 12213/2113

Rules

Standard IO Applies
Standard Loopholes Apply

This is code-golf so fewest bytes wins!
Have Fun!

*/

package main

import (
	"fmt"
	"math/big"
	"strings"
)

func main() {
	assert(decimalize("16327/4") == "4081.75")
	assert(decimalize("186/400") == "0.465")
	assert(decimalize("23164/100") == "231.64")
	assert(decimalize("32604/20000") == "1.6302")
	assert(decimalize("22764/16384") == "1.389404296875")
	assert(decimalize("1/3") == "1/3")
	assert(decimalize("3598/2261") == "514/323")
	assert(decimalize("7725/18529") == "7725/18529")
	assert(decimalize("21329/3774") == "21329/3774")
	assert(decimalize("12213/2113") == "12213/2113")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

/*

https://www.onlinemath4all.com/how-to-determine-if-a-fraction-is-terminating-or-repeating.html

Can the denominator be expressed purely as powers of 2 and 5 determines if it is repeating or not.

*/

func decimalize(s string) string {
	var a, b int64
	n, _ := fmt.Sscanf(s, "%d/%d", &a, &b)
	if n != 2 {
		return "invalid fraction"
	}

	if div_2_5(b) == 1 {
		x := big.NewRat(a, b)
		t := x.FloatString(len(s) * 2)
		t = strings.TrimRight(t, "0")
		return t
	}

	g := gcd(a, b)
	return fmt.Sprintf("%d/%d", a/g, b/g)
}

func div_2_5(x int64) int64 {
	for x%2 == 0 {
		x /= 2
	}
	for x%5 == 0 {
		x /= 5
	}
	return x
}

func gcd(a, b int64) int64 {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}
