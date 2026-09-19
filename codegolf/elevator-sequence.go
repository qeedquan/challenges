/*

Totally not inspired by Lyxal repeatedly mentioning elevators in chat :P

Challenge
In short: simulate some people filling up an elevator and then leaving it.

The elevator is simplified as a grid, where each person can occupy one cell of the grid. The height and width of the grid is the input parameter. The width is always odd, and it has an opening of 1 unit width at the center of the top side. The following diagram shows an elevator of width 5 and height 4, initially empty:

+------   ------+
| ?  ?  ?  ?  ? |
| ?  ?  ?  ?  ? |
| ?  ?  ?  ?  ? |
| ?  ?  ?  ?  ? |
+---------------+
Now, 20 people, numbered 1 to 20 in the order of boarding, start filling up the elevator. People tend to stick to the front, but cannot block other people boarding when some spots are still empty. As a simplification, let's simply assume that people fill the spots in the left-right-left-right fashion from the frontmost row, leaving the middle column empty (which is then filled by the last few people):

+------    ------+
|  1  3 20  4  2 |
|  5  7 19  8  6 |
|  9 11 18 12 10 |
| 13 15 17 16 14 |
+----------------+
When people leave the elevator, they do row-by-row, starting with the center column and then alternating left and right sides. So the order of leaving is as follows:

20, 3, 4, 1, 2, 19, 7, 8, 5, 6, 18, 11, 12, 9, 10, 17, 15, 16, 13, 14
The challenge is to produce this sequence for given width and height of the elevator (again, the width is guaranteed to be odd).

You can use 0-based numbering instead of 1-based.

sequence I/O applies. The I/O format can be in one of three ways:

Take width and height, and output the full sequence
Take width, height, and index (0- or 1-based), and output the n-th number (index is guaranteed to be valid)
Take width, height, and n (at most the number of cells), and output the first n numbers
The standard code-golf rules apply. The shortest code in bytes wins.

More test cases
width = 1, height = 1
output = 1

width = 1, height = 10
output = 10, 9, 8, 7, 6, 5, 4, 3, 2, 1

width = 9, height = 1
output = 9, 7, 8, 5, 6, 3, 4, 1, 2

width = 7, height = 5
output = 35, 5, 6, 3, 4, 1, 2, 34, 11, 12, 9, 10, 7, 8, 33, 17, 18,
15, 16, 13, 14, 32, 23, 24, 21, 22, 19, 20, 31, 29, 30, 27, 28, 25, 26

*/

package main

import (
	"slices"
)

func main() {
	assert(slices.Equal(
		elevator(1, 1),
		[]int{1},
	))

	assert(slices.Equal(
		elevator(1, 10),
		[]int{10, 9, 8, 7, 6, 5, 4, 3, 2, 1},
	))

	assert(slices.Equal(
		elevator(9, 1),
		[]int{9, 7, 8, 5, 6, 3, 4, 1, 2},
	))

	assert(slices.Equal(
		elevator(7, 5),
		[]int{
			35, 5, 6, 3, 4, 1, 2, 34, 11,
			12, 9, 10, 7, 8, 33, 17, 18,
			15, 16, 13, 14, 32, 23, 24,
			21, 22, 19, 20, 31, 29, 30,
			27, 28, 25, 26,
		},
	))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func elevator(w, h int) []int {
	if w < 1 || h < 1 {
		return []int{}
	}

	r := make([]int, w*h)
	for n := range r {
		y := n / w
		if n%w != 0 {
			r[n] = (((w-1)*(y+1) - n%w) ^ 1) + 1
		} else {
			r[n] = w*h - y
		}
	}
	return r
}
