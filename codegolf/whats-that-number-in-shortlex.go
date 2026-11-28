/*

Most computers store integers in binary, but output them in decimal. However, decimal is just one representation, we just happen to find it convenient.

This challenge is to write some code to output an integer value in shortlex decimal.

What's that?
http://en.wikipedia.org/wiki/Shortlex_order

Shortlex takes the length of the sequence of digits as the primary signifier of value. The sequence, starting from an empty string representing zero, is...

ε,0,1,...,8,9,00,01,...98,99,000,001,...,998,999,0000,...
(Think of Excel columns, but using only the decimal digits.)

Write a program or function that accepts an integer and returns a string corresponding to the shortlex-decimal representation of that integer as described above.

Test values:

0 → "" (Empty string)
1 → "0"
10 → "9"
11 → "00"
42 → "31"
100 → "89"
800 → "689"
1060 → "949"
10270 → "9159"
100501 → "89390"

*/

package main

import "fmt"

func main() {
	assert(shortlex(0) == "")
	assert(shortlex(1) == "0")
	assert(shortlex(10) == "9")
	assert(shortlex(11) == "00")
	assert(shortlex(42) == "31")
	assert(shortlex(100) == "89")
	assert(shortlex(800) == "689")
	assert(shortlex(1060) == "949")
	assert(shortlex(10270) == "9159")
	assert(shortlex(100501) == "89390")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func shortlex(n int) string {
	if n < 1 {
		return ""
	}
	return shortlex((n-1)/10) + fmt.Sprint((n-1)%10)
}
