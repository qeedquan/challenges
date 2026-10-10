/*

The flag of Greenland consists of two red sections and two white sections.
I'll provide a diagram below, but also give a textual description.
The background of the flag is a rectangle that is 18 units wide and 12 units tall.
The bottom half of the background is red, and the top half is white.
There's a circle in the middle with a radius of 4 units, with the colors reversed: the top half is red, and the bottom half is white.
The circle is centered vertically, but not horizontally:
There are 3 units of space between the circle and the left edge of the flag, and 7 units of space between the circle and the right edge of the flag.

https://i.sstatic.net/cwe4h8hg.png

Your challenge is to generate this flag in some capacity -- be that displaying it on the screen, or saving it as an image file.
Retrieving it from an online resource or outputting the emoji is banned.
The red color does not have to exactly match the color in the image above, as long as it is obviously red.
(I couldn't actually find conclusive information about what shade of red it's supposed to be -- different sites gave conflicting answers.)

*/

package main

import (
	"flag"
	"image"
	"image/color"
	"image/draw"
	"image/png"
	"os"
)

var (
	scale = 50
)

func main() {
	flag.IntVar(&scale, "scale", scale, "specify scale")
	flag.Parse()

	m := render(scale)
	png.Encode(os.Stdout, m)
}

func render(s int) *image.RGBA {
	var (
		red   = image.NewUniform(color.RGBA{200, 16, 46, 255})
		white = image.NewUniform(color.White)
	)

	w := 18 * s
	h := 12 * s
	r := image.Rect(0, 0, w, h)
	m := image.NewRGBA(r)

	r0 := image.Rect(0, 0, w, h/2)
	r1 := image.Rect(0, h/2, w, h)
	r2 := image.Rect(3*s, 2*s, 11*s, 10*s)
	cc := image.Pt(7*s, 6*s)
	rd := 4 * s

	draw.Draw(m, r0, white, image.ZP, draw.Src)
	draw.Draw(m, r1, red, image.ZP, draw.Src)
	for y := r2.Min.Y; y <= r2.Max.Y; y++ {
		for x := r2.Min.X; x <= r2.Max.X; x++ {
			dx := x - cc.X
			dy := y - cc.Y
			if dx*dx+dy*dy < rd*rd {
				if y < h/2 {
					m.Set(x, y, red)
				} else {
					m.Set(x, y, white)
				}
			}
		}
	}
	return m
}
