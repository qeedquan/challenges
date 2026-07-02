/*

Create a combinator function named flip that takes a function as an argument and returns that function with it's arguments reversed.

For example:

flip(print)(4,5) // returns "5 -> 4"

function print(a,b) {
  return a + " -> " + b;
}

The idea is to reverse any number of arguments using a higher order function, without any concern for the function being passed into it.

*/

package main

import (
	"fmt"
	"slices"
)

type fn func(...int) string

func main() {
	f := flip(print)
	fmt.Println(f(4, 5))
}

func print(x ...int) string {
	if len(x) < 2 {
		return ""
	}
	return fmt.Sprintf("%d -> %d", x[0], x[1])
}

func flip(f fn) fn {
	return func(x ...int) string {
		slices.Reverse(x[:])
		return f(x...)
	}
}
