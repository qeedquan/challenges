/*

You have a 30-centimetre ruler. Or is it a 11.8-inch ruler? Or is it even a 9.7-attoparsec ruler?
It means the same thing, of course, but no-one can quite decide which one is the standard.
To help people with this often-frustrating situation you've been tasked with creating a calculator to do the nasty conversion work for you.

Your calculator must be able to convert between metres, inches, miles and attoparsecs.
It must also be able to convert between kilograms, pounds, ounces and hogsheads of Beryllium.

Input Description
You will be given a request in the format: N oldUnits to newUnits

For example:

3 metres to inches
Output Description
If it's possible to convert between the units, print the output as follows:

3 metres is 118.1 inches
If it's not possible to convert between the units, print as follows:

3 metres can't be converted to pounds
Notes
Rather than creating a method to do each separate type of conversion, it's worth storing the ratios between all of the units in a 2-D array or something similar to that.

*/

package main

import (
	"bytes"
	"fmt"
)

func main() {
	fmt.Println(Q(1.2, "yd", 1).As("mm"))
	fmt.Println(Q(3, "m", 1).As("in"))
	fmt.Println(Q(3, "m", 1).As("pd"))

	q1 := Q(2.1, "kg", 1)
	q2 := Q(1, "mi", 1)
	q3 := Q(1, "hr", 2)
	q4 := q1.Mul(q2).Quo(q3)
	fmt.Println(q4.As("N"))
}

// ported from @skeeto solution
type Quantity struct {
	value              float64
	length, mass, time int
}

func (q Quantity) Mul(p Quantity) Quantity {
	return Quantity{
		q.value * p.value,
		q.length + p.length,
		q.mass + p.mass,
		q.time + p.time,
	}
}

func (q Quantity) Quo(p Quantity) Quantity {
	return q.Mul(p.Invert())
}

func (q Quantity) Invert() Quantity {
	return Quantity{
		1.0 / q.value, -q.length, -q.mass, -q.time,
	}
}

func (q Quantity) String() string {
	w := new(bytes.Buffer)
	fmt.Fprintf(w, "%v ", q.value)
	if q.length == 1 {
		fmt.Fprintf(w, "m ")
	} else if q.length != 0 {
		fmt.Fprintf(w, "m^%d ", q.length)
	}
	if q.mass == 1 {
		fmt.Fprintf(w, "kg ")
	} else if q.mass != 0 {
		fmt.Fprintf(w, "kg^%d ", q.mass)
	}
	if q.time == 1 {
		fmt.Fprintf(w, "s ")
	} else if q.time != 0 {
		fmt.Fprintf(w, "s^%d", q.time)
	}
	return w.String()
}

func (q Quantity) As(name string) string {
	u := Q(1, name, 1)
	if q.length != u.length || q.mass != u.mass || q.time != u.time {
		return "<incompatible units>"
	}
	return fmt.Sprintf("%v %v", q.value/u.value, name)
}

func Q(v float64, name string, expt int) Quantity {
	u := name_to_quantity[name]
	return Quantity{
		v * u.value, u.length * expt, u.mass * expt, u.time * expt,
	}
}

var name_to_quantity = map[string]Quantity{
	"m":   Quantity{1, 1, 0, 0},
	"cm":  Quantity{0.01, 1, 0, 0},
	"mm":  Quantity{0.001, 1, 0, 0},
	"in":  Quantity{0.0254, 1, 0, 0},
	"ft":  Quantity{0.3048, 1, 0, 0},
	"yd":  Quantity{0.9144, 1, 0, 0},
	"mi":  Quantity{1609.344, 1, 0, 0},
	"apc": Quantity{0.031, 1, 0, 0},
	"kg":  Quantity{1, 0, 1, 0},
	"lb":  Quantity{0.45359237, 0, 1, 0},
	"s":   Quantity{1, 0, 0, 1},
	"min": Quantity{60, 0, 0, 1},
	"hr":  Quantity{3600, 0, 0, 1},
	"N":   Quantity{1, 1, 1, -2},
}
