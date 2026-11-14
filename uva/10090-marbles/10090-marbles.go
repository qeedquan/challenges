package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(solve(43, 1, 3, 2, 4))
	fmt.Println(solve(40, 5, 9, 5, 12))
}

func solve(v, c1, n1, c2, n2 int64) (int64, int64) {
	x, y, d := exgcd(n1, n2)
	if v%d != 0 {
		return -1, -1
	}

	x *= v / d
	y *= v / d
	n2 /= d
	n1 /= d
	l := int64(math.Ceil(float64(-x) / float64(n2)))
	u := int64(math.Floor(float64(y) / float64(n1)))
	if l <= u {
		r1 := c1*(x+n2*l) + c2*(y-n1*l)
		r2 := c1*(x+n2*u) + c2*(y-n1*u)
		if r1 < r2 {
			return x + n2*l, y - n1*l
		}
		return x + n2*u, y - n1*u
	}

	return -1, -1
}

func exgcd(a, b int64) (int64, int64, int64) {
	if b == 0 {
		return 1, 0, a
	}

	x, y, d := exgcd(b, a%b)
	return y, x - (a/b)*y, d
}
