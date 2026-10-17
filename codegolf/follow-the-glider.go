/*

https://i.sstatic.net/1KsUH2x3.gif

Generate four 2D arrays(2D string or whatever is fine) of same size that follows a glider in Conway's life of game.

Each cell is 3x3 plus 1-width border.
Each frame, it advances 1 cycle and shift the image by 1/4 cell, aka. 1 pixel.
After 4 cycle it returns to original state.
Use three values in output to mean white, black and grey(cell border)
The 2D arrays may be any size, but:
Cell border must spread the whole array
All the five active cells, with their border, must be always totally visible.
It's fine to flip the image, aka. move to another direction than right-bottom.
Shortest code in each language wins.

*/

package main

import (
	"fmt"
	"time"
)

func main() {
	animate(400 * time.Millisecond)
}

func animate(delay time.Duration) {
	index := 0
	for {
		fmt.Printf("\x1bc")
		fmt.Println(GLIDERS[index])
		index = (index + 1) % len(GLIDERS)
		time.Sleep(delay)
	}
}

var GLIDERS = []string{GLIDER1, GLIDER2, GLIDER3, GLIDER4}

const GLIDER1 = `
   .   .   .   .   .
   .   .   .   .   .
   .   .   .   .   .
....................
   .   .   .XXX.   .
   .   .   .XXX.   .
   .   .   .XXX.   .
....................
   .XXX.   .XXX.   .
   .XXX.   .XXX.   .
   .XXX.   .XXX.   .
....................
   .   .XXX.XXX.   .
   .   .XXX.XXX.   .
   .   .XXX.XXX.   .
....................
   .   .   .   .   .
   .   .   .   .   .
   .   .   .   .   .
....................
`

const GLIDER2 = `
  .   .   .   .   .
  .   .   .   .   .
....................
  .   .XXX.   .   .
  .   .XXX.   .   .
  .   .XXX.   .   .
....................
  .   .   .XXX.XXX.
  .   .   .XXX.XXX.
  .   .   .XXX.XXX.
....................
  .   .XXX.XXX.   .
  .   .XXX.XXX.   .
  .   .XXX.XXX.   .
....................
  .   .   .   .   .
  .   .   .   .   .
  .   .   .   .   .
....................
  .   .   .   .   .
`

const GLIDER3 = `
 .   .   .   .   .
....................
 .   .   .XXX.   .
 .   .   .XXX.   .
 .   .   .XXX.   .
....................
 .   .   .   .XXX.
 .   .   .   .XXX.
 .   .   .   .XXX.
....................
 .   .XXX.XXX.XXX.
 .   .XXX.XXX.XXX.
 .   .XXX.XXX.XXX.
....................
 .   .   .   .   .
 .   .   .   .   .
 .   .   .   .   .
....................
 .   .   .   .   .
 .   .   .   .   .
`

const GLIDER4 = `
....................
.   .   .   .   .
.   .   .   .   .
.   .   .   .   .
....................
.   .XXX.   .XXX.
.   .XXX.   .XXX.
.   .XXX.   .XXX.
....................
.   .   .XXX.XXX.
.   .   .XXX.XXX.
.   .   .XXX.XXX.
....................
.   .   .XXX.   .
.   .   .XXX.   .
.   .   .XXX.   .
....................
.   .   .   .   .
.   .   .   .   .
.   .   .   .   .
`
