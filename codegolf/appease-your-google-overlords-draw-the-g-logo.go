/*

Write a program or function that takes in a positive integer N, and outputs an N×N pixel image of Google's "G" logo according to this* construction:

https://i.stack.imgur.com/fMbCw.png

For example, if N is 400, a 400×400 pixel logo should be output, with correct dimensions and colors:

https://i.stack.imgur.com/Ga0da.png

It should look accurate regardless of how large or small N is. e.g. here is N = 13: "G" logo 13x13 example

Your code should not need to connect to the internet. For example, scaling an externally hosted svg is not allowed. (Scaling an svg encoded in your code would be fine though.)

Anti-aliasing may be used or not. It's up to you.

Notice that the horizontal bar of the "G" does not extend all the way to the right edge of the image. The circle curves normally inward on the right edge before it is cut off.

The shortest code in bytes wins.

* The construction of the logo has been simplified for this challenge. The correct construction can be seen here and here.

https://g-design.storage.googleapis.com/production/v6/assets/article/evolving-the-google-identity/g-letter.mp4

*/

package main

import (
	"flag"
	"fmt"
	"image"
	"image/color"
	"image/png"
	"os"
	"strconv"
)

func main() {
	flag.Usage = usage
	flag.Parse()
	if flag.NArg() < 1 {
		usage()
	}

	n, _ := strconv.Atoi(flag.Arg(0))
	m := logo(n)
	png.Encode(os.Stdout, m)
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: [options] <size>")
	flag.PrintDefaults()
	os.Exit(2)
}

// ported from @JungHwan Min solution
func logo(n int) *image.RGBA {
	r := image.Rect(0, 0, n, n)
	m := image.NewRGBA(r)
	for y := 0; y < n; y++ {
		for x := 0; x < n; x++ {
			a := 2*float64(x)/float64(n) - 1
			b := 2*float64(y)/float64(n) - 1

			c := color.RGBA{}
			switch {
			case 0 < a && a < 0.8 && b*b < 0.04:
				c = color.RGBA{0x42, 0x85, 0xf4, 0xff}

			case a*a+b*b > 1 || a*a+b*b < 0.36:

			case a*a < b*b:
				if b < 0 {
					c = color.RGBA{0xea, 0x43, 0x35, 0xff}
				} else {
					c = color.RGBA{0x34, 0xa8, 0x53, 0xff}
				}

			case a < 0:
				c = color.RGBA{0xfb, 0xbc, 0x05, 0xff}

			case b >= -0.2:
				c = color.RGBA{0x42, 0x85, 0xf4, 0xff}
			}

			m.SetRGBA(x, y, c)
		}
	}
	return m
}
