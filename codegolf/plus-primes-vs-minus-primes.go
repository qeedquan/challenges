/*

Most of us know...
that all primes p>3 are of the form enter image description here

But, how many are the Plus Primes (6n+1) and how many are the Minus Primes (6n-1) in a certain range?

The Challenge
Given an integer k>5 , count how many primes<=k are PlusPrimes and how many are MinusPrimes.

Examples
for k=100 we have
[5, 11, 17, 23, 29, 41, 47, 53, 59, 71, 83, 89] 12 MinusPrimes
and
[7, 13, 19, 31, 37, 43, 61, 67, 73, 79, 97] 11 PlusPrimes

for k=149 we have
[5, 11, 17, 23, 29, 41, 47, 53, 59, 71, 83, 89, 101, 107, 113, 131, 137, 149]
18 MinusPrimes
and
[7, 13, 19, 31, 37, 43, 61, 67, 73, 79, 97, 103, 109, 127, 139]
15 PlusPrimes

Rules
Your code must output 2 integers: one for the MinusPrimes and one for the PlusPrimes in any order you like (please specify which is which).
This is code-golf: shortest answer in bytes wins!

Test Cases
Input -> Output [MinusPrimes,PlusPrimes]

6->[1,0]
7->[1,1]
86->[11,10]
986->[86,78]
5252->[351,344]
100000->[4806,4784]
4000000->[141696, 141448]

*/

package main

import (
	"fmt"
	"math/big"
)

func main() {
	test(100, 12, 11)
	test(149, 18, 15)
	test(6, 1, 0)
	test(7, 1, 1)
	test(86, 11, 10)
	test(986, 86, 78)
	test(5252, 351, 344)
	test(100000, 4806, 4784)
	test(4000000, 141696, 141448)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(n, rm, rp int64) {
	m, p := pmprimes(n)
	fmt.Println(m, p)
	assert(m == rm)
	assert(p == rp)
}

func pmprimes(n int64) (m, p int64) {
	for i := int64(0); i <= n/6+1; i++ {
		x := 6*i + 1
		y := 6*i - 1
		if x <= n && isprime(x) {
			p += 1
		}
		if y <= n && isprime(y) {
			m += 1
		}
	}
	return
}

func isprime(n int64) bool {
	x := big.NewInt(n)
	return x.ProbablyPrime(2)
}
