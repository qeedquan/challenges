/*

Although it's done a few times as sub-challenge of a larger challenge, and we also have a challenge to remove the borders of a square matrix, I couldn't find a challenge to output the borders of a given matrix, so here it is.

Challenge:
Given a rectangular-shaped matrix containing integers as input, output its borders.

Challenge rules:
The input is guaranteed to be a rectangular-shaped matrix (or empty)
The input can contain negative and duplicated integers
The output format and type is flexible and can be in any order (e.g. [[1,2,3],[4,5,6],[7,8,9]] may result in [1,2,3,4,6,7,8,9]; or [[1,2,3],[6,9],[8,7],[4]]; or 9\n8\n7\n6\n4\n3\n2\n1\n; etc.).
As long as it's clear that just the border of the input-matrix is output, almost every output-format is allowed. (If you're unsure whether an output format is allowed, feel free to ask in the comments.)

General Rules:
This is code-golf, so the shortest answer in bytes wins.
Don't let code-golf languages discourage you from posting answers with non-codegolfing languages. Try to come up with an as short as possible answer for 'any' programming language.
Standard rules apply for your answer with default I/O rules, so you are allowed to use STDIN/STDOUT, functions/method with the proper parameters and return-type, full programs. Your call.
Default Loopholes are forbidden.
If possible, please add a link with a test for your code (e.g. TIO).
Also, adding an explanation for your answer is highly recommended.

Test Cases:
Input	Output	Visualized
[[1,2,3],
 [4,5,6],
 [7,8,9]]
[1,2,3,4,6,7,8,9]

[[]]	[]	N/A

[[0]]	[0]

[[ 9, 2,-5, 3],
 [18, 3, 8, 0],
 [ 2, 7,21,-3],
 [ 9,-5,10,99]]
[9,2,-5,3,18,0,2,-3,9,-5,10,99]

[[1,2,3]]	[1,2,3]

[[9],
 [8],
 [8],
 [9]]
[9,8,8,9]

[[ 10, 20, 30, 40, 50, 60],
 [ 70, 80, 90,-90,-80,-70],
 [-60,-50,-40,-30,-20,-10]]
[10,20,30,40,50,60,70,
-70,-60,-50,-40,-30,-20,-10]

[[ 1, 2, 3, 4, 5, 6],
 [ 7, 8, 9,10,11,12],
 [13,14,15,16,17,18],
 [19,20,21,22,23,24],
 [25,26,27,28,29,30],
 [31,32,33,34,35,36],
 [37,38,39,40,41,42],
 [43,44,45,46,47,48],
 [49,50,51,52,53,54],
 [55,56,57,58,59,60]]
[1,2,3,4,5,6,7,12,13,18,
19,24,25,30,31,36,37,42,43,
48,49,54,55,56,57,58,59,60]

[[-11, 18,  3,-40,123],
 [ 18,-33,  9,765,100]]
[-11,18,3,-40,123,18,-33,9,765,100]

[[14, 3],
 [ 3,14],
 [14, 3],
 [ 3,14],
 [14, 3]]
[14,3,3,14,14,3,3,14,14,3]


*/

package main

import (
	"fmt"
	"slices"
)

func main() {
	test([][]int{
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9},
	}, []int{1, 2, 3, 4, 6, 7, 8, 9})

	test([][]int{{}}, []int{})

	test([][]int{{0}}, []int{0})

	test([][]int{
		{9, 2, -5, 3},
		{18, 3, 8, 0},
		{2, 7, 21, -3},
		{9, -5, 10, 99},
	}, []int{9, 2, -5, 3, 18, 0, 2, -3, 9, -5, 10, 99})

	test([][]int{{1}, {2}, {3}}, []int{1, 2, 3})

	test([][]int{{9}, {8}, {8}, {9}}, []int{9, 8, 8, 9})

	test([][]int{
		{10, 20, 30, 40, 50, 60},
		{70, 80, 90, -90, -80, -70},
		{-60, -50, -40, -30, -20, -10},
	}, []int{10, 20, 30, 40, 50, 60, 70, -70, -60, -50, -40, -30, -20, -10})

	test([][]int{
		{1, 2, 3, 4, 5, 6},
		{7, 8, 9, 10, 11, 12},
		{13, 14, 15, 16, 17, 18},
		{19, 20, 21, 22, 23, 24},
		{25, 26, 27, 28, 29, 30},
		{31, 32, 33, 34, 35, 36},
		{37, 38, 39, 40, 41, 42},
		{43, 44, 45, 46, 47, 48},
		{49, 50, 51, 52, 53, 54},
		{55, 56, 57, 58, 59, 60},
	}, []int{1, 2, 3, 4, 5, 6, 7, 12, 13, 18, 19, 24, 25, 30, 31, 36, 37, 42, 43, 48, 49, 54, 55, 56, 57, 58, 59, 60})

	test([][]int{
		{-11, 18, 3, -40, 123},
		{18, -33, 9, 765, 100},
	}, []int{-11, 18, 3, -40, 123, 18, -33, 9, 765, 100})

	test([][]int{
		{14, 3},
		{3, 14},
		{14, 3},
		{3, 14},
		{14, 3},
	}, []int{14, 3, 3, 14, 14, 3, 3, 14, 14, 3})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(m [][]int, r []int) {
	p := borders(m)
	fmt.Println(p)
	assert(slices.Equal(p, r))
}

func borders(m [][]int) []int {
	r := []int{}
	if len(m) == 0 || len(m[0]) == 0 {
		return r
	}

	w, h := len(m[0]), len(m)
	for x := range w {
		r = append(r, m[0][x])
	}

	for y := 1; y < h-1; y++ {
		r = append(r, m[y][0])
		if w > 1 {
			r = append(r, m[y][w-1])
		}
	}

	if h > 1 {
		for x := range w {
			r = append(r, m[h-1][x])
		}
	}

	return r
}
