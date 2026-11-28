/*

Simple enough this one - you will be given an array. The values in the array will either be numbers or strings, or a mix of both. You will not get an empty array, nor a sparse one.

Your job is to return a single array that has first the numbers sorted in ascending order, followed by the strings sorted in alphabetic order. The values must maintain their original type.

Note that numbers written as strings are strings and must be sorted with the other strings.

*/

package main

import (
	"fmt"
	"sort"
)

func main() {
	fmt.Println(doublesort([]any{1, "a", 3, "b", 2, "z"}))
}

func doublesort(a []any) []any {
	sort.Slice(a, func(i, j int) bool {
		x := a[i]
		y := a[j]
		switch x := x.(type) {
		case int:
			switch y := y.(type) {
			case int:
				return x < y
			case string:
				return true
			}
		case string:
			switch y := y.(type) {
			case int:
				return false
			case string:
				return x < y
			}
		}
		panic("unsupported type")
	})
	return a
}
