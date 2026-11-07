/*

Your task is to write a program or function which, given two nonzero integers x and y, returns a truthy value if the image at coordinates x east and y north of xkcd's click and drag comic is mostly white and a falsey value otherwise.

Specifications
The image should be retrieved from imgs.xkcd.com/clickdrag/[y]n[x]e.png, where [y] and [x] are replaced with the absolute values of the input y and x values.
If x is negative, e should be changed to a w. If y is negative, n should be changed to a s.
If a 404 error is returned, assume the image is mostly white (output truthy) if y is positive and mostly black otherwise. This is because (as far as I can tell) xkcd stores neither completely white regions of the sky nor completely black regions of the ground, leading to less data in their servers and these 404s you must handle. This error handling is not intended to deal with the images not being available.
"white" is defined as rgb #FFFFFF. You may assume that the images are only white(#FFFFFF) and black(#000000), without gray or other colors. "Mostly white" is defined as at least 2097153 pixels of the image are white (because the png the program should retrieve from img.xkcd.com is always 2048x2048 pixels).
The program may have any behavior when dealing with pixels that are not exactly #FFFFFF nor #000000 but must produce the same output as expected for the test cases.
Example
The image at x=2, y=9 should be retrieved from imgs.xkcd.com/clickdrag/9n2e.png and appears as follows (formatted as quote to show border):

https://i.sstatic.net/1AtPPm.png

It is mostly white, so the program should return a truthy value.

Input / Output
Input should be two integers or a list of two integers representing x and y.

Output should be a truthy or falsy value corresponding to if the image is mostly white.

Input and output should be through any standard I/O method.

Test Cases

Truthy (as (x,y))
2,9
7,-17
9, 5
3, 2
-5, 1
1, 3

Falsy (as (x,y))
3, 1
3, -1
7, -16
2, 1
5, 1
17, -1

*/

package main

import (
	"fmt"
	"image"
	_ "image/gif"
	_ "image/jpeg"
	_ "image/png"
	"net/http"
)

func main() {
	assert(clickdrag(2, 9) == true)
	assert(clickdrag(7, -17) == true)
	assert(clickdrag(9, 5) == true)
	assert(clickdrag(3, 2) == true)
	assert(clickdrag(-5, 1) == true)
	assert(clickdrag(1, 3) == true)

	assert(clickdrag(3, 1) == false)
	assert(clickdrag(3, -1) == false)
	assert(clickdrag(7, -16) == false)
	assert(clickdrag(2, 1) == false)
	assert(clickdrag(5, 1) == false)
	assert(clickdrag(17, -1) == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func clickdrag(x, y int) bool {
	pic, err := getpic(x, y)
	if err != nil {
		return y > 0
	}
	return pure(pic)
}

func getpic(x, y int) (image.Image, error) {
	dx, dy := 'e', 'n'
	if x < 0 {
		x, dx = -x, 'w'
	}
	if y < 0 {
		y, dy = -y, 's'
	}

	url := fmt.Sprintf("http://imgs.xkcd.com/clickdrag/%d%c%d%c.png", y, dy, x, dx)
	resp, err := http.Get(url)
	if err != nil {
		return nil, err
	}

	pic, _, err := image.Decode(resp.Body)
	return pic, err
}

func pure(pic image.Image) bool {
	white := 0
	total := 0
	bounds := pic.Bounds()
	for y := bounds.Min.Y; y < bounds.Max.Y; y++ {
		for x := bounds.Min.X; x < bounds.Max.X; x++ {
			rgba := pic.At(x, y)
			red, green, blue, _ := rgba.RGBA()
			if red == 0xffff && green == 0xffff && blue == 0xffff {
				white++
			}
			total++
		}
	}
	return float64(white)/float64(total) >= 0.5
}
