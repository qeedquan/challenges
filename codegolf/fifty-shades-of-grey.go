/*

Boys and girls are excited to see Fifty Shades of Grey on the silver screen, we just want to code without being bothered, so here's a challenge to pick our brain.

You have to:

Print on the screen fifty squares filled each with a different shade of grey
If your language of choice lacks image processing capabilities, you could output an image file
Squares must be visible, at least 20 x 20 pixels
You cannot use random numbers unless you make sure each shade is unique.
You cannot connect to any service over any network
You cannot read any files in your program.
You cannot use any libraries out of the standard libraries of your language of choice.
This is code golf so shortest code wins.

*/

package main

import (
	"image"
	"image/color"
	"image/draw"
	"image/png"
	"os"
)

func main() {
	m := gen(10, 5, 20, 5)
	png.Encode(os.Stdout, m)
}

func gen(w, h, s, t int) *image.Gray {
	r := image.Rect(0, 0, w*s, h*s)
	m := image.NewGray(r)
	g := color.Gray{255}
	for y := 0; y < h; y++ {
		for x := 0; x < w; x++ {
			draw.Draw(m, image.Rect(x*s, y*s, (x+1)*s, (y+1)*s), image.NewUniform(g), image.ZP, draw.Src)
			g.Y -= uint8(t)
		}
	}
	return m
}
