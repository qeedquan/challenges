/*

JavaScript numbers have only enough storage space to represent 53 bit sized integers. This means any integer smaller than -2^53 and any integer larger than 2^53 might be rounded incorrectly. For example:

9007199254740993 === 9007199254740992 //true

Your task is to create a function which will return the sum of two given integers only when you are certain that the sum is correct. So, as long as the integers and their sum are never larger than 53 bits in magnitude, you must return the sum of the two given integers.

Anytime an integer with a magnitude larger than 53 bits is used your function must return false.

a and b will always be integers, but they may be larger than 53 bits.

*/

package main

func main() {
	assert(certainsum(7, 20) == int64(27))
	assert(certainsum(2, 2) == int64(4))
	assert(certainsum(22, -3) == int64(19))
	assert(certainsum(9007199254740993, -999) == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func certainsum(a, b int64) any {
	const limit = 1 << 53
	if !in(a, limit) || !in(b, limit) || !in(a+b, limit) {
		return false
	}
	return a + b
}

func in(x, n int64) bool {
	return -n <= x && x <= n
}
