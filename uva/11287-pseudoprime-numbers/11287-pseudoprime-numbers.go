package main

import (
	"math/big"
)

func main() {
	assert(pseudoprime(3, 2) == "no")
	assert(pseudoprime(10, 3) == "no")
	assert(pseudoprime(341, 2) == "yes")
	assert(pseudoprime(341, 3) == "no")
	assert(pseudoprime(1105, 2) == "yes")
	assert(pseudoprime(1105, 3) == "yes")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func pseudoprime(p, a int64) string {
	P := big.NewInt(p)
	A := big.NewInt(a)
	Z := new(big.Int)
	Z.Exp(A, P, P)
	if P.ProbablyPrime(2) || Z.Cmp(A) != 0 {
		return "no"
	}
	return "yes"
}
