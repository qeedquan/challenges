/*

The prime 41, can be written as the sum of six consecutive primes:

41 = 2 + 3 + 5 + 7 + 11 + 13
This is the longest sum of consecutive primes that adds to a prime below one-hundred.

The longest sum of consecutive primes below one-thousand that adds to a prime, contains 21 terms, and is equal to 953.

Which prime, below one-million, can be written as the sum of the most consecutive primes?

*/

package main

import (
	"fmt"
	"math/big"
)

func main() {
	fmt.Println(consecutive(100))
	fmt.Println(consecutive(1000))
	fmt.Println(consecutive(1000000))
}

func consecutive(n int) int {
	r := 0
	p := genprimes(n)
	l := len(p)
	for c, i := 0, 0; i < l; i++ {
		v := 0
		for j := i; j < l; j++ {
			if v += p[j]; v > n {
				break
			}

			if isprime(v) && j-i > c {
				c, r = j-i, v
			}
		}
	}
	return r
}

func genprimes(n int) []int {
	var r []int
	for i := 2; i <= n; i++ {
		if isprime(i) {
			r = append(r, i)
		}
	}
	return r
}

func isprime(n int) bool {
	x := big.NewInt(int64(n))
	return x.ProbablyPrime(2)
}
