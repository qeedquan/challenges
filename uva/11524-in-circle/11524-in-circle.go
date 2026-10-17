package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Printf("%.4f\n", solve(140.9500536497, 15.3010457320, 550.3704847907, 464.9681681852, 65.9737378230, 55.0132446384, 10.7791711946))
	fmt.Printf("%.4f\n", solve(208.2835101182, 145.7725891419, 8.8264176452, 7.6610997600, 436.1911036207, 483.6031801012, 140.2797089713))
}

func solve(r, m1, n1, m2, n2, m3, n3 float64) float64 {
	a := n1 * n3
	b := m1 * n3
	c := m3 * m1
	ta := a + b
	tb := b + c
	tc := a + c
	s := (ta + tb + tc) / 2
	area := math.Sqrt(s * (s - ta) * (s - tb) * (s - tc))
	x := r * (ta + tb + tc) / 2 / area
	return area * x * x
}
