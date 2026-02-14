/*

A binary matrix means that all elements are 0 or 1. For each individual row of the matrix, this row is sorted in non-decreasing order.

Given a row-sorted binary matrix binaryMatrix, return leftmost column index(0-indexed) with at least a 1 in it. If such index doesn't exist, return -1.

You can't access the Binary Matrix directly.  You may only access the matrix using a BinaryMatrix interface:

    BinaryMatrix.get(row, col) returns the element of the matrix at index (row, col) (0-indexed).
    BinaryMatrix.dimensions() returns a list of 2 elements [rows, cols], which means the matrix is rows * cols.

Submissions making more than 1000 calls to BinaryMatrix.get will be judged Wrong Answer.  Also, any solutions that attempt to circumvent the judge will result in disqualification.

For custom testing purposes you're given the binary matrix mat as input in the following four examples. You will not have access the binary matrix directly.

Example 1:
Input: mat = [[0,0],[1,1]]
Output: 0

Example 2:
Input: mat = [[0,0],[0,1]]
Output: 1

Example 3:
Input: mat = [[0,0],[0,0]]
Output: -1

Example 4:
Input: mat = [[0,0,0,1],[0,0,1,1],[0,1,1,1]]
Output: 1

Constraints:

    rows == mat.length
    cols == mat[i].length
    1 <= rows, cols <= 100
    mat[i][j] is either 0 or 1.
    mat[i] is sorted in a non-decreasing way.

*/

package main

type BinaryMatrix interface {
	Dim() (int, int)
	Get(int, int) int
}

type Matrix [][]int

func main() {
	assert(leftone(Matrix{{0, 0}, {1, 1}}) == 0)
	assert(leftone(Matrix{{0, 0}, {0, 1}}) == 1)
	assert(leftone(Matrix{{0, 0}, {0, 0}}) == -1)
	assert(leftone(Matrix{{0, 0, 0, 1}, {0, 0, 1, 1}, {0, 1, 1, 1}}) == 1)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func leftone(matrix BinaryMatrix) int {
	rows, cols := matrix.Dim()
	row := 0
	col := cols - 1
	for row < rows && col >= 0 {
		if matrix.Get(row, col) == 0 {
			row += 1
		} else {
			col -= 1
		}
	}
	if col+1 != cols {
		return col + 1
	}
	return -1
}

func (m Matrix) Dim() (int, int) {
	if len(m) == 0 {
		return 0, 0
	}
	return len(m), len(m[0])
}

func (m Matrix) Get(i, j int) int {
	return m[i][j]
}
