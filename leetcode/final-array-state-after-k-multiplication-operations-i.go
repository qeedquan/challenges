/*

You are given an integer array nums, an integer k, and an integer multiplier.

You need to perform k operations on nums. In each operation:

Find the minimum value x in nums. If there are multiple occurrences of the minimum value, select the one that appears first.
Replace the selected minimum value x with x * multiplier.
Return an integer array denoting the final state of nums after performing all k operations.

Example 1:

Input: nums = [2,1,3,5,6], k = 5, multiplier = 2

Output: [8,4,6,5,6]

Explanation:

Operation	Result
After operation 1	[2, 2, 3, 5, 6]
After operation 2	[4, 2, 3, 5, 6]
After operation 3	[4, 4, 3, 5, 6]
After operation 4	[4, 4, 6, 5, 6]
After operation 5	[8, 4, 6, 5, 6]

Example 2:

Input: nums = [1,2], k = 3, multiplier = 4

Output: [16,8]

Explanation:

Operation	Result
After operation 1	[4, 2]
After operation 2	[4, 8]
After operation 3	[16, 8]

Constraints:
1 <= nums.length <= 100
1 <= nums[i] <= 100
1 <= k <= 10
1 <= multiplier <= 5


Hint 1
Maintain sorted pairs (nums[index], index) in a priority queue.

Hint 2
Simulate the operation k times.

*/

package main

import (
	"container/heap"
	"fmt"
	"reflect"
)

func main() {
	test(
		[]int{2, 1, 3, 5, 6}, 5, 2,
		[]int{8, 4, 6, 5, 6},
	)

	test(
		[]int{1, 2}, 3, 4,
		[]int{16, 8},
	)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a []int, k, m int, r []int) {
	p := finalstate(a, k, m)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func finalstate(a []int, k, m int) []int {
	var h minheap
	heap.Init(&h)
	for i, v := range a {
		heap.Push(&h, [2]int{i, v})
	}

	for range k {
		p := heap.Pop(&h)
		x := p.([2]int)
		x[1] *= m
		heap.Push(&h, x)
	}

	r := make([]int, len(a))
	for h.Len() > 0 {
		p := heap.Pop(&h)
		x := p.([2]int)
		r[x[0]] = x[1]
	}
	return r
}

type minheap [][2]int

func (h minheap) Len() int { return len(h) }
func (h minheap) Less(i, j int) bool {
	if h[i][1] == h[j][1] {
		return h[i][0] < h[j][0]
	}
	return h[i][1] < h[j][1]
}
func (h minheap) Swap(i, j int) { h[i], h[j] = h[j], h[i] }

func (h *minheap) Push(x interface{}) { *h = append(*h, x.([2]int)) }
func (h *minheap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}
