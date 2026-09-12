/*

Description
You can paint an asperand by pixels in three steps:

First you paint a "border" - the perimeter of a square with sides k.
Then you need to paint a pixel, the top-left corner of which touches the bottom-right corner of your "border". Let's call it the "bridge".
Finally, you will need to paint the spots that are at 1 pixel distance from your "border", including the pixel of which the bottom-left corner is touching the top-right corner of the "bridge", but excluding any others that would be touching the "bridge".

Here are some examples of this:

https://justpaste.it/img/78b363ec3c92b9be234603fd8ca0b1e4.png

Examples for 0<k<5

Your task is to find the number of pixels that need to be painted, for different k:

k = 1 => 11
k = 2 => 18
k = 3 => 26
k = 4 => 34

# Limitations are 1 ≤ k ≤ 1e9

The idea for this kata was taken from the Ukrainian Informatics Olympiad 2023.

*/

package main

func main() {
	assert(pixels(1) == 11)
	assert(pixels(2) == 18)
	assert(pixels(3) == 26)
	assert(pixels(4) == 34)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func pixels(n int) int {
	if n < 1 {
		return 0
	}

	r := 1
	if n != 1 {
		r = 2*n + 2*(n-2)
	}
	r += 3*(n+2) + n

	return r
}
