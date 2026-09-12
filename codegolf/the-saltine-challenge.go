/*

Here is an ASCII saltine cracker:

 _________________
|  .     .     .  |
|     .     .     |
|  .     .     .  |
|     .     .     |
|  .     .     .  |
|_________________|
Here are two crackers stacked:

 _________________
|  .     .     .  |
|     . __________|______
|  .   |  .     .     .  |
|     .|     .     .     |
|  .   |  .     .     .  |
|______|     .     .     |
       |  .     .     .  |
       |_________________|
Write the shortest program possible that takes a positive integer and draws a stack of that many ASCII saltine crackers.

Input may come from stdin, command line, or you may simply write a function. The input will always be valid. Output must go to stdout or closest alternative.

Each stacked cracker is always shifted 2 characters down and 7 characters right of the cracker below it. There should be no trailing spaces or extraneous newlines.

The shortest program in bytes wins.

Examples
If the input is 1 the output is

 _________________
|  .     .     .  |
|     .     .     |
|  .     .     .  |
|     .     .     |
|  .     .     .  |
|_________________|
If the input is 2 the output is

 _________________
|  .     .     .  |
|     . __________|______
|  .   |  .     .     .  |
|     .|     .     .     |
|  .   |  .     .     .  |
|______|     .     .     |
       |  .     .     .  |
       |_________________|
If the input is 3 the output is

 _________________
|  .     .     .  |
|     . __________|______
|  .   |  .     .     .  |
|     .|     . __________|______
|  .   |  .   |  .     .     .  |
|______|     .|     .     .     |
       |  .   |  .     .     .  |
       |______|     .     .     |
              |  .     .     .  |
              |_________________|
And so on.

the real saltine challenge

*/

package main

import (
	"fmt"
	"image"
)

func main() {
	for i := range 11 {
		saltine(i)
	}
}

func saltine(n int) {
	art := []string{
		" _________________",
		"|  .     .     .  |",
		"|     .     .     |",
		"|  .     .     .  |",
		"|     .     .     |",
		"|  .     .     .  |",
		"|_________________|",
	}

	d := newdrawing()
	ox := 0
	oy := 0
	for range n {
		for y := range art {
			for x := range art[y] {
				d.Set(x+ox, y+oy, art[y][x])
			}
		}
		ox += 7
		oy += 2
	}

	fmt.Printf("n=%d\n", n)
	r := d.Bounds()
	for y := r.Min.Y; y < r.Max.Y; y++ {
		for x := r.Min.X; x < r.Max.X; x++ {
			fmt.Printf("%c", d.At(x, y))
		}
		fmt.Println()
	}
	fmt.Println()
}

type Drawing struct {
	image.Rectangle
	grid map[image.Point]byte
}

func newdrawing() *Drawing {
	return &Drawing{
		grid: make(map[image.Point]byte),
	}
}

func (d *Drawing) Set(x, y int, c byte) {
	p := image.Pt(x, y)
	d.grid[p] = c
	d.Min.X = min(d.Min.X, p.X)
	d.Min.Y = min(d.Min.Y, p.Y)
	d.Max.X = max(d.Max.X, p.X+1)
	d.Max.Y = max(d.Max.Y, p.Y+1)
}

func (d *Drawing) At(x, y int) byte {
	p := image.Pt(x, y)
	c, ok := d.grid[p]
	if !ok {
		return ' '
	}
	return c
}
