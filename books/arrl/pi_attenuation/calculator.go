package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(resistors(50, 3))
	fmt.Println(resistors(50, 16.62))
}

/*

R1 is connected to 2 R2 parallel shunt resistors

Calculate R1, R2
Given:
Z0 - impedance in ohms
A  - attenuation in db

*/

func resistors(Z0, A float64) (R1, R2 float64) {
	d := math.Pow(10, A/20)
	R1 = Z0 * 0.5 * (d - 1/d)
	R2 = Z0 * (d + 1) / (d - 1)
	return
}
