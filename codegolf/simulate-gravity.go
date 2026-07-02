/*

Given the effort to coolness ratio, I'm pretty surprised there wasn't a question on here for this already. The task for this question is to simulate n-body gravity!

Simple? I thought the n-body problem was famously unsolved!
Yeah, yeah; whatever. There's (provably) no analytic equation, but gravity really just follows one simple rule:

F = (G*m1*m2) / r^2

That's it. There's no big gatchas until you start dealing with relativity, and relativity puts gatchas on everything.
We're actually going to simplify our simulation even more, and say all our masses are one kg, and exist in a magical world
where the gravitational constant G is 1 m^3 / (kg*s^2), so the equation you're going to simulate is

r'[i] = Sum[j != i, normalize(r_ij) / length(r_ij)^2 ] for all i

"Gah," I hear you cry. "You tricked me, what are all these extra symbols you've added! There's dots and sums and hats and bars! And your A's upside down, the pointy bit goes up!"

Don't Panic!
Mathematicians love code golf too, most of these symbols are just fancy loops. We'll go one step at a time, from the outside in.
The upside down A is the closest you get to an actual for loop in math, and it means that this whole equation individually applies to each of our bodies,
represented by a variable i. It's basically equivalent to for i in bodies.

The double dot is a little more tricky. In math terms, it's called 'the second derivative in time', but we don't need to overcomplicate things.
A derivative (in time) is a fancy way to say "the amount something changes (per second)," so the double dot is the change of the change of each radius.
Our pseudocode now looks like this:

for i in bodies {
    v[i] += equation(i)
    r[i] += v[i]
}

(for the math buffs that just started complaining, see this video for why we update velocity first)

The next piece is the summation.
This is also a for loop, except you add up all the terms and return the result.
The thing on the bottom defines which values we're adding up.
This means equation is now sum(fraction(i,j) for j in bodies if j != i).

Almost there! The ij subscript means the vector pointing from ri to rj, which you find by taking a vector(index-by-index) difference:
rij == r[j] - r[i] == [rj[1]-ri[1]; rj[2]-ri[2]; rj[3]-ri[3]].
The bars mean finding the magnitude, which you do by taking the square root of the sum of the squares of the components.
In code that's rij_mag = sqrt(rij[1]^2 + rij[2]^2 + rij[3]^2).
The hat, which means normalizing a vector, is found by dividing the magnitude; but we're already doing that (twice)!
Dividing it out one more time is the same as incrementing the exponent to a ^3.

Putting that all together, our pseudocode is:

for i in range(num_bodies) {
    v[i] += sum(
        (r[j]-r[i]) / sqrt(
            ( r[j][1]-r[i][1] )^2 + ( r[j][2]-r[i][2] )^2 + ( r[j][3]-r[i][3] )^2
        )^3
        for j in range(num_bodies)
        if j != i
    )
    r[i] += v[i]
}
Requirements
Your task for this code-golf challenge is to simulate one second of gravity.
That is, your code should do the equivalent of running the above for loop once.
You will be given n bodies, where each body has a velocity and position. You may take these 6n numbers however you like,
but you should return the updated 6n numbers in the same way. (ie, your code should accept its own output as a new input).

You can assume that two bodies will never perfectly overlap (so there's no division by zero),
and you don't need to worry about precision (so just use the default floaty numeric type).

All the normal rules, standard loopholes, etc apply.

Test cases
{velocities}, {positions} -> {v}, {r}

{}, {} -> {}, {}
{[10, 5, 1]}, {[1, 2, 3]} -> {[10, 5, 1]}, {[11, 7, 4]}
{[.5,0,0], [-.5,0,0]}, {[.5,0,0], [-.5,0]} -> {[-.5,0,0], [.5,0,0]}, {[0,0,0], [0,0,0]}
{[0,0,0], [0,0,0], [0,0,0]}, {[1,0,0], [0,1,0], [0,0,1]} -> {[-.7071, .3535, .3535], [.3535, -.7071, .3535], [.3535, .3535, -.7071]}, {[.2928, .3535, .3535], [.3535, .2928, .3535], [.3535, .3535, .2928]}

Brownie Points
We simplified some stuff here, but we've done the hardest part of a fully fledged n-body gravity simulation.
If you want extra brownie points, you can add those complications back in.
First, we want the gravitational constant G.
Then, we take a mass[] array with the mass of each body
Finally, we take t and dt for total time and step time

Our updated pseudocode is:

T=0
while T < t {
    for i in range(num_bodies) {
        v[i] += G * sum(
            mass[j] * (r[j]-r[i]) / norm(r[j] - r[i])^3
            for j in range(num_bodies)
            if j != i
        ) * dt
        r[i] += v[i] * dt
    }
    T += dt
}

*/

package main

import (
	"fmt"
	"math"
)

type vec3 struct {
	x, y, z float64
}

func main() {
	fmt.Println(sim(
		[]vec3{},
		[]vec3{},
	))

	fmt.Println(sim(
		[]vec3{{10, 5, 1}},
		[]vec3{{1, 2, 3}},
	))

	fmt.Println(sim(
		[]vec3{{.5, 0, 0}, {-.5, 0, 0}},
		[]vec3{{.5, 0, 0}, {-.5, 0, 0}},
	))

	fmt.Println(sim(
		[]vec3{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
		[]vec3{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}},
	))
}

func sim(v, r []vec3) ([]vec3, []vec3) {
	for i := range r {
		a := vec3{}
		for j := range r {
			if i == j {
				continue
			}
			a = add(a, scale(sub(r[j], r[i]), 1/cube(dist(r[j], r[i]))))
		}
		v[i] = add(v[i], a)
	}

	for i := range r {
		r[i] = add(r[i], v[i])
	}

	return v, r
}

func (v vec3) String() string {
	return fmt.Sprintf("[%.4f %.4f %.4f]", v.x, v.y, v.z)
}

func add(a, b vec3) vec3 {
	return vec3{
		a.x + b.x,
		a.y + b.y,
		a.z + b.z,
	}
}

func sub(a, b vec3) vec3 {
	return vec3{
		a.x - b.x,
		a.y - b.y,
		a.z - b.z,
	}
}

func dist(a, b vec3) float64 {
	dx := a.x - b.x
	dy := a.y - b.y
	dz := a.z - b.z
	return math.Sqrt(dx*dx + dy*dy + dz*dz)
}

func scale(a vec3, s float64) vec3 {
	return vec3{
		a.x * s,
		a.y * s,
		a.z * s,
	}
}

func cube(x float64) float64 {
	return x * x * x
}
