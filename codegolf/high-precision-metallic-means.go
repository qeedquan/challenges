/*

Background
The metallic means, starting with the famous golden mean, are defined for every natural number (positive integer), and each one is an irrational constant (it has an infinite non-recurring decimal expansion).

For a natural number n, the nth metallic mean is the root of a quadratic equation x^2 - nx = 1

The roots are always

[n +- sqrt(4 + n^2)] / 2

but the metallic mean is usually given as the positive root. So for this question it will be defined by:

[n + sqrt(4 + n^2)] / 2

For n=1 the result is the famous golden ratio:

(1 + sqrt(5)) / 2

Challenge
Your code should take 2 inputs: n and p (the order is not important as long as it is consistent)

n is a natural number indicating which metallic mean
p is a natural number indicating how many decimal places of precision
Your code should output the nth metallic mean to p decimal places precision.

Validity
Your code is valid if it works for values of n and p from 1 to 65,535.

You must output a decimal in the form

digit(s).digit(s) (without spaces)

For example, the golden mean to 9 decimal places is

1.618033988

Display the last digit without rounding, as it would appear in a longer decimal expansion. The next digit in the golden mean is a 7, but the final 8 in the example should not be rounded up to a 9.

The number of decimal digits must be p, which means any trailing zeroes must also be included.

Answers of the form

(1 + sqrt(5)) / 2

are not valid - you must use a decimal expansion.

You may output up to 1 leading newline and up to 1 trailing newline. You may not output any spaces, or any other characters besides digits and the single point/full stop/period.

Score
This is standard code golf: your score is the number of bytes in your code.

*/

package main

import (
	"fmt"
	"math/big"
)

func main() {
	for i := range uint64(11) {
		fmt.Println(i, metallic(i, 9))
	}
}

// https://en.wikipedia.org/wiki/Metallic_mean
func metallic(n uint64, p uint) string {
	var (
		two  = big.NewFloat(2)
		four = big.NewFloat(4)
	)

	r := new(big.Float)
	x := new(big.Float)
	x.SetUint64(n)
	r.SetPrec(p * 10)
	r.Mul(x, x)
	r.Add(r, four)
	r.Sqrt(r)
	r.Add(r, x)
	r.Quo(r, two)

	s := r.Text('f', int(p+1))
	s = s[:len(s)-1]
	return s
}
