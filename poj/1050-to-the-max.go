/*

Description

Given a two-dimensional array of positive and negative integers, a sub-rectangle is any contiguous sub-array of size 1*1 or greater located within the whole array. The sum of a rectangle is the sum of all the elements in that rectangle. In this problem the sub-rectangle with the largest sum is referred to as the maximal sub-rectangle.
As an example, the maximal sub-rectangle of the array:

0 -2 -7 0
9 2 -6 2
-4 1 -4 1
-1 8 0 -2
is in the lower left corner:

9 2
-4 1
-1 8
and has a sum of 15.

Input

The input consists of an N * N array of integers. The input begins with a single positive integer N on a line by itself, indicating the size of the square two-dimensional array. This is followed by N^2 integers separated by whitespace (spaces and newlines). These are the N^2 integers of the array, presented in row-major order. That is, all numbers in the first row, left to right, then all numbers in the second row, left to right, etc. N may be as large as 100. The numbers in the array will be in the range [-127,127].

Output

Output the sum of the maximal sub-rectangle.

Sample Input

4
0 -2 -7 0 9 2 -6 2
-4 1 -4  1 -1

8  0 -2

Sample Output

15

Source

Greater New York 2001

*/

package main

func main() {
	assert(maxsubrect([][]int{
		{0, -2, -7, 0},
		{9, 2, -6, 2},
		{-4, 1, -4, 1},
		{-1, 8, 0, -2},
	}) == 15)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func maxsubrect(m [][]int) int {
	n := len(m)
	p := alloc(n + 1)
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			p[i+1][j] = m[i][j]
		}
	}

	for i := 1; i < n; i++ {
		for j := 0; j < n; j++ {
			p[i+1][j] += p[i][j]
		}
	}

	r := 0
	for i := 1; i <= n; i++ {
		for j := i; j <= n; j++ {
			s := 0
			for k := 0; k < n; k++ {
				v := p[j][k] - p[i-1][k]
				s = max(s+v, 0)
				r = max(r, s)
			}
		}
	}
	return r
}

func alloc(n int) [][]int {
	m := make([][]int, n)
	t := make([]int, n*n)
	for i := range m {
		m[i] = t[i*n : (i+1)*n]
	}
	return m
}
