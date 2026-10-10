/*

Introduction
As is known, in 2017, Finland celebrates its 100 years of independence. To mark the occasion, it is your job to produce a Finnish flag for everyone's enjoyment.

Challenge
Create a program or a function that produces the flag of Finland (the grey border is there for presentation purposes only):

https://i.stack.imgur.com/SRuCL.png

Flag specifications
The ratio of the flag is 18:11, with the cross being 3 units thick, giving a horizontal ratio set of 5:3:10 and a vertical ratio set of 4:3:4.
The picture must be at least 180 x 110 pixels in size, or in case of ASCII art, 90 x 55 characters.
There is no official RGB colour for the blue, but use the closest approximation of (0, 53, 128). If your system doesn't support RGB values, use blue.
For the white colour, use RGB (255, 255, 255) or white.
Not so fast
As drawing the Finnish national flag would be simpler than last year's Icelandic challenge, we'll have to ramp up the difficulty a bit. Given that Finland's Independence Day is on 6 December, the decimal number 100 must appear somewhere on the flag when the date in Finland (UTC+02:00) is 2017-12-06 or later (your code should not assume that the machine it's running on is set to a particular timezone). Before the date, the number must not be there. The number must be printed in black (RGB (0, 0, 0) or black) but its placement and font parameters are up to you.

An example of such a render (again, ignore the border):

https://i.stack.imgur.com/9PPxf.png

For testing purposes, it would be nice to include two additional versions of your solution, one with a fixed date in the past and one in the future.

Rules
Standard loopholes are forbidden, as are built-in flag images/libraries. Also, your code must not take any input.

Finns don't like small talk, and this is code-golf, so don't waste characters!

*/

package main

import (
	"flag"
	"image"
	"image/color"
	"image/draw"
	"image/png"
	"os"
	"strconv"
)

func main() {
	s := 50
	flag.Parse()
	if flag.NArg() >= 1 {
		s, _ = strconv.Atoi(flag.Arg(0))
	}

	m := finlandflag(s)
	png.Encode(os.Stdout, m)
}

func finlandflag(s int) *image.RGBA {
	w := 18 * s
	h := 11 * s
	r := image.Rect(0, 0, w, h)
	m := image.NewRGBA(r)

	blue := image.NewUniform(color.RGBA{0, 53, 128, 255})
	white := image.NewUniform(color.RGBA{255, 255, 255, 255})

	r0 := image.Rect(5, 0, 5+3, 11)
	r1 := image.Rect(0, 4, 18, 4+3)
	r0 = scale(r0, s)
	r1 = scale(r1, s)

	draw.Draw(m, r, white, image.ZP, draw.Src)
	draw.Draw(m, r0, blue, image.ZP, draw.Src)
	draw.Draw(m, r1, blue, image.ZP, draw.Src)

	return m
}

func scale(r image.Rectangle, s int) image.Rectangle {
	r.Min.X *= s
	r.Min.Y *= s
	r.Max.X *= s
	r.Max.Y *= s
	return r
}
