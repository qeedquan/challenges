/*

You have a swimming pool that is filled to the brim with water. You need to empty it, but you can't think of an efficient method. So you decide to use your red solo cup. You will repeatedly fill the cup all the way and dump it outside the pool.

Challenge
How long will it take to empty the pool?

Input
[shape of pool] [dimensions] [shape of cup] [dimensions] [speed]

shape of pool will be one of these strings: circle, triangle, or rectangle. Note that these actually refer to the 3-dimensional shapes: cylinder, triangular prism, and rectangular prism.
dimensions will be different depending on the shape.
circle: [radius] [height]. Volume = π r2 h
triangle: [base] [height] [length]. Volume = 1/2(bh) * length
rectangle: [width] [length] [height] Volume = lwh
shape of cup and dimensions work the same way. The cup can also be either a circle, triangle, or rectangle.
speed is the amount of time it takes to empty one cup full of water in seconds.
Output
The number of seconds it takes to empty the swimming pool. This can be rounded to the nearest second.

Notes
There will be no units in the input. All distance units are assumed to be the same (a shape won't have a height in inches and a width in feet).
Use 3.14 for pi.
Input will be made up of strings and floating-point numbers.
It will never rain. No water will ever be added.
You have a very steady hand. You will fill the cup exactly to the brim every time, and you will never spill any.
Once you get near the end, it will get hard to scoop up a full cup of water. You do not need to worry about this. You're very strong, so you can tilt the pool onto its side (without using up any more time).
Anytime you make a calculation, it's okay to round to the nearest hundredth. Your final answer will not need to be exact.
Test Cases
Input: triangle 10 12.25 3 circle 5 2.2 5
Output: 10
Even though there is less than 172.7 left on the last scoop, it still takes the whole five seconds to empty it.

Input: triangle 5 87.3 20001 rectangle 5.14 2 105.623 0.2
Output: 804.2

You should round to the nearest hundredth after each calculation.
The final calculation is rounded up from 804.05567 to 804.2. This is because that last little bit of water must be emptied.
Rules
You can write a full program or function.
Input should be taken from stdin or function parameters. Output should be printed through stdout or returned.
The input format can be rearranged, as long as you specify that in the submission. You can also shorten the strings "circle", "triangle", and "rectangle."
Libraries and built-in functions that involve volume or area are not allowed.

Scoring
This is code-golf. Submission with least number of bytes wins.

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	test("triangle", []float64{10, 12.25, 3}, "circle", []float64{5, 2.2}, 5, 10)
	test("triangle", []float64{5, 87.3, 20001}, "rectangle", []float64{5.14, 2, 105.623}, 0.2, 804.2)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(shape1 string, dimension1 []float64, shape2 string, dimension2 []float64, speed float64, result float64) {
	value := solve(shape1, dimension1, shape2, dimension2, speed)
	fmt.Println(value)
	assert(math.Abs(value-result) < 1e-8)
}

func volume(shape string, dimension []float64) float64 {
	switch shape {
	case "circle":
		return math.Pi * dimension[0] * dimension[0] * dimension[1]
	case "triangle":
		return 0.5 * dimension[0] * dimension[1] * dimension[2]
	case "rectangle":
		return dimension[0] * dimension[1] * dimension[2]
	}
	return -1
}

func solve(shape1 string, dimension1 []float64, shape2 string, dimension2 []float64, speed float64) float64 {
	volume1 := volume(shape1, dimension1)
	volume2 := volume(shape2, dimension2)
	return math.Ceil(volume1/volume2) * speed
}
