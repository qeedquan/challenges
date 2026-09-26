/*

You will be given a string s. It is guaranteed that the string has equal and at least one [s and ]s. It is also guaranteed that the brackets are balanced. The string can also have other characters.

The objective is to output/return a list of tuples or a list of lists containing indices of each [ and ] pair.

note: The string is zero-indexed.
Example: !^45sdfd[hello world[[djfut]%%357]sr[jf]s][srtdg][] should return

[(8, 41), (20, 33), (21, 27), (36, 39), (42, 48), (49, 50)] or something equivalent to this. Tuples are not necessary. Lists can also be used.

Test cases:

input:[[asdf][][td([)ty54g% ]hg[[f]u][f[[jhg][gfd]sdf]sdfs]ghd]fr43f]
output:[(0, 62),(1, 6), (7, 8), (9, 56), (13, 22), (25, 30), (26, 28), (31, 52), (33, 47), (34, 38), (39, 43)]
input:[[][][][]][[][][][[[[(]]]]]))
output:[(0, 9), (1, 2), (3, 4), (5, 6), (7, 8), (10,26),(11, 12), (13, 14), (15, 16), (17, 25), (18, 24), (19, 23), (20, 22)]
input:[][][[]]
output:[(0, 1), (2, 3), (4, 7), (5, 6)]
input:[[[[[asd]as]sd]df]fgf][][]
output:[(0, 21), (1, 17), (2, 14), (3, 11), (4, 8), (22, 23), (24, 25)]
input:[]
output:[(0,1)]
input:[[(])]
output:[(0, 5), (1, 3)]
This is code-golf, so the shortest code in bytes for each programming language wins.

*/

package main

import (
	"fmt"
	"reflect"
	"sort"
)

func main() {
	test(
		"!^45sdfd[hello world[[djfut]%%357]sr[jf]s][srtdg][]",
		[][2]int{{8, 41}, {20, 33}, {21, 27}, {36, 39}, {42, 48}, {49, 50}},
	)

	test(
		"[[asdf][][td([)ty54g% ]hg[[f]u][f[[jhg][gfd]sdf]sdfs]ghd]fr43f]",
		[][2]int{{0, 62}, {1, 6}, {7, 8}, {9, 56}, {13, 22}, {25, 30}, {26, 28}, {31, 52}, {33, 47}, {34, 38}, {39, 43}},
	)

	test(
		"[[][][][]][[][][][[[[(]]]]]))",
		[][2]int{{0, 9}, {1, 2}, {3, 4}, {5, 6}, {7, 8}, {10, 26}, {11, 12}, {13, 14}, {15, 16}, {17, 25}, {18, 24}, {19, 23}, {20, 22}},
	)

	test(
		"[][][[]]",
		[][2]int{{0, 1}, {2, 3}, {4, 7}, {5, 6}},
	)

	test(
		"[[[[[asd]as]sd]df]fgf][][]",
		[][2]int{{0, 21}, {1, 17}, {2, 14}, {3, 11}, {4, 8}, {22, 23}, {24, 25}},
	)

	test(
		"[]",
		[][2]int{{0, 1}},
	)

	test(
		"[[(])]",
		[][2]int{{0, 5}, {1, 3}},
	)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(s string, r [][2]int) {
	p := matching(s)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func matching(s string) [][2]int {
	r := [][2]int{}
	p := []int{}
	for i, c := range s {
		switch c {
		case '[':
			p = append(p, i)
		case ']':
			n := len(p)
			if n > 0 {
				r = append(r, [2]int{p[n-1], i})
				p = p[:n-1]
			}
		}
	}

	sort.Slice(r, func(i, j int) bool {
		if r[i][0] == r[j][0] {
			return r[i][1] < r[j][1]
		}
		return r[i][0] < r[j][0]
	})
	return r
}
