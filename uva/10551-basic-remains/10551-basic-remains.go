package main

import (
	"math/big"
)

func main() {
	assert(solve(2, "1100", "101") == "10")
	assert(solve(10, "123456789123456789123456789", "1000") == "789")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(b int, p, m string) string {
	x := new(big.Int)
	y := new(big.Int)
	x.SetString(p, b)
	y.SetString(m, b)
	x.Mod(x, y)
	return x.Text(b)
}
