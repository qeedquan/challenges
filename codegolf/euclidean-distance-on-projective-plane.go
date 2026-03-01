/*

Motivated by this challenge

Background
Let we have a square sheet of flexible material. Roughly speaking, we may close it on itself four ways:

https://i.stack.imgur.com/gMSjv.jpg

Here the color marks the edges that connect and the vectors indicate the direction. The sphere and torus are obtained without flipping the sides, Klein bottle — with one flipping edge, and projective plane with both.

Surprisingly torus, not a sphere, in many senses is the simplest construct. For example, you can't comb a hairy ball flat without creating a cowlick (but torus can).
This is why torus is often used in games, puzzles and research.

Specific info
This is a separate picture for fundamental polygon (or closing rule) of projective plane (for 1..N notation):

https://i.stack.imgur.com/DaXpb.jpg

Neighborhood of [1, 1] cell for N x N lattice:

https://i.stack.imgur.com/N2rdI.jpg

Example how to find distance for points (2, 4) and (5, 3) in 5 x 5 projective plane:

https://i.stack.imgur.com/JhHkl.jpg

Green paths are shortest, so it is the distance.

Task
For given two points and size of lattice,
find euclidean distance between points on the projective plane.

I/O
Flexible, in any suitable formats

Test cases
For 1..N notation
N, p1, p2 → distance For a better understanding, also indicated distance on torus (for same points and size):

5, [1, 1], [1, 1] → 0.0 (0.0)
5, [2, 4], [5, 3] → 2.24 (2.24)
5, [2, 4], [4, 1] → 2.0   (1.41)
10, [2, 2], [8, 8] → 4.12 (5.66)
10, [1, 1], [10, 10]  → 1.0 (1.41)
10, [4, 4], [6, 6]  → 2.83 (2.83)

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	test(5, 1, 1, 1, 1, 0.0)
	test(5, 2, 4, 5, 3, 2.24)
	test(5, 2, 4, 4, 1, 2.0)
	test(10, 2, 2, 8, 8, 4.12)
	test(10, 1, 1, 10, 10, 1.0)
	test(10, 4, 4, 6, 6, 2.83)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(N, x, y, X, Y int, r float64) {
	d := dist(N, x, y, X, Y)
	fmt.Println(d)
	assert(math.Abs(d-r) < 1e-2)
}

// ported from @138 Aspen solution
func dist(N, x, y, X, Y int) float64 {
	a := []int{x - X, x - X - N, X + x - N - 1, X + x - N - 1, X + x - N - 1, x - X + N}
	b := []int{y - Y, Y + y - N - 1, y - Y - N, N - (Y + y - N - 1), y - Y + N, Y + y - N - 1}
	d := math.MaxFloat64
	for i := range a {
		d = min(d, math.Hypot(float64(a[i]), float64(b[i])))
	}
	return d
}
