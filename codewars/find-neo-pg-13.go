/*

Neo is somewhere in the Matrix.

public interface Matrix {
  public int size();
  public int get(int x, int y);
}


You are Morpheus, and your job is to find him.

public class Morpheus {
  public int[] find(Matrix matrix, int neo) {
    // return Neo's x and y coordinates as a two-element array
  }
}

The matrix is controlled by machines, so it is very orderly. It is quadratic, and the following rules hold for all elements:

matrix[x,y] < matrix[x+1,y]
matrix[x,y] < matrix[x,y+1]

And of course, there will be no duplicates of Neo - he is *The One*.

*/

package main

import (
	"reflect"
)

type Matrix interface {
	Size() int
	Get(x, y int) int
}

type Grid [][]int

func main() {
	test(Grid{}, 1, nil)
	test(Grid{{1}}, 1, []int{0, 0})
	test(Grid{{1, 2}, {3, 4}}, 1, []int{0, 0})
	test(Grid{{1, 2}, {3, 4}}, 2, []int{0, 1})
	test(Grid{{1, 2}, {3, 4}}, 3, []int{1, 0})
	test(Grid{{1, 2}, {3, 4}}, 4, []int{1, 1})
	test(Grid{
		{0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
		{10, 11, 12, 13, 14, 15, 16, 17, 18, 19},
		{20, 21, 22, 23, 24, 25, 26, 27, 28, 29},
		{30, 31, 32, 33, 34, 35, 36, 37, 38, 39},
		{40, 41, 42, 43, 44, 45, 46, 47, 48, 49},
		{50, 51, 52, 53, 54, 55, 56, 57, 58, 59},
		{60, 61, 62, 63, 64, 65, 66, 67, 68, 69},
		{70, 71, 72, 73, 74, 75, 76, 77, 78, 79},
		{80, 81, 82, 83, 84, 85, 86, 87, 88, 89},
		{90, 91, 92, 93, 94, 95, 96, 97, 98, 99},
	}, 42, []int{4, 2})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(matrix Matrix, neo int, expected []int) {
	location := find(matrix, neo)
	assert(reflect.DeepEqual(location, expected))
}

func find(matrix Matrix, neo int) []int {
	n := matrix.Size()
	x, y := 0, n-1
	for x < n {
		id := matrix.Get(x, y)
		if neo == id {
			return []int{x, y}
		}
		if id < neo {
			x++
		} else {
			y--
		}
	}
	return nil
}

func (g Grid) Size() int {
	return len(g)
}

func (g Grid) Get(x, y int) int {
	return g[x][y]
}
