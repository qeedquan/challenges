/*

Ohm's law tells us that the current (I) in amps flowing through a resistance (R) in Ohms when a voltage (V) is applied across it is given as follows:

V = I / R
Similarly the power (P) in watts dissipated by that resistance is given by:

P = V * I
By rearrangement and substitution, formulae may be derived for calculating two of these quantities when any of the other two is given. These formulae are summarised as follows (note this image uses E instead of V for volts):

https://i.sstatic.net/1MEBo.png

Given an input of any two of these quantities in a string, output the other two.

Input numbers will be decimals in whatever format is appropriate for your language. Precision should be to at least 3 decimal places. (IEEE 754-2008 binary32 floats are sufficient.)
Each input number will be suffixed with a unit. This will be one of V A W R for Voltage, Amperage, Power and Resistance (or the equivalent lowercase). Additionally, you may use Ω instead of R. The units will not have any decimal prefixes (Kilo-, milli-, etc).
The two input quantities will be given in any order in one string, separated by a single space.
Input quantities will always be real numbers greater than 0.
Output will be in the same format as input.
Equation-solving builtins are disallowed.

Example Inputs
1W 1A
12V 120R
10A 10V
8R 1800W
230V 13A
1.1W 2.333V

Corresponding Outputs
1V 1R
0.1A 1.2W
1R 100W
120V 15A
2990W 17.692R
0.471A 4.948R

It should be noted that solutions to this challenge will effectively be self-inverses. In other words if you apply a solution to input A B and get output C D, then apply a solution to input C D, then the output should be A B again, though possibly out of order and perturbed due to FP rounding. So test inputs and outputs may be used interchangeably.

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	test("1W", "1A")
	test("12V", "120R")
	test("10A", "10V")
	test("8R", "1800W")
	test("230V", "13A")
	test("1.1W", "2.333V")
}

func test(s0, s1 string) {
	r0, r1 := solve(s0, s1)
	fmt.Println(r0, r1)
}

func solve(s0, s1 string) (string, string) {
	v := vars(s0, s1)
	if v == nil {
		return "", ""
	}
	return calc(v)
}

func vars(s0, s1 string) map[byte]float64 {
	var (
		v0, v1 float64
		u0, u1 byte
	)
	n0, _ := fmt.Sscanf(s0, "%f%c", &v0, &u0)
	n1, _ := fmt.Sscanf(s1, "%f%c", &v1, &u1)

	v := map[byte]float64{
		'A': math.NaN(),
		'V': math.NaN(),
		'W': math.NaN(),
		'R': math.NaN(),
	}
	v[u0] = v0
	v[u1] = v1
	if n0 != 2 || n1 != 2 || u0 == u1 || len(v) != 4 {
		return nil
	}
	return v
}

func calc(v map[byte]float64) (string, string) {
	I, E, P, R := v['A'], v['V'], v['W'], v['R']

	sym := "AVWR"
	vals := [][]float64{
		{E / R, P / E, math.Sqrt(P / R)},
		{math.Sqrt(P * R), P / I, I * R},
		{E * I, I * I * R, (E * E) / R},
		{P / (I * I), (E * E) / P, E / I},
	}

	r := []string{}
loop:
	for i := range vals {
		u := sym[i]
		if !math.IsNaN(v[u]) {
			continue
		}

		for _, x := range vals[i] {
			if !math.IsNaN(x) {
				r = append(r, fmt.Sprintf("%.3f%c", x, u))
				continue loop
			}
		}
	}
	if len(r) != 2 {
		return "", ""
	}

	return r[0], r[1]
}
