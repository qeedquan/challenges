/*

Let's suppose there is a finite unknown number n (n can be very large, does not necessarily fit 64-bits; think of BigInteger in Java or long in Python) and a function cmp(x) that returns true if x <= n.

Write a program to determine n in minimum number of calls to cmp.

*/

package main

import (
	"fmt"
	"math/big"
	"math/rand"
	"time"
)

func main() {
	for i := uint(0); i <= 1e4; i++ {
		fmt.Println(i, mincmp(randint(i)))
	}
}

func mincmp(x *big.Int) *big.Int {
	var (
		one = big.NewInt(1)
	)

	r := big.NewInt(0)
	h := big.NewInt(0)
	i := big.NewInt(0)
	j := big.NewInt(1)
	j.Lsh(j, uint(x.BitLen()))
	for i.Cmp(j) < 0 {
		h.Add(i, j)
		h.Rsh(h, 1)
		if h.Cmp(x) < 0 {
			i.Add(h, one)
		} else {
			j.Set(h)
		}
		r.Add(r, one)
	}
	return r
}

func randint(bits uint) *big.Int {
	t := time.Now()
	u := rand.NewSource(t.UnixNano())
	r := rand.New(u)

	l := big.NewInt(1)
	l.Lsh(l, bits)

	z := new(big.Int)
	z.Rand(r, l)
	return z
}
