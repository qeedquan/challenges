/*

Some but not all

Description
Your task is to create a function that given a sequence and a predicate, returns True if only some (but not all) the elements in the sequence are True after applying the predicate

Examples
('abcdefg&%$', x -> isLetter(x)) == true
('&%$=', x -> isLetter x) == false
('abcdefg', x -> isLetter x) == false

([4, 1], x -> x > 3) == true
([1, 1], x -> x > 3) == false
([4, 4], x -> x > 3) == false

*/

package main

import (
	"unicode"
)

func main() {
	assert(somenotall([]rune("abcdefg&%$"), isletter) == true)
	assert(somenotall([]rune("&%$="), isletter) == false)
	assert(somenotall([]rune("abcdefg"), isletter) == false)

	assert(somenotall([]int{4, 1}, isgt3) == true)
	assert(somenotall([]int{1, 1}, isgt3) == false)
	assert(somenotall([]int{4, 4}, isgt3) == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func somenotall[T any](x []T, f func(T) bool) bool {
	c := 0
	for i := range x {
		if f(x[i]) {
			c += 1
		}
	}
	return c > 0 && c != len(x)
}

func isletter(r rune) bool {
	r = unicode.ToLower(r)
	return 'a' <= r && r <= 'z'
}

func isgt3(x int) bool {
	return x > 3
}
