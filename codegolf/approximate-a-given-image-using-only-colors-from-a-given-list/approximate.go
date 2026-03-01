/*

The Specs
Your program must read the image from one file and write the results to another file, the name of at least the first of which should be taken from the input

You may accept and return any image format or formats, as long as you specify in your answers which ones you are using

An exception should be thrown if the specified source file does not exist

The final image must be as close as possible to the initial image (by per-pixel euclidean metric on RGB values) while using only colors from a list read from the file "colors.txt" (it will not necessarily use all of them)

When determing the nearest color, you should use the euclidean metric on RGB values, Δc=sqrt((Δr)2+(Δg)2+(Δb)2), when two or more colors on the list are equally close, any of those colors is valid
The list of colors given will be formatted with one rgb color code on each line, with spaces seperating the red, green, and blue values

You may assume that at least three but no more than 1,000 colors will be listed

This is code golf, so the shortest program wins

Some test cases:
(if RGB values in the output images do not exactly match those in the list, this is due to a problem with Java's ImageIO.write)

input:
https://i.sstatic.net/dd6xF.jpg

colors.txt:
255 0 0
250 150 0
255 50 0
0 0 200
0 0 80
0 0 0

output:
https://i.sstatic.net/42pIi.jpg

input:
https://i.sstatic.net/1buZg.jpg

colors.txt:

100 60 0
0 0 20
0 0 70
0 20 90
15 15 15
100 100 100
120 120 120
150 150 150

output:
https://i.sstatic.net/ivB8i.jpg

input:
https://i.sstatic.net/au4cn.jpg

colors.txt:

0 0 0
10 20 15
25 25 20
35 30 20
40 35 25
55 55 60
70 60 50
130 100 80
130 140 145
140 100 70
165 130 90
200 160 130
230 210 220
250 250 250

output:
https://i.sstatic.net/XYXfD.jpg

input:
https://i.sstatic.net/yZ1lE.jpg

colors.txt:
0 0 0
70 50 40
80 0 0
120 100 90
120 120 120
170 150 90
170 170 170
170 200 195
190 140 100
190 205 165
210 170 120

output:
https://i.sstatic.net/SJan7.jpg

Again, I put together a java program to generate the sample output. I'll golf it down a little further, and then I may post it as an answer later.

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
	"math"
	"os"
)

func main() {
	flag.Usage = usage
	flag.Parse()
	if flag.NArg() != 3 {
		usage()
	}

	img, err := loadimage(flag.Arg(0))
	check(err)

	cols, err := getcolors(flag.Arg(1))
	check(err)

	closestimage(img, cols)

	err = writeimage(flag.Arg(2), img)
	check(err)
}

func check(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: [options] <input> <colors> <output>")
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

func closestimage(m *image.RGBA, p []color.RGBA) {
	r := m.Bounds()
	for y := r.Min.Y; y < r.Max.Y; y++ {
		for x := r.Min.X; x < r.Max.X; x++ {
			m.SetRGBA(x, y, closestcolor(p, m.RGBAAt(x, y)))
		}
	}
}

func closestcolor(p []color.RGBA, c color.RGBA) color.RGBA {
	b := math.MaxFloat64
	r := color.RGBA{}
	for i := range p {
		v := score(p[i], c)
		if v < b {
			b, r = v, p[i]
		}
	}
	return r
}

func score(a, b color.RGBA) float64 {
	dr := float64(a.R) - float64(b.R)
	dg := float64(a.G) - float64(b.G)
	db := float64(a.B) - float64(b.B)
	return dr*dr + dg*dg + db*db
}

func getcolors(name string) ([]color.RGBA, error) {
	f, err := os.Open(name)
	if err != nil {
		return nil, err
	}

	r := []color.RGBA{}
	s := bufio.NewScanner(f)
	for s.Scan() {
		c := color.RGBA{A: 255}
		l := s.Text()
		n, _ := fmt.Sscanf(l, "%d %d %d", &c.R, &c.G, &c.B)
		if n != 3 {
			continue
		}
		r = append(r, c)
	}
	return r, nil
}
