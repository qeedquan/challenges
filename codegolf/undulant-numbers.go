/*

An undulant number is a number where its digits alternate between up and down like the following number: 461902 or 708143, or even 1010101, but not 123, because 2 < 3.

Write a program or function which returns a truthy value if a number is undulant, and a falsy value otherwise. The shortest code wins.

Note: Single digit numbers are a valid input but are not considered udulant, thus isUndulant returns false for n < 10.

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	tab := []int{10, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 101, 102, 103, 104, 105, 106, 107, 108, 109, 120, 121, 130, 131, 132, 140, 141, 142, 143, 150}

	assert(undulant(461902) == true)
	assert(undulant(708143) == true)
	assert(undulant(1010101) == true)
	assert(undulant(123) == false)

	assert(reflect.DeepEqual(gen(len(tab)), tab))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func gen(n int) []int {
	r := []int{}
	for i := 10; len(r) < n; i++ {
		if undulant(i) {
			r = append(r, i)
		}
	}
	return r
}

// https://oeis.org/A355301
func undulant(n int) bool {
	if n < 10 {
		return false
	}

	s := fmt.Sprint(n)
	t := cmp(s[0], s[1])
	for i := 1; i < len(s); i++ {
		if t == 0 || cmp(s[i], s[i-1]) != -t {
			return false
		}
		t = -t
	}
	return true
}

func cmp(a, b byte) int {
	if a < b {
		return -1
	}
	if a == b {
		return 0
	}
	return 1
}
