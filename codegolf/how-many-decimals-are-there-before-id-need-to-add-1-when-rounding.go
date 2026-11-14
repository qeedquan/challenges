/*

When you round a number, if the next digit is >= 5 you add 1. For example:

3.1415926535 rounded to 1dp is 3.1
3.1415926535 rounded to 4dp is 3.1416    <-- Note the 5 changed to 6
3.1415926535 rounded to 5dp is 3.14159

3.1415926535 rounded to 9dp is 3.141592654  <-- Note the 3 changed to 4
You challenge is to receive an integer as input and output the number of decimal places before which you would have to round the square root of the number - i.e. the number of decimal places before anumber digit which is >= 5 occurs.

The integer will be between 0 and 100,000 inclusive so for the edge case of 59752 you need to support 17 decimal points (to check the 17th).

If you programming language can't change the number of decimal points, you can display a "?" message to the user.

Example:

Input    Root                     Output

    5 -> 2.23 606797749979     -> 2
   41 -> 6.40312423 743284     -> 8      (Largest gap under 100)
  596 -> 24.4131112314 674     -> 10     (Largest gap under 1000)
59752 -> 244.44222221212112029 -> 16     (Largest gap under 100000)
Do what you want on perfect squares.

This is code-golf so shortest code wins.

For anyone interested, the number 310,617 is the biggest under 1,000,000 and has 18 before you reach a digit >= 5.

*/

package main

import (
	"math/big"
	"strings"
)

func main() {
	assert(index(5) == 2)
	assert(index(41) == 8)
	assert(index(596) == 10)
	assert(index(59752) == 16)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func index(n uint64) int {
	const prec = 10000
	z := new(big.Float)
	z.SetPrec(prec)
	z.SetUint64(n)
	z.Sqrt(z)

	s := z.Text('f', prec)
	i := strings.IndexRune(s, '.')
	if i < 0 {
		return 0
	}
	return strings.IndexAny(s[i+1:], "56789")
}
