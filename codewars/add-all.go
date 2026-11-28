/*

Yup!! The problem name reflects your task; just add a set of numbers. But you may feel yourselves condescended, to write a program just to add a set of numbers. Such a problem will simply question your erudition. So, let's add some flavor of ingenuity to it. Addition operation requires cost now, and the cost is the summation of those two to be added. So, to add 1 and 10, you need a cost of 11. If you want to add 1, 2 and 3, there are several ways:

1 + 2 = 3, cost = 3,
3 + 3 = 6, cost = 6,
Total = 9.
1 + 3 = 4, cost = 4,
2 + 4 = 6, cost = 6,
Total = 10.
2 + 3 = 5, cost = 5,
1 + 5 = 6, cost = 6,
Total = 11.

I hope you have understood already your mission: to add a set of integers so that the cost is minimal.

Your Task
Given a vector of integers, return the minimum total cost of addition.

*/

package main

import (
	"container/heap"
)

func main() {
	assert(addall([]int{1, 2, 3}) == 9)
	assert(addall([]int{1, 2, 3, 4}) == 19)
	assert(addall([]int{1, 2, 3, 4, 5}) == 33)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func addall(x []int) int {
	r := 0
	h := IntHeap(x)
	heap.Init(&h)
	for h.Len() > 1 {
		x := heap.Pop(&h).(int)
		y := heap.Pop(&h).(int)
		r += x + y
		heap.Push(&h, x+y)
	}
	return r
}

type IntHeap []int

func (h IntHeap) Len() int           { return len(h) }
func (h IntHeap) Less(i, j int) bool { return h[i] < h[j] }
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
