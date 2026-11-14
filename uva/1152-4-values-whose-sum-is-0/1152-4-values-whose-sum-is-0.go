package main

import (
	"math/rand"
)

func main() {
	assert(solve(
		[]int{-45, -41, -36, -36, 26, -32},
		[]int{22, -27, 53, 30, -38, -54},
		[]int{42, 56, -37, -75, -10, -6},
		[]int{-16, 30, 77, -46, 62, 45},
	) == 5)

	limit := 268435456
	low := -limit
	high := limit
	for n := range 100 {
		a := make([]int, n)
		b := make([]int, n)
		c := make([]int, n)
		d := make([]int, n)
		for i := range n {
			a[i] = rand.Intn(high-low) + low
			b[i] = rand.Intn(high-low) + low
			c[i] = rand.Intn(high-low) + low
			d[i] = rand.Intn(high-low) + low
		}

		assert(solve(a, b, c, d) == solvebf(a, b, c, d))
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(a, b, c, d []int) int {
	h := make(map[int]int)
	for _, x := range a {
		for _, y := range b {
			h[x+y] += 1
		}
	}

	r := 0
	for _, x := range c {
		for _, y := range d {
			r += h[-x-y]
		}
	}
	return r
}

func solvebf(a, b, c, d []int) int {
	r := 0
	for _, x := range a {
		for _, y := range b {
			for _, z := range c {
				for _, w := range d {
					if x+y+z+w == 0 {
						r += 1
					}
				}
			}
		}
	}
	return r
}
