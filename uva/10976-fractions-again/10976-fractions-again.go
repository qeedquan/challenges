package main

import (
	"fmt"
	"math/big"
	"reflect"
)

func main() {
	test(2, []string{
		"1/2 = 1/6 + 1/3",
		"1/2 = 1/4 + 1/4",
	})
	test(12, []string{
		"1/12 = 1/156 + 1/13",
		"1/12 = 1/84 + 1/14",
		"1/12 = 1/60 + 1/15",
		"1/12 = 1/48 + 1/16",
		"1/12 = 1/36 + 1/18",
		"1/12 = 1/30 + 1/20",
		"1/12 = 1/28 + 1/21",
		"1/12 = 1/24 + 1/24",
	})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(k int64, r []string) {
	p := pairs(k)
	fmt.Println(len(p))
	for _, s := range p {
		fmt.Println(s)
	}
	fmt.Println()
	assert(reflect.DeepEqual(p, r))
}

func pairs(k int64) []string {
	one := big.NewInt(1)

	p := []string{}
	K := big.NewRat(1, k)
	X := new(big.Rat)
	for y := int64(1); y <= 2*k; y++ {
		Y := big.NewRat(1, y)
		X.Sub(K, Y)

		N1 := X.Num()
		D1 := X.Denom()
		D2 := Y.Denom()
		if N1.Cmp(one) == 0 && D1.Cmp(D2) >= 0 {
			p = append(p, fmt.Sprintf("1/%v = 1/%v + 1/%v", k, D1, D2))
		}
	}
	return p
}
