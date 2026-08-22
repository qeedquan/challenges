package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(solve(0))
	fmt.Println(solve(1000000))
}

var memo = make(map[int]int)

func solve(n int) int {
	if n < 0 {
		return 0
	}

	if n == 0 {
		return 1
	}

	if r, f := memo[n]; f {
		return r
	}

	x := float64(n)
	a := math.Floor(x - math.Sqrt(x))
	b := math.Floor(math.Log(x))
	c := math.Floor(x * math.Sin(x) * math.Sin(x))
	r := solve(int(a)) + solve(int(b)) + solve(int(c))

	memo[n] = r % 1000000
	return memo[n]
}
