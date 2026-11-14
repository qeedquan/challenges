/*

Typically, when we want to represent a magnitude and direction in 2D space, we use a 2-axis vector. These axes are typically called X and Y:

https://i.stack.imgur.com/8ahzR.png

This isn't always convenient, however. The game BattleTech is played on a hexagonal grid, and it's convenient for the axes to line up with the sides of the hexagons. To represent velocity, thrust, and other such values, BattleTech uses a 6-axis Thrust Vector, with axes named A-F:

https://i.stack.imgur.com/bAPMf.png

Here are a few example Thrust Vectors, all of which represent the following magnitude and direction:

https://i.stack.imgur.com/KqxD9.png

{ A = 2, B = 1, C = 0, D = 0, E = 0, F = 0 }
{ A = 3, B = 0, C = 1, D = 0, E = 0, F = 0 }
{ A = 5, B = 0, C = 0, D = 3, E = -1, F = 0 }

This follows from two rules of equivalence for Thrust Vectors:

Adding or subtracting the same value to two opposite axes (A/D, B/E or C/F) leads to an equivalent Thrust Vector: { A = 1, D = 1 } => {A = 0, D = 0}
Subtracting a value from two axes with a single axis between them (A/C, B/D, C/E, D/F, E/A, F/B) and adding that value to the axis between them leads to an equivalent Thrust Vector: { A = 1, B = 0, C = 1 } => { A = 0, B = 1, C = 0}
It is possible to make a simple Thrust Vector look very complicated by placing value in axes in a different direction than the vector actually points in, which is undesirable. A Consolidated Thrust Vector is a Thrust Vector that fulfills the following conditions:

No axes hold a negative value.
There are up to 2 axes with nonzero values.
If there are 2 axes with nonzero values, they are adjacent axes.
Of the above example vectors, only the first is Consolidated.

Your challenge is to accept a 6-axis vector (as a 6-element list or other convenient structure) of integer magnitudes, and return an equivalent vector which has been consolidated. There is only one possible solution for any given input.

Test cases:

-1, 0, 0, 0, 0, 0 => 0, 0, 0, 1, 0, 0
1, 0, 0, 2, 0, 0 => 0, 0, 0, 1, 0, 0
1, 0, 2, 0, 0, 0 => 0, 1, 1, 0, 0, 0
1, 2, 3, 4, 5, 6 => 0, 0, 0, 0, 6, 0
1, 0, 2, 0, 3, 0 => 0, 0, 0, 1, 1, 0
1, 0, 1, 0, 1, 0 => 0, 0, 0, 0, 0, 0
0, 0, 0, 0, 0, 0 => 0, 0, 0, 0, 0, 0
0, 0, 0, 0, 0, 1 => 0, 0, 0, 0, 0, 1
1, 0, 0, 0, 1, 0 => 0, 0, 0, 0, 0, 1
-1, -1, -1, 1, 1, 1 => 0, 0, 0, 0, 4, 0

*/

package main

func main() {
	assert(consolidate([6]int{-1, 0, 0, 0, 0, 0}) == [6]int{0, 0, 0, 1, 0, 0})
	assert(consolidate([6]int{1, 0, 0, 2, 0, 0}) == [6]int{0, 0, 0, 1, 0, 0})
	assert(consolidate([6]int{1, 0, 2, 0, 0, 0}) == [6]int{0, 1, 1, 0, 0, 0})
	assert(consolidate([6]int{1, 2, 3, 4, 5, 6}) == [6]int{0, 0, 0, 0, 6, 0})
	assert(consolidate([6]int{1, 0, 2, 0, 3, 0}) == [6]int{0, 0, 0, 1, 1, 0})
	assert(consolidate([6]int{1, 0, 1, 0, 1, 0}) == [6]int{0, 0, 0, 0, 0, 0})
	assert(consolidate([6]int{0, 0, 0, 0, 0, 0}) == [6]int{0, 0, 0, 0, 0, 0})
	assert(consolidate([6]int{0, 0, 0, 0, 0, 1}) == [6]int{0, 0, 0, 0, 0, 1})
	assert(consolidate([6]int{1, 0, 0, 0, 1, 0}) == [6]int{0, 0, 0, 0, 0, 1})
	assert(consolidate([6]int{-1, -1, -1, 1, 1, 1}) == [6]int{0, 0, 0, 0, 4, 0})
	assert(consolidate([6]int{0, 1, 1, 2, 3, 5}) == [6]int{0, 0, 0, 0, 4, 2})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

/*

@Neil

Example for given test case of 0, 1, 1, 2, 3, 5:

Subtract each element from its opposite, resulting in -2, -2, -4, 2, 2, 4.

Take alternate elements, resulting in -2, 2, 4. The median is 2.

Subtract 2 from the alternate elements, resulting in 0, -4, 0, 0, 0, 2.

Reverse the -4, resulting in 0, 0, 0, 0, 4, 2 which is the final answer.

*/

func consolidate(v [6]int) [6]int {
	var r [6]int
	for i := 0; i < 3; i++ {
		r[i] = v[i] - v[i+3]
		r[i+3] = v[i+3] - v[i]
	}
	m := mid(r[1], r[3], r[5])

	for i := 0; i < 6; i++ {
		if i&1 == 0 {
			r[i] = 0
		} else {
			r[i] -= m
		}
	}

	for i := 0; i < 3; i++ {
		if r[i] < 0 || r[i+3] < 0 {
			r[i+3], r[i] = abs(r[i]), abs(r[i+3])
		}
	}

	return r
}

func mid(a, b, c int) int {
	x := a - b
	y := b - c
	z := a - c
	if x*y > 0 {
		return b
	}
	if x*z > 0 {
		return c
	}
	return a
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}
