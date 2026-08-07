/*

This one is simple to describe and I could hardly believe that this was not golfed before:

For a given image (whatever format is supported by your language), find the unique colors and output a list of the colors.

Print the color code in hex RGB, that is a hash sign # followed by 2 digits for R, 2 digits for G and 2 digits for B. (#xxxxxx where x can be 0-9, A-F and/or a-f).
The hex code shall be followed by a space and the decimal pixel count, then a newline (\n or \r\n).
The list shall be sorted by count descending (most frequent color at the top).
If there's a tie (two colors with the same amount), the order is not important.
The image will not contain transparency, so any alpha value is not important. The alpha value may not be part of the output.
An image size of 4000x3000 must be supported (that may matter to type definitions)

Sample image "10red 20blue 30black 40white":
https://i.stack.imgur.com/QTE4O.png

Expected output:

#FFFFFF 40
#000000 30
#0000FF 20
#FF0000 10

Sample image "blue gradient":
https://i.stack.imgur.com/5s1Ob.png

One of the expected outputs (since the order of same colors may vary):

#718DFF 19
#5571FF 15
#3855FF 11
#8DAAFF 11
#1C38FF 7
#AAAAFF 7
#8D8DFF 6
#AAC6FF 6
#C6C6FF 5
#C6E2FF 4
#001CFF 3
#E2E2FF 3
#FFFFFF 3

Sample image "testImage", kindly provided by @Luis Mendo:
https://i.stack.imgur.com/z07VA.gif

Expected output:

#FFFFFF 18042
#000000 1754
#FF3300 204

Similar to this question, but the output is text, not an image.

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
	_ "image/png"
	"log"
	"os"
	"sort"
)

func main() {
	flag.Parse()
	if flag.NArg() < 1 {
		usage()
	}

	m, err := loadimage(flag.Arg(0))
	check(err)

	p := count(m)
	for _, p := range p {
		fmt.Printf("%v %v\n", strcol(p.c), p.n)
	}
}

func check(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: [options] <image>")
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
			return strcol(p[i].c) < strcol(p[j].c)
		}
		return p[i].n > p[j].n
	})

	return p
}

func strcol(c color.RGBA) string {
	return fmt.Sprintf("#%02X%02X%02X", c.R, c.G, c.B)
}

type Chroma struct {
	n int
	c color.RGBA
}
