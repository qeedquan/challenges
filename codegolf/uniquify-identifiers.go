/*

Introduction
By definition, unique identifiers should be unique. Having multiple identifiers that are the same causes one to retrieve unexpected data. But with data arriving concurrently from multiple sources, it can be difficult to ensure uniqueness. Write a function the uniquifies a list of identifiers.

This is possibly the worst puzzle fluff I have written, but you get the idea.

Requirements
Given a list of zero or more positive integers, apply the following rules to each number from first to last:

If the number is the first of its kind, keep it.
If the number has previously been encountered, replace it with the lowest positive integer not found anywhere in the entire input list or any existing output.
For the solution:

The solution may be a program or a function.
The input may be a string, an array, passed as arguments, or keyboard input.
The output may be a string, an array, or printed to the screen.
All numbers in the output list are distinct.
Assumptions
The input list is clean. It only contains positive integers.
A positive integer has the range from 1 to 231-1.
Less than 256 MB of memory is available for your program's variables. (Basically, no 2,147,483,648-element arrays are permitted.)
Test Cases
Input:  empty
Output: empty

Input:  5
Output: 5

Input:  1, 4, 2, 5, 3, 6
Output: 1, 4, 2, 5, 3, 6

Input:  3, 3, 3, 3, 3, 3
Output: 3, 1, 2, 4, 5, 6

Input:  6, 6, 4, 4, 2, 2
Output: 6, 1, 4, 3, 2, 5

Input:  2147483647, 2, 2147483647, 2
Output: 2147483647, 2, 1, 3

Scoring
Just a simple code golf. Lowest byte count by this time next week wins.

*/

package main

import (
	"fmt"
	"math"
	"reflect"
)

func main() {
	test([]int{}, []int{})
	test([]int{5}, []int{5})
	test([]int{1, 4, 2, 5, 3, 6}, []int{1, 4, 2, 5, 3, 6})
	test([]int{3, 3, 3, 3, 3, 3}, []int{3, 1, 2, 4, 5, 6})
	test([]int{6, 6, 4, 4, 2, 2}, []int{6, 1, 4, 3, 2, 5})
	test([]int{2147483647, 2, 2147483647, 2}, []int{2147483647, 2, 1, 3})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a, r []int) {
	p := uniquify(a)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func uniquify(a []int) []int {
	r := make([]int, len(a))
	m := make(map[int]bool)
	p := []int{}
	for i, v := range a {
		if !m[v] {
			r[i], m[v] = v, true
		} else {
			p = append(p, i)
		}
	}

	x := 1
	for _, i := range p {
		for m[x] && x < math.MaxInt {
			x++
		}
		r[i], m[x] = x, true
	}

	return r
}
