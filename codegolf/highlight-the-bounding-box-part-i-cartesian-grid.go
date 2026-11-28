/*

You're given a rectangular grid of the characters . and #, like this:

..........
..#.......
....#..#..
...#......
..........
Your task is to fill the entire axis-aligned bounding box of the # with further #:

..........
..######..
..######..
..######..
..........
The axis-aligned bounding box is the smallest rectangle which contains all the #.

Want more? Try Part II!

Rules
You may use any two distinct printable ASCII characters (0x20 to 0x7E, inclusive), in place of # and .. I'll continue referring to them as # and . for the remainder of the specification though.

Input and output may either be a single linefeed-separated string or a list of strings (one for each line), but the format has to be consistent.

You may assume that the input contains at least one # and all lines are the same length.

You may write a program or a function and use any of the our standard methods of receiving input and providing output.

You may use any programming language, but note that these loopholes are forbidden by default.

This is code-golf, so the shortest valid answer – measured in bytes – wins.

Test Cases
Each test case has input and output next to each other.

#    #

...    ...
#..    #..
...    ...

...    ...
#..    ###
..#    ###

.#.    ###
#..    ###
..#    ###

.....    .....
.#.#.    .###.
.....    .....

...    ...
.#.    .#.
...    .#.
.#.    .#.
...    ...

..........    ..........
..........    ..........
....#.....    ....#.....
..........    ..........

..........    ..........
..........    ..........
....#.....    ...##.....
...#......    ...##.....

..........    ..........
..#.......    ..###.....
....#.....    ..###.....
...#......    ..###.....

..........    ..........
..#.......    ..######..
....#..#..    ..######..
...#......    ..######..

.........#    ..########
..#.......    ..########
....#..#..    ..########
...#......    ..########

*/

package main

import (
	"fmt"
	"math"
	"reflect"
)

func main() {
	test([][]byte{
		[]byte("#"),
	}, [][]byte{
		[]byte("#"),
	})

	test([][]byte{
		[]byte("..."),
		[]byte("#.."),
		[]byte("..."),
	}, [][]byte{
		[]byte("..."),
		[]byte("#.."),
		[]byte("..."),
	})

	test([][]byte{
		[]byte("..."),
		[]byte("#.."),
		[]byte("..#"),
	}, [][]byte{
		[]byte("..."),
		[]byte("###"),
		[]byte("###"),
	})

	test([][]byte{
		[]byte(".#."),
		[]byte("#.."),
		[]byte("..#"),
	}, [][]byte{
		[]byte("###"),
		[]byte("###"),
		[]byte("###"),
	})

	test([][]byte{
		[]byte("....."),
		[]byte(".#.#."),
		[]byte("....."),
	}, [][]byte{
		[]byte("....."),
		[]byte(".###."),
		[]byte("....."),
	})

	test([][]byte{
		[]byte("..."),
		[]byte(".#."),
		[]byte("..."),
		[]byte(".#."),
		[]byte("..."),
	}, [][]byte{
		[]byte("..."),
		[]byte(".#."),
		[]byte(".#."),
		[]byte(".#."),
		[]byte("..."),
	})

	test([][]byte{
		[]byte(".........."),
		[]byte(".........."),
		[]byte("....#....."),
		[]byte(".........."),
	}, [][]byte{
		[]byte(".........."),
		[]byte(".........."),
		[]byte("....#....."),
		[]byte(".........."),
	})

	test([][]byte{
		[]byte(".........."),
		[]byte(".........."),
		[]byte("....#....."),
		[]byte("...#......"),
	}, [][]byte{
		[]byte(".........."),
		[]byte(".........."),
		[]byte("...##....."),
		[]byte("...##....."),
	})

	test([][]byte{
		[]byte(".........."),
		[]byte("..#......."),
		[]byte("....#....."),
		[]byte("...#......"),
	}, [][]byte{
		[]byte(".........."),
		[]byte("..###....."),
		[]byte("..###....."),
		[]byte("..###....."),
	})

	test([][]byte{
		[]byte(".........."),
		[]byte("..#......."),
		[]byte("....#..#.."),
		[]byte("...#......"),
	}, [][]byte{
		[]byte(".........."),
		[]byte("..######.."),
		[]byte("..######.."),
		[]byte("..######.."),
	})

	test([][]byte{
		[]byte(".........#"),
		[]byte("..#......."),
		[]byte("....#..#.."),
		[]byte("...#......"),
	}, [][]byte{
		[]byte("..########"),
		[]byte("..########"),
		[]byte("..########"),
		[]byte("..########"),
	})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(m, r [][]byte) {
	hilight(m)
	dump(m)
	assert(reflect.DeepEqual(m, r))
}

func hilight(m [][]byte) {
	x0, y0 := math.MaxInt, math.MaxInt
	x1, y1 := math.MinInt, math.MinInt
	for y := range m {
		for x := range m[y] {
			if m[y][x] == '.' {
				continue
			}
			x0 = min(x0, x)
			x1 = max(x1, x)
			y0 = min(y0, y)
			y1 = max(y1, y)
		}
	}

	for y := y0; y <= y1; y++ {
		for x := x0; x <= x1; x++ {
			m[y][x] = '#'
		}
	}
}

func dump(m [][]byte) {
	for y := range m {
		for x := range m[y] {
			fmt.Printf("%c", m[y][x])
		}
		fmt.Println()
	}
	fmt.Println()
}
