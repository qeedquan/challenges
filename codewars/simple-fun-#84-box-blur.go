/*

Task
Last night you had to study, but decided to party instead. Now there is a black and white photo of you that is about to go viral. You cannot let this ruin your reputation, so you want to apply box blur algorithm to the photo to hide its content.

The algorithm works as follows: each pixel x in the resulting image has a value equal to the average value of the input image pixels' values from the 3 × 3 square with the center at x. All pixels at the edges are cropped.

As pixel's value is an integer, all fractions should be rounded down.

Example

image = [
  [1, 1, 1],
  [1, 7, 1],
  [1, 1, 1]
]

result = [
  [1]
]

In the given example all boundary pixels were cropped, and the value of the pixel in the middle was obtained as floor((1 + 1 + 1 + 1 + 7 + 1 + 1 + 1 + 1) / 9) = floor(15 / 9) = 1.

Input/Output
[input] 2D integer array image

An image is stored as a rectangular matrix of non-negative integers.

Constraints:

3 ≤ image.length ≤ 15,

3 ≤ image[0].length ≤ 15,

0 ≤ image[i][j] ≤ 255.

[output] 2D integer array

A blurred image.

*/

package main

import "fmt"

func main() {
	fmt.Println(boxblur([][]int{
		{1, 1, 1},
		{1, 7, 1},
		{1, 1, 1},
	}))

	fmt.Println(boxblur([][]int{
		{0, 18, 9},
		{27, 9, 0},
		{81, 63, 45},
	}))

	fmt.Println(boxblur([][]int{
		{36, 0, 18, 9},
		{27, 54, 9, 0},
		{81, 63, 72, 45},
	}))

	fmt.Println(boxblur([][]int{
		{7, 4, 0, 1},
		{5, 6, 2, 2},
		{6, 10, 7, 8},
		{1, 4, 2, 0},
	}))

	fmt.Println(boxblur([][]int{
		{36, 0, 18, 9, 9, 45, 27},
		{27, 0, 54, 9, 0, 63, 90},
		{81, 63, 72, 45, 18, 27, 0},
		{0, 0, 9, 81, 27, 18, 45},
		{45, 45, 27, 27, 90, 81, 72},
		{45, 18, 9, 0, 9, 18, 45},
		{27, 81, 36, 63, 63, 72, 81},
	}))
}

func boxblur(m [][]int) [][]int {
	r := [][]int{}
	for y := 1; y < len(m)-1; y++ {
		p := []int{}
		for x := 1; x < len(m[y])-1; x++ {
			s := 0
			for dy := -1; dy <= 1; dy++ {
				for dx := -1; dx <= 1; dx++ {
					s += m[y+dy][x+dx]
				}
			}
			p = append(p, s/9)
		}
		r = append(r, p)
	}
	return r
}
