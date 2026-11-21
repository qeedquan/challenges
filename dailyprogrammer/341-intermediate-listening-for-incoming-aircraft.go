/*

Description
You're the operator of a small squadron stationed along the coast listening for incoming enemy aircraft. This is before RADAR, and so your team is equipped with giant microphones and headphones that they use to constantly scour the skies for signs of incoming aircraft. All they are able to get to you is the angle and direction in which they heard a propeller.

Acoustic location is the science of using sound to determine the distance and direction of something. As a military air defense tool, passive acoustic location was used from mid-World War I to the early years of World War II to detect enemy aircraft by picking up the noise of their engines. Most of the work on anti-aircraft sound ranging was done by the British. They developed an extensive network of sound mirrors that were used from World War I through World War II. Sound mirrors normally work by using moveable microphones to find the angle that maximizes the amplitude of sound received, which is also the bearing angle to the target. Two sound mirrors at different positions will generate two different bearings, which allows the use of triangulation to determine a sound source's position.

Your task today is to be the operator of such a network - given locations of your operators and their reports, can you figure out where are the enemy aircraft? Hurry, you have to scramble the fighters to defend your nation.

Input Description
You'll be given two reports for one inbound aircraft as a row of three numbers: the first two are the X and Y coordinates of the station as integers, the third is the angle for maximum sound amplitude as a floating point number. This angle will be 0-360, clockwise starting in the top for 0 degrees. Example:

0 0 45
10 0 0
Output Description
Your program should output the location of the enemy aircraft as a grid coordinate, a pair of numbers in X and Y positions - they may be floating point values. Example:

10.0 10.0

Challenge Inputs
CORRECTED GEOMETRY thanks to u/mn-haskell-guy

0 0 24.0
11 7 343.4

10 1 0.0
2 8 352.82

0 0 30.9
10 1 336.42

Challenge Outputs
4 9
10 9
5 3

*/

package main

import (
	"fmt"
	"math"
)

/*

@mn-haskell-guy

My answers:

  0  0  24.00 11  7 343.40 - OK: 7.838 17.605
 10  1   0.00  2  8 352.82 - Inconsistent
  0  0  30.90 10  1 336.42 - OK: 6.035 10.084
The second problem is labelled "Inconsistent" because the rays don't intersect: the ray from 10 1 is due north, but 2 8 is to the west of 10 1 and its ray is in the NW direction.

Reversing each of the bearings (adding 180 to the angles) yields this solution:

 10  1 180.00  2  8 172.82 - OK: 10.000 -55.505
To hit the original challenge answers, the following bearings should be used:

  bearing from  0  0 to  4  9 is  23.96
  bearing from 11  7 to  4  9 is 285.95
  bearing from 10  1 to 10  9 is   0.00
  bearing from  2  8 to 10  9 is  82.87
  bearing from  0  0 to  5  3 is  59.04
  bearing from 10  1 to  5  3 is 291.80

*/

func main() {
	triangulate(0, 0, 24, 11, 7, 343.4)
	triangulate(10, 1, 0.0, 2, 8, 352.82)
	triangulate(0, 0, 30.9, 10, 1, 336.42)

	// corrected challenge #2
	triangulate(10, 1, 180.0, 2, 8, 352.82-180)

	bearing(0, 0, 4, 9)
	bearing(11, 7, 4, 9)

	bearing(10, 1, 10, 9)
	bearing(2, 8, 10, 9)

	bearing(0, 0, 5, 3)
	bearing(10, 1, 5, 3)
}

func near(a, b float64) bool {
	const eps = 1e-8
	return math.Abs(a-b) <= eps
}

// solve ax + by == e, cx * dy == f
func solve2x2(a, b, c, d, e, f float64) (float64, float64) {
	disc := a*d - b*c
	if near(disc, 0) {
		return math.NaN(), math.NaN()
	}
	x := (e*d - b*f) / disc
	y := (a*f - e*c) / disc
	return x, y
}

func solve(x0, y0, a0, x1, y1, a1 float64) (string, float64, float64) {
	// a0, and a1 are in degrees "clockwise starting in the top for 0 degrees"
	r0 := (90 - a0) * math.Pi / 180
	r1 := (90 - a1) * math.Pi / 180
	// x0 + t*cos r0 == x1 + s*cos r1
	a := math.Cos(r0)
	b := -math.Cos(r1)
	e := x1 - x0
	// y0 + t*sin r0 == y1 + s*sin r1
	c := math.Sin(r0)
	d := -math.Sin(r1)
	f := y1 - y0
	t, s := solve2x2(a, b, c, d, e, f)
	if !math.IsNaN(t) && !math.IsNaN(s) {
		if t >= 0 && s >= 0 {
			x := x0 + t*math.Cos(r0)
			y := y0 + t*math.Sin(r0)
			return "OK", x, y
		}
		return "Inconsistent", 0, 0
	}
	return "Parallel", 0, 0
}

func triangulate(x0, y0, a0, x1, y1, a1 float64) {
	status, x, y := solve(x0, y0, a0, x1, y1, a1)
	prob := fmt.Sprintf("% 6.2f % 6.2f % 6.2f % 6.2f % 6.2f % 6.2f", x0, y0, a0, x1, y1, a1)
	st := status
	if status == "OK" {
		st = fmt.Sprintf("OK: %.3f %.3f", x, y)
	}
	fmt.Println(prob, "-", st)
}

func bearing(x0, y0, x1, y1 float64) {
	a := 90 - (math.Atan2(y1-y0, x1-x0) / math.Pi * 180)
	if a < 0 {
		a += 360
	}
	fmt.Printf("bearing from (% 6.2f, % 6.2f) to (% 6.2f, % 6.2f) is %6.2f\n", x0, y0, x1, y1, a)
}
