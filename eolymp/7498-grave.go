/*

Gerard develops a Halloween computer game.
The game is played on a rectangular graveyard with a rectangular chapel in it.
During the game, the player places new rectangular graves on the graveyard.
The grave should completely fit inside graveyard territory and should not overlap with the chapel.
The grave may touch borders of the graveyard or the chapel.

https://static.e-olymp.com/content/14/14fe2381fedac56d85d5ac7c4ab99452e429be16.gif

Gerard asked you to write a program that determines whether it is possible to place a new grave of givensize or there is not enough space for it.

Input
The first line contains two pairs of integers:
x1, y1, x2, y2 (−10^9≤x1<x2≤10^9, −10^9≤y1<y2≤10^9) - coordinates of bottom left and top right corners of the graveyard.
The second line also contains two pairs of integers x3, y3, x4, y4 (x1<x3<x4<x2, y1<y3<y4<y2) - coordinates of bottom left and top right corners of the chapel.

The third line contains two integers w, h - width and height of the new grave (1≤w,h≤10^9).
Side with length w should be placed along OX axis, side with length h - along OY axis.

Output
Print "Yes", if it is possible to place the new grave, or "No", if there is not enough space for it.

Examples

Input #1
1 1 11 8
2 3 8 6
3 2

Answer #1
Yes

Input #2
1 1 11 8
2 3 8 6
4 3

Answer #2
No

*/

package main

func main() {
	assert(solve(
		1, 1, 11, 8,
		2, 3, 8, 6,
		3, 2,
	) == "Yes")

	assert(solve(
		1, 1, 11, 8,
		2, 3, 8, 6,
		4, 3,
	) == "No")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(x1, y1, x2, y2, x3, y3, x4, y4, w, h int) string {
	switch {
	case fit(x1, y1, x2, y3, w, h),
		fit(x1, y1, x3, y2, w, h),
		fit(x1, y4, x2, y2, w, h),
		fit(x4, y1, x2, y2, w, h):
		return "Yes"
	}
	return "No"
}

func fit(x1, y1, x2, y2, w, h int) bool {
	dx := x2 - x1
	dy := y2 - y1
	return w <= dx && h <= dy
}
