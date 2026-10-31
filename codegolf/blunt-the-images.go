/*

Introduction
Sharp edges are, frankly, just plain dangerous so, given a PNG as input, blur the image using the method described below and blunt those damned sharp edges.

Method
To get the RGB value of each pixel, use the following three equations:

R = sqrt( 1/n * (1.5*Sum[a=1, n, R^2[a]]) )
G = sqrt( 1/n * (1.5*Sum[a=1, n, G^2[a]]) )
B = sqrt( 1/n * (1.5*Sum[a=1, n, B^2[a]]) )

Where Sum[a=1, n, R^2[a]] is the sum of the red values of each of the adjacent pixels squared. The value of n is the number of adjacent pixels (e.g., a corner pixel will have an n value of 3, whilst a pixel around the center of the image will have an n value of 8).

An adjacent pixel is a pixel which is 1 pixel away from the original pixel in all directions (left, right, up, down and on all of the diagonals).

https://i.stack.imgur.com/R971E.png

For example, in the following 3 x 1 image:

https://i.stack.imgur.com/M2QI5.jpg
The blurred RGB value of the middle pixel will be:

R = sqrt((1.5*(0^2 + 0^2))/2) = 0
G = sqrt((1.5*(0^2 + 255^2))/2) = 220.836 ~ 221
B = sqrt((1.5*(255^2 + 0^2))/2) = 220.836 ~ 221

where any decimal outputs are rounded to the nearest unit. You should not simply floor the result.

Therefore, the middle pixel will be the colour (0, 221, 221), or:

https://i.stack.imgur.com/ndh2b.png

Resulting in the image:
https://i.stack.imgur.com/UgsEO.jpg

You should repeat this process for every pixel in the image. (Note that you do this with the original pixels and not the modified pixels. Basically, you shouldn't overwrite the original image, and should keep it completely separate from the new, blurred image).

If you calculate any values to be greater than 255, assume that its value is 255 (I.e., a value of 374 would be set to 255).

The resulting output should be a separate PNG image (you may name this whatever you wish).

Examples
Super Mario

Original:
https://i.stack.imgur.com/6XCHW.png
Blurred:
https://i.stack.imgur.com/Kgmez.png

Checkerboard
Original:
https://i.stack.imgur.com/W9Ro4.png
Blurred:
https://i.stack.imgur.com/1p9Pq.png

Crisps
Original
https://i.stack.imgur.com/hJ0Qd.png
Blurred
https://i.stack.imgur.com/gqywH.png

Not so crisp anymore

American Gothic
Original:
https://i.stack.imgur.com/ugBuo.png
Blurred:
https://i.stack.imgur.com/EJIGc.png

To see the blur on larger images, it's best to run the program again on the blurred image:
https://i.stack.imgur.com/cqDw7.png

Challenge
The shortest code to blur a given PNG image wins.

You can use image processing libraries (such as PIL) but you must not use built-in blurring functions (Mathematica, I'm looking at you).

Note
As @orlp says below:

For the record, (to my knowledge) this is not a standard blurring method. This challenge is not an educational resource.

*/
package main

import (
	"bufio"
	"flag"
	"fmt"
	"image"
	"image/color"
	"image/draw"
	"image/png"
	"log"
	"math"
	"os"
)

func main() {
	log.SetFlags(0)
	log.SetPrefix("blunt: ")

	flag.Usage = usage
	flag.Parse()
	if flag.NArg() != 2 {
		usage()
	}

	pic, err := loadimage(flag.Arg(0))
	check(err)

	blu := blunt(pic)

	err = writeimage(flag.Arg(1), blu)
	check(err)
}

func check(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: <image> <output>")
	flag.PrintDefaults()
	os.Exit(2)
}

func loadimage(name string) (*image.RGBA, error) {
	f, err := os.Open(name)
	if err != nil {
		return nil, err
	}
	defer f.Close()

	r := bufio.NewReader(f)
	m, _, err := image.Decode(r)
	if err != nil {
		return nil, err
	}

	b := m.Bounds()
	p := image.NewRGBA(b)
	draw.Draw(p, b, m, image.ZP, draw.Src)
	return p, nil
}

func blunt(pic *image.RGBA) *image.RGBA {
	r := pic.Bounds()
	m := image.NewRGBA(r)
	for y := r.Min.Y; y < r.Max.Y; y++ {
		for x := r.Min.X; x < r.Max.X; x++ {
			var (
				cr, cg, cb float64
				cn         float64
			)

			co := pic.RGBAAt(x, y)
			for dy := -1; dy <= 1; dy++ {
				for dx := -1; dx <= 1; dx++ {
					p := image.Pt(x+dx, y+dy)
					if (dx == 0 && dy == 0) || !p.In(r) {
						continue
					}

					col := pic.RGBAAt(p.X, p.Y)
					cr += float64(col.R) * float64(col.R)
					cg += float64(col.G) * float64(col.G)
					cb += float64(col.B) * float64(col.B)
					cn += 1
				}
			}

			cr = math.Sqrt((1.5 * cr) / cn)
			cg = math.Sqrt((1.5 * cg) / cn)
			cb = math.Sqrt((1.5 * cb) / cn)

			cr = math.Round(cr)
			cg = math.Round(cg)
			cb = math.Round(cb)

			cr = clamp(cr, 0, 255)
			cg = clamp(cg, 0, 255)
			cb = clamp(cb, 0, 255)

			m.SetRGBA(x, y, color.RGBA{uint8(cr), uint8(cg), uint8(cb), co.A})
		}
	}
	return m
}

func writeimage(name string, m *image.RGBA) error {
	f, err := os.Create(name)
	if err != nil {
		return err
	}

	err = png.Encode(f, m)
	xerr := f.Close()
	if err == nil {
		err = xerr
	}

	return err
}

func clamp(x, a, b float64) float64 {
	if x < a {
		x = a
	} else if x > b {
		x = b
	}
	return x
}
