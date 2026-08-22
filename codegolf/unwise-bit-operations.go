/*

I like to golf in dc, but I'm sometimes frustrated because dc doesn't have bitwise operations.

Challenge
Provide four named functions which implement the equivalent of the c bitwise operations &, |, ~ and ^ (bitwise AND, OR, NOT and XOR).
Each function will take two operands (~ takes only one) which are at least 32-bit unsigned integers.
Each function will return an unsigned integer of the same bit-width as the operands.

Restriction
You may only use operations that are supported by dc. These are:

+ - * / Arithmetic addition, subtraction, multiplication and division
~ modulo (or divmod if your language supports it)
^ exponentiation
| modular exponentiation
v square root
> >= == != <= < standard equality/inequality operators
>> << bit shift operators. dc doesn't have these, but since they are trivially implemented in terms of division/multiplication by powers of 2, then I will allow these.
Control structures in dc my be clumsily built using (recursive) macros and (in)equality operations. You may use whatever built-in control structures your language has.

You may also use logical operators && || !, even though these aren't directly available in dc.

You must not use the bitwise operators &, |, ~ and ^ or any functions that trivially implement them.

In addition you must not use built-in base-conversion-of-string operators or functions.

Please also consider providing a test program or online compiler snippet (not included in the golf score) to help verify your answer.

*/

package main

import (
	"math"
)

func main() {
	N := uint(1 << 31)
	for x := uint(0); x <= N; x++ {
		assert(not(x) == ^x)
	}

	N = 1e4
	for x := uint(0); x <= N; x++ {
		for y := uint(0); y <= N; y++ {
			assert(and(x, y) == x&y)
			assert(or(x, y) == x|y)
			assert(xor(x, y) == x^y)
		}
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

/*

https://en.wikipedia.org/wiki/Bitwise_operation

*/

func not(x uint) uint {
	return math.MaxUint - x
}

func and(x, y uint) uint {
	if x < y {
		x, y = y, x
	}
	r := uint(0)
	n := ilog2(x)
	for i := uint(0); i <= n; i++ {
		b := uint(1) << i
		r += b * ((x / b) % 2) * ((y / b) % 2)
	}
	return r
}

func or(x, y uint) uint {
	if x < y {
		x, y = y, x
	}
	r := uint(0)
	n := ilog2(x)
	for i := uint(0); i <= n; i++ {
		b := uint(1) << i
		u := (x / b) % 2
		v := (y / b) % 2
		r += b * ((u + v) - u*v)
	}
	return r
}

func xor(x, y uint) uint {
	if x < y {
		x, y = y, x
	}
	r := uint(0)
	n := ilog2(x)
	for i := uint(0); i <= n; i++ {
		b := uint(1) << i
		r += b * ((x/b + y/b) % 2)
	}
	return r
}

func ilog2(x uint) uint {
	if x == 0 {
		return 0
	}
	return uint(math.Log2(float64(x)))
}
