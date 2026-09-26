/*

Task
Your apple has a virus, and the infection is spreading.

The apple is a two-dimensional array, containing strings "V" (virus) and "A" (uninfected parts). For each hour, the infection spreads one space up, down, left and right.

Input: 2D array apple and number n (n >= 0).

Output: 2D array showing the apple after n hours.

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test([][]byte{
		{'A', 'A', 'A', 'A', 'A'},
		{'V', 'A', 'A', 'A', 'A'},
		{'A', 'A', 'A', 'A', 'A'},
		{'A', 'A', 'A', 'A', 'A'},
		{'A', 'A', 'A', 'A', 'A'},
	}, 0, [][]byte{
		{'A', 'A', 'A', 'A', 'A'},
		{'V', 'A', 'A', 'A', 'A'},
		{'A', 'A', 'A', 'A', 'A'},
		{'A', 'A', 'A', 'A', 'A'},
		{'A', 'A', 'A', 'A', 'A'},
	})

	test([][]byte{
		{'A', 'A', 'A', 'A', 'A'},
		{'V', 'A', 'A', 'A', 'A'},
		{'A', 'A', 'A', 'A', 'A'},
		{'A', 'A', 'A', 'A', 'A'},
		{'A', 'A', 'A', 'A', 'A'},
	}, 1, [][]byte{
		{'V', 'A', 'A', 'A', 'A'},
		{'V', 'V', 'A', 'A', 'A'},
		{'V', 'A', 'A', 'A', 'A'},
		{'A', 'A', 'A', 'A', 'A'},
		{'A', 'A', 'A', 'A', 'A'},
	})

	test([][]byte{
		{'A', 'A', 'A', 'A', 'A'},
		{'V', 'A', 'A', 'A', 'A'},
		{'A', 'A', 'A', 'A', 'A'},
		{'A', 'A', 'A', 'A', 'A'},
		{'A', 'A', 'A', 'A', 'A'},
	}, 2, [][]byte{
		{'V', 'V', 'A', 'A', 'A'},
		{'V', 'V', 'V', 'A', 'A'},
		{'V', 'V', 'A', 'A', 'A'},
		{'V', 'A', 'A', 'A', 'A'},
		{'A', 'A', 'A', 'A', 'A'},
	})

	test([][]byte{
		{'A', 'A', 'A', 'A', 'A'},
		{'A', 'A', 'A', 'A', 'A'},
		{'A', 'A', 'V', 'A', 'A'},
		{'A', 'A', 'A', 'A', 'A'},
		{'A', 'A', 'A', 'A', 'A'},
	}, 1, [][]byte{
		{'A', 'A', 'A', 'A', 'A'},
		{'A', 'A', 'V', 'A', 'A'},
		{'A', 'V', 'V', 'V', 'A'},
		{'A', 'A', 'V', 'A', 'A'},
		{'A', 'A', 'A', 'A', 'A'},
	})

	test([][]byte{
		{'A', 'A', 'A', 'A', 'A'},
		{'A', 'A', 'A', 'A', 'A'},
		{'A', 'A', 'V', 'A', 'A'},
		{'A', 'A', 'A', 'A', 'A'},
		{'A', 'A', 'A', 'A', 'A'},
	}, 2, [][]byte{
		{'A', 'A', 'V', 'A', 'A'},
		{'A', 'V', 'V', 'V', 'A'},
		{'V', 'V', 'V', 'V', 'V'},
		{'A', 'V', 'V', 'V', 'A'},
		{'A', 'A', 'V', 'A', 'A'},
	})

	test([][]byte{
		{'A', 'A', 'A', 'A', 'A'},
		{'A', 'A', 'A', 'A', 'A'},
		{'A', 'A', 'V', 'A', 'A'},
		{'A', 'A', 'A', 'A', 'A'},
		{'A', 'A', 'A', 'A', 'A'},
	}, 3, [][]byte{
		{'A', 'V', 'V', 'V', 'A'},
		{'V', 'V', 'V', 'V', 'V'},
		{'V', 'V', 'V', 'V', 'V'},
		{'V', 'V', 'V', 'V', 'V'},
		{'A', 'V', 'V', 'V', 'A'},
	})

	test([][]byte{
		{'A', 'A', 'A', 'A', 'A'},
		{'A', 'A', 'A', 'A', 'A'},
		{'A', 'A', 'V', 'A', 'A'},
		{'A', 'A', 'A', 'A', 'A'},
		{'A', 'A', 'A', 'A', 'A'},
	}, 4, [][]byte{
		{'V', 'V', 'V', 'V', 'V'},
		{'V', 'V', 'V', 'V', 'V'},
		{'V', 'V', 'V', 'V', 'V'},
		{'V', 'V', 'V', 'V', 'V'},
		{'V', 'V', 'V', 'V', 'V'},
	})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(m [][]byte, n int, r [][]byte) {
	sc(m, n)
	dump(m)
	assert(reflect.DeepEqual(m, r))
}

func dump(m [][]byte) {
	for y := range m {
		for x := range m[y] {
			fmt.Printf("%c ", m[y][x])
		}
		fmt.Println()
	}
	fmt.Println()
}

func sc(m [][]byte, n int) {
	for range n {
		for y := range m {
			for x := range m[y] {
				spread(m, x, y, n)
			}
		}

		for y := range m {
			for x := range m[y] {
				if m[y][x] != 'A' {
					m[y][x] = 'V'
				}
			}
		}
	}
}

func spread(m [][]byte, x, y, n int) {
	if m[y][x] != 'V' {
		return
	}

	dir := [][2]int{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}
	for _, d := range dir {
		px := x + d[0]
		py := y + d[1]
		if py < 0 || py >= len(m) || px < 0 || px >= len(m[py]) {
			continue
		}
		m[py][px] = 'X'
	}
}
