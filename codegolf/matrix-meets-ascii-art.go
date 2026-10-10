/*

A binary matrix represents a shape in the plane. 1 means a unit square at that position. 0 means nothing. The background is 0.

For example, the array [[0,1,0],[0,0,1],[1,1,1]] represents the following shape:

     o----o
     |////|
     |////|
     o----o----o
          |////|
          |////|
o----o----o----o
|////|////|////|
|////|////|////|
o----o----o----o
Challenge
You take input as the array and output the matching ASCII art.

As with all code-golfing challenges, the shortest code in terms of bytes wins.
Examples
[[1,1,1],[0,0,0]]

o----o----o----o
|////|////|////|
|////|////|////|
o----o----o----o
(You may or may not trim)

[[0,1,0],[1,0,1]]

     o----o
     |////|
     |////|
o----o----o----o
|////|    |////|
|////|    |////|
o----o    o----o
[[1,0,1,0],[0,0,0,0],[1,1,1,0]

o----o    o----o
|////|    |////|
|////|    |////|
o----o    o----o


o----o----o----o
|////|////|////|
|////|////|////|
o----o----o----o
[[1]]

o----o
|////|
|////|
o----o
You can choose whether or not to trim surrounding whitespace, from either rows, columns, both or neither

*/

package main

import (
	"fmt"
)

func main() {
	render([][]int{{0, 1, 0}, {0, 0, 1}, {1, 1, 1}})
	render([][]int{{1, 1, 1}, {0, 0, 0}})
	render([][]int{{0, 1, 0}, {1, 0, 1}})
	render([][]int{{1, 0, 1, 0}, {0, 0, 0, 0}, {1, 1, 1, 0}})
	render([][]int{{1}})
}

// Ported from @matteo_c solution
func render(shape [][]int) {
	const symbols = "/|-o"

	fmt.Println(shape)
	if len(shape) == 0 || len(shape[0]) == 0 {
		return
	}

	canvas := make([][]byte, 4*len(shape))
	for y := range canvas {
		canvas[y] = make([]byte, 6*len(shape[0]))
		for x := range canvas[y] {
			canvas[y][x] = ' '
		}
	}

	for y := range shape {
		for x, value := range shape[y] {
			if value == 0 {
				continue
			}
			for dy := range 4 {
				for dx := range 6 {
					i := truth(dy%3 < 1)
					j := truth(dx%5 < 1)
					canvas[3*y+dy][5*x+dx] = symbols[2*i+j]
				}
			}
		}
	}

	for y := range canvas {
		fmt.Printf("%s\n", canvas[y])
	}
}

func truth(x bool) int {
	if x {
		return 1
	}
	return 0
}
