/*

Draw a line... except it must be your implementation of a line using only the ability to draw a point.
Think implementing a line is too easy? Try it :). You can output the result in ASCII text if you'd like instead of using a graphics library.
A successful implementation will be able to draw this (https://imgur.com/a8LuR).
Only being able to draw horizontal, vertical, and diagonal lines is not enough, and the lines can't contain any holes.
Also, if you're drawing a line (I'll use drawLine(x1, y1, x2, y2) as an example) using the following call: drawLine(100, 10, 200, 300), then the following call must draw the same line: drawLine(200, 300, 100, 10).

*/

package main

import (
	"image"
	"image/color"
	"image/draw"
	"image/png"
	"os"
)

func main() {
	png.Encode(os.Stdout, picture())
}

func picture() *image.RGBA {
	var (
		cyan  = color.RGBA{0, 183, 239, 255}
		black = color.RGBA{0, 0, 0, 255}
	)

	img := image.NewRGBA(image.Rect(0, 0, 207, 194))
	draw.Draw(img, img.Bounds(), image.NewUniform(color.White), image.ZP, draw.Src)
	supercoverline(img, 2, 97, 201, 97, cyan)
	supercoverline(img, 2, 99, 201, 99, cyan)
	supercoverline(img, 99, 187, 99, 4, cyan)
	supercoverline(img, 67, 2, 123, 185, black)
	supercoverline(img, 71, 191, 129, 6, black)
	supercoverline(img, 70, 1, 126, 185, black)
	supercoverline(img, 97, 87, 97, 4, cyan)
	supercoverline(img, 68, 189, 127, 4, black)
	supercoverline(img, 35, 113, 168, 79, black)
	supercoverline(img, 38, 115, 169, 81, black)
	supercoverline(img, 34, 81, 161, 117, black)
	return img
}

// https://xlinux.nist.gov/dads/HTML/bresenham.html
// http://eugen.dedu.free.fr/projects/bresenham/
func supercoverline(img *image.RGBA, x1, y1, x2, y2 int, col color.RGBA) {
	x, y := x1, y1
	dx := x2 - x1
	dy := y2 - y1

	// first point
	img.Set(x1, y1, col)

	// NB the last point can't be here, because of its previous point (which has to be verified)
	xstep, ystep := 1, 1
	if dy < 0 {
		ystep, dy = -1, -dy
	}
	if dx < 0 {
		xstep, dx = -1, -dx
	}

	ddy := 2 * dy // work with double values for full precision
	ddx := 2 * dx
	if ddx >= ddy { // first octant (0 <= slope <= 1)
		// compulsory initialization (even for errprev, needed when dx==dy)
		errprev, err := dx, dx    // start in the middle of the square
		for i := 0; i < dx; i++ { // do not use the first point (already done)
			x += xstep
			err += ddy
			if err > ddx { // increment y if AFTER the middle ( > )
				y += ystep
				err -= ddx
				// three cases (octant == right->right-top for directions below):
				if err+errprev < ddx { // bottom square also
					img.Set(x, y-ystep, col)
				} else if err+errprev > ddx { // left square also
					img.Set(x-xstep, y, col)
				} else { // corner: bottom and left squares also
					img.Set(x, y-ystep, col)
					img.Set(x-xstep, y, col)
				}
			}
			img.Set(x, y, col)
			errprev = err
		}
	} else { // the same as above
		errprev, err := dy, dy
		for i := 0; i < dy; i++ {
			y += ystep
			err += ddx
			if err > ddy {
				x += xstep
				err -= ddy
				if err+errprev < ddy {
					img.Set(x-xstep, y, col)
				} else if err+errprev > ddy {
					img.Set(x, y-ystep, col)
				} else {
					img.Set(x-xstep, y, col)
					img.Set(x, y-ystep, col)
				}
			}
			img.Set(x, y, col)
			errprev = err
		}
	}
	// assert ((y == y2) && (x == x2));  // the last point (y2,x2) has to be the same with the last point of the algorithm
}
