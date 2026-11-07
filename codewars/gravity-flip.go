/*

If you've completed this kata already and want a bigger challenge, here's the 3D version

Bob is bored during his physics lessons so he's built himself a toy box to help pass the time. The box is special because it has the ability to change gravity.

There are some columns of toy cubes in the box arranged in a line. The i-th column contains a_i cubes. At first, the gravity in the box is pulling the cubes downwards. When Bob switches the gravity, it begins to pull all the cubes to a certain side of the box, d, which can be either 'L' or 'R' (left or right). Below is an example of what a box of cubes might look like before and after switching gravity.

+---+                                       +---+
|   |                                       |   |
+---+                                       +---+
+---++---+     +---+              +---++---++---+
|   ||   |     |   |   -->        |   ||   ||   |
+---++---+     +---+              +---++---++---+
+---++---++---++---+         +---++---++---++---+
|   ||   ||   ||   |         |   ||   ||   ||   |
+---++---++---++---+         +---++---++---++---+
Given the initial configuration of the cubes in the box, find out how many cubes are in each of the n columns after Bob switches the gravity.

Examples (input -> output:
* 'R', [3, 2, 1, 2]      ->  [1, 2, 2, 3]
* 'L', [1, 4, 5, 3, 5 ]  ->  [5, 5, 4, 3, 1]

*/

package main

import (
	"reflect"
	"sort"
)

func main() {
	test('R', []int{3, 2, 1, 2}, []int{1, 2, 2, 3})
	test('L', []int{1, 4, 5, 3, 5}, []int{5, 5, 4, 3, 1})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(d rune, a, r []int) {
	flip(d, a)
	assert(reflect.DeepEqual(a, r))
}

func flip(d rune, a []int) []int {
	switch d {
	case 'R':
		sort.Slice(a, func(i, j int) bool { return a[i] < a[j] })
	case 'L':
		sort.Slice(a, func(i, j int) bool { return a[i] > a[j] })
	}
	return a
}
