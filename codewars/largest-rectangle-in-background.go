/*

Imagine a photo taken to be used in an advertisement. The background on the left of the motive is whitish and you want to write some text on that background. So you scan the photo with a high resolution scanner and, for each line, count the number of pixels from the left that are sufficiently white and suitable for being written on. Your job is to find the area of the largest text box you can place on those pixels.

Example: In the figure below, the whitish background pixels of the scanned photo are represented by asterisks.

*********************************
*********
*******
******
******
******
**************
**************
**************
***************
*********************
If you count the pixels on each line from the left you get the list (or array, depending on which language you are using) [33, 9, 7, 6, 6, 6, 14, 14, 14, 15, 21]. The largest reactangle that you can place on these pixels has an area of 70, and is represented by the dots in the figure below.

*********************************
*********
*******
******
******
******
..............
..............
..............
..............*
..............*******
Write a function that, given a list of the number whitish pixels on each line in the background, returns the area of the largest rectangle that fits on that background.

*/

package main

func main() {
	assert(largest([]int{3, 5, 12, 4, 10}) == 16)
	assert(largest([]int{6, 2, 5, 4, 5, 1, 6}) == 12)
	assert(largest([]int{9, 7, 5, 4, 2, 5, 6, 7, 7, 5, 7, 6, 4, 4, 3, 2}) == 36)

	assert(largest([]int{}) == 0)
	assert(largest([]int{0}) == 0)
	assert(largest([]int{0, 0, 0}) == 0)
	assert(largest([]int{1, 1, 1}) == 3)
	assert(largest([]int{1, 2, 3}) == 4)
	assert(largest([]int{3, 2, 1}) == 4)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func largest(histogram []int) int {
	best := 0
	stack := [][2]int{}
	histogram = append(histogram, 0)
	for index, height := range histogram {
		start := index
		for {
			size := len(stack)
			if !(size > 0 && stack[size-1][1] > height) {
				break
			}

			value := stack[size-1]
			stack = stack[:size-1]
			best = max(best, value[1]*(index-value[0]))
			start = value[0]
		}
		stack = append(stack, [2]int{start, height})
	}
	return best
}
