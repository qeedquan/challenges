/*

Compute the sum of two numbers

You cannot use if,while,for, ?:, ||, && etc., or recursion!
Assume it is Int.32
Shortest answer wins

*/

package main

func main() {
	N := int32(10000)
	for a := -N; a <= N; a++ {
		for b := -N; b <= N; b++ {
			assert(add(a, b) == a+b)
		}
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

/*

Ported from @shiona solution

Based on the Kogge-Stone algorithm
https://en.wikipedia.org/wiki/Kogge%E2%80%93Stone_adder

*/

func add(a, b int32) int32 {
	x, y := a&b, a^b
	x, y = shift(1, x, y)
	x, y = shift(2, x, y)
	x, y = shift(4, x, y)
	x, y = shift(8, x, y)
	x, y = shift(16, x, y)
	return a ^ b ^ x<<1
}

func shift(s, x, y int32) (int32, int32) {
	x |= y & (x << s)
	y &= y << s
	return x, y
}
