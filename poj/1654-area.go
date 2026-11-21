/*

Description

You are going to compute the area of a special kind of polygon. One vertex of the polygon is the origin of the orthogonal coordinate system. From this vertex, you may go step by step to the following vertexes of the polygon until back to the initial vertex. For each step you may go North, West, South or East with step length of 1 unit, or go Northwest, Northeast, Southwest or Southeast with step length of square root of 2.

For example, this is a legal polygon to be computed and its area is 2.5:

http://poj.org/images/1654_1.jpg

Input

The first line of input is an integer t (1 <= t <= 20), the number of the test polygons. Each of the following lines contains a string composed of digits 1-9 describing how the polygon is formed by walking from the origin. Here 8, 2, 6 and 4 represent North, South, East and West, while 9, 7, 3 and 1 denote Northeast, Northwest, Southeast and Southwest respectively. Number 5 only appears at the end of the sequence indicating the stop of walking. You may assume that the input polygon is valid which means that the endpoint is always the start point and the sides of the polygon are not cross to each other.Each line may contain up to 1000000 digits.

Output

For each polygon, print its area on a single line.

Sample Input

4
5
825
6725
6244865

Sample Output

0
0
0.5
2

Source

POJ Monthly--2004.05.15 Liu Rujia@POJ

*/

package main

type vec2 struct {
	x, y int
}

func main() {
	assert(area("5") == 0)
	assert(area("825") == 0)
	assert(area("6725") == 0.5)
	assert(area("6244865") == 2)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func area(s string) float64 {
	dirs := map[rune]vec2{
		'1': vec2{-1, -1},
		'2': vec2{0, -1},
		'3': vec2{1, -1},
		'4': vec2{-1, 0},
		'5': vec2{0, 0},
		'6': vec2{1, 0},
		'7': vec2{-1, 1},
		'8': vec2{0, 1},
		'9': vec2{1, 1},
	}

	var (
		p1, p2 vec2
		r      int
	)
	for _, c := range s {
		d, f := dirs[c]
		if !f {
			return -1
		}

		if d.x != 0 || d.y != 0 {
			p2 = add(p1, d)
		} else {
			p2 = vec2{0, 0}
		}
		r += wedge(p1, p2)
		p1 = p2
	}
	return float64(abs(r)) / 2
}

func add(a, b vec2) vec2 {
	return vec2{a.x + b.x, a.y + b.y}
}

func wedge(a, b vec2) int {
	return a.x*b.y - a.y*b.x
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}
