/*

Inclusion-Exclusion lets you calculate the sizes of some unions and intersections between sets knowing some of the other values. I won't explain it exactly, but your challenge is to visualize inclusion-exclusion on a Venn Diagram.

Because I'm nice, you'll be using rectangles, not circles.

You will be given a list of rectangles denoted by top-left and bottom-right corner coordinates in any reasonable format (list of 4-tuples, list of pairs of pairs, list of pairs, etc). You can assume that all coordinates are non-negative and within your language's (reasonable) number range (please specify what it is if it's less than 128). You can choose to be left-inclusive or left-exclusive and right-inclusive or right-exclusive. Regardless of your chosen format, you can assume all rectangles are at least 1x1.

Then, you are to draw out each rectangle on the screen (ASCII canvas) using a single non-whitespace character k, which is yours to choose.

However, whenever two rectangles overlap, the overlapping area shall be drawn with another non-whitespace character l != k, also yours to choose.

Whenever three rectangles overlap, the overlapping area should be drawn with k, and for an odd number of rectangles covering, k, and an even number, l.

The background should be single whitespaces (0x20).

Test Cases (k = "#", l = ".")
0 0 9 9
1 1 10 10
2 2 11 11

#########
#........#
#.#######.#
#.#######.#
#.#######.#
#.#######.#
#.#######.#
#.#######.#
#.#######.#
 #........#
  #########

1 1 3 3
2 2 4 4


 ##
 #.#
  ##

1 1 9 9
2 2 8 8
3 3 7 7


 ########
 #......#
 #.####.#
 #.####.#
 #.####.#
 #.####.#
 #......#
 ########
Notes
Leading spaces and newlines (which occur if the minimum coordinate isn't 0, 0) must be present
Any trailing spaces and newlines are allowed to a reasonable extent (i.e. don't trail like 100000000 newlines, that's just annoying)
x- and y- axes can face either way but you must be consistent and specify which (default is x- right and y- down)
coordinates can be 0-, 1-, or 2- indexed.

Reference Proton Implementation

coordinates = []
while input() -> line {
	coordinates.append(map(int, line.split()))
}
grid = [[" "] * max(x[2] for x : coordinates) for i : 0 .. max(x[3] for x : coordinates)]
for c : coordinates {
	for x : c[0] .. c[2] {
		for y : c[1] .. c[3] {
			if grid[x][y] == chr(35) { grid[x][y] = "." }
			else { grid[x][y] = chr(35) }
		}
	}
}
print("    " + "\n    ".join(map(map(str) + " ".join,coordinates)))
print()
print("    " + "\n    ".join(map("".join,grid)))
print()

This is code-golf, so the objective is to have the shortest code. Happy golfing!

*/

package main

import (
	"fmt"
	"image"
	"math"
)

func main() {
	vie([]image.Rectangle{
		image.Rect(0, 0, 9, 9),
		image.Rect(1, 1, 10, 10),
		image.Rect(2, 2, 11, 11),
	}, '#', '.')

	vie([]image.Rectangle{
		image.Rect(1, 1, 3, 3),
		image.Rect(2, 2, 4, 4),
	}, '#', '.')

	vie([]image.Rectangle{
		image.Rect(1, 1, 9, 9),
		image.Rect(2, 2, 8, 8),
		image.Rect(3, 3, 7, 7),
	}, '#', '.')
}

func vie(r []image.Rectangle, k, l rune) {
	b := bounds(r)
	for y := b.Min.Y; y < b.Max.Y; y++ {
		for x := b.Min.X; x < b.Max.X; x++ {
			p := image.Pt(x, y)
			c := collisions(p, r)
			switch {
			case c == 0:
				fmt.Printf(" ")
			case c&1 == 0:
				fmt.Printf("%c", l)
			default:
				fmt.Printf("%c", k)
			}
		}
		fmt.Println()
	}
	fmt.Println()
}

func bounds(r []image.Rectangle) image.Rectangle {
	if len(r) == 0 {
		return image.ZR
	}

	x0, y0 := math.MaxInt, math.MaxInt
	x1, y1 := math.MinInt, math.MinInt
	for _, r := range r {
		x0 = min(x0, r.Min.X)
		y0 = min(y0, r.Min.Y)
		x1 = max(x1, r.Max.X)
		y1 = max(y1, r.Max.Y)
	}
	return image.Rect(x0, y0, x1, y1)
}

func collisions(p image.Point, r []image.Rectangle) int {
	c := 0
	for _, r := range r {
		if p.In(r) {
			c++
		}
	}
	return c
}
