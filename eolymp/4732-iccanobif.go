/*

Fibonacci numbers is a sequence of numbers F(n), given by the formula:

F(0)=1, F(1)=1, F(n)=F(n-1)+F(n-2)

Fibonacci number f is given. Find its index n. You must find such index n that F(n)=f.

Input
Fibonacci number f (2 ≤ f ≤ 2*10^9).

Output
Print the index of Fibonacci number f.

Examples
Input #1
2

Answer #1
2

*/

package main

import (
	"math"
	"sort"
)

var (
	SQRT5 = math.Sqrt(5)
	PHI   = (1 + SQRT5) / 2
	PSI   = (1 - SQRT5) / 2
)

func main() {
	assert(solve(2) == 2)
	for i := 2; i <= 50; i++ {
		assert(solve(fib(i)) == i)
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(n int) int {
	if n < 1 {
		return -1
	}

	l := math.Round(math.Log2(float64(n))) + 64
	x := sort.Search(int(l), func(i int) bool {
		return fib(i) >= n
	})

	if fib(x) != n {
		return -1
	}
	return x
}

func fib(n int) int {
	if n < 0 {
		return 0
	}

	p := float64(n + 1)
	r := (math.Pow(PHI, p) - math.Pow(PSI, p)) / SQRT5
	return int(math.Round(r))
}
