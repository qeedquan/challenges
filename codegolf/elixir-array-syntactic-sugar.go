/*

In Elixir, (linked) lists are in the format [head | tail] where head can be anything and tail is a list of the rest of the list, and [] - the empty list - is the only exception to this.

Lists can also be written like [1, 2, 3] which is equivalent to [1 | [2 | [3 | []]]]

Your task is to convert a list as described. The input will always be a valid list (in Elixir) containing only numbers matching the regex \[(\d+(, ?\d+)*)?\]. You may take the input with (one space after each comma) or without spaces. The output may be with (one space before and after each |) or without spaces.

For inputs with leading zeroes you may output either without the zeroes or with.

Input must be taken as a string (if writing a function), as does output.

Examples
[] -> []
[5] -> [5 | []]
[1, 7] -> [1 | [7 | []]]
[4, 4, 4] -> [4 | [4 | [4 | []]]]
[10, 333] -> [10 | [333 | []]]
related, not a duplicate as this in part involves adding mode ] to the end. Additionally, the Haskell answer here is quite different to the one there.

*/

package main

import "fmt"

func main() {
	assert(elixir([]int{}) == "[]")
	assert(elixir([]int{5}) == "[5 | []]")
	assert(elixir([]int{1, 7}) == "[1 | [7 | []]]")
	assert(elixir([]int{4, 4, 4}) == "[4 | [4 | [4 | []]]]")
	assert(elixir([]int{10, 333}) == "[10 | [333 | []]]")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func elixir(a []int) string {
	if len(a) == 0 {
		return "[]"
	}
	return fmt.Sprintf("[%v | %v]", a[0], elixir(a[1:]))
}
