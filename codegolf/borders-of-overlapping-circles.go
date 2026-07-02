/*

Given the coordinates of several points on a plane, and the radius of a circle surrounding each point, draw polygons representing the circles and the edges where the circles meet. Straight edges will always fall along circle-circle intersection lines, but might not follow the full length of these lines.

Per mbomb007's suggestion, imagine the behavior of 2D soap bubbles. That's technically wrong, because soap bubbles would always meet at 120° angles to minimize energy, while these circles may meet at any angle.

This is a Voronoi diagram, minus a defined area plane. Thanks Andreas. This is actually a generalization of a Voronoi diagram called a power diagram.

Examples
For example, given two points and two radii, the output might look like this:
https://i.sstatic.net/5xKZE.png

Add another point and radius and the output might look like this:
https://i.sstatic.net/vaplX.png

Input
You can structure the input however you wish. Please post results with the following inputs.

Test 1

x: 10, y: 10, r: 10
x: 25, y: 12, r: 8
Test 2

x: 8, y: 10, r: 6
x: 20, y: 8, r: 4
x: 18, y: 20, r: 12
Output
Output should be graphical and should include polygon borders, but nothing else is required. Points and intersections do not need to be represented like they are in the examples.

Constraints
No point will exist within the radius of another circle.
Standard codegolf rules.
No answers with loopholes will be accepted, but feel free to have fun with it.

*/

package main

import (
	"bufio"
	"flag"
	"fmt"
	"image"
	"image/color"
	"math"
	"os"
)

var flags struct {
	size   int
	shadow float64
}

func main() {
	parseflags()

	test("circle_1.pgm", []Circle{{10, 10, 10}, {25, 12, 8}})
	test("circle_2.pgm", []Circle{{8, 10, 6}, {20, 8, 4}, {18, 20, 12}})
	test("circle_3.pgm", []Circle{
		{6, 63, 4}, {16, 88, 9}, {64, 94, 11}, {97, 96, 3}, {23, 32, 13}, {54, 14, 7},
		{41, 81, 3}, {7, 7, 4}, {77, 18, 8}, {98, 55, 4}, {2, 56, 7}, {62, 18, 5},
		{13, 74, 2}, {33, 56, 12}, {49, 48, 4}, {6, 76, 2}, {82, 70, 9},
		{21, 71, 2}, {27, 5, 10}, {3, 32, 6}, {70, 62, 6}, {74, 46, 4}, {21, 60, 7},
		{18, 47, 7}, {94, 2, 4}, {39, 97, 7}, {62, 63, 2}, {87, 29, 8}, {19, 17, 4},
		{61, 23, 2}, {73, 1, 8}, {40, 17, 13}, {99, 41, 4}, {81, 57, 7}, {1, 68, 5},
		{38, 3, 4}, {46, 36, 9}, {4, 39, 2}, {73, 77, 3}, {93, 19, 10}, {67, 42, 3},
		{96, 65, 2}, {2, 16, 3}, {28, 92, 3}, {54, 58, 2}, {39, 86, 5}, {84, 82, 5},
		{79, 43, 4}, {5, 47, 1}, {34, 41, 8}, {65, 5, 2}, {9, 44, 3}, {53, 3, 6}, {1, 12, 1},
		{81, 95, 7}, {74, 31, 2}, {63, 61, 1}, {35, 72, 1}, {44, 71, 2}, {57, 35, 5},
		{46, 65, 6}, {57, 45, 4}, {93, 94, 1}, {99, 81, 13}, {13, 58, 4}, {68, 32, 6},
		{11, 2, 6}, {52, 98, 7}, {51, 25, 5}, {84, 2, 2}, {44, 92, 3}, {23, 72, 2},
		{32, 99, 7}, {13, 19, 3}, {97, 29, 8}, {58, 80, 3}, {67, 82, 5}, {59, 60, 3},
		{86, 87, 5}, {29, 73, 2}, {5, 93, 4}, {42, 74, 1}, {75, 85, 8}, {91, 53, 5},
		{23, 82, 4}, {19, 97, 8}, {51, 88, 3}, {67, 12, 6}, {60, 53, 1}, {66, 72, 2},
		{57, 64, 2}, {66, 49, 2}, {44, 0, 4}, {11, 69, 1}, {93, 60, 5}, {56, 50, 3},
		{19, 68, 3}, {64, 75, 3}, {6, 17, 2}, {82, 5, 2},
	})
	test("circle_4.pgm", []Circle{{7, 9, 7}, {1, 3, 2}, {4, 0, 4}, {9, 2, 4}, {0, 8, 5}})
}

