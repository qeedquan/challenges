/*

Seeing as there have been an awful lot of normal Fibonacci challenges, I decided that it might be interesting to calculate the Reciprocal Fibonacci constant - namely, the sum of the reciprocals of the Fibonacci sequence.

The challenge is to calculate the Reciprocal Fibonacci constant with the number of Fibonacci series to use digit given as input, i.e. an input of 10 means to calculate based on the reciprocals of the first 10 Fibonacci numbers. In the likely case of a tie, shortest code wins.

The winner will be chosen in three weeks via standard code-golf rules.

*/

package main

import (
	"fmt"
	"math/big"
)

func main() {
	fmt.Println(fibmi(xint(256)))
}

// https://oeis.org/A079586
func fibmi(n *big.Int) *big.Rat {
	one := xint(1)
	r := xrat(0, 1)
	for i := xint(1); i.Cmp(n) < 0; i.Add(i, one) {
		v := new(big.Rat)
		v.SetFrac(one, fib(i))
		r.Add(r, v)
	}
	return r
}

func fib(n *big.Int) *big.Int {
	one := xint(1)
	a := xint(0)
	b := xint(1)
	c := new(big.Int)
	for i := xint(0); i.Cmp(n) < 0; i.Add(i, one) {
		c.Add(a, b)
		a.Set(b)
		b.Set(c)
	}
	return a
}

func xint(x int64) *big.Int {
	return big.NewInt(x)
}

func xrat(n, d int64) *big.Rat {
	return big.NewRat(n, d)
}
