/*

Description

Stan and Ollie play the game of Odd Brownie Points. Some brownie points are located in the plane, at integer coordinates. Stan plays first and places a vertical line in the plane. The line must go through a brownie point and may cross many (with the same x-coordinate). Then Ollie places a horizontal line that must cross a brownie point already crossed by the vertical line.
Those lines divide the plane into four quadrants. The quadrant containing points with arbitrarily large positive coordinates is the top-right quadrant.

The players score according to the number of brownie points in the quadrants. If a brownie point is crossed by a line, it doesn't count. Stan gets a point for each (uncrossed) brownie point in the top-right and bottom-left quadrants. Ollie gets a point for each (uncrossed) brownie point in the top-left and bottom-right quadrants.

Your task is to compute the scores of Stan and Ollie given the point through which they draw their lines.

Input

Input contains a number of test cases. The data of each test case appear on a sequence of input lines. The first line of each test case contains a positive odd integer 1 < n < 200000 which is the number of brownie points. Each of the following n lines contains two integers, the horizontal (x) and vertical (y) coordinates of a brownie point. No two brownie points occupy the same place. The input ends with a line containing 0 (instead of the n of a test).

Output

For each test case of input, print a line with two numbers separated by a single space. The first number is Stan's score, the second is the score of Ollie when their lines cross the point whose coordinates are given at the center of the input sequence of points for this case.

Sample Input

11
3 2
3 3
3 4
3 6
2 -2
1 -3
0 0
-3 -3
-3 -2
-3 -4
3 -7
0

Sample Output

6 3

Source

Waterloo local 2005.06.11

*/

package main

import "image"

func main() {
	assert(score([]image.Point{
		{3, 2},
		{3, 3},
		{3, 4},
		{3, 6},
		{2, -2},
		{1, -3},
		{0, 0},
		{-3, -3},
		{-3, -2},
		{-3, -4},
		{3, -7},
	}) == [2]int{6, 3})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func score(p []image.Point) [2]int {
	r := [2]int{}
	n := len(p)
	if n == 0 {
		return r
	}

	c := p[(n-1)/2]
	for _, p := range p {
		switch {
		case (p.X > c.X && p.Y > c.Y) || (p.X < c.X && p.Y < c.Y):
			r[0]++
		case (p.X > c.X && p.Y < c.Y) || (p.X < c.X && p.Y > c.Y):
			r[1]++
		}
	}
	return r
}
