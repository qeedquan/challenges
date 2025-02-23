/*

Input
A integer n ( ≥ 1) and a digit d (an integer such that 0 ≤ d ≤ 9).

In either order; from stdin or parameters or whatever; to a program or function; etc.

Output
The integers from 1 to n inclusive (in order) whose decimal representations contain an even number of ds. (That is, the integers in the list are the integers that have, respectively, an even number of ds.)

In any standard format, etc. In particular, the output need not be represented in decimal.

If output as a single string, the integers must be separated somehow (spaces, commas, newlines, null bytes, whatever).

Examples
in(d,n) ↦ out
1,12    ↦ 2 3 4 5 6 7 8 9 11
0,111   ↦ 1,2,3,4,5,6,7,8,9,11,12,13,14,15,16,17,18,19,21,22,23,24,25,26,27,28,29,31,32,33,34,35,36,37,38,39,41,42,43,44,45,46,47,48,49,51,52,53,54,55,56,57,58,59,61,62,63,64,65,66,67,68,69,71,72,73,74,75,76,77,78,79,81,82,83,84,85,86,87,88,89,91,92,93,94,95,96,97,98,99,100,111

Thanks
To quintopia for the title.

*/

package main

import (
	"fmt"
	"slices"
)

func main() {
	test(1, 12, []int{2, 3, 4, 5, 6, 7, 8, 9, 11})
	test(0, 111, []int{1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 13, 14, 15, 16, 17, 18, 19, 21, 22, 23, 24, 25, 26, 27, 28, 29, 31, 32, 33, 34, 35, 36, 37, 38, 39, 41, 42, 43, 44, 45, 46, 47, 48, 49, 51, 52, 53, 54, 55, 56, 57, 58, 59, 61, 62, 63, 64, 65, 66, 67, 68, 69, 71, 72, 73, 74, 75, 76, 77, 78, 79, 81, 82, 83, 84, 85, 86, 87, 88, 89, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 111})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(d, n int, r []int) {
	x := gen(d, n)
	fmt.Println(x)
	assert(slices.Equal(x, r))
}

func gen(d, n int) []int {
	r := []int{}
	for i := 1; i <= n; i++ {
		s := fmt.Sprint(i)
		if count(s, d)&1 == 0 {
			r = append(r, i)
		}
	}
	return r
}

func count(s string, d int) int {
	c := 0
	for _, r := range s {
		if int(r-'0') == d {
			c++
		}
	}
	return c
}
