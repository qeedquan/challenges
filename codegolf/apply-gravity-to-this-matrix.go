/*

This was inspired by this question. Given an m×n matrix of 0's and 1's,
apply "gravity" to it. This means to drop down all the 1's as if they were affected by gravity.

For example

[[1,0,1,1,0,1,0]
 [0,0,0,1,0,0,0]
 [1,0,1,1,1,1,1]
 [0,1,1,0,1,1,0]
 [1,1,0,1,0,0,1]]
Should result in

[[0,0,0,0,0,0,0]
 [0,0,0,1,0,0,0]
 [1,0,1,1,0,1,0]
 [1,1,1,1,1,1,1]
 [1,1,1,1,1,1,1]]

As all 1's have been dropped down.

input
Input will be atleast  1×1.
You may take input in all reasonable forms (Bitsets, arrays, Lists) and either output the result,
return a new Bitset, array or list or simply modify the input.

This is code golf, so the answer with the fewest bytes wins!

test-cases
More test-cases:

[[1,0]                   [[0,0]
 [0,0]            ->      [1,0]
 [1,0]]                   [1,0]]

[[1,1,1,1,1]            [[1,0,1,1,0]
 [1,0,1,1,0]      ->     [1,1,1,1,0]
 [1,1,1,1,0]]            [1,1,1,1,1]]

[[1]]             ->    [[1]]
The brackets are just there to visualize arrays, they are not required in your output!

*/

package main

import "fmt"

func main() {
	dump(apply([][]int{
		{1, 0, 1, 1, 0, 1, 0},
		{0, 0, 0, 1, 0, 0, 0},
		{1, 0, 1, 1, 1, 1, 1},
		{0, 1, 1, 0, 1, 1, 0},
		{1, 1, 0, 1, 0, 0, 1},
	}))

	dump(apply([][]int{
		{1, 0},
		{0, 0},
		{1, 0},
	}))

	dump(apply([][]int{
		{1, 1, 1, 1, 1},
		{1, 0, 1, 1, 0},
		{1, 1, 1, 1, 0},
	}))

	dump(apply([][]int{
		{1},
	}))
}

func apply(m [][]int) [][]int {
	if len(m) == 0 || len(m[0]) == 0 {
		return m
	}

	w, h := len(m[0]), len(m)
	for x := range w {
		c := 0
		for y := range h {
			if m[y][x] == 1 {
				c += 1
			}
		}

		for y := range h {
			m[y][x] = 0
			if h-y <= c {
				m[y][x] = 1
			}
		}
	}
	return m
}

func dump(m [][]int) {
	for i := range m {
		fmt.Println(m[i])
	}
	fmt.Println()
}
