/*

An [octahedron](https://en.wikipedia.org/wiki/Octahedron) is an 8-sided polyhedron whose faces are triangles.

Create a method that outputs a 3-dimensional array of an octahedron in which the height, width, and depth are equal to the provided integer `size`, which is equal to the length from one vertex to the opposite vertex on the octahedron.

## Example

```
createOctahedron(7)

{{
{ 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 1, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0 }
}, {
{ 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 1, 0, 0, 0 },
{ 0, 0, 1, 1, 1, 0, 0 },
{ 0, 0, 0, 1, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0 }
}, {
{ 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 1, 0, 0, 0 },
{ 0, 0, 1, 1, 1, 0, 0 },
{ 0, 1, 1, 1, 1, 1, 0 },
{ 0, 0, 1, 1, 1, 0, 0 },
{ 0, 0, 0, 1, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0 }
}, {
{ 0, 0, 0, 1, 0, 0, 0 },
{ 0, 0, 1, 1, 1, 0, 0 },
{ 0, 1, 1, 1, 1, 1, 0 },
{ 1, 1, 1, 1, 1, 1, 1 },
{ 0, 1, 1, 1, 1, 1, 0 },
{ 0, 0, 1, 1, 1, 0, 0 },
{ 0, 0, 0, 1, 0, 0, 0 }
}, {
{ 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 1, 0, 0, 0 },
{ 0, 0, 1, 1, 1, 0, 0 },
{ 0, 1, 1, 1, 1, 1, 0 },
{ 0, 0, 1, 1, 1, 0, 0 },
{ 0, 0, 0, 1, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0 }
}, {
{ 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 1, 0, 0, 0 },
{ 0, 0, 1, 1, 1, 0, 0 },
{ 0, 0, 0, 1, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0 }
}, {
{ 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 1, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0 }
}}
```
where each 1 represents a cubic unit that the octahedron takes up and where 0 is a cubic unit of empty space.

## Notes

 - The method should return an empty array/list if either
 - The input size is even (because then it wouldn't be an octahedron. It'd be an irregular polyhedron with 26 sides)
 - if the input size is 0 or less
 - if input size is 1 (that's called a cube).

*/

package main

import (
	"reflect"
)

func main() {
	test(7, [][][]int{
		{
			{0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 1, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0},
		},
		{
			{0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 1, 0, 0, 0},
			{0, 0, 1, 1, 1, 0, 0},
			{0, 0, 0, 1, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0},
		},
		{
			{0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 1, 0, 0, 0},
			{0, 0, 1, 1, 1, 0, 0},
			{0, 1, 1, 1, 1, 1, 0},
			{0, 0, 1, 1, 1, 0, 0},
			{0, 0, 0, 1, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0},
		},
		{
			{0, 0, 0, 1, 0, 0, 0},
			{0, 0, 1, 1, 1, 0, 0},
			{0, 1, 1, 1, 1, 1, 0},
			{1, 1, 1, 1, 1, 1, 1},
			{0, 1, 1, 1, 1, 1, 0},
			{0, 0, 1, 1, 1, 0, 0},
			{0, 0, 0, 1, 0, 0, 0},
		},
		{
			{0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 1, 0, 0, 0},
			{0, 0, 1, 1, 1, 0, 0},
			{0, 1, 1, 1, 1, 1, 0},
			{0, 0, 1, 1, 1, 0, 0},
			{0, 0, 0, 1, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0},
		},
		{
			{0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 1, 0, 0, 0},
			{0, 0, 1, 1, 1, 0, 0},
			{0, 0, 0, 1, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0},
		},
		{
			{0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 1, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0},
		},
	})

	test(0, [][][]int{})
	test(8, [][][]int{})
	test(-7, [][][]int{})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(n int, r [][][]int) {
	m := octahedron(n)
	assert(reflect.DeepEqual(m, r))
}

func octahedron(n int) [][][]int {
	if n < 3 || n&1 == 0 {
		return [][][]int{}
	}

	m := make([][][]int, n)
	for i := range m {
		m[i] = make([][]int, n)
		for j := range m[i] {
			m[i][j] = make([]int, n)
		}
	}

	for z, w := 0, 0; n&1 > 0 && z < n; {
		x0 := n / 2
		x1 := x0
		for y := n/2 - w; y <= n/2+w; y++ {
			for x := x0; x <= x1; x++ {
				m[z][y][x] = 1
			}

			if y < n/2 {
				x0, x1 = x0-1, x1+1
			} else {
				x0, x1 = x0+1, x1-1
			}
		}

		z += 1
		w = z
		if z > n/2 {
			w = n - z - 1
		}
	}
	return m
}
