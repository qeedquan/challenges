/*

Given an array of integers. Rearrange its elements to form a max-heap.

Input
The first line contains the number of elements in the array n (n≤1000).

The second line contains n integers, each with an absolute value not exceeding 10^6.

Output
Print the rearranged array representing a max-heap. If there are multiple solutions, print any one of them.

https://static.e-olymp.com/content/94/94b59391780652167dd211f1a56ef2f14d2f7ffd.gif

Examples

Input #1
6
5 3 2 7 1 10

Answer #1
10 7 5 3 1 2

*/

package main

import (
	"container/heap"
	"fmt"
	"reflect"
)

func main() {
	test([]int{5, 3, 2, 7, 1, 10}, []int{10, 7, 5, 3, 1, 2})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(x, r []int) {
	p := solve(x)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func solve(x []int) []int {
	h := IntHeap(x)
	heap.Init(&h)
	return h
}

type IntHeap []int

func (h IntHeap) Len() int           { return len(h) }
func (h IntHeap) Less(i, j int) bool { return h[i] > h[j] }
func (h IntHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *IntHeap) Push(x any) {
	*h = append(*h, x.(int))
}

func (h *IntHeap) Pop() any {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}
