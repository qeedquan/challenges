/*

Problem
You've stumbled upon a paradoxical mathematical phenomenon related to prime numbers. Consider the following scenario:

You have an infinite list of prime numbers:
2,3,5,7,11,13,17,19,...

Now, you decide to pair up these prime numbers in a way that each prime is paired with its consecutive prime number and generate fractions by dividing the smaller number of each pair by the larger number. And you start adding them...
2/3+ 3/5 + 5/7 + 7/11 + 11/13 + 13/17...
they seem to be converging!!!??? Your task is to calculate the sum of all fractions in this sequence.

Write a program or function that calculates the sum of these fractions up to a specified number of pairs (n).

Input:
An integer n representing the number of prime pairs to consider (1 ≤ n ≤ 1000).
Output
A floating-point number or The accurate fraction representing the sum of the fractions.

Examples
n=3
2/3 + 3/5 + 5/7=1.980952

Smallest code wins (bytes)

Some test cases
  3 =   1.980952  (208/105)
  7 =   5.122912  (24845332/4849845)
  9 =   6.742102  (21809669044/3234846615)
185 = 179.189745
564 = 556.886274
849 = 841.414962
999 = 991.228537

*/

package main

import (
	"fmt"
	"math"
	"math/big"
)

func main() {
	test(3, 1.980952)
	test(7, 5.122912)
	test(9, 6.742102)
	test(185, 179.189745)
	test(564, 556.886274)
	test(849, 841.414962)
	test(999, 991.228537)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(n int64, r float64) {
	x := sfp(n)
	f, _ := x.Float64()
	fmt.Println(f)
	assert(math.Abs(f-r) < 1e-6)
}

func sfp(n int64) *big.Rat {
	r := big.NewRat(0, 1)
	p := new(big.Rat)
	a := int64(2)
	b := int64(3)
	for i := int64(0); i < n; i++ {
		p.SetFrac64(a, b)
		r.Add(r, p)
		a, b = b, nextprime(b)
	}
	return r
}

func nextprime(n int64) int64 {
	for {
		if n == math.MaxInt64 {
			return -1
		}

		if n++; isprime(n) {
			break
		}
	}
	return n
}

func isprime(n int64) bool {
	x := big.NewInt(n)
	return x.ProbablyPrime(2)
}
