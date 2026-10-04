package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(solve(0.1))
	fmt.Println(solve(0.2))
	fmt.Println(solve(0.3))
}

func solve(a float64) (x, y, z float64) {
	a2 := a * a
	z = a2 - a2*math.Pi/4
	z -= a2*math.Pi/4 - a2*math.Pi/6 - (a2*math.Pi/6 - a2*math.Sqrt(3)/4)
	y = a2 - a2*math.Pi/4 - 2*z
	x = a2 - 4*y - 4*z
	y *= 4
	z *= 4
	return
}
