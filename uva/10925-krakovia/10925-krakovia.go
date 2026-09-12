package main

import (
	"fmt"
	"math/big"
)

func main() {
	fmt.Println(solve([]string{"5400000000", "5400000000", "5400000000"}, "3"))
	fmt.Println(solve([]string{"5400000000", "5400000000", "9000000001"}, "2"))
}

func solve(items []string, friends string) (string, string) {
	sum := new(big.Int)
	value := new(big.Int)
	for _, item := range items {
		value.SetString(item, 10)
		sum.Add(sum, value)
	}

	divisor := new(big.Int)
	divisor.SetString(friends, 10)

	total := new(big.Int)
	total.Quo(sum, divisor)

	return sum.String(), total.String()
}
