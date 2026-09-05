/*

Task
Given an image with a line on it, produce or display an image with the line extended till the edge of image. The line is black and the background is white. The image size is 100x100 The image comes in any reasonable format (e.g. jpg, png, ppm, bmp).

Line format
I'm using a simplified version of Bresenham's line algorithm for drawing lines. Lines will only have an integer slope so that the line will never partially cover a pixel but not color it:
https://i.stack.imgur.com/XeLYJ.png

At a minimum the line will be 3x3 unless the line is straight, in which case you will only see 3x1 or 1x3 in the image. Lines will also have one side on the edge of the image, so you only have to extend it in one direction.

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
	_ "image/png"
	"log"
	"math"
	"os"
)

func main() {
	flag.Parse()
	if flag.NArg() != 2 {
		usage()
	}

	m, err := readimage(flag.Arg(0))
	check(err)

	r := m.Bounds()

	p0, p1 := findline(m)
	p2 := lineparam(p0, p1, -r.Dx())
	p3 := lineparam(p0, p1, r.Dx())
	recolor(m, black, white)
	bresenham(m, p2.X, p2.Y, p3.X, p3.Y, black)

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

func findline(m *image.RGBA) (image.Point, image.Point) {
	p := image.Pt(math.MaxInt, math.MaxInt)
	q := image.Pt(math.MinInt, math.MinInt)
	r := m.Bounds()
	for y := r.Min.Y; y < r.Max.Y; y++ {
		for x := r.Min.X; x < r.Max.X; x++ {
			c := m.RGBAAt(x, y)
			if c.R != 0 || c.G != 0 || c.B != 0 {
				continue
			}

			if p.Y > y || (p.Y == y && p.X > x) {
				p = image.Pt(x, y)
			}
			if q.Y < y || (q.Y == y && q.X < x) {
				q = image.Pt(x, y)
			}
		}
	}

	return p, q
}

func recolor(m *image.RGBA, c0, c1 color.RGBA) {
	r := m.Bounds()
	for y := r.Min.Y; y < r.Max.Y; y++ {
		for x := r.Min.X; x < r.Max.X; x++ {
			c := m.RGBAAt(x, y)
			if c == c0 {
				m.SetRGBA(x, y, c1)
			}
		}
	}
}

func bresenham(m *image.RGBA, x0, y0, x1, y1 int, c color.RGBA) {
	dx := abs(x1 - x0)
	dy := -abs(y1 - y0)
	sx := -1
	sy := -1
	if x0 < x1 {
		sx = 1
	}
	if y0 < y1 {
		sy = 1
	}
	err := dx + dy
	for {
		m.SetRGBA(x0, y0, c)
		if x0 == x1 && y0 == y1 {
			break
		}
		e2 := 2 * err
		if e2 >= dy {
			err += dy
			x0 += sx
		}
		if e2 <= dx {
			err += dx
			y0 += sy
		}
	}
}

func lineparam(a, b image.Point, t int) image.Point {
	d := b.Sub(a)
	x := a.X + t*d.X
	y := a.Y + t*d.Y
	return image.Pt(x, y)
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}

var (
	white = color.RGBA{255, 255, 255, 255}
	black = color.RGBA{0, 0, 0, 255}
)
