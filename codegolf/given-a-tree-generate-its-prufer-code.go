/*

In graph-theory a Prüfer code is a unique sequence of integers that denotes a specific tree.

You can find the Prüfer code of a tree with the following algorithm taken from Wikipedia:

Consider a labeled tree T with vertices {1, 2, ..., n}. At step i, remove the leaf with the smallest label and set the ith element of the Prüfer sequence to be the label of this leaf's neighbor.

(Note that since it's a leaf it will only have one neighbor).

You should stop the iteration when only two vertices remain in the graph.

Task
Given a labeled tree as input output its Prüfer code. You may take input in any reasonable manner. Such as an adjacency matrix or your languages builtin graph representation. (You may not take input as a Prüfer code).

This is code-golf so you should aim to minimize the bytes in your source.

Test cases
Here are some inputs in ASCII with their outputs below. You do not need to support ASCII input like this.

    3
    |
1---2---4---6
    |
    5

{2,2,2,4}
1---4---3
    |
5---2---6---7
|
8

{4,4,2,6,2,5}
5---1---4   6
    |       |
    2---7---3

{1,1,2,7,3}

*/

package main

import (
	"container/heap"
	"fmt"
	"reflect"
)

func main() {
	test(6, [][2]int{
		{1, 2},
		{3, 2},
		{2, 5},
		{2, 4},
		{4, 6},
	}, []int{2, 2, 2, 4})

	test(8, [][2]int{
		{1, 4},
		{4, 3},
		{4, 2},
		{2, 5},
		{2, 6},
		{5, 8},
		{6, 7},
	}, []int{4, 4, 2, 6, 2, 5})

	test(7, [][2]int{
		{5, 1},
		{1, 4},
		{1, 2},
		{2, 7},
		{7, 3},
		{3, 6},
	}, []int{1, 1, 2, 7, 3})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(n int, e [][2]int, r []int) {
	p := tree2prufer(n, e)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

// https://forthright48.com/prufer-code-linear-representation-of-a-labeled-tree/
func tree2prufer(n int, e [][2]int) []int {
	m := make(map[int][]int, n)
	for _, e := range e {
		u, v := e[0], e[1]
		m[u] = append(m[u], v)
		m[v] = append(m[v], u)
	}

	h := new(IntHeap)
	for i := 1; i <= n; i++ {
		if len(m[i]) == 1 {
			*h = append(*h, i)
		}
	}
	heap.Init(h)

	r := []int{}
	for i := n; i > 2; i-- {
		x := heap.Pop(h).(int)
		y := m[x][0]
		r = append(r, y)

		m[y] = remove(m[y], x)
		if len(m[y]) == 1 {
			heap.Push(h, y)
		}
	}

	return r
}

func remove(a []int, v int) []int {
	n := len(a)
	for i := range a {
		if a[i] == v {
			a[i], a[n-1] = a[n-1], a[i]
		}
	}
	return a[:n-1]
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
