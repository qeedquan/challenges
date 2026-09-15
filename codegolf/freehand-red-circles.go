/*

Over on http://meta.stackoverflow.com, we have a few memes of our own. One of them is Freehand Red Circles.

See this post:

https://meta.stackexchange.com/questions/19478/the-many-memes-of-meta/19775#19775

So, the challenge is,

can you draw freehand red circles... with code?
Additional restrictions:

You will take an image as input, and you must output the image with freehand red circle added.
Must be predictable, i.e. same image input must result in same output. You can use randomness, but results have to be consistent for same input.
Output must be exactly the same image as input, except with circle (no other alterations).
The freehand red circle must look freehand (no perfect circles!), be red (obviously), and look generally like a circle (no random squiggly lines).
This is a popularity-contest, so the answer with the most upvotes at the beginning of March 2014 will win. There is no specific goal, other than "freehand red circles," so be as creative as possible so you get the most upvotes! (To be as unbiased as possible, I will upvote any answer that follows the rules.)

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
	"math/rand"
	"os"
	"strconv"
)

func main() {
	flag.Usage = usage
	flag.Parse()
	if flag.NArg() != 5 {
		usage()
	}

	m, err := readimage(flag.Arg(3))
	check(err)

	X, _ := strconv.ParseFloat(flag.Arg(0), 64)
	Y, _ := strconv.ParseFloat(flag.Arg(1), 64)
	R, _ := strconv.ParseFloat(flag.Arg(2), 64)
	freehand(m, X, Y, R)

	check(writeimage(flag.Arg(4), m))
}

func check(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: X Y R <input> <output>")
	flag.PrintDefaults()
	os.Exit(2)
}

/*

@user15259

X: [0, 100] x center of the circle as a percentage of image width
Y: [0, 100] y center of the circle as a percentage of image height
R: [0, 100] radius of the circle as a percentage of the image diagonal

For example, if the image size is [200, 200] and X=50, Y=50, R=50
The center will then be [0.5*200, 0.5*200] = [100, 100]
The radius will be sqrt(200**2 + 200**2) * 0.5 ~= 141.42

The algorithm picks a random angle a between [0, 180] degrees and a starting radius r=R
Then for a number of iterations proportional to R
Modulate the radius r by a small random amount and increase the angle by 1/r

Use the radius r and angle a that we generated to draw a 2x2 block of red centered at X, Y

This gives freehand looking circles by making the radius and angle squiggly as it traces out a circle

*/

func freehand(m *image.RGBA, X, Y, R float64) {
	b := m.Bounds()
	W := float64(b.Dx())
	H := float64(b.Dy())

	X = W * X / 100
	Y = H * Y / 100
	R = math.Hypot(W, H) * R / 100

	a := uniform(math.Pi)
	i := 2*math.Pi*R + uniform(R/4)
	r := R
	for ; i > 0; i-- {
		r += uniform(2.0) - 1.0
		f := math.Sin(a)*r + X
		g := math.Cos(a)*r + Y

		for x := f - 2; x <= f+2; x++ {
			for y := g - 2; y <= g+2; y++ {
				m.SetRGBA(int(x), int(y), color.RGBA{255, 0, 0, 255})
			}
		}
		a += 1 / R
	}
}

func uniform(x float64) float64 {
	return rand.Float64() * x
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
