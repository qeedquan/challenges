/*

Given a hue between 0° and 360°, generate an image file or display an image of an HSV (hue-saturation-value) color picker square for that hue, e.g. for the input 123:

https://i.sstatic.net/xFyWsI6i.png

The output must be a square at least 256 pixels on a side with saturation varying from 0.0% to 100.0% left-to-right and value varying from 100.0% to 0.0% top-to-bottom. Each pixel should be a unique color, but rounding errors causing adjacent pixels to be equal are allowed.

Input
The input will be a single integer between 0 and 360 inclusive representing the hue in degrees.

Output
The output must either be displayed on the screen or written to a file or stdout in a common image file format.

Entries must include an example image file (converted to an SE-friendly format if necessary), screenshot, or snippet (for HTML/CSS/JavaScript entries).

Output using a lossy file format will necessarily have compression artifacts that may affect the uniqueness or order of the pixels. This is allowed.

Rules
Standard rules apply. Standard loopholes are forbidden.

This is code-golf; shortest solution in bytes wins.

*/

package main

import (
	"flag"
	"fmt"
	"image"
	"image/color"
	"image/png"
	"log"
	"math"
	"os"
)

var flags struct {
	size int
	hue  float64
}

func main() {
	parseflags()
	picture := generate(flags.size, flags.hue)

	file, err := os.Create(flag.Arg(0))
	check(err)
	defer file.Close()

	err = png.Encode(file, picture)
	check(err)
}

func check(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: [options] image.png")
	flag.PrintDefaults()
	os.Exit(2)
}

func parseflags() {
	flag.Usage = usage
	flag.IntVar(&flags.size, "size", 256, "specify image size")
	flag.Float64Var(&flags.hue, "hue", 130, "specify hue in degrees")
	flag.Parse()
	if flag.NArg() < 1 {
		usage()
	}
}

func generate(size int, hue float64) *image.RGBA {
	bounds := image.Rect(0, 0, size, size)
	picture := image.NewRGBA(bounds)
	for y := range size {
		for x := range size {
			saturation := float64(x) / float64(size)
			value := 1 - float64(y)/float64(size)
			red, green, blue := hsv2rgb(hue, saturation, value)

			picture.SetRGBA(x, y, color.RGBA{
				uint8(red * 255),
				uint8(green * 255),
				uint8(blue * 255),
				255,
			})
		}
	}
	return picture
}

func hsv2rgb(H, S, V float64) (R, G, B float64) {
	C := V * S
	HP := math.Mod(H/60.0, 6)
	X := C * (1 - math.Abs(math.Mod(HP, 2)-1))
	M := V - C

	if 0 <= HP && HP < 1 {
		R = C
		G = X
		B = 0
	} else if 1 <= HP && HP < 2 {
		R = X
		G = C
		B = 0
	} else if 2 <= HP && HP < 3 {
		R = 0
		G = C
		B = X
	} else if 3 <= HP && HP < 4 {
		R = 0
		G = X
		B = C
	} else if 4 <= HP && HP < 5 {
		R = X
		G = 0
		B = C
	} else if 5 <= HP && HP < 6 {
		R = C
		G = 0
		B = X
	} else {
		R = 0
		G = 0
		B = 0
	}

	R += M
	G += M
	B += M
	return
}
