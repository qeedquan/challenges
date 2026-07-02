/*

You are given an array of integers stones where stones[i] is the weight of the ith stone.

We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together. Suppose the heaviest two stones have weights x and y with x <= y. The result of this smash is:

    If x == y, both stones are destroyed, and
    If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.

At the end of the game, there is at most one stone left.

Return the weight of the last remaining stone. If there are no stones left, return 0.

Example 1:

Input: stones = [2,7,4,1,8,1]
Output: 1
Explanation:
We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of the last stone.

Example 2:

Input: stones = [1]
Output: 1

Constraints:

    1 <= stones.length <= 30
    1 <= stones[i] <= 1000

*/

package main

import (
	"container/heap"
)

func main() {
	assert(lsw([]int{2, 7, 4, 1, 8, 1}) == 1)
	assert(lsw([]int{1}) == 1)
	assert(lsw([]int{32, 32}) == 0)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func lsw(a []int) int {
	p := append(Int{}, a...)
	h := &p

	heap.Init(h)
	for h.Len() > 1 {
		y := heap.Pop(h).(int)
		x := heap.Pop(h).(int)
		if y > x {
			heap.Push(h, y-x)
		}
	}

	r := 0
	if h.Len() > 0 {
		r = heap.Pop(h).(int)
	}

	return r
}

type Int []int

func (h Int) Len() int           { return len(h) }
func (h Int) Less(i, j int) bool { return h[i] > h[j] }
func (h Int) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *Int) Push(x any) {
	*h = append(*h, x.(int))
}

func (h *Int) Pop() any {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}
