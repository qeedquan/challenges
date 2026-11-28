/*

Introduction
We define twin primes as two natural numbers p,p+2 which both are prime.

Example: 5 and 7 are twin primes.

Let's define the twin number of some set of numbers as the number of twin prime numbers in that set

Example: {6,7,11,13,18,29,31} has a twin number 4, since there are four twin primes; 11,13 and 29,31.

Program
Input: A number n

Output: The twin number of the set of all natural numbers below n

Scoring
This is code-golf, so lowest bytes wins.

*/

package main

import (
	"math/big"
)

func main() {
	assert(twins([]int64{5, 7}) == 2)
	assert(twins([]int64{6, 7, 11, 13, 18, 29, 31}) == 4)
	assert(twins([]int64{3, 5, 7}) == 3)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func twins(a []int64) int {
	c := make(map[int64]bool)
	m := set(a)
	for p := range m {
		if m[p] && m[p+2] && isprime(p) && isprime(p+2) {
			c[p], c[p+2] = true, true
		}
	}
	return len(c)
}

func set(a []int64) map[int64]bool {
	m := make(map[int64]bool)
	for _, v := range a {
		m[v] = true
	}
	return m
}

func isprime(n int64) bool {
	x := big.NewInt(n)
	return x.ProbablyPrime(2)
}
