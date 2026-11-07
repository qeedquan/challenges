/*

We've had a lot of challenges on differentiation and integration, but none on just solving related rates problems. So in this challenge, you will get a bunch of derivatives (They will be numeric, not in terms of any variables) and have to find another derivative.

The input will come in a newline separated list of equations, in the form dx/dt = 4. There can be decimals and negatives.

The input will end with one differential, the one you will have to find. You can assume there will always be enough information to find it, butt there may also be excess information.

You may also have to consider the derivative of the inverse function, e.g. if you have dy/dx = 3, you also know that dx/dy = 1/3.

Your output will be in the form dy/dt = 6. All the whitespace, etc. has to be the same. Assume all variables are always one letter (They can be uppercase, and they can be d).

This is code-golf, so shortest code in bytes wins!

Test Cases
dy/dx = 4
dx/dt = 5
dy/dt

answer: dy/dt = 20

dy/dx = -3
dt/dx = 3
dy/dt

answer: dy/dt = -1

dA/dt = 4
dA/dC = 2
dC/dr = 6.28
dr/dt

answer: dr/dt = 0.3184713375796178

dx/dy = 7
dx/dt = 0
dy/dt

answer: dy/dt = 0

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	test([]string{
		"dy/dx = 4",
		"dx/dt = 5",
	}, "dy/dt", 20)

	test([]string{
		"dA/dt = 4",
		"dA/dC = 2",
		"dC/dr = 6.28",
	}, "dr/dt", 0.3184713375796178)

	test([]string{
		"dx/dy = 7",
		"dx/dt = 0",
	}, "dy/dt", 0)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(s []string, w string, r float64) {
	v := chain(s, w)
	fmt.Println(v)
	assert(math.Abs(v-r) < 1e-6)
}

type Rate struct {
	a, b string
	v    float64
}

func chain(s []string, w string) float64 {
	return find(mix(rates(s)), w)
}

func rates(s []string) []Rate {
	r := []Rate{}
	for _, s := range s {
		var (
			a, b rune
			v    float64
		)

		n, _ := fmt.Sscanf(s, "d%c/d%c = %f", &a, &b, &v)
		if n == 3 {
			r = append(r, Rate{
				string(a),
				string(b),
				v,
			})
		}
	}
	return r
}

func gen(r []Rate) []Rate {
	p := []Rate{}
	for i := range r {
		x := r[i]
		p = append(p, Rate{x.b, x.a, 1 / x.v})

		for j := range r {
			y := r[j]
			switch {
			case x.b == y.a:
				p = append(p, Rate{x.a, y.b, x.v * y.v})
			case x.a == y.b:
				p = append(p, Rate{x.b, y.a, 1 / (x.v * y.v)})
			}
		}
	}
	return p
}

func mix(r []Rate) []Rate {
	for {
		p := gen(r)
		f := true

	loop:
		for i := range p {
			for j := range r {
				if p[i].a == r[j].a && p[i].b == r[j].b {
					continue loop
				}
			}
			r = append(r, p[i])
			f = false
		}

		if f {
			break
		}
	}
	return r
}

func find(r []Rate, w string) float64 {
	for _, r := range r {
		s := fmt.Sprintf("d%v/d%v", r.a, r.b)
		if s == w {
			return r.v
		}
	}
	return 0
}
