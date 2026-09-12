/*

Complete the method public float[] getVector(boolean[] wasd) to calculate the players movement vector resulting from user input to the WASD keys.

The method accepts an array of 4 boolean values representing the pressed state of the W, A, S and D keys where true indicates the key is pressed. Any number of keys may be pressed at a time.

The method should return a float array of size 2 representing the x any y components of the resulting movement vector where W and S map to positive and negative y respectively and A and D map to negative and positive x respectively.

The players should always move at speed 1.

*/

package main

import "math"

func main() {
	test([4]bool{false, false, false, false}, 0, 0)
	test([4]bool{true, false, false, false}, 0, 1)
	test([4]bool{false, true, false, false}, -1, 0)
	test([4]bool{false, false, true, false}, 0, -1)
	test([4]bool{false, true, false, true}, 0, 0)
	test([4]bool{false, true, true, true}, 0, -1)
	test([4]bool{true, true, true, true}, 0, 0)
	test([4]bool{false, true, true, false}, -math.Sqrt2*0.5, -math.Sqrt2*0.5)
	test([4]bool{false, false, true, true}, math.Sqrt2*0.5, -math.Sqrt2*0.5)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(wasd [4]bool, rx, ry float64) {
	const eps = 1e-12
	x, y := vector(wasd)
	assert(math.Abs(x-rx) < eps)
	assert(math.Abs(y-ry) < eps)
}

func vector(wasd [4]bool) (float64, float64) {
	s := math.Sqrt2 * 0.5
	x := keypress(wasd, 3, 1)
	y := keypress(wasd, 0, 2)
	if x != 0 && y != 0 {
		x, y = x*s, y*s
	}
	return x, y
}

func keypress(wasd [4]bool, k0, k1 int) float64 {
	if wasd[k0] && !wasd[k1] {
		return 1
	}
	if !wasd[k0] && wasd[k1] {
		return -1
	}
	return 0
}
