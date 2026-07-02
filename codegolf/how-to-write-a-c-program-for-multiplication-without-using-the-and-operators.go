/*

Is it possible to write a C program that multiplies two numbers without using the multiplication and addition operators?

I found this on Stack Overflow. Please help this poor programmer with his problem. And please don't give answers like c = a/(1/((float)b)), which is exactly the same as c = a*b. (And is already given as an answer.)

The answer with the most upvotes on January 19th 2014 wins.

Note: This is a code-trolling question. Please do not take the question and/or answers seriously. More information is in code-trolling.

*/

package main

func main() {
	const N = 200
	for x := uint(0); x <= N; x++ {
		for y := uint(0); y <= N; y++ {
			assert(mul(x, y) == x*y)
		}
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func inc(x uint) uint {
	if x&1 != 0 {
		return inc(x>>1) << 1
	}
	return x | 1
}

func dec(x uint) uint {
	if x&1 != 0 {
		return x ^ 1
	}
	return dec(x>>1)<<1 | 1
}

func add(x, y uint) uint {
	if x != 0 {
		return add(dec(x), inc(y))
	}
	return y
}

// ported from @Oberon solution
func mul(x, y uint) uint {
	if x == 0 {
		return 0
	}
	if x^1 != 0 {
		return add(y, mul(dec(x), y))
	}
	return y
}
