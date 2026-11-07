/*

Goldbach's conjecture is one of the oldest unsolved problems in number theory and in all of mathematics. It states:

Every even integer, greater than 2, can be expressed as the sum of two primes [1].

Your task is to check whether this conjecture holds for integers up to 107.

Input
Input starts with an integer T (≤ 300), denoting the number of test cases.

Each case starts with a line containing an integer n (4 ≤ n ≤ 107, n is even).

Output
For each case, print the case number and the number of ways you can express n as sum of two primes. To be more specific, we want to find the number of (a, b) where:

Both a and b are prime,
a + b = n and
a ≤ b.
Sample
Input	Output
2
6
4

Case 1: 1
Case 2: 1

Notes
[1] An integer is said to be prime, if it is divisible by exactly two different integers. First few primes are {2, 3, 5, 7, 11, 13, ...}.

*/

package main

import (
	"math"
	"math/big"
)

func main() {
	tab := []uint64{
		0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 2, 0, 1, 1, 2, 1, 2, 0, 2, 1, 2, 1, 3, 0,
		3, 1, 3, 0, 2, 0, 3, 1, 2, 1, 4, 0, 4, 0, 2, 1, 3, 0, 4, 1, 3, 1, 4, 0,
		5, 1, 4, 0, 3, 0, 5, 1, 3, 0, 4, 0, 6, 1, 3, 1, 5, 0, 6, 0, 2, 1, 5, 0,
		6, 1, 5, 1, 5, 0, 7, 0, 4, 1, 5, 0, 8, 1, 5, 0, 4, 0, 9, 1, 4, 0, 5, 0,
		7, 0, 3, 1, 6, 0, 8, 1, 5, 1,
	}

	assert(solve(6) == 1)
	assert(solve(4) == 1)

	for i := range tab {
		assert(solve(uint64(i)) == tab[i])
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A061358
func solve(n uint64) uint64 {
	r := uint64(0)
	for _, p := range eratosthenes(n/2 + 1) {
		if isprime(n - p) {
			r += 1
		}
	}
	return r
}

func eratosthenes(n uint64) []uint64 {
	l := uint64(math.Sqrt(float64(n)))
	p := make([]bool, n)
	for i := uint64(2); i <= l; i++ {
		for j := i + i; j < n; j += i {
			p[j] = true
		}
	}

	var r []uint64
	for i := uint64(2); i < n; i++ {
		if !p[i] {
			r = append(r, i)
		}
	}
	return r
}

func isprime(n uint64) bool {
	z := new(big.Int)
	z.SetUint64(n)
	return z.ProbablyPrime(2)
}
