/*

In astronomical terms, a syzygy is when 3 or more objects line up in a straight line. The classic example of this is an eclipse (not the IDE, thankfully.) If the Sun, the Moon and the Earth (in that order) line up in a straight line, then the Moon is directly in-between the Sun and the Earth, meaning the view of the Sun is occluded - a solar eclipse. Another example of a syzygy is a transit. This is like an eclipse, but when a planet goes in front of the sun instead; for example, in this image, the big yellow disc is (predictably) the Sun and the circular black spot in the middle is Mercury. It's like a mini-eclipse. Besides these two examples, syzygy can occur without the Sun. The dots in this image here are the planets Mercury, Venus and Jupiter. They do not form a perfect syzygy - the chance of that occurring is next to nothing - but they line up close enough that they're within a few degrees of each other in the sky.

The Wikipedia page for syzygy is here: en.wikipedia.org/wiki/Syzygy_(astronomy)

Today, you'll have two challenges. The first one is to pronounce syzygyfication. The second one will be to determine if a syzygy is occurring at a given time, for a given solar system.

Simplification
This challenge as stated would require a load of mathematics to solve. For this programming challenge, we will assume that the planets orbit the Sun in perfect circles on the same plane, that the Sun does not move at all, and the planets all start off with zero degrees rotation (ie. all in syzygy with each other.)

Formal Inputs and Outputs
Required Data
You will need this data of the Solar system. An AU (astronomical unit) is the distance from the Earth to the Sun. The orbital period is the time it takes for the planet to complete its orbit; a value of eg. 2 means the planet completes an orbit around the Sun every 2 years.

Object	Orbit Radius (AU)	Orbital Period (Earth year)
Sun	0.000	n/a
Mercury	0.387	0.241
Venus	0.723	0.615
Earth	1.000	1.000
Mars	1.524	1.881
Jupiter	5.204	11.862
Saturn	9.582	29.457
Uranus	19.189	84.017
Neptune	30.071	164.795
Input Description
You are to accept a number, which is a number of years after the starting time.

Output Description
You are to output which of the planets, or the Sun, are in syzygy at the given time (in no particular order). For example:

Venus-Sun-Earth syzygy occurring.
A syzygy should be when the objects are within 1 degree of each other in the sky. Remember, syzygy can also occur when the Sun is in-between the two objects. In this case, this is called 'opposition'.

Sample Inputs and Outputs
An example 4-syzygy occurs at 3.30085 years, where Mercury, Earth, Mars and Jupiter line up. A visual example of this is here. Some more syzygy occurrences are:

Time (Earth year)	Syzygy
3.30085	Mercury-Earth-Mars-Jupiter
9.12162	Sun-Mercury-Mars, Mercury-Venus-Saturn
18.0852	Sun-Mars-Saturn, Mercury-Earth-Saturn-Neptune
31.0531	Sun-Earth-Saturn, Venus-Earth-Mars
40.2048	Sun-Venus-Mars, Mercury-Mars-Saturn, Earth-Mars-Uranus
66.2900	Sun-Venus-Earth-Uranus

Extension
If your programming language supports it, draw a view of the Solar system at the given time, to show the objects in syzygy (like the image above.)

*/

package main

import (
	"fmt"
	"math"
)

// ported from @Elite6809 solution
type Vec2 struct {
	x, y float64
}

type Planet struct {
	name   string
	radius float64
	period float64
	omega  float64
}

func main() {
	planets := []Planet{
		{name: "Sun", radius: 0.000, period: 1.000},
		{name: "Mercury", radius: 0.387, period: 0.241},
		{name: "Venus", radius: 0.723, period: 0.615},
		{name: "Earth", radius: 1.000, period: 1.000},
		{name: "Mars", radius: 1.524, period: 1.881},
		{name: "Jupiter", radius: 5.204, period: 11.862},
		{name: "Saturn", radius: 9.582, period: 29.457},
		{name: "Uranus", radius: 19.189, period: 84.017},
		{name: "Neptune", radius: 30.071, period: 164.795},
	}
	omegas(planets)
	syzygy(planets, 3.30085)
	syzygy(planets, 9.12162)
	syzygy(planets, 18.0852)
	syzygy(planets, 31.0531)
	syzygy(planets, 40.2048)
	syzygy(planets, 66.2900)
}

// calculate angular frequency given a time period to work with trig functions
func omegas(p []Planet) {
	for i := range p {
		p[i].omega = 2 * math.Pi / p[i].period
	}
}

// return planet position at time t, using the circle equation
func position(p *Planet, t float64) Vec2 {
	return Vec2{
		p.radius * math.Cos(p.omega*t),
		p.radius * math.Sin(p.omega*t),
	}
}

// calculates shortest distance between two angles
func angle_diff(a, b float64) float64 {
	return math.Abs(math.Mod(b-a+math.Pi, 2*math.Pi) - math.Pi)
}

// calculates angular bearing from one planet to another at time t
func angle_to(p, q *Planet, t float64) float64 {
	P := position(p, t)
	Q := position(q, t)
	return math.Atan((Q.y - P.y) / (Q.x - P.x))
}

// work out if three planets are in syzygy at time t (within an epsilon rad of each other)
func in_syzygy(p, q, r *Planet, t float64) bool {
	const eps = 0.01
	return angle_diff(angle_to(q, p, t), angle_to(q, r, t)) < eps
}

// generate combinations of n choose k
func comb(m, n int, f func([]int)) {
	c := make([]int, n)
	for i := range c {
		c[i] = n - i
	}

	z := []int{}
	for {
		z = z[:0]
		for i := n; i > 0; i-- {
			z = append(z, c[i-1])
		}
		f(z)

		i := 0
		if c[i]++; c[i] <= m {
			continue
		}

		for c[i] >= m-i {
			if i++; i >= n {
				return
			}
		}

		for c[i]++; i > 0; i-- {
			c[i-1] = c[i] + 1
		}
	}
}

// generate all combinations of n choose k and see if there is syzygy between them
func n_syzygy(p []Planet, k int, t float64) {
	f := func(c []int) {
		for i := 0; i+2 < len(c); i++ {
			if !in_syzygy(&p[c[i]-1], &p[c[i+1]-1], &p[c[i+2]-1], t) {
				return
			}
		}

		for _, i := range c {
			fmt.Printf("%s ", p[i-1].name)
		}
		fmt.Println()
	}

	comb(len(p), k, f)
}

// check if there is a syzygy between any [3..n] planets and print it out
func syzygy(p []Planet, t float64) {
	fmt.Printf("T=%f\n", t)
	for k := 3; k <= len(p); k++ {
		n_syzygy(p, k, t)
	}
	fmt.Println()
}
