/*

Problem Description
Imagine you're a turtle on a grid.
You're given two numbers f and b, and you're facing east.
You perform a march across the grid, counting each of the cells you encounter, according to the following rules:

By default, you write the count to the cell you're in, then walk forward.
If the count is divisible by f, you write F to the cell you're in, then turn right, then walk forward.
If the count is divisible by b, you write B to the cell you're in, then turn left, then walk forward.
If the count is divisible by both f and b, you write FB to the cell you're in, then walk forward.
If you reach a square you've already been to, you stop.
For example, following these rules using f = 3 and b = 5 will generate a pattern like this:

    F 28 29 FB  1  2  F
   26                 4
 F  B                 B  F
23                       7
22                       8
 F  B                 B  F
   19                11
    F 17 16 FB 14 13  F

The challenge
Write a program or function that accepts two numbers as input, corresponding to f and b, and produces as output the pattern for these numbers given by the rules above.

Formatting requirements:

Each cell is two characters wide
Cell contents are right aligned within these two characters
Cells on the same row are delimited by a space
The first column of cells must contain a non-empty cell
All rows must contain non-empty cells
Trailing whitespace is not required, but allowed
However, the total width of each row must not exceed 3 times the number of non-empty columns
Your code must work for provided test cases.

Standard loopholes are disallowed.

This is code golf; shortest answer in bytes wins.

Test cases
(f=3, b=5 case repeated here as a courtesy convenience).

f=3, b=5 ->
    F 28 29 FB  1  2  F
   26                 4
 F  B                 B  F
23                       7
22                       8
 F  B                 B  F
   19                11
    F 17 16 FB 14 13  F

f=4, b=10 ->
 F 25 26 27  F
23          29
22        1  2  3  F
21                 5
FB                 6
19                 7
18           B  9  F
17          11
 F 15 14 13  F

f=3, b=11 ->
 F 16 17  F
14       19
13     1  2  F
 F  B        4
   10        5
    F  8  7  F

f=5, b=9 ->
    F 41 42 43 44  1  2  3  4  F
   39                          6
   38                          7
   37                          8
 F  B                          B  F
34                               11
33                               12
32                               13
31                               14
 F 29 28  B              B 17 16  F
         26             19
          F 24 23 22 21  F

f=5, b=13 ->
    F 31 32 33 34  F
   29             36
   28        1  2  3  4  F
   27                    6
 F  B                    7
24                       8
23                       9
22              B 12 11  F
21             14
 F 19 18 17 16  F

*/

package main

import (
	"fmt"
	"image"
	"math"
)

func main() {
	tfb(3, 5)
	tfb(4, 10)
	tfb(3, 11)
	tfb(5, 9)
	tfb(5, 13)
}

func tfb(f, b int) {
	g := make(map[image.Point]string)
	x, y := 0, 0
	i, d := 1, 3
	p := image.Pt(x, y)
	for g[p] == "" {
		q := not(i%f)<<1 | not(i%b)
		switch q {
		case 3:
			g[p] = "FB"
		case 2:
			g[p] = "F"
			d = (d + 3) % 4
		case 1:
			g[p] = "B"
			d = (d + 1) % 4
		case 0:
			g[p] = fmt.Sprint(i)
		}

		if d%2 != 0 {
			x += d - 2
		} else {
			y += d - 1
		}

		p = image.Pt(x, y)
		i += 1
	}

	x0, x1 := math.MaxInt, math.MinInt
	y0, y1 := math.MaxInt, math.MinInt
	for p := range g {
		x0 = min(x0, p.X)
		x1 = max(x1, p.X)
		y0 = min(y0, p.Y)
		y1 = max(y1, p.Y)
	}

	fmt.Printf("f=%d b=%d\n", f, b)
	for y := y0; y <= y1; y++ {
		for x := x0; x <= x1; x++ {
			p := image.Pt(x, y)
			fmt.Printf("%2s ", g[p])
		}
		fmt.Println()
	}
	fmt.Println()
}

func not(x int) int {
	if x == 0 {
		return 1
	}
	return 0
}
