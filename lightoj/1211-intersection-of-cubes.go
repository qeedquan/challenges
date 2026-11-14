/*

You are given n cubes, each cube is described by two points in 3D space: (x1, y1, z1) being one corner of the cube and (x2, y2, z2) being the opposite corner. Assume that the sides of each of the cubes are parallel to the axis. Your task is to find the volume of their intersection.

Input
Input starts with an integer T (≤ 100), denoting the number of test cases.

Each case starts with a line containing an integer n (1 ≤ n ≤ 100). Each of the next n lines contains six integers x1 y1 z1 x2 y2 z2 (1 ≤ x1, y1, z1, x2, y2, z2 ≤ 1000, x1 < x2, y1 < y2, z1 < z2) where (x1, y1, z1) is the co-ordinate of one corner and (x2, y2, z2) is the co-ordinate of the opposite corner.

Output
For each case, print the case number and volume of their intersection.

Sample
Input	Output
2
2
1 1 1 3 3 3
1 1 1 2 2 2
3
7 8 9 20 20 30
2 2 2 50 50 50
13 14 15 18 30 40

Case 1: 1
Case 2: 450

*/

package main

import "math"

type Point struct {
	x, y, z int
}

func main() {
	assert(solve([][2]Point{
		{{1, 1, 1}, {3, 3, 3}},
		{{1, 1, 1}, {2, 2, 2}},
	}) == 1)

	assert(solve([][2]Point{
		{{7, 8, 9}, {20, 20, 30}},
		{{2, 2, 2}, {50, 50, 50}},
		{{13, 14, 15}, {18, 30, 40}},
	}) == 450)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(corners [][2]Point) int {
	near := Point{math.MaxInt, math.MaxInt, math.MaxInt}
	far := Point{0, 0, 0}
	for _, p := range corners {
		far.x = max(far.x, p[0].x)
		far.y = max(far.y, p[0].y)
		far.z = max(far.z, p[0].z)
		near.x = min(near.x, p[1].x)
		near.y = min(near.y, p[1].y)
		near.z = min(near.z, p[1].z)
	}
	X := near.x - far.x
	Y := near.y - far.y
	Z := near.z - far.z
	if X > 0 && Y > 0 && Z > 0 {
		return X * Y * Z
	}
	return 0
}
