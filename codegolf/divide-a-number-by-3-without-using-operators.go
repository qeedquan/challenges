/*

Quoting this question on SO (Spoiler alert!):

This question has been asked in an Oracle interview.

How would you divide a number by 3 without using *, /, +, -, %, operators?

The number may be signed or unsigned.

The task is solvable, but see if you can write the shortest code.

Rules:
Perform the required integer division (/3)
Do not use the non-text-based operators *, /, +, -, or % (or their equivalents, such as __div__ or add()). This also applies to incrementing and decrementing operators, like i++ or i--. Use of operators for string concatenation and formatting are OK. Using these characters for different operators, such as unary - operator for negative numbers, or * to represent a pointer in C is OK as well.
Input value can be arbitrarily large (whatever your system can handle), both positive and negative
Input can be on STDIN or ARGV or entered any other way
Create the shortest code you can to do the above

*/

package main

func main() {
	N := 1000000
	for i := -N; i <= N; i++ {
		assert(div3(i) == i/3)
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// ported from @baby-rabbit solution
func div3(n int) int {
	m := 1
	if n < 0 {
		m = 2
	}

	x := add(n, m)
	y := 0
	for x&^3 != 0 {
		y = add(x>>2, y)
		x = add(x>>2, x&3)
	}
	return y
}

func add(a, b int) int {
	for a != 0 {
		a, b = (a&b)<<1, a^b
	}
	return b
}
