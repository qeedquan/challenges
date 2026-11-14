/*

The task
This challenge is very simple. Your input is a rectangular 2D array of integers, sized at least 1×1. It can be taken in any reasonable format. Your output shall be the input array, but with all entries not on the first or last row or column set to 0. It must be in the same format as the input.

For example, if the input array is

67  4 -8  5 13
 9 13 42  4 -7
 1  1  3 -9 29
16 99  8 77  0
then the correct output is

67  4 -8  5 13
 9  0  0  0 -7
 1  0  0  0 29
16 99  8 77  0
Rules and scoring
You can write a full program or a function, and functions are allowed to modify the input in place instead of returning it. The lowest byte count wins, and standard loopholes are disallowed.

Test cases
These are formatted as nested lists to make copy-pasting easier.

[[3]] -> [[3]]
[[7,2,8]] -> [[7,2,8]]
[[3],[5],[12],[-6]] -> [[3],[5],[12],[-6]]
[[99,98,97],[88,87,86]] -> [[99,98,97],[88,87,86]]
[[6,7],[8,9],[10,11]] -> [[6,7],[8,9],[10,11]]
[[-1,-2,-3],[1,2,3],[5,5,5]] -> [[-1,-2,-3],[1,0,3],[5,5,5]]
[[67,4,-8,5,13],[9,13,42,4,-7],[1,1,3,-9,29],[16,99,8,77,0]] -> [[67,4,-8,5,13],[9,0,0,0,-7],[1,0,0,0,29],[16,99,8,77,0]]
[[0,1,0,1,0],[1,0,1,0,1],[0,1,0,1,0],[1,0,1,0,1],[0,1,0,1,0]] -> [[0,1,0,1,0],[1,0,0,0,1],[0,0,0,0,0],[1,0,0,0,1],[0,1,0,1,0]]

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test([][]int{
		{3},
	}, [][]int{
		{3},
	})

	test([][]int{
		{7, 2, 8},
	}, [][]int{
		{7, 2, 8},
	})

	test([][]int{
		{3},
		{5},
		{12},
		{-6},
	}, [][]int{
		{3},
		{5},
		{12},
		{-6},
	})

	test([][]int{
		{99, 98, 97},
		{88, 87, 86},
	}, [][]int{
		{99, 98, 97},
		{88, 87, 86},
	})

	test([][]int{
		{6, 7},
		{8, 9},
		{10, 11},
	}, [][]int{
		{6, 7},
		{8, 9},
		{10, 11},
	})

	test([][]int{
		{-1, -2, -3},
		{1, 2, 3},
		{5, 5, 5},
	}, [][]int{
		{-1, -2, -3},
		{1, 0, 3},
		{5, 5, 5},
	})

	test([][]int{
		{67, 4, -8, 5, 13},
		{9, 13, 42, 4, -7},
		{1, 1, 3, -9, 29},
		{16, 99, 8, 77, 0},
	}, [][]int{
		{67, 4, -8, 5, 13},
		{9, 0, 0, 0, -7},
		{1, 0, 0, 0, 29},
		{16, 99, 8, 77, 0},
	})

	test([][]int{
		{0, 1, 0, 1, 0},
		{1, 0, 1, 0, 1},
		{0, 1, 0, 1, 0},
		{1, 0, 1, 0, 1},
		{0, 1, 0, 1, 0},
	}, [][]int{
		{0, 1, 0, 1, 0},
		{1, 0, 0, 0, 1},
		{0, 0, 0, 0, 0},
		{1, 0, 0, 0, 1},
		{0, 1, 0, 1, 0},
	})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(m, r [][]int) {
	hollow(m)
	fmt.Println(m)
	assert(reflect.DeepEqual(m, r))
}

func hollow(m [][]int) [][]int {
	for i := 1; i < len(m)-1; i++ {
		for j := 1; j < len(m[i])-1; j++ {
			m[i][j] = 0
		}
	}
	return m
}
