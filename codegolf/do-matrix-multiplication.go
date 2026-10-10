/*

In mathematics, matrix multiplication or the matrix product is a binary operation that produces a matrix from two matrices.
The definition is motivated by linear equations and linear transformations on vectors, which have numerous applications in applied mathematics, physics, and engineering.
In more detail, if A is an n × m matrix and B is an m × p matrix, their matrix product AB is an n × p matrix, in which the m entries across a row of A are multiplied with the m entries down a columns of B and summed to produce an entry of AB.
When two linear transformations are represented by matrices, then the matrix product represents the composition of the two transformations.

Source: Wikipedia

In other words, to multiply two matrices, for example:

1 2 3   1 4
2 3 4 × 3 1 =
3 4 5   4 6
First, take row number 1 in the first matrix, column number 1 in the second matrix, and multiply 1 by 1, 2 by 3, and 3 by 4.

1 × 1 = 1
2 × 3 = 6
3 × 4 = 12
Now add them together to get your first item:

1 2 3   1 4   19
2 3 4 × 3 1 =
3 4 5   4 6
For the second number in the first column of the result, you will need to take row number 2 instead of row number 1 and do the same thing.

1 × 2 = 2
3 × 3 = 9
4 × 4 = 16
      = 27
After you do the entire first column, the result looks like this:

1 2 3   1 4   19
2 3 4 × 3 1 = 27
3 4 5   4 6   35
Now, do the same exact thing again, but take the second column instead of the first column, resulting in:

1 2 3   1 4   19 24
2 3 4 × 3 1 = 27 35
3 4 5   4 6   35 46

Your task
Given two matrices (max dimensions 200x200), containing numbers in the range -10000 to 10000, where the number of columns on the first one equals the number of rows on the second, multiply the first one by the second one. (Matrix multiplication is non-commutative.)

You may take input and give output as an array of arrays (or equivalent), a matrix (if your language has that format) or a multiline string.

You may not use any built-ins for matrix multiplication.

Test cases
1 2   1 2 3 4 5    13 16 19 22 25
3 4 × 6 7 8 9 10 = 27 34 41 48 55
5 6                41 52 63 74 85

2 3   3 5   15 13
3 4 × 3 1 = 21 19

5 3            11    27
1 3      1 3   7     15
9 3    × 2 4 = 15    39
1 -1000        -1999 -3997

Remember, this is code-golf, so the code with the fewest bytes wins.

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test(
		[][]int{{1, 2}, {3, 4}, {5, 6}},
		[][]int{{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}},
		[][]int{{13, 16, 19, 22, 25}, {27, 34, 41, 48, 55}, {41, 52, 63, 74, 85}},
	)

	test(
		[][]int{{2, 3}, {3, 4}},
		[][]int{{3, 5}, {3, 1}},
		[][]int{{15, 13}, {21, 19}},
	)

	test(
		[][]int{{5, 3}, {1, 3}, {9, 3}, {1, -1000}},
		[][]int{{1, 3}, {2, 4}},
		[][]int{{11, 27}, {7, 15}, {15, 39}, {-1999, -3997}},
	)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a, b, r [][]int) {
	c := matcopy(r)
	matzero(c)
	matmul(a, b, c)
	fmt.Println(c)
	assert(reflect.DeepEqual(c, r))
}

func matzero(m [][]int) {
	for i := range m {
		for j := range m[i] {
			m[i][j] = 0
		}
	}
}

func matcopy(m [][]int) [][]int {
	p := make([][]int, len(m))
	for i := range p {
		p[i] = append(p[i], m[i]...)
	}
	return p
}

func matmul(a, b, c [][]int) [][]int {
	if len(a) == 0 || len(a[0]) == 0 || len(b) == 0 || len(b[0]) == 0 {
		return c
	}

	m, n := len(a), len(a[0])
	o, p := len(b), len(b[0])
	if n != o {
		panic("invalid dimension")
	}

	for i := 0; i < m; i++ {
		for j := 0; j < p; j++ {
			v := 0
			for k := 0; k < n; k++ {
				v += a[i][k] * b[k][j]
			}
			c[i][j] = v
		}
	}
	return c
}
