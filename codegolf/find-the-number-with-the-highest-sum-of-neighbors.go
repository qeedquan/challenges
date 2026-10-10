/*

The Challenge
Given a grid of numbers (10 <= N <= 99) Return number with the highest sum of the four numbers adjacent to it; that is the numbers above, below, right, and left of the number, but not itself.

The number itself does not count, only its four neighbors.
A number on the edge should be treated as though the missing number is a 0.
I will design the test to avoid ties.
Numbers will not repeat.
This is code-golf.
Example
Given

56 98 32 96
12 64 45 31
94 18 83 71
Return

18
A Real Test
Given

98 95 67 66 57 16 40 94 84 37
87 14 19 34 83 99 97 78 50 36
18 44 29 47 21 86 24 15 91 61
60 41 51 26 10 58 11 62 55 71
42 85 56 12 46 81 93 65 49 77
89 13 74 39 54 76 92 33 82 90
96 88 70 79 80 28 25 20 75 68
38 63 17 72 53 48 73 30 45 69
64 35 32 31 23 43 22 52 27 59
Return

13
Given

82 43 79 81 94 36 17 64 58
24 52 13 87 70 18 28 61 69
16 99 75 21 50 44 89 90 51
49 80 63 31 54 65 41 55 38
67 91 76 78 23 86 83 14 73
46 68 62 77 34 48 20 74 10
33 35 26 97 59 66 25 37 32
12 92 84 27 85 56 22 40 45
96 15 98 53 39 30 88 71 29
60 42 11 57 95 19 93 72 47
Return

15

*/

package main

func main() {
	assert(neighborsum([][]int{
		{56, 98, 32, 96},
		{12, 64, 45, 31},
		{94, 18, 83, 71},
	}) == 18)

	assert(neighborsum([][]int{
		{98, 95, 67, 66, 57, 16, 40, 94, 84, 37},
		{87, 14, 19, 34, 83, 99, 97, 78, 50, 36},
		{18, 44, 29, 47, 21, 86, 24, 15, 91, 61},
		{60, 41, 51, 26, 10, 58, 11, 62, 55, 71},
		{42, 85, 56, 12, 46, 81, 93, 65, 49, 77},
		{89, 13, 74, 39, 54, 76, 92, 33, 82, 90},
		{96, 88, 70, 79, 80, 28, 25, 20, 75, 68},
		{38, 63, 17, 72, 53, 48, 73, 30, 45, 69},
		{64, 35, 32, 31, 23, 43, 22, 52, 27, 59},
	}) == 13)

	assert(neighborsum([][]int{
		{82, 43, 79, 81, 94, 36, 17, 64, 58},
		{24, 52, 13, 87, 70, 18, 28, 61, 69},
		{16, 99, 75, 21, 50, 44, 89, 90, 51},
		{49, 80, 63, 31, 54, 65, 41, 55, 38},
		{67, 91, 76, 78, 23, 86, 83, 14, 73},
		{46, 68, 62, 77, 34, 48, 20, 74, 10},
		{33, 35, 26, 97, 59, 66, 25, 37, 32},
		{12, 92, 84, 27, 85, 56, 22, 40, 45},
		{96, 15, 98, 53, 39, 30, 88, 71, 29},
		{60, 42, 11, 57, 95, 19, 93, 72, 47},
	}) == 15)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func neighborsum(m [][]int) int {
	r, u := 0, 0
	for y := range m {
		for x := range m[y] {
			v := at(m, x-1, y)
			v += at(m, x+1, y)
			v += at(m, x, y-1)
			v += at(m, x, y+1)
			if v > u {
				r, u = m[y][x], v
			}
		}
	}
	return r
}

func at(m [][]int, x, y int) int {
	if y < 0 || y >= len(m) || x < 0 || x >= len(m[y]) {
		return 0
	}
	return m[y][x]
}
