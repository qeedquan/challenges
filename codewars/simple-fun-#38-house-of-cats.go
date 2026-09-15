/*

Task
There are some people and cats in a house. You are given the number of legs they have all together. Your task is to return an array containing every possible number of people that could be in the house sorted in ascending order. It's guaranteed that each person has 2 legs and each cat has 4 legs.

Example
For legs = 6, the output should be [1, 3].

There could be either 1 cat and 1 person (4 + 2 = 6) or 3 people (2 * 3 = 6).

For legs = 2, the output should be [1].

There can be only 1 person.

Input/Output
[input] integer legs

The total number of legs in the house.

Constraints: 2 ≤ legs ≤ 100.

[output] an integer array

Every possible number of people that can be in the house.

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test(6, []int{1, 3})
	test(2, []int{1})
	test(8, []int{0, 2, 4})
	test(4, []int{0, 2})
	test(44, []int{0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(l int, r []int) {
	p := cats(l)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func cats(l int) []int {
	r := []int{}
	for i := range l/2 + 1 {
		if (l-i*2)%4 == 0 {
			r = append(r, i)
		}
	}
	return r
}
