package main

import (
	"fmt"
	"math/big"
)

func main() {
	assert(add("111", "10") == "1001")
	assert(add("1101", "101") == "10010")
	assert(add("1101", "10111") == "100100")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func add(a, b string) string {
	x := new(big.Int)
	y := new(big.Int)
	x.SetString(a, 2)
	y.SetString(b, 2)
	x.Add(x, y)
	return fmt.Sprintf("%b", x)
}
