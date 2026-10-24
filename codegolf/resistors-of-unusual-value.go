/*

Introduction
When building an electronics project, a schematic may call for a resistor of an unusual value (say, 510 ohms). You check your parts bin and find that you have no 510-ohm resistors. But you do have many common values above and below this value. By combining resistors in parallel and series, you should be able to approximate the 510-ohm resistor fairly well.

Task
You must write a function or program which accepts a list of resistor values (resistors you stock) and a target value (which you aim to approximate). The program must consider:

Individual resistors
Two resistors in series
Two resistors in parallel
The program should compute all possible combinations of 1 and 2 resistors from the stock list (including two copies of the same resistor value), compute their series and parallel resistance, then sort the configurations according to how well they approximate the target value.

The output format should be one configuration per line, with a + denoting series and | denoting parallel, and some space or an = sign before the net resistance.

Formulas
The resistance of one resistor is R1
The net resistance of two resistors in series is R1 + R2
The net resistance of two resistors in parallel is 1 / (1/R1 + 1/R2)
The distance between an approximated resistance value and the target value can be calculated as pseudo-logarithmic distance, not linear distance: dist = abs(Rapprox / Rtarget - 1). For example, 200 is closer to 350 than it is to 100.
A better distance measure is true logarithmic distance dist = abs(log(Rapprox/Rtarget)), but since this was not specified in the original question, you are free to use either measurement.
Scoring
Score is measured in characters of code, per usual golf rules. Lowest score wins.

Example
We have the following resistors in stock [100, 150, 220, 330, 470, 680, 1000, 1500, 2200, 3300, 4700] and wish to target 510 ohms. The program should output 143 configurations, approximately as shown (you can change the format, but make sure the meaning is easily determined):

680 | 2200     519.444
1000 | 1000    500.
150 + 330      480.
220 + 330      550.
470            470
680 | 1500     467.89
680 | 3300     563.819
100 + 470      570.
220 + 220      440.
100 + 330      430.
470 | 4700     427.273
680 | 4700     594.052
1000 | 1500    600.
470 | 3300     411.406
680 | 1000     404.762
150 + 470      620.
...
many more rows
...
2200 + 4700    6900.
3300 + 4700    8000.
4700 + 4700    9400.
In this example, the best approximation of 510 ohms is given by 680- and 2200-ohm resistors in parallel.

*/

package main

import (
	"fmt"
	"math"
	"sort"
)

func main() {
	r := gen([]float64{100, 150, 220, 330, 470, 680, 1000, 1500, 2200, 3300, 4700}, 510)
	dump(r)
}

func gen(v []float64, t float64) []resistance {
	r := []resistance{}
	n := len(v)
	for i := 0; i < n; i++ {
		r = append(r, resistance{op: 'u', r1: v[i], value: v[i]})
		for j := i; j < n; j++ {
			r = append(r, resistance{op: '+', r1: v[i], r2: v[j], value: v[i] + v[j]})
			r = append(r, resistance{op: '|', r1: v[i], r2: v[j], value: 1 / (1/v[i] + 1/v[j])})
		}
	}

	sort.Slice(r, func(i, j int) bool {
		d1 := math.Abs(math.Log(r[i].value / t))
		d2 := math.Abs(math.Log(r[j].value / t))
		return d1 < d2
	})

	return r
}

func dump(r []resistance) {
	for _, r := range r {
		switch r.op {
		case 'u':
			fmt.Printf("%4.0f        = %.3f\n", r.r1, r.value)
		default:
			fmt.Printf("%4.0f %c %4.0f = %.3f\n", r.r1, r.op, r.r2, r.value)
		}
	}
}

type resistance struct {
	op     rune
	r1, r2 float64
	value  float64
}
