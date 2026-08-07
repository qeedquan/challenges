/*

Rules
You will receive as input a list that contains integers and strings. Your task is to move all of the strings to the end of the list and all of the integers to the beginning of the list.

This is code-golf so the answer with the least number of bytes wins.

*/

package main

import (
	"fmt"
	"sort"
)

func main() {
	fmt.Println(sortis([]any{"a", "b", "c", 1, 2, 3}))
	fmt.Println(sortis([]any{"a", "b", "c", 1, 2, 300, "d", "e", "f", 20, 30, 40}))
}

func sortis(a []any) []any {
	sort.SliceStable(a, func(i, j int) bool {
		k0, i0, s0 := get(a[i])
		k1, i1, s1 := get(a[j])
		switch {
		case k0 == 'i' && k1 == 'i':
			return i0 < i1
		case k0 == 's' && k1 == 's':
			return s0 < s1
		case k0 == 'i' && k1 == 's':
			return true
		}
		return false
	})
	return a
}

func get(x any) (rune, int, string) {
	i, ok := x.(int)
	if ok {
		return 'i', i, ""
	}

	s, ok := x.(string)
	if ok {
		return 's', 0, s
	}

	return 'u', 0, ""
}
