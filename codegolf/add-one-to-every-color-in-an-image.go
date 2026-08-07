/*

You would simply take this image and make every color added one to every hexadecimal digit. For example, #49de5f would become #5aef60 (with the 9 looping to an a, and the f looping to a 0.)

https://i.stack.imgur.com/CU4Ez.png
https://i.stack.imgur.com/JKsUY.png

This would also mean that all white (#ffffff) would become black (#000000) because all f loops back to 0, but all black will become a lighter shade of black (#111111).
https://i.stack.imgur.com/IpNyi.png
https://i.stack.imgur.com/xng8i.png

Scoring is based on the least number of bytes used, as this is a code-golf question.

Use the below image as the input image for your code, and put the output image of your code into your answer.

https://i.stack.imgur.com/m7Qmg.png

If you want to, you can also use this other rainbow image:

https://i.stack.imgur.com/bJ7US.jpg

*/

package main

import (
	"bufio"
	"flag"
	"fmt"
	"image"
	"image/draw"
	"image/png"
	"log"
	"os"
)

func main() {
	flag.Usage = usage
	flag.Parse()
	if flag.NArg() < 2 {
		usage()
	}

	img, err := loadimage(flag.Arg(0))
	check(err)

	err = writeimage(flag.Arg(1), add1(img))
	check(err)
}

func check(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: [options] <input> <output>")
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

func add1(m *image.RGBA) *image.RGBA {
	r := m.Bounds()
	for y := r.Min.Y; y < r.Max.Y; y++ {
		for x := r.Min.X; x < r.Max.X; x++ {
			c := m.RGBAAt(x, y)
			c.R = inc(c.R)
			c.G = inc(c.G)
			c.B = inc(c.B)
			m.SetRGBA(x, y, c)
		}
	}
	return m
}

func inc(x uint8) uint8 {
	lo := (x&0xf + 1) & 0xf
	hi := (x>>4 + 1) & 0xf
	return hi<<4 | lo
}
