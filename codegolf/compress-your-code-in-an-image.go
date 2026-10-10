/*

This is a quine variation.

Introduction
We all write short code, because some obscure reasons, but whatever we do, the'll take up at least 144 pixels/byte (with a 12px font). But what would happen, if we would encode our code in images? This is your task today.

Challenge
You task is to read in your own source code (non-proper quines are allowed, e.g. literally reading the source file), and create an image out of it, by setting the red, green and blue components of a pixel based on the ASCII value of the character.

Example:

We have the string "Hello world!"

Hello world!
Let's convert this to ASCII values:

72 101 108 108 111 32 119 111 114 108 100 33
Map the RGB values to it (If the source code's length is not divisible by 3, use 0s as the remaining characters):

 __________________________________________________
| R | G | B || R | G | B || R | G | B || R | G | B |
----------------------------------------------------
|72 |101|108||108|111|32 ||119|111|114||108|100|33 |
----------------------------------------------------
We then create the image with the smallest area out of it. We have 4 sets of RGB values, so the smallest image will be a 2*2 image, going from the top left pixel to the right:

https://i.sstatic.net/0DDnF.png

And we get this awfully colored image (resized, so it's at least visible, also proves the fact how small it can get)

Rules/Additional information
There's no input
The output should be as a separate file, or in a separate window.
For multibyte characters, split the character in 2 bytes.
The source code must be at least 1 byte long
The image should be the one from the possible sizes, wich has the closest width/height ratio to 1
The pixel count on the image should exactly be ceil(byte count / 3), no extra pixels should be added

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

var flags struct {
	scale int
}

func main() {
	flag.IntVar(&flags.scale, "scale", 32, "specify scale")
	flag.Usage = usage
	flag.Parse()
	if flag.NArg() != 1 {
		usage()
	}

	picture, err := compress(flag.Arg(0), flags.scale)
	check(err)

	png.Encode(os.Stdout, picture)
}

func check(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: [options] <file>")
	flag.PrintDefaults()
	os.Exit(2)
}

func compress(name string, scale int) (*image.RGBA, error) {
	file, err := os.Open(name)
	if err != nil {
		return nil, err
	}
	defer file.Close()

	var palette []color.RGBA
	reader := bufio.NewReader(file)
	for {
		r, err0 := reader.ReadByte()
		g, err1 := reader.ReadByte()
		b, err2 := reader.ReadByte()
		if err0 != nil {
			break
		}
		if err1 != nil {
			g = 0
		}
		if err2 != nil {
			b = 0
		}
		palette = append(palette, color.RGBA{r, g, b, 255})
	}

	pitch := int(math.Sqrt(float64(len(palette))))
	size := float64(pitch * scale)

	bounds := image.Rect(0, 0, int(size), int(size))
	picture := image.NewRGBA(bounds)
	draw.Draw(picture, bounds, image.NewUniform(color.Black), image.ZP, draw.Src)

	for index, color := range palette {
		x := index % pitch
		y := index / pitch
		position := image.Rect(x*scale, y*scale, (x+1)*scale, (y+1)*scale)
		draw.Draw(picture, position, image.NewUniform(color), image.ZP, draw.Src)
	}

	return picture, nil
}
