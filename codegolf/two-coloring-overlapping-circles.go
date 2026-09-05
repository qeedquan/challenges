/*

Write a program or function that takes in the following input in a reasonable format of your choice:

Two positive integers W and H that define the width and height of the image you'll be generating.

Two RGB colors C1 and C2 that will be used to color the image.

A list of 3-tuples of the form (r, x, y) that define circles with radius r and center x, y in the plane of the image. r is a positive integer and x and y are any integers. The top left pixel of the image is 0, 0 and the x-axis increases to the right and the y-axis increases downward.

Output an image with dimensions W by H that is colored with C1 and C2 such that no two neighboring regions defined by all the overlapping circles are the same color.

For example: If the input is

W = 300
H = 200
C1 = (255, 200, 0)
C2 = (128, 0, 255)
Circles = (25, 50, 80), (40, 80, 120), (300, -100, 6), (17, 253, 162)
then the circle boundaries look like this:
https://i.sstatic.net/32ZWG.png

There are six distinct, contiguous regions in the image created by the circles. Each region must be colored with C1 (yellow) or C2 (purple) such that no two neighboring regions are the same color.

There are two ways to do this, their only difference being that the colors are swapped:
https://i.sstatic.net/B9i2M.png
https://i.sstatic.net/xYDKp.png

Thus, either of these two images would be valid output for the example input.

Something like this would be invalid output since two yellow regions neighbor each other.

Your output images should follow these guidelines:

Besides C1 and C2, a third, neutral color such as black or white may be used for circle boundaries as long as they are no more than 5 pixels thick. (Black, 1-pixel thick boundaries are present in the example above.)

Circles boundaries are not required, however. The regions may neighbor each other directly:
https://i.sstatic.net/FxVwY.png
https://i.sstatic.net/22Ll0.png

Both of these is another valid output to the example above.

Circles should be as accurate as reasonably possible, using circle drawing algorithms or whatever your graphics library provides.

In general, pixel-perfection is not required, but if the input parameters are scaled equally larger and larger, the resulting image should become more and more accurate.

Anti-aliasing is allowed but not required.

Gridlines or axis labels etc. in the background are not allowed.

The shortest code in bytes wins.

More Examples
All using these inputs with different sets of circles:

W = 100
H = 60
C1 = (255, 0, 0)
C2 = (0, 0, 255)
In any example the colors can be swapped and remain valid.

Circles =
A. empty list
B. (13, 16, 20)
C. (30, 16, 20)
D. (200, 16, 20)
E. (42, 50, 20)
F. (42, 50, 20), (17, 40, 30)
G. (42, 50, 20), (17, 20, 30)
H. (42, 50, 20), (17, 10, 30), (10, 50, 30)
I. (42, 50, 20), (17, 10, 30), (35, 50, 20)
J. (18, 36, 40), (18, 63, 40), (18, 50, 20)
K. (100, -10, -20), (60, 50, -10)
L. (18, 36, 40), (18, 63, 40), (18, 50, 20), (14, 50, 20), (5, 50, 18), (20, 0, 0), (70, 22, 0), (10000, -9970, 0), (135, 100, -80)

A. https://i.sstatic.net/lvbth.png
B. https://i.sstatic.net/bVjqk.png
C. https://i.sstatic.net/8Ashr.png
D. https://i.sstatic.net/lvbth.png
E. https://i.sstatic.net/2P9tT.png
F. https://i.sstatic.net/GygSx.png
G. https://i.sstatic.net/aArsj.png
H. https://i.sstatic.net/2TEYw.png
I. https://i.sstatic.net/Aig4n.png
J. https://i.sstatic.net/FkZLe.png
K. https://i.sstatic.net/AWrkW.png
L. https://i.sstatic.net/kXh8W.png
*/

package main

import (
	"image"
	"image/color"
	"image/png"
	"log"
	"os"
)

type Circle struct {
	radius int
	x, y   int
}

func main() {
	purple := color.RGBA{255, 200, 0, 255}
	yellow := color.RGBA{128, 0, 255, 255}
	red := color.RGBA{255, 0, 0, 255}
	blue := color.RGBA{0, 0, 255, 255}
	O := []Circle{{25, 50, 80}, {40, 80, 120}, {300, -100, 6}, {17, 253, 162}}
	A := []Circle{}
	B := []Circle{{13, 16, 20}}
	C := []Circle{{30, 16, 20}}
	D := []Circle{{200, 16, 20}}
	E := []Circle{{42, 50, 20}}
	F := []Circle{{42, 50, 20}, {17, 40, 30}}
	G := []Circle{{42, 50, 20}, {17, 20, 30}}
	H := []Circle{{42, 50, 20}, {17, 10, 30}, {10, 50, 30}}
	I := []Circle{{42, 50, 20}, {17, 10, 30}, {35, 50, 20}}
	J := []Circle{{18, 36, 40}, {18, 63, 40}, {18, 50, 20}}
	K := []Circle{{100, -10, -20}, {60, 50, -10}}
	L := []Circle{{18, 36, 40}, {18, 63, 40}, {18, 50, 20}, {14, 50, 20}, {5, 50, 18}, {20, 0, 0}, {70, 22, 0}, {10000, -9970, 0}, {135, 100, -80}}

	output("circles_O.png", 300, 200, purple, yellow, O)
	output("circles_A.png", 100, 60, blue, red, A)
	output("circles_B.png", 100, 60, blue, red, B)
	output("circles_C.png", 100, 60, blue, red, C)
	output("circles_D.png", 100, 60, blue, red, D)
	output("circles_E.png", 100, 60, blue, red, E)
	output("circles_F.png", 100, 60, blue, red, F)
	output("circles_G.png", 100, 60, blue, red, G)
	output("circles_H.png", 100, 60, blue, red, H)
	output("circles_I.png", 100, 60, blue, red, I)
	output("circles_J.png", 100, 60, blue, red, J)
	output("circles_K.png", 100, 60, blue, red, K)
	output("circles_L.png", 100, 60, blue, red, L)
}

func output(name string, width, height int, color1, color2 color.RGBA, circles []Circle) {
	picture := generate(width, height, color1, color2, circles)
	writepng(name, picture)
}

/*

@Matthew Roh

Product[k=1, n] ((x-x[k])^2 + (y-y[k])^2 - r^2) >= 0

Explanation
The product of multiple circle equations ((x-a)^2+(y-b)^2-r^2) >= 0 will make a graph which this question needs.
In the equation, n is the size of the array, and (x, y or r)_k is the kth (x, y, or r) element.

*/

func generate(width, height int, color1, color2 color.RGBA, circles []Circle) *image.RGBA {
	bounds := image.Rect(0, 0, width, height)
	picture := image.NewRGBA(bounds)
	for y := range height {
		for x := range width {
			if energy(x, y, circles) >= 0 {
				picture.SetRGBA(x, y, color1)
			} else {
				picture.SetRGBA(x, y, color2)
			}
		}
	}
	return picture
}

func energy(x, y int, circles []Circle) int {
	if len(circles) == 0 {
		return 0
	}

	result := 1
	for _, c := range circles {
		dx := x - c.x
		dy := y - c.y
		dr := c.radius
		if dx*dx+dy*dy < dr*dr {
			result *= dx*dx + dy*dy - dr*dr
		}
	}
	return result
}

func writepng(name string, picture *image.RGBA) {
	file, err := os.Create(name)
	if err != nil {
		log.Fatal(err)
	}
	defer file.Close()

	err = png.Encode(file, picture)
	if err != nil {
		log.Fatal(err)
	}
}
