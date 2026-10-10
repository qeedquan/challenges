/*

Input
The name of a file in the raster graphics format of your choice. The chosen format must support at least 8 bits per channel and 3 channels.

Output
A file in the same format, with the same dimensions and pixels as the first, but whose pixels are grouped in descending order of the number of times they occur, sorted from left-to-right, top-to-bottom.

If certain colours of pixels appear the same number of times, their order is unspecified.
You must not overwrite the input file (use a different file name for the output).
Any and all third-party image processing libraries are permitted.

Example
https://i.sstatic.net/Uj69P.png

Will give output similar to:
https://i.sstatic.net/lDgk4.png

Especially in the lower parts of the image some variation may occur, due to different tie breaking between colours of equal frequency.

*/

package main

import (
	"flag"
	"fmt"
	"image"
	"image/color"
	"image/draw"
	_ "image/gif"
	_ "image/jpeg"
	"image/png"
	"log"
	"os"
	"sort"
)

func main() {
	flag.Parse()
	if flag.NArg() < 2 {
		usage()
	}

	m, err := loadimage(flag.Arg(0))
	check(err)

	sortedimage(m, count(m))

	err = writeimage(flag.Arg(1), m)
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

	m, _, err := image.Decode(f)
	if err != nil {
		return nil, err
	}

	return conv(m), nil
}

func conv(m image.Image) *image.RGBA {
	r := m.Bounds()
	p := image.NewRGBA(r)
	draw.Draw(p, r, m, image.ZP, draw.Src)
	return p
}

func sortedimage(m *image.RGBA, p []Chroma) {
	r := m.Bounds()
	i := 0
	for y := r.Min.Y; y < r.Max.Y; y++ {
		for x := r.Min.X; x < r.Max.X; x++ {
			if i >= len(p) {
				m.SetRGBA(x, y, color.RGBA{A: 255})
			} else {
				m.SetRGBA(x, y, p[i].c)
				if p[i].n--; p[i].n <= 0 {
					i++
				}
			}
		}
	}
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

func count(m *image.RGBA) []Chroma {
	h := make(map[color.RGBA]int)
	r := m.Bounds()
	for y := r.Min.Y; y < r.Max.Y; y++ {
		for x := r.Min.X; x < r.Max.X; x++ {
			c := m.RGBAAt(x, y)
			h[c]++
		}
	}

	var p []Chroma
	for k, v := range h {
		p = append(p, Chroma{v, k})
	}

	sort.SliceStable(p, func(i, j int) bool {
		if p[i].n == p[j].n {
			return rgba(p[i].c) < rgba(p[j].c)
		}
		return p[i].n > p[j].n
	})

	return p
}

func rgba(c color.RGBA) uint32 {
	return uint32(c.R) | uint32(c.G)<<8 | uint32(c.B)<<16 | uint32(c.A)<<24
}

type Chroma struct {
	n int
	c color.RGBA
}
