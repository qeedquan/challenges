/*

You have some sticks with positive integer lengths.

You can connect any two sticks of lengths X and Y into one stick by paying a cost of X + Y.  You perform this action until there is one stick remaining.

Return the minimum cost of connecting all the given sticks into one stick in this way.

Example 1:

Input: sticks = [2,4,3]
Output: 14

Example 2:

Input: sticks = [1,8,3,5]
Output: 30

Constraints:

1 <= sticks.length <= 10^4
1 <= sticks[i] <= 10^4

*/

package main

import "container/heap"

func main() {
	assert(connectsticks([]int{2, 4, 3}) == 14)
	assert(connectsticks([]int{1, 8, 3, 5}) == 30)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func connectsticks(sticks []int) int {
	minheap := new(IntHeap)
	for _, stick := range sticks {
		heap.Push(minheap, stick)
	}

	result := 0
	for minheap.Len() > 1 {
		x := heap.Pop(minheap).(int)
		y := heap.Pop(minheap).(int)
		result += x + y
		heap.Push(minheap, x+y)
	}
	return result
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
