/*

Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

Example 1:
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

Example 2:
Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

Constraints:

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-2^31 <= matrix[i][j] <= 2^31 - 1

Follow up:

A straightforward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?

Hint 1
If any cell of the matrix has a zero we can record its row and column number using additional memory.
But if you don't want to use extra memory then you can manipulate the array instead. i.e. simulating exactly what the question says.

Hint 2
Setting cell values to zero on the fly while iterating might lead to discrepancies.
What if you use some other integer value as your marker? There is still a better approach for this problem with O(1) space.

Hint 3
We could have used 2 sets to keep a record of rows/columns which need to be set to zero.
But for an O(1) space solution, you can use one of the rows and and one of the columns to keep track of this information.

Hint 4
We can use the first cell of every row and column as a flag.
This flag would determine whether a row or column has been set to zero.

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test(
		[][]int{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}},
		[][]int{{1, 0, 1}, {0, 0, 0}, {1, 0, 1}},
	)

	test(
		[][]int{{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}},
		[][]int{{0, 0, 0, 0}, {0, 4, 5, 0}, {0, 3, 1, 0}},
	)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(m, r [][]int) {
	zeroes(m)
	fmt.Println(m)
	assert(reflect.DeepEqual(m, r))
}

func zeroes(m [][]int) {
	if len(m) == 0 || len(m[0]) == 0 {
		return
	}

	w, h := len(m[0]), len(m)
	r, c := false, false
	for y := 0; y < h; y++ {
		for x := 0; x < w; x++ {
			if m[y][x] == 0 {
				if y == 0 {
					r = true
				}
				if x == 0 {
					c = true
				}

				m[0][x] = 0
				m[y][0] = 0
			}
		}
	}

	for y := 1; y < h; y++ {
		for x := 1; x < w; x++ {
			if m[0][x] == 0 || m[y][0] == 0 {
				m[y][x] = 0
			}
		}
	}

	if r {
		for x := 0; x < w; x++ {
			m[0][x] = 0
		}
	}

	if c {
		for y := 0; y < h; y++ {
			m[y][0] = 0
		}
	}
}
