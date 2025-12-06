/*

We want to find the area of a set of buildings stacked close to each other.

A matrix (an array of arrays) gives us a description of the building from above, where each number represents the height expressed in cubes 1*1*1, the cubes are stacked adjacent to each other.

For example:

matrix = [[2,1],[2,0]]

In position (0,0), there are 2 cubes stacked on each other
In position (0,1), there is only 1 cube
In position (1,0), there are 2 cubes stacked on each other
In position (1,1), there are 0 cubes stacked on each other.

So, the total covered area is 20.
The matrix will be of at least size 1*1 and square.

Note: The floor of the building counts as area as well.

*/

package main

func main() {
	assert(surfacearea([][]int{{1}}) == 6)
	assert(surfacearea([][]int{{2, 1}, {2, 0}}) == 20)
	assert(surfacearea([][]int{{1, 3, 4}, {2, 2, 3}, {1, 2, 4}}) == 60)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func surfacearea(m [][]int) int {
	r := 0
	for i := range m {
		for j := range m[i] {
			if m[i][j] > 0 {
				r += 2 + 4*m[i][j]
			}
			if i > 0 {
				r -= 2 * min(m[i][j], m[i-1][j])
			}
			if j > 0 {
				r -= 2 * min(m[i][j], m[i][j-1])
			}
		}
	}
	return r
}
