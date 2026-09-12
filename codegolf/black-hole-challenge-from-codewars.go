/*

I came across this challenge from codewars. I wish to know how to solve this problem. The problem description is given below.

Its elements are in range[1..n^2]. The matrix is filled by rings, from the outwards the innermost. Each ring is filled with numbers in the following way:

The first number is written in the top left corner;
The second number is written in the top right corner;
The third number is written in the bottom right corner;
The fourth number is written in the bottom left corner;
Each next number is written next to the number written 4 steps before it, until the ring is filled.
The matrix is constructed when all numbers are written.``` Given the size of the hole, return the number written at (a, b) - you may use any consistent indexing, but please specify if (a, b) is anything other than 0-indexed and row-major.

Example
For n = 4, a = 1, b = 1, the output should be 13.

The hole looks like this:

[ [  1,  5,  9,  2 ]
  [ 12, 13, 14,  6 ]
  [  8, 16, 15, 10 ]
  [  4, 11,  7,  3 ]
]

The element at (1, 1) is 13
Test cases
(a, b) is 0-indexed and row-major here.

n   a   b   result
1   0   0    1
2   0   0    1
3   0   0    1
4   0   0    1
2   0   1    2
3   0   1    5
3   1   1    9
4   1   1   13
4   2   1   16
5   2   3   22

*/

package main

import (
	"sort"
)

func main() {
	hole4 := [4][4]int{
		{1, 5, 9, 2},
		{12, 13, 14, 6},
		{8, 16, 15, 10},
		{4, 11, 7, 3},
	}

	assert(number(1, 0, 0) == 1)
	assert(number(2, 0, 0) == 1)
	assert(number(3, 0, 0) == 1)
	assert(number(4, 0, 0) == 1)
	assert(number(2, 0, 1) == 2)
	assert(number(3, 0, 1) == 5)
	assert(number(3, 1, 1) == 9)
	assert(number(4, 1, 1) == 13)
	assert(number(4, 2, 1) == 16)
	assert(number(5, 2, 3) == 22)

	for a := range hole4 {
		for b := range hole4[a] {
			assert(number(4, a, b) == hole4[a][b])
		}
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

/*

@TFeld

Explanation:
This takes advantage of the fact that there is some symmetry to the matrix.

The matrix can be split into four quarters, which are equal when rotated (+ an offset of 1-3).

https://i.stack.imgur.com/PW3oo.png

The first part A,B,C=... finds out which quarter the current coordinates are in, by finding the smallest coordinates, relative to each quarter:

https://i.stack.imgur.com/IPsX9.png

(green: (a,b), yellow: (n-b,a), red: (n-a,n-b), blue: (b,n-a))

The coordinate pair is then converted to a value:

(0,0) = 1, (0,1) = 5, and so on; each coordinate is 4 larger than the previous.

sum((n-(i*2))*4for i in range(A)) skips the rows above, +(B-A)*4 moves along the row, and +C adds the offset.

sum((n-(i*2))*4for i in range(A))+(B-A)*4+C is shortened to (n-A)*4*A+4*B+C

*/

func number(n, a, b int) int {
	n, A, B, C := minimum(n-1, a, b)
	return (n-A)*4*A + 4*B + C
}

func minimum(n, a, b int) (m, A, B, C int) {
	x := [][3]int{
		{a, b, 1},
		{n - b, a, 2},
		{n - a, n - b, 3},
		{b, n - a, 4},
	}

	sort.SliceStable(x, func(i, j int) bool {
		for k := range 3 {
			if x[i][k] < x[j][k] {
				return true
			}
			if x[i][k] > x[j][k] {
				return false
			}
		}
		return false
	})

	return n, x[0][0], x[0][1], x[0][2]
}
