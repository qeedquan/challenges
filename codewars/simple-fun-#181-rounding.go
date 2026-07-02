/*

Task
Round the given number n to the nearest multiple of m.

If n is exactly in the middle of 2 multiples of m, return n instead.

Example
For n = 20, m = 3, the output should be 21.

For n = 19, m = 3, the output should be 18.

For n = 50, m = 100, the output should be 50.

Input/Output
[input] integer n
1 ≤ n < 10^9.

[input] integer m
3 ≤ m < 10^9.

[output] an integer

*/

package main

func main() {
	assert(rounding(20, 3) == 21)
	assert(rounding(19, 3) == 18)
	assert(rounding(1, 10) == 0)
	assert(rounding(50, 100) == 50)
	assert(rounding(123, 456) == 0)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func rounding(n, m int) int {
	l := n - (n % m)
	u := l + m
	if n-l == u-n {
		return n
	}
	if n-l < u-n {
		return l
	}
	return u
}
