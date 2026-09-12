/*

Story

It's a pretty relaxing life here at the nut farm.

Most of the time we just sit around looking at our nuts.

But once a year comes harvesting time...

Harvesting nuts is very easy. We just shake the trees and the nuts fall out!

As they fall down the nuts might hit branches:

    Sometimes they bounce left.
    Sometimes they bounce right.
    Sometimes they get stuck in the tree and don't fall out at all.

Legend

    o = a nut
    \ = branch. A nut hitting this branch bounces right
    / = branch. A nut hitting this branch bounces left
    _ = branch. A nut hitting this branch gets stuck in the tree
    . = leaves, which have no effect on falling nuts
    | = tree trunk, which has no effect on falling nuts
     = empty space, which has no effect on falling nuts

Kata Task

Shake the tree and count where the nuts land.

Output - An array (same width as the tree) which indicates how many nuts fell at each position ^

^ See the example tests
Notes

    The nuts are always found at the top of the tree
    Nuts do not affect the falling patterns of other nuts
    There are always enough spaces for nuts to fall between branches
    There are no branches at the extreme left/right edges of the tree matrix so it is not possible for a nut to fall "out of bounds"

Example

.o.oooooo.o.o.oooooo.
..\.\.../..\.../..\..
..../..\..../....../.
.....\...././.\..\.\.
...../../././...\....
.../.../..\./.\..\...
./.......\../.\../...
....\..../....././...
.../.\._.\../._../.\.
.\...././....\../.\..
./......././.../../..

101005000020000000040

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test([][]byte{
		[]byte(" o o o  "),
		[]byte(" /    / "),
		[]byte("   /    "),
		[]byte("  /  /  "),
		[]byte("   ||   "),
		[]byte("   ||   "),
		[]byte("   ||   "),
	}, []int{1, 1, 0, 0, 1, 0, 0, 0})

	test([][]byte{
		[]byte(` o o o  `),
		[]byte(` \    \ `),
		[]byte(`   \    `),
		[]byte(`  \  \  `),
		[]byte(`   ||   `),
		[]byte(`   ||   `),
		[]byte(`   ||   `),
	}, []int{0, 0, 0, 1, 1, 0, 1, 0})

	test([][]byte{
		[]byte(" o o o  "),
		[]byte(" _      "),
		[]byte("   _ _  "),
		[]byte("   ||   "),
		[]byte("   ||   "),
		[]byte("   ||   "),
	}, []int{0, 0, 0, 0, 0, 0, 0, 0})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(tree [][]byte, expected []int) {
	nuts := shaketree(tree)
	fmt.Println(nuts)
	assert(reflect.DeepEqual(nuts, expected))
}

func shaketree(tree [][]byte) []int {
	if len(tree) == 0 || len(tree[0]) == 0 {
		return []int{}
	}

	nuts := make([]int, len(tree[0]))
	for x, y := 0, 0; x < len(nuts); x, y = x+1, x+1 {
		if tree[0][x] != 'o' {
			continue
		}

	loop:
		for _, c := range tree {
			switch c[y] {
			case '_':
				y = -1
				break loop
			case '\\':
				y++
			case '/':
				y--
			}
		}
		if y >= 0 {
			nuts[y]++
		}
	}
	return nuts
}
