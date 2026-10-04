/*

Let's create a simple, surjective mapping from positive integers to Gaussian integers, which are complex numbers where the real and imaginary parts are integers.

Given a positive integer, for example 4538, express it in binary with no leading 0's:

4538 base 10 = 1000110111010 base 2
Remove any trailing 0's:

100011011101
Replace any runs of one or more 0's with a single +:

1+11+111+1
Replace all 1's with i's:

i+ii+iii+i
Evaluate the resulting complex expression and output the simplified Gaussian integer:

i+ii+iii+i = i+i*i+i*i*i+i = 2i+i^2+i^3 = 2i+(-1)+(-i) = -1+i
The output can be expressed in a traditional mathematical way, or given as two separate integers for the real and complex parts. For the 4538 example, any of these would be fine:

-1+i
i-1
-1+1i
(-1, 1)
-1 1
-1\n1
For inputs like 29, mathy formatted outputs such as 0, 0i, or 0+0i are all fine.

Using j (or something else) instead of i is fine if that is more natural for your language.

The shortest code in bytes wins.

*/

package main

import (
	"fmt"
)

func main() {
	test(4538, -1, 1)
	test(29, 0, 0)
	test(2452, -1, 3)
	test(9999, 1, 0)
	test(862, 0, 1)
	test(24536311, -1, 0)
	test(1023, -1, 0)
	test(7, 0, -1)
	test(42, 0, 3)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(x uint, r, i int) {
	xr, xi := cbn(x)
	fmt.Println(xr, xi)
	assert(xr == r && xi == i)
}

func cbn(x uint) (r, i int) {
	for x != 0 {
		n := trailingones(x)
		if n == 0 {
			x >>= 1
			continue
		}

		x >>= n
		switch n & 3 {
		case 1:
			i++
		case 2:
			r--
		case 3:
			i--
		case 0:
			r++
		}
	}
	return
}

func trailingones(x uint) int {
	c := 0
	for ; x&1 != 0; x >>= 1 {
		c++
	}
	return c
}
