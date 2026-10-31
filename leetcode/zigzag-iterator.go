/*

Given two 1d vectors, implement an iterator to return their elements alternately.

Example:

Input:
v1 = [1,2]
v2 = [3,4,5,6]


Output: [1,3,2,4,5,6]


Explanation: By calling  next repeatedly until hasNext returns false, the order of elements returned by next
should be: [1,3,2,4,5,6].
Follow up: What if you are givenk1d vectors? How well can your code be extended to such cases?

Clarificationfor the follow up question:
The "Zigzag" order is not clearly defined and is ambiguous fork > 2cases. If "Zigzag" does not look right to you, replace "Zigzag" with "Cyclic". For example:

Input:

[1,2,3]
[4,5,6,7]
[8,9]


Output: [1,4,8,2,5,9,3,6,7].

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test([][]int{{1, 2}, {3, 4, 5, 6}}, []int{1, 3, 2, 4, 5, 6})
	test([][]int{{1, 2, 3}, {4, 5, 6, 7}, {8, 9}}, []int{1, 4, 8, 2, 5, 9, 3, 6, 7})
}

func test(vals [][]int, res []int) {
	var (
		z   Zigzag
		out []int
	)

	z.Init(vals)
	for z.HasNext() {
		out = append(out, z.Next())
	}
	fmt.Println(out)
	assert(reflect.DeepEqual(out, res))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

type Zigzag struct {
	vals [][]int
	idx  []int
	cur  int
}

func (z *Zigzag) Init(vals [][]int) {
	z.vals = vals
	z.idx = make([]int, len(vals))
	z.cur = 0
}

func (z *Zigzag) Next() int {
	if !z.HasNext() {
		return 0
	}

	for {
		i := z.idx[z.cur]
		v := z.vals[z.cur]
		if i < len(v) {
			z.idx[z.cur]++
			z.cur = (z.cur + 1) % len(z.idx)
			return v[i]
		}
		z.cur = (z.cur + 1) % len(z.idx)
	}
}

func (z *Zigzag) HasNext() bool {
	for i, p := range z.idx {
		if p < len(z.vals[i]) {
			return true
		}
	}
	return false
}
