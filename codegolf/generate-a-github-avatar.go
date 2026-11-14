/*

Background / Description
Note: as @HelkaHomba points out, the actual GitHub identicons are not actually random but based on the hash of a username

The default GitHub avatar is a 5x5-pixel image. A color is picked randomly, and then random pixels are filled in on one side (right or left, 2x5 size) using that color. Then that side is copied & flipped to the other side, across the y-axis. The pixels left over that are not filled in are #F0F0F0, or rgb(240,240,240).

The center column's pixels (1x5 size) are then randomly filled in, using the same color as previously.

Output
Note: for this challenge we will ignore the space that encloses the GitHub avatars

The program should output a 5x5 pixel image file. See http://meta.codegolf.stackexchange.com/a/9095/42499 for specifics

Examples
Note: these were obviously scaled up from 5x5 so you can see them

https://i.stack.imgur.com/N1EeF.png
https://i.stack.imgur.com/7h1ea.png

Good luck!

*/

package main

import (
	"flag"
	"fmt"
	"image"
	"image/color"
	"image/draw"
	"image/png"
	"log"
	"math/rand"
	"os"
)

var (
	avatarsize = flag.Int("a", 5, "avatar size")
	pixelsize  = flag.Int("s", 32, "pixel size")
)

func main() {
	flag.Parse()
	if flag.NArg() < 1 {
		usage()
	}

	m := mkimage(avatar(*avatarsize), *pixelsize)
	f, err := os.Create(flag.Arg(0))
	check(err)

	check(png.Encode(f, m))
	check(f.Close())
}

func check(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: [options] file")
	flag.PrintDefaults()
	os.Exit(2)
}

func mkimage(p [][]color.RGBA, s int) *image.RGBA {
	n := len(p)
	r := image.Rect(0, 0, n*s, n*s)
	m := image.NewRGBA(r)
	for y := range p {
		for x := range p[y] {
			draw.Draw(m, image.Rect(x*s, y*s, (x+1)*s, (y+1)*s), image.NewUniform(p[y][x]), image.ZP, draw.Src)
		}
	}
	return m
}

func avatar(n int) [][]color.RGBA {
	c := randrgb()
	p := make([][]color.RGBA, n)
	for i := range p {
		p[i] = make([]color.RGBA, n)
	}

	for y := range p {
		for x := range p[y] {
			p[y][x] = color.RGBA{240, 240, 240, 255}
		}

		if rand.Intn(2) == 1 {
			p[y][n/2] = c
		}
	}

	for x := 0; x < n/2; x++ {
		for y := range p {
			if rand.Intn(2) == 1 {
				p[y][x] = c
				p[y][n-x-1] = c
			}
		}
	}

	return p
}

func randrgb() color.RGBA {
	return color.RGBA{
		R: uint8(rand.Intn(256)),
		G: uint8(rand.Intn(256)),
		B: uint8(rand.Intn(256)),
		A: 255,
	}
}
