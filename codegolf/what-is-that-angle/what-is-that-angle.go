/*

The goal of this challenge is to determine the angle of a line in a image.

Rules on the image:

The image background will be white (#FFFFFF)
The stroke of the line will be black (#000000)
The line will NOT be anti-aliased
The image will be 100x100 pixels
The line will start at the center of the image
The line will start pointing down (6-OClock)
The line will be 50 pixels long
The angle of the line will be measured going counterclockwise from the starting position
The image codec will be either .jpg or .png
Input format will be a file name passed by the command line arg, script input, or function arg. Output format is simple - just output the number of degrees (e.g. 90).

Answers can be ±1 degree of the stated measure. Here are a few example images:

Here is the code used to create the images (this is coded with Processing):

int deg = 45;

int centX = width/2, centY = height/2;

background(255);
noSmooth();
line(centX,
     centY,
     centX + sin(radians(deg))*50,
     centY + cos(radians(deg))*50);

saveFrame("line-"+deg+".png");// image codec can be changed here. use '.png' or '.jpg'

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
	_ "image/png"
	"log"
	"math"
	"os"
)

func main() {
	flag.Parse()
	if flag.NArg() != 1 {
		usage()
	}

	m, err := readimage(flag.Arg(0))
	check(err)

	fmt.Println(detect(m))
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: [options] <image>")
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

func detect(m *image.RGBA) float64 {
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

	o := midpoint(r)
	if distance(o, q) < distance(o, p) {
		p, q = q, p
	}

	t := math.Atan2(float64(q.Y-p.Y), float64(q.X-p.X))
	t = 360 - math.Mod(deg2rad(t)+270, 360)
	if t >= 360 {
		t -= 360
	}
	return t
}

func deg2rad(x float64) float64 {
	return x * 180 / math.Pi
}

func distance(a, b image.Point) float64 {
	return math.Hypot(float64(a.X-b.X), float64(a.Y-b.Y))
}

func midpoint(r image.Rectangle) image.Point {
	return image.Pt(
		(r.Min.X+r.Max.X)/2,
		(r.Min.Y+r.Max.Y)/2,
	)
}
