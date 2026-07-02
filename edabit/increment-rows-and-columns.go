/*

Write a function that takes in three parameters: r, c, i, where:

r and c are the number of rows and columns to initialize a zero matrix.
i represents the list of incrementing operations (+1).
And returns the resulting matrix after applying all the increment operations. Each increment operation will add 1 to the rows or columns specified in the incrementing list.

To illustrate:

final(3, 3, ["2r", "2c", "1r", "0c"])

# Initialize a 3 x 3 matrix of zeroes.

[
  [0, 0, 0],
  [0, 0, 0],
  [0, 0, 0]
]

# Apply "2r" (increment index 2 row).

[
  [0, 0, 0],
  [0, 0, 0],
  [1, 1, 1]
]

# Apply "2c" (increment index 2 column).

[
  [0, 0, 1],
  [0, 0, 1],
  [1, 1, 2]
]

# Apply "1r" (increment index 1 row).

[
  [0, 0, 1],
  [1, 1, 2],
  [1, 1, 2]
]

# Apply "0c" (increment index 0 column).
# This is the result you should return.

[
  [1, 0, 1],
  [2, 1, 2],
  [2, 1, 2]
]
Examples
final(2, 2, ["0r", "0r", "0r", "1c"]) ➞ [
  [3, 4],
  [0, 1]
]

final(2, 2, ["0c"]) ➞ [
  [1, 0],
  [1, 0]
]

final(3, 3, ["0c", "1c", "1c", "2c", "2c", "2c"]) ➞ [
    [1, 2, 3],
    [1, 2, 3],
    [1, 2, 3]
]

final(3, 3, []) ➞ [
  [0, 0, 0],
  [0, 0, 0],
  [0, 0, 0]
]

Notes
The 2D matrix is 0-indexed.
The matrix created will have at least one row and one column.
All increment operations will be exactly +1.

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test(3, 3, []string{"2r", "2c", "1r", "0c"}, [][]int{
		{1, 0, 1},
		{2, 1, 2},
		{2, 1, 2},
	})

	test(2, 2, []string{"0r", "0r", "0r", "1c"}, [][]int{
		{3, 4},
		{0, 1},
	})

	test(2, 2, []string{"0c"}, [][]int{
		{1, 0},
		{1, 0},
	})

	test(3, 3, []string{"0c", "1c", "1c", "2c", "2c", "2c"}, [][]int{
		{1, 2, 3},
		{1, 2, 3},
		{1, 2, 3},
	})

	test(3, 3, []string{}, [][]int{
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0},
	})

	test(3, 4, []string{"1r", "1r", "1r", "3c", "3c", "3c"}, [][]int{
		{0, 0, 0, 3},
		{3, 3, 3, 6},
		{0, 0, 0, 3},
	})

	test(10, 1, []string{"1r", "2r", "3r", "0c"}, [][]int{
		{1},
		{2},
		{2},
		{2},
		{1},
		{1},
		{1},
		{1},
		{1},
		{1},
	})

	test(2, 5, []string{"1r", "1r", "1r", "1c", "0c", "0c", "1r", "0c", "1r", "0c"}, [][]int{
		{4, 1, 0, 0, 0},
		{9, 6, 5, 5, 5},
	})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(r, c int, s []string, rm [][]int) {
	m := final(r, c, s)
	fmt.Println(m)
	assert(reflect.DeepEqual(m, rm))
}

func final(r, c int, s []string) [][]int {
	m := make([][]int, r)
	for i := range m {
		m[i] = make([]int, c)
	}

	mr := make([]int, r)
	mc := make([]int, c)
	for _, s := range s {
		var i int
		n, _ := fmt.Sscanf(s, "%v", &i)
		if n != 1 {
			continue
		}

		var p []int
		switch s[len(s)-1] {
		case 'r':
			p = mr
		case 'c':
			p = mc
		default:
			continue
		}

		if 0 <= i && i < len(p) {
			p[i]++
		}
	}

	for i := range m {
		for j := range m[i] {
			m[i][j] = mr[i] + mc[j]
		}
	}

	return m
}
