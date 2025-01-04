/*

This year's UEFA Euro 2016 is over and besides a couple of negative headlines there has been a very positive surprise as well – the Iceland national football team. Let's draw their national flag.

Input

Well, obviously this challenge has no input.

Output

Draw the flag of Iceland in any applicable visual format of at least 100 x 72 pixels or 25 x 18 characters.
Save the output to a file or present it instantly – example formats are: images like png, jpg etc., vector graphics, draw on HTML canvas or even use non-whitespace characters for visualization.
Use these colors: blue: #0048e0, white: #ffffff and red: #d72828.
If your language doesn't support specific color values, use the standard values for red, blue and white from the ANSI color codes.
Draw the flag with the correct proportions, as shown in the figure below:

https://upload.wikimedia.org/wikipedia/commons/9/93/Flag_of_Iceland_%28with_dimensions%29.svg

You can write a program or a function. If it is an anonymous function, please include an example of how to invoke it.
This is code-golf so shortest answer in bytes wins.
Standard loopholes are disallowed.

*/

package main

import (
	"flag"
	"fmt"
	"image"
	"image/color"
	"image/draw"
	"image/png"
	"log"
	"os"
)

var (
	scale = flag.Int("s", 10, "scale factor")
)

func main() {
	flag.Parse()
	if flag.NArg() < 1 {
		usage()
	}

	f, err := os.Create(flag.Arg(0))
	check(err)
	check(png.Encode(f, gen(*scale)))
	check(f.Close())
}

func check(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: [options] file")
	flag.PrintDefaults()
	os.Exit(2)
}

func gen(s int) *image.RGBA {
	var (
		blue  = image.NewUniform(color.RGBA{2, 82, 156, 255})
		white = image.NewUniform(color.RGBA{255, 255, 255, 255})
		red   = image.NewUniform(color.RGBA{220, 30, 53, 255})
	)

	r := image.Rect(0, 0, 25*s, 18*s)
	m := image.NewRGBA(r)

	r0 := image.Rect(7*s, 0, (7+1+2+1)*s, 18*s)
	r1 := image.Rect(0, 7*s, 25*s, (7+1+2+1)*s)
	r2 := image.Rect((7+1)*s, 0, (7+1+2)*s, 18*s)
	r3 := image.Rect(0, (7+1)*s, 25*s, (7+1+2)*s)

	draw.Draw(m, r, blue, image.ZP, draw.Src)
	draw.Draw(m, r0, white, image.ZP, draw.Src)
	draw.Draw(m, r1, white, image.ZP, draw.Src)
	draw.Draw(m, r2, red, image.ZP, draw.Src)
	draw.Draw(m, r3, red, image.ZP, draw.Src)

	return m
}
