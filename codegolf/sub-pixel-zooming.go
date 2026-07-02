/*

Your task is to take a 24 BPP sRGB image and output the same image upscaled 3x into red, green, and blue subpixels. The resulting image will be made entirely of pure black, red, green, and blue pixels.

Each pixel from the source image, when zoomed, produces an arrangement of 9 sub-pixels that can be either on or off (i.e. their respective color or black). The specific arrangement uses three columns of red, green, and blue, in that order, like so:

https://i.stack.imgur.com/EqbgU.png

(Note that the borders on these "pixels" are for demonstration only.)

Since each of the nine subpixels can only be on or off, you will have to quantize the input image and use different subpixel patterns to achieve 3 levels of brightness.

For each subpixel in the image:

For color levels 0-74, all subpixels should be black.
For color levels 75-134, the middle subpixel should be the respective color and the other two should be black.
For color levels 135-179, the middle subpixel should be black and the other two should be the respective color
For color levels 180-255, all three subpixels should be their respective color
I chose these level ranges because those are what happened to look good

Apply this transformation to every pixel in the image and output the subpixel-upscaled image.

Single-pixel examples
rgb(40, 130, 175) will produce this pattern:

https://i.stack.imgur.com/du09P.png

rgb(160, 240, 100) will produce this pattern:

https://i.stack.imgur.com/4pBCK.png

Full Image Examples

https://i.stack.imgur.com/1BCtA.png
https://i.stack.imgur.com/2A2Sp.png

https://i.stack.imgur.com/LZb1S.png
https://i.stack.imgur.com/J251d.png

https://i.stack.imgur.com/AO0Nj.png
https://i.stack.imgur.com/Phmnb.png

Images sourced from Wikipedia

Rules and notes
Input and output may be in any convenient format, whether that's actual image files or (possibly nested) lists of RGB values.
You may assume the pixels are in the sRGB colorspace with 24BPP.
Happy golfing!

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

func main() {
	log.SetFlags(0)
	log.SetPrefix("sub-pixel-zooming: ")

	flag.Usage = usage
	flag.Parse()
	if flag.NArg() != 2 {
		usage()
	}

	m, err := load(flag.Arg(0))
	check(err)

	err = write(flag.Arg(1), subpixelzoom(m))
	check(err)
}

func check(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: [options] <infile> <outfile>")
	flag.PrintDefaults()
	os.Exit(2)
}

func load(name string) (*image.RGBA, error) {
	f, err := os.Open(name)
	if err != nil {
		return nil, err
	}
	defer f.Close()

	m, _, err := image.Decode(f)
	if err != nil {
		return nil, err
	}

	r := m.Bounds()
	p := image.NewRGBA(r)
	draw.Draw(p, r, m, image.ZP, draw.Src)
	return p, nil
}

func write(name string, m *image.RGBA) error {
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

func subpixelzoom(m *image.RGBA) *image.RGBA {
	r := m.Bounds()
	w := r.Dx()
	h := r.Dy()

	p := image.NewRGBA(image.Rect(0, 0, 3*w, 3*h))
	for y := 0; y < h; y++ {
		for x := 0; x < w; x++ {
			R := [3]color.RGBA{red, red, red}
			G := [3]color.RGBA{green, green, green}
			B := [3]color.RGBA{blue, blue, blue}

			c := m.RGBAAt(x, y)
			if c.R < 135 {
				R[0], R[2] = black, black
			}
			if c.G < 135 {
				G[0], G[2] = black, black
			}
			if c.B < 135 {
				B[0], B[2] = black, black
			}

			if c.R < 75 || (c.R >= 135 && c.R <= 179) {
				R[1] = black
			}
			if c.G < 75 || (c.G >= 135 && c.G <= 179) {
				G[1] = black
			}
			if c.B < 75 || (c.B >= 135 && c.B <= 179) {
				B[1] = black
			}

			X := 3 * x
			Y := 3 * y
			p.SetRGBA(X-1, Y-1, R[0])
			p.SetRGBA(X-1, Y+0, R[1])
			p.SetRGBA(X-1, Y+1, R[2])

			p.SetRGBA(X, Y-1, G[0])
			p.SetRGBA(X, Y+0, G[1])
			p.SetRGBA(X, Y+1, G[2])

			p.SetRGBA(X+1, Y-1, B[0])
			p.SetRGBA(X+1, Y+0, B[1])
			p.SetRGBA(X+1, Y+1, B[2])
		}
	}
	return p
}

var (
	red   = color.RGBA{255, 0, 0, 255}
	green = color.RGBA{0, 255, 0, 255}
	blue  = color.RGBA{0, 0, 255, 255}
	black = color.RGBA{0, 0, 0, 255}
)
