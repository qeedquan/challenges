/*

The challenge, should you accept it, is to determine how much you win in the Bingo Golf Flax Lottery. Based on but not equal to the BingoFlax lottery

The input is two lists of numbers (positive non-zero integers).

The first list always contains 24 potentially non-unique numbers that make up your board, a 5 x 5 grid of numbers from the list in reading order: Left to right, top to bottom. The mid cell is always a free cell (a "wild card") that matches any number and this is why the board input is 24 numbers and not 25 (=5*5). Note: the same number may appear more than once.

The second input list is of any length. These are numbers that may or may not match numbers on your board.

Matching numbers may or may not end up making one or more winning patterns on your board.

The type of winning pattern if any determine how much you win.

If more than one winning pattern emerge, only the one with the most prize money matter. Don't sum up the patterns.

The winning patterns and their prize money are:

https://i.stack.imgur.com/6uWSN.png

Your program or function should return 500000, 10000, 1000, 500, 200, 100, 50, 30 or 0 for no winning pattern.

Example 1:

Input: 5 21 34 51 74 3 26 39 60 73 2 28 59 67 12 30 33 49 75 10 17 40 50 66
and: 33 10 7 12 60 49 23 38 15 75 40 30
Winning pattern: horizontal line.
Result: 50

https://i.stack.imgur.com/WJ5UV.png

Example 2:

Input: 5 21 34 51 74 3 26 39 60 73 2 28 59 67 12 60 33 49 75 10 17 40 50 66
and: 33 10 7 12 60 49 23 12 15 75 40 97 74 99
Two winning patterns: horizontal and forward diagonal since the mid cell is always free – only the most winning counts
Note: 60 appear twice on the board and since 60 is called from the second list both 60's counts as a match. The one 60 in the call list matches all 60's on the board.
Result: 500

https://i.stack.imgur.com/kfzbs.png

Example 3:

Input: 9 13 4 42 67 24 17 1 7 19 22 10 30 41 8 12 14 20 39 52 25 3 48 64
and: 9 2 4 13 11 67 42 24 41 50 19 22 39 64 52 48 3 25
Almost border, but missing 8. You still win 100 for the vertical line at the right edge.
Result: 100

https://i.stack.imgur.com/X3Zw3.png

This is Code Golf, shortest answer wins.

*/

package main

func main() {
	assert(flax(
		[]int{5, 21, 34, 51, 74, 3, 26, 39, 60, 73, 2, 28, 59, 67, 12, 30, 33, 49, 75, 10, 17, 40, 50, 66},
		[]int{33, 10, 7, 12, 60, 49, 23, 38, 15, 75, 40, 30},
	) == 50)

	assert(flax(
		[]int{5, 21, 34, 51, 74, 3, 26, 39, 60, 73, 2, 28, 59, 67, 12, 60, 33, 49, 75, 10, 17, 40, 50, 66},
		[]int{33, 10, 7, 12, 60, 49, 23, 12, 15, 75, 40, 97, 74, 99},
	) == 500)

	assert(flax(
		[]int{9, 13, 4, 42, 67, 24, 17, 1, 7, 19, 22, 10, 30, 41, 8, 12, 14, 20, 39, 52, 25, 3, 48, 64},
		[]int{9, 2, 4, 13, 11, 67, 42, 24, 41, 50, 19, 22, 39, 64, 52, 48, 3, 25},
	) == 100)

}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func flax(x, u []int) int {
	lut := [][2]int{
		{0x1f8c63f, 500000},
		{0x1151151, 10000},
		{0x739c0, 1000},
		{0x111110, 500},
		{0x1041041, 200},
		{0x108421, 100},
		{0x210842, 100},
		{0x421084, 100},
		{0x842108, 100},
		{0x1084210, 100},
		{0x1f, 50},
		{0x3e0, 50},
		{0x7c00, 50},
		{0xf8000, 50},
		{0x1f00000, 50},
		{0x1100011, 30},
	}

	m := make(map[int]bool)
	for _, v := range u {
		m[v] = true
	}

	b := 0x1000
	for i, v := range x {
		s := i
		if i >= 12 {
			s++
		}

		if m[v] {
			b |= 1 << s
		}
	}

	for _, v := range lut {
		if b&v[0] == v[0] {
			return v[1]
		}
	}

	return 0
}
