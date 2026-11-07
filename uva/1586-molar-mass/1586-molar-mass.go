package main

import (
	"fmt"
	"math"
)

func main() {
	test("C", 12.010)
	test("C6H5OH", 94.108)
	test("NH2CH2COOH", 75.070)
	test("C12H22O11", 342.296)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(s string, r float64) {
	v := solve(s)
	fmt.Println(v)
	assert(math.Abs(v-r) < 1e-4)
}

func solve(s string) float64 {
	mol := map[byte]float64{
		'C': 12.01,
		'H': 1.008,
		'O': 16.00,
		'N': 14.01,
	}

	r := 0.0
	n := len(s)
	for i := 0; i < n; {
		e := s[i]
		c := 0
		i += 1
		for ; i < n && isdigit(s[i]); i++ {
			c = c*10 + int(s[i]-'0')
		}
		c = max(c, 1)
		r += mol[e] * float64(c)
	}
	return r
}

func isdigit(r byte) bool {
	return '0' <= r && r <= '9'
}
