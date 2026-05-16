/*

Description
For this challenge you will get a couple of images containing a secret word, you will have to unscramble the images to be able to read the words.

To unscramble the images you will have to line up all non-gray scale pixels on each "row" of the image.

Formal Inputs & Outputs
You get a scrambled image, which you will have to unscramble to get the original image.

Input description
Challenge 1: input

Challenge 2: input

Challenge 3: input

Output description
You should post the correct images or words.

Notes/Hints
The colored pixels are red (#FF0000, rgb(255, 0, 0))

Bonus
Bonus: input

This image is scrambled both horizontally and vertically.
The colored pixels are a gradient from green to red ((255, 0, _), (254, 1, _), ..., (1, 254, _), (0, 255, _)).

Finally
Have a good challenge idea?

Consider submitting it to r/dailyprogrammer_ideas

*/

package main

import (
	"bufio"
	"flag"
	"fmt"
	"image"
	"image/draw"
	_ "image/gif"
	_ "image/jpeg"
	"image/png"
	"log"
	"os"
)

func main() {
	flag.Usage = usage
	flag.Parse()
	if flag.NArg() != 2 {
		usage()
	}

	m, err := readimage(flag.Arg(0))
	check(err)

	unscramble(m)

	check(writeimage(flag.Arg(1), m))
}

func check(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: <input> <output>")
	flag.PrintDefaults()
	os.Exit(2)
}

func rotate(m *image.RGBA, y int) {
	r := m.Bounds()
	c := m.RGBAAt(r.Min.X, y)
	for x := r.Min.X + 1; x < r.Max.X; x++ {
		nc := m.RGBAAt(x, y)
		m.SetRGBA(x, y, c)
		c = nc
	}
	m.SetRGBA(r.Min.X, y, c)
}

func unscramble(m *image.RGBA) {
	r := m.Bounds()
	w := r.Dx()
	for y := r.Min.Y; y < r.Max.Y; y++ {
		s := 0
		for x := r.Min.X; x < r.Max.X; x++ {
			c := m.RGBAAt(x, y)
			if c.R != c.G || c.R != c.B {
				s = x
				break
			}
		}

		for range w - s {
			rotate(m, y)
		}
	}
}

func readimage(name string) (*image.RGBA, error) {
	f, err := os.Open(name)
	if err != nil {
		return nil, err
	}
	defer f.Close()

	br := bufio.NewReader(f)
	m, _, err := image.Decode(br)
	if err != nil {
		return nil, err
	}

	r := m.Bounds()
	p := image.NewRGBA(r)
	draw.Draw(p, r, m, image.ZP, draw.Src)

	return p, nil
}

func writeimage(name string, img *image.RGBA) error {
	f, err := os.Create(name)
	if err != nil {
		return err
	}

	w := bufio.NewWriter(f)
	err = png.Encode(w, img)
	if err != nil {
		return err
	}

	err = w.Flush()
	xerr := f.Close()
	if err == nil {
		err = xerr
	}

	return err
}
