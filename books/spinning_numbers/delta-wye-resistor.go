/*

https://eng.libretexts.org/Bookshelves/Electrical_Engineering/Electronics/Book%3A_AC_Electrical_Circuit_Analysis%3A_A_Practical_Approach_(Fiore)/05%3A_Analysis_Theorems_and_Techniques/5.6%3A_Delta-Y_(Pi-T)_Conversions

Note:
The transform only makes it that 3 resistor circuits in some series/parallel configuration from the Delta network is equivalent to 2 series resistor circuits in the Y network.
3 resistor circuits in the Delta network does *NOT* form a 3 resistor circuit in the Y network using any combination (can test this by iterating all series/parallel permutations for Delta and Y network and see the values get: they don't match)

Can visualize this by visualizing the current movement to the circuit, from any configuration XY to XZ, there is no way for the current to traverse through all 3 resistor circuits in the Y network

*/

package main

import (
	"fmt"
)

func main() {
	RA, RB, RC := 4653.0, 54.0, 3.045
	R1, R2, R3 := d2y(RA, RB, RC)

	RXY_1 := parallel(RC, series(RA, RB))
	RXY_2 := series(R1, R2)
	fmt.Println("RXY", RXY_1, RXY_2)

	RXZ_1 := parallel(RB, series(RA, RC))
	RXZ_2 := series(R1, R3)
	fmt.Println("RXZ", RXZ_1, RXZ_2)

	RZY_1 := parallel(RA, series(RB, RC))
	RZY_2 := series(R3, R2)
	fmt.Println("RZY", RZY_1, RZY_2)
}

func series(R ...float64) float64 {
	v := 0.0
	for i := range R {
		v += R[i]
	}
	return v
}

func parallel(R ...float64) float64 {
	v := 0.0
	for i := range R {
		v += 1 / R[i]
	}
	return 1 / v
}

func d2y(RA, RB, RC float64) (R1, R2, R3 float64) {
	RS := RA + RB + RC
	R1 = (RB * RC) / RS
	R2 = (RA * RC) / RS
	R3 = (RA * RB) / RS
	return
}

func y2d(R1, R2, R3 float64) (RA, RB, RC float64) {
	RS := R1*R2 + R2*R3 + R3*R1
	RA = RS / R1
	RB = RS / R2
	RC = RS / R3
	return
}
