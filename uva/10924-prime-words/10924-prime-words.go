package main

import "math/big"

func main() {
	assert(solve("UFRN") == "It is a prime word.")
	assert(solve("contest") == "It is not a prime word.")
	assert(solve("AcM") == "It is not a prime word.")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(s string) string {
	v := int64(0)
	for _, r := range s {
		switch {
		case 'a' <= r && r <= 'z':
			v += int64(r - 'a' + 1)
		case 'A' <= r && r <= 'Z':
			v += int64(r - 'A' + 27)
		}
	}

	x := big.NewInt(v)
	if x.ProbablyPrime(2) {
		return "It is a prime word."
	}
	return "It is not a prime word."
}
