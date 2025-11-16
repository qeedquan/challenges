/*

Task
Some people are standing in a row in a park. There are trees between them which cannot be moved.

Your task is to rearrange the people by their heights in a non-descending order without moving the trees.

Example
For a = [-1, 150, 190, 170, -1, -1, 160, 180], the output should be

[-1, 150, 160, 170, -1, -1, 180, 190].

Input/Output
[input] integer array a

If a[i] = -1, then the ith position is occupied by a tree. Otherwise a[i] is the height of a person standing in the ith position.

Constraints:

5 ≤ a.length ≤ 30,

-1 ≤ a[i] ≤ 200.

[output] an integer array

Sorted array a with all the trees untouched.

*/

package main

import (
	"reflect"
	"sort"
)

func main() {
	test([]int{-1, 150, 190, 170, -1, -1, 160, 180}, []int{-1, 150, 160, 170, -1, -1, 180, 190})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a, r []int) {
	sortheight(a)
	assert(reflect.DeepEqual(a, r))
}

func sortheight(a []int) []int {
	p := newindexslice(a)
	sort.Sort(p)
	return a
}

type indexslice struct {
	i []int
	a []int
}

func newindexslice(a []int) *indexslice {
	p := &indexslice{a: a}
	for i := range a {
		if a[i] != -1 {
			p.i = append(p.i, i)
		}
	}
	return p
}

func (p *indexslice) Len() int {
	return len(p.i)
}

func (p *indexslice) Swap(i, j int) {
	i = p.i[i]
	j = p.i[j]
	p.a[i], p.a[j] = p.a[j], p.a[i]
}

func (p *indexslice) Less(i, j int) bool {
	i = p.i[i]
	j = p.i[j]
	return p.a[i] < p.a[j]
}
