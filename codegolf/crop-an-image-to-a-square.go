/*

In this challenge, you will take an input image and crop it to make a square, leaving only the central part of the input image.

The answers must work with landscape, portrait, or square input images. The width of the output image should be equal to the shortest side of the input image e.g. the result of a 200x300 image should be a 200x200 image. An equal amount must be cropped from both ends of the input image e.g. for a 200x300 input image, 50 pixels should be cropped from each end of the image, leaving only the central part of the image. Where its not possible to crop an equal amount from both sides e.g. a 200x301 image, the extra 1 pixel may be cropped from either end of the image. For a square input image, the output should be identical to the input.

Input:

The input file should be read from the hard disk of the machine running the program. You may choose which of bmp, jpeg, png or pnm to support as the input image format.

Output

The output file should be written to the hard disk of the machine running the program. The format of the output image should be bmp, jpeg, png or pnm.

Win Criteria

This is code golf. Shortest code wins.

Notes:

The input/output file paths do not count towards the program size.
The standard libraries of your programming language may be used. Other libraries are disallowed.
Standard loopholes apply.
Example:

Input Image:

https://i.stack.imgur.com/3GWEw.jpg

Expected Output:

https://i.stack.imgur.com/6m4fc.jpg

Images by kirill777 - licenced CC-BY 3.0

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

	err = writeimage(flag.Arg(1), crop(m))
	check(err)
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: <input> <output>")
	flag.PrintDefaults()
	os.Exit(2)
}

func check(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func crop(m *image.RGBA) *image.RGBA {
	b := m.Bounds()
	w := b.Dx()
	h := b.Dy()

	s := min(w, h)
	t := max(w, h)
	x := (t - h) / 2
	y := (t - w) / 2

	r := image.Rect(x, y, x+s, y+s)
	p := m.SubImage(r)
	return p.(*image.RGBA)
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
	png.Encode(w, img)

	err = w.Flush()
	xerr := f.Close()
	if err == nil {
		err = xerr
	}

	return err
}
