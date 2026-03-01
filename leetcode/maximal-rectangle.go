/*

Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Example 1:

https://assets.leetcode.com/uploads/2020/09/14/maximal.jpgInput: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.

Example 2:

Input: matrix = [["0"]]
Output: 0
Example 3:

Input: matrix = [["1"]]
Output: 1

Constraints:

rows == matrix.length
cols == matrix[i].length
1 <= rows, cols <= 200
matrix[i][j] is '0' or '1'.

*/

package main

func main() {
	assert(maximal([][]int{
		{'1', '0', '1', '0', '0'},
		{'1', '0', '1', '1', '1'},
		{'1', '1', '1', '1', '1'},
		{'1', '0', '0', '1', '0'},
	}) == 6)

	assert(maximal([][]int{
		{'0'},
	}) == 0)

	assert(maximal([][]int{
		{'1'},
	}) == 1)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func maximal(m [][]int) int {
	if len(m) == 0 || len(m[0]) == 0 {
		return 0
	}

	h := len(m)
	w := len(m[0])
	H := make([]int, w)
	L := make([]int, w)
	R := make([]int, w)
	for i := range R {
		R[i] = w
	}

	a := 0
	for i := range h {
		l := 0
		r := w
		for j := range w {
			if m[i][j] == '1' {
				H[j] += 1
				L[j] = max(L[j], l)
			} else {
				l = j + 1
				H[j] = 0
				L[j] = 0
				R[j] = w
			}
		}

		for j := w - 1; j >= 0; j-- {
			if m[i][j] == '1' {
				R[j] = min(R[j], r)
				a = max(a, H[j]*(R[j]-L[j]))
			} else {
				r = j
			}
		}
	}
	return a
}
