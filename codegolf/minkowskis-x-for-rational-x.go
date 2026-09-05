/*

Here is Minkowski's question mark function:
https://en.wikipedia.org/wiki/Minkowski%27s_question-mark_function
https://en.wikipedia.org/wiki/File:Minkowski_question_mark.svg

It is a strictly increasing and continuous function from the reals to themselves that, among other unusual properties, maps rational numbers to dyadic rationals (those with a power-of-two denominator).
Specifically, suppose the continued fraction representation of a rational number x is [a0;a1,…,an], then

?(x) = a0 + Sum[i=1, n] (-1)^(i+1) / (2^(a1 + a2 ... a_i-1))

For example, 58/27 has continued fraction representation [2;6,1,3], so
?(58/27) = 2 + 1/(2^(6-1)) - 1/(2^(6+1-1)) + 1/(2^(6+1+3-1)) = 2 + 2^-5 - 2^-6 + 2^-9 = 1033 / 2^9

so the pair (1033, 9) should be returned in this case. Similarly for 30/73 with expansion [0;2,2,3,4]:
?(30/73) = 2^-1 - 2^-3 + 2^-6 - 2^-10 = 399 / 2^10

and (399, 10) should be returned here. Note that it does not matter whether the form ending in 1 is used or not.

Task
Given a rational number x, determine ?(x)=a / 2^b as a rational number in lowest terms (so that b is a non-negative integer, as small as possible, and a is odd unless b=0) and output a and b (not 2^b).
x may be taken in any reasonable format, and if you take a pair of integers you may assume the corresponding fraction is in lowest terms.

This is code-golf; fewest bytes wins.

Test cases
x -> a, b
0/1 -> 0, 0
1/1 -> 1, 0
1/2 -> 1, 1
-1/2 -> -1, 1
2/1 -> 2, 0
1/3 -> 1, 2
1/8 -> 1, 7
2/5 -> 3, 3
8/5 -> 13, 3
58/27 -> 1033, 9
30/73 -> 399, 10
144/89 -> 853, 9
-17/77 -> -767, 13
-17/99 -> -133, 12
355/113 -> 12648447, 22
16000/1 -> 16000, 0

*/

package main

import (
	"fmt"
	"math/big"
)

func main() {
	test("0/1", 0, 0)
	test("1/1", 1, 0)
	test("1/2", 1, 1)
	test("-1/2", -1, 1)
	test("2/1", 2, 0)
	test("1/3", 1, 2)
	test("1/8", 1, 7)
	test("2/5", 3, 3)
	test("8/5", 13, 3)
	test("58/27", 1033, 9)
	test("30/73", 399, 10)
	test("144/89", 853, 9)
	test("-17/77", -767, 13)
	test("-17/99", -133, 12)
	test("355/113", 12648447, 22)
	test("16000/1", 16000, 0)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(s string, a, b int64) {
	x := q(xstr(s))
	y := xrat(a, 1<<b)
	fmt.Println(x, y)
	assert(cmp(x, y) == 0)
}

var (
	zero    = xint(0)
	onehalf = xrat(1, 2)
	one     = xint(1)
	two     = xint(2)
)

/*

@Anders Kaseorg

?(x) => 0                           x = 0
        ?(x/(1-x))/2                0 < x <= 1/2
        ceil(x) - ?(ceil(x) - x)    otherwise
*/

func q(x *big.Rat) *big.Rat {
	switch {
	case cmp(zero, x) == 0:
		return zero
	case cmp(zero, x) < 1 && cmp(x, onehalf) < 1:
		return quo(q(quo(x, sub(one, x))), two)
	default:
		y := ceil(x)
		return sub(y, q(sub(y, x)))
	}
}

func xint(x int64) *big.Rat {
	return big.NewRat(x, 1)
}

func xrat(x, y int64) *big.Rat {
	return big.NewRat(x, y)
}

func xstr(s string) *big.Rat {
	z := new(big.Rat)
	z.SetString(s)
	return z
}

func cmp(x, y *big.Rat) int {
	return x.Cmp(y)
}

func ceil(x *big.Rat) *big.Rat {
	if x.IsInt() {
		return x
	}

	t := new(big.Rat)
	t.Add(x, one)

	a := t.Num()
	b := t.Denom()
	a.Quo(a, b)

	z := new(big.Rat)
	z.SetInt(a)

	return z
}

func sub(x, y *big.Rat) *big.Rat {
	z := new(big.Rat)
	z.Sub(x, y)
	return z
}

func quo(x, y *big.Rat) *big.Rat {
	z := new(big.Rat)
	z.Quo(x, y)
	return z
}
