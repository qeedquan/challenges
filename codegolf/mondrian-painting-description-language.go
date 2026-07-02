/*

This challenge consists in coding an interpreter for a Mondrian painting description language (MPDL).

Language definition
The language operates on a stack of rectangles. A rectangle is defined by its upper left coordinate and lower right coordinate. Coordinates must be integers. The stack is initialized with a single rectangle with attributes (1,1,254,254)

Each command has the following format: <character><integer>

There are three commands:

v<integer> : perform a vertical split on the latest rectangle in the stack, at the position indicated by the parameter (as percentage). The source rectangle is removed from the stack and replaced with the two new rectangles that result of the split. The left rectangle is pushed on the stack, then the right rectangle. As rectangle coordinates are integers, fractions should be rounded to biggest smaller integer.

h<integer> : horizontal split. The top rectangle is pushed on the stack, then the bottom rectangle.

c<integer> : removes the latest rectangle from the stack and paints it to the color given as parameter. 1 = white, 2 = red, 3 = blue, 4 = yellow

Challenge
Write a program that takes as parameter a painting description and creates a 256x256 bitmap representation of the painted rectangles. The rectangles must be separated with a 3 pixel black line. A one or two pixel rectangle should have his non-black pixels hidden by the border black pixels.

The input can be read as a parameter or as a file, up to you. The commands should be separated by a space. You can assume that the input file has correct syntax and does not have trailing or leading spaces, tabs, etc. The output can be directly displayed on the screen, or saved to a file, up to you.

The shortest code wins.

Test
The following source:

v25 h71 v93 h50 c4 c1 c1 c2 h71 c3 h44 c1 c1
Should produce the Composition II in Red, Blue and Yellow:

https://i.stack.imgur.com/Zmw3O.png

*/

package main

import (
	"fmt"
	"image"
	"image/color"
	"image/png"
	"math"
	"os"
	"strings"
)

func main() {
	pic := interpret("v25 h71 v93 h50 c4 c1 c1 c2 h71 c3 h44 c1 c1")
	png.Encode(os.Stdout, pic)
}

func interpret(code string) *image.RGBA {
	dim := image.Rect(0, 0, 256, 256)
	pic := image.NewRGBA(dim)
	paint(pic, dim, white)

	stack := []image.Rectangle{
		image.Rect(1, 1, 254, 254),
	}

	insts := strings.Split(code, " ")
	for _, inst := range insts {
		var (
			op  byte
			val int
		)

		nread, _ := fmt.Sscanf(inst, "%c%d", &op, &val)
		if nread != 2 {
			continue
		}

		sp := len(stack) - 1
		if sp < 0 {
			break
		}

		switch op {
		case 'v', 'h':
			rect := stack[sp]
			rect0 := rect
			rect1 := rect

			if op == 'v' {
				x := interpolate(rect.Min.X, rect.Max.X, val)
				rect0.Max.X = x
				rect1.Min.X = x
			} else {
				y := interpolate(rect.Min.Y, rect.Max.Y, val)
				rect0.Max.Y = y
				rect1.Min.Y = y
			}

			stack[sp] = rect0
			stack = append(stack, rect1)

		case 'c':
			if 0 <= val && val < len(palette) {
				paint(pic, stack[sp], palette[val])
			}
			stack = stack[:sp]
		}
	}

	return pic
}

func paint(pic *image.RGBA, rect image.Rectangle, col color.RGBA) {
	for y := rect.Min.Y; y < rect.Max.Y; y++ {
		for x := rect.Min.X; x < rect.Max.X; x++ {
			pic.SetRGBA(x, y, col)
		}
	}

	for y := 0; y < 2; y++ {
		for x := rect.Min.X; x < rect.Max.X; x++ {
			pic.SetRGBA(x, rect.Min.Y+y, black)
			pic.SetRGBA(x, rect.Max.Y-y-1, black)
		}
	}

	for y := rect.Min.Y; y < rect.Max.Y; y++ {
		for x := 0; x < 2; x++ {
			pic.SetRGBA(rect.Min.X+x, y, black)
			pic.SetRGBA(rect.Max.X-x, y, black)
		}
	}
}

func interpolate(x0, x1, percent int) int {
	percent = min(max(percent, 0), 100)
	x := float64(x0) + float64((x1-x0)*percent)/100
	x = math.Round(x)
	return int(x)
}

var (
	white   = color.RGBA{255, 255, 255, 255}
	black   = color.RGBA{0, 0, 0, 255}
	red     = color.RGBA{255, 0, 0, 255}
	blue    = color.RGBA{0, 0, 121, 255}
	yellow  = color.RGBA{255, 255, 0, 255}
	palette = []color.RGBA{black, white, red, blue, yellow}
)
