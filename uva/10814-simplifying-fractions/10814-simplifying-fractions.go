package main

import (
	"fmt"
	"math/big"
)

func main() {
	fmt.Println(simplify("1/2"))
	fmt.Println(simplify("2/4"))
	fmt.Println(simplify("3/3"))
	fmt.Println(simplify("4/2"))
}

func simplify(s string) string {
	r := new(big.Rat)
	r.SetString(s)
	return r.String()
}
