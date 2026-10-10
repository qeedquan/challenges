/*

Description

The cows are trying to find their roots. They are not so smart as humans when they find square roots, the cows lose the integer portion of their square root calculation. Thus, instead of calculating the square root of 2 to be 1.4142135623730950488016887242096980785696, they deduce that it is 0.4142135623730950488016887242096980785696. The square root of 16 is calculated to be 0 (obviously an error).

The erroneous ciphering does, however, lead to an interesting question. Given a string of digits of length L (1 <= L <= 9), what is the smallest integer whose bovine square root decimal part begins with those digits?

By way of example, consider the string "123". The square root of 17 is approximately 4.1231056256176605498214098559740770251472 so the bovine square root is: 0.1231056256176605498214098559740770251472 whose decimal part (just after the period) starts with 123. It turns out that 17 is the smallest integer with this property.
Input

Line 1: A single integer, L

Line 2: L digits (with no spaces)
Output

Line 1: A single integer that is the smallest integer whose bovine square root starts with the supplied string
Sample Input

3
123
Sample Output

17

Hint

Be careful of floating point arithmetic. It engenders rounding errors that can be surprising.

Explanation of the sample:

sqrt(17) ~= 4.1231056256176605498214098559740770251472

Source

USACO 2005 December Bronze

*/

package main

import (
	"math"
	"math/big"
	"strings"
)

func main() {
	assert(bovineroot("414213562373095048801688724209698078569") == 2)
	assert(bovineroot("123") == 17)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func bovineroot(s string) int64 {
	n := 10 * len(s)
	z := new(big.Float)
	z.SetPrec(uint(n))
	for i := int64(0); i < math.MaxInt64; i++ {
		z.SetInt64(i)
		z.Sqrt(z)

		t := z.Text('f', n)
		if strings.HasPrefix(t[2:], s) {
			return i
		}
	}
	return -1
}
