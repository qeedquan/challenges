/*

In elementary school, children learn about proper fractions, where the numerator is less than the denominator, and thus the value of the fraction is less than one. Later, they are taught about fractions where the value of the fraction is greater than one, and two different ways to express these fractions: mixed fractions and improper fractions.

Given a mixed fraction, determine if it is equivalent to the improper fraction where the integer value and the numerator are concatenated together. For example, for input 1 3/4, the improper fraction is 13/4.

Test Cases
1 3/4        -> falsey
1 3/10       -> truthy
6 6/7        -> falsey
55 55/100    -> truthy
4 9/100      -> falsey
40 9/100     -> falsey
7 49/1000    -> falsey
9 1/2        -> falsey
999 999/1000 -> truthy
1 21/200     -> falsey
1 21/101     -> falsey
For input, you may take the integer part and the fraction part as separate inputs, but you may not take the fraction as input in two pieces, and you may not take it as a decimal value. You may drop the integer part (not take it as input) if you do not need to use it.

*/

package main

import (
	"math/big"
)

func main() {
	assert(equal("1", "3/4") == false)
	assert(equal("1", "3/10") == true)
	assert(equal("6", "6/7") == false)
	assert(equal("55", "55/100") == true)
	assert(equal("4", "9/100") == false)
	assert(equal("40", "9/100") == false)
	assert(equal("7", "49/1000") == false)
	assert(equal("9", "1/2") == false)
	assert(equal("999", "999/1000") == true)
	assert(equal("1", "21/200") == false)
	assert(equal("1", "21/101") == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func equal(i, f string) bool {
	x := xadd(xrat(i), xrat(f))
	y := xrat(i + f)
	return x.Cmp(y) == 0
}

func xrat(s string) *big.Rat {
	x := new(big.Rat)
	x.SetString(s)
	return x
}

func xadd(x, y *big.Rat) *big.Rat {
	z := new(big.Rat)
	z.Add(x, y)
	return z
}
