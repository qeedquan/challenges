/*

Overview:

From Wikipedia: An Egyptian fraction is the sum of distinct unit fractions. That is, each fraction in the expression has a numerator equal to 1 and a denominator that is a positive integer, and all the denominators differ from each other. The value of an expression of this type is a positive rational number a/b. Every positive rational number can be represented by an Egyptian fraction.

Challenge:

Write the shortest function that will return the values of all the denominators for the smallest set of unit fractions that add up to a given fraction.

Rules/Constraints:

Input will be two positive integer values.
This can be on STDIN, argv, comma separated, space delimited, or any other method you prefer.
The first input value shall be the numerator and the second input value the denominator.
The first input value shall be less than the second.
The output may include a value(s) that exceeds the memory limitations of your system/language (RAM, MAX_INT, or whatever other code/system constraints exist). If this happens, simply truncate the result at the highest possible value and note that somehow (i.e. ...).
The output should be able to handle a denominator value up to at least 2,147,483,647 (231-1, signed 32-bit int).
A higher value (long, etc.) is perfectly acceptable.
The output shall be a listing of all values of denominators of the smallest set of unit fractions found (or the fractions themselves, i.e. 1/2).
The output shall be ordered ascending according to the value of the denominator (descending by the value of the fraction).
The output can be delimited any way you wish, but there must be some character between so as to differentiate one value from the next.
This is code golf, so the shortest solution wins.
Exmaples:

Input 1:

43, 48

Output 1:

2, 3, 16

Input 2:

8/11

Output 2:

1/2 1/6 1/22 1/66

Input 3:

5 121

Output 3:

33 121 363

*/

package main

import (
	"fmt"
	"math"
	"math/big"
)

func main() {
	test(43, 48)
	test(8, 11)
	test(5, 121)

	N := int64(480)
	for a := int64(0); a <= N; a++ {
		for b := int64(a); b <= N; b++ {
			test(a, b)
		}
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a, b int64) {
	x := egyptian(a, b)
	fmt.Println(a, b, x)
	assert(check(a, b, x))
}

func check(a, b int64, x []int64) bool {
	if a < 1 || b < 1 {
		return len(x) == 0
	}

	f0 := big.NewRat(a, b)
	f1 := big.NewRat(0, 1)
	for i := range x {
		f1.Add(f1, big.NewRat(1, x[i]))
	}
	return f0.Cmp(f1) == 0
}

/*

https://en.wikipedia.org/wiki/Egyptian_fraction

Ported from @Keith Randall solution

*/

func egyptian(a, b int64) []int64 {
	r := []int64{}
	if a < 1 || b < 1 {
		return r
	}

	for n := int64(1); n < math.MaxInt64; n++ {
		r = decompose(n, a, b)
		if len(r) > 0 {
			break
		}
	}
	return r
}

func decompose(n, a, b int64) []int64 {
	r := []int64{}
	if a == 0 {
		return r
	}
	if n < 2 {
		if b%a == 0 {
			r = append(r, b/a)
		}
		return r
	}

	for m := (b + a - 1) / a; m < b*n/a; m++ {
		r = decompose(n-1, a*m-b, m*b)
		if len(r) > 0 {
			r = append([]int64{m}, r...)
			break
		}
	}
	return r
}
