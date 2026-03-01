/*

Introduction
A quixel is a quantum pixel. Similar to a classical pixel, it is represented with 3 integer values (Red, Green, Blue). However, quixels are in a super position of these 3 states instead of a combination. This super position only lasts until the quixel is observed at which point it collapses to one of three classical pixels; RGB(255,0,0), RGB(0,255,0) and RGB(0,0,255).

Specification
Representation
Each quixel is represented as an array of 3 integers between 0 and 255, r, g and b respectively.
Super Positions
Each quixel is in a super position between the Red, Blue and Green states represented by R, G and B respectively.

Observation
When each quixel is observed it collapses into one of the three states. The probability of each classical state is R = (r + 1) / (r + g + b +3), G = (g + 1) / (r + g + b + 3) and B = (b + 1) / (r + g + b + 3). This way each classical state always as a non-zero probability of showing up.

Input
The function or program should take a image of quixels. How it does this is flexible. A filename, using a multi-dimensional array, etc are all acceptable.

Output
The function or program should produce an image of classical pixels. The data structure for this produced image is also flexible. Note that all of the pixels should be one of these three: RGB(255,0,0), RGB(0,255,0) and RGB(0,0,255)
The output should not be deterministic; these are quantum pixels! The same input should result in different outputs.
If your language has no way of generating a random number, you can take random bytes as input

Scoring
This is code-golf so fewest bytes win.

*/

package main

import (
	"bufio"
	"flag"
	"fmt"
	"image"
	"image/color"
	"image/draw"
	_ "image/gif"
	_ "image/jpeg"
	"image/png"
	"log"
	"math/rand"
	"os"
)

type Quixel struct {
	*image.RGBA
}

func main() {
	flag.Usage = usage
	flag.Parse()
	if flag.NArg() < 2 {
		usage()
	}

	m, err := loadimage(flag.Arg(0))
	check(err)

	err = writeimage(flag.Arg(1), m)
	check(err)
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: [options] <input> <output>")
	flag.PrintDefaults()
	os.Exit(2)
}

func check(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func loadimage(name string) (image.Image, error) {
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
	return &Quixel{p}, nil
}

func writeimage(name string, m image.Image) error {
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

func (q *Quixel) At(x, y int) color.Color {
	c := q.RGBA.RGBAAt(x, y)
	s := float64(c.R) + float64(c.G) + float64(c.B) + 3
	r := (float64(c.R) + 1) / s
	g := (float64(c.G) + 1) / s
	b := (float64(c.B) + 1) / s

	p := color.RGBA{255, 0, 0, 255}
	switch x := rand.Float64(); {
	case r <= x && x <= r+g:
		p = color.RGBA{0, 255, 0, 255}
	case r+g < x && x <= r+g+b:
		p = color.RGBA{0, 0, 255, 255}
	}
	return p
}