func parseflags() {
	flag.IntVar(&flags.size, "size", 500, "specify image size")
	flag.Float64Var(&flags.shadow, "shadow", 1, "specify shadow factor")
	flag.Parse()
}

func test(name string, circles []Circle) {
	err := writepgm(name, render(flags.size, flags.shadow, circles))
	if err != nil {
		panic(err)
	}
}

func writepgm(name string, picture *image.RGBA) error {
	file, err := os.Create(name)
	if err != nil {
		return err
	}
	defer file.Close()

	stream := bufio.NewWriter(file)
	defer stream.Flush()

	bounds := picture.Bounds()
	fmt.Fprintf(stream, "P2 %d %d 255\n", bounds.Dx(), bounds.Dy())
	for y := bounds.Min.Y; y < bounds.Max.Y; y++ {
		for x := bounds.Min.X; x < bounds.Max.X; x++ {
			shade := picture.RGBAAt(x, y)
			fmt.Fprintln(stream, shade.A)
		}
	}
	return nil
}

type Circle struct {
	x, y   float64
	radius float64
}

// ported from @Anders Kaseorg solution
func render(size int, shadow float64, circles []Circle) *image.RGBA {
	x0, y0, x1, y1 := bounds(circles)
	aspect := (-x1 - x0) / float64(size-1)
	width := size
	height := int(2 - (y0+y1)/aspect)

	picture := image.NewRGBA(image.Rect(0, 0, width, height))
	for yi := range height {
		for xi := range width {
			x, y := float64(width-xi), float64(height-yi)
			proximal, locus := closest(x1, y0, aspect, shadow, x, y, circles)
			shade := pixelate(x1, y0, aspect, shadow, proximal, locus, x, y, circles)
			picture.SetRGBA(xi, yi, color.RGBA{A: shade})
		}
	}
	return picture
}

func bounds(circles []Circle) (x0, y0, x1, y1 float64) {
	x0, y0 = math.MaxInt, math.MaxInt
	x1, y1 = math.MaxInt, math.MaxInt
	for _, circle := range circles {
		x0 = min(x0, circle.x-circle.radius)
		y0 = min(y0, circle.y-circle.radius)
		x1 = min(x1, -circle.x-circle.radius)
		y1 = min(y1, -circle.y-circle.radius)
	}
	return
}

func closest(x1, y0, aspect, shadow float64, x, y float64, circles []Circle) (float64, int) {
	proximal, locus := math.MaxFloat64, 0
	for index, circle := range circles {
		distance := sdf(x1, y0, aspect, shadow, x, y, circle.x, circle.y, circle.radius)
		if distance > 0 {
			distance /= circle.radius
		}
		if distance < proximal {
			proximal, locus = distance, index
		}
	}
	return proximal, locus
}

func pixelate(x1, y0, aspect, shadow, proximal float64, locus int, x, y float64, circles []Circle) uint8 {
	shade := proximal
	center := &circles[locus]
	if proximal <= 0 {
		shade0 := -proximal / center.radius
		shade1 := math.MaxFloat64
		for index, circle := range circles {
			if locus != index {
				distance := sdf(x1, y0, aspect, shadow, x, y, circle.x, circle.y, circle.radius) - proximal
				distance /= math.Sqrt(distance2(center.x-circle.x, center.y-circle.y))
				shade1 = min(shade1, distance)
			}
		}
		shade = min(shade0, shade1)
	}
	shade = 255 * min(1, shade/(2*aspect))
	return uint8(shade)
}

func distance2(x, y float64) float64 {
	return x*x + y*y
}

func sdf(x1, y0, aspect, shadow, x, y, u, v, radius float64) float64 {
	return (distance2(x1+x*aspect+u, y0+y*aspect-v) - radius*radius) / shadow
}
