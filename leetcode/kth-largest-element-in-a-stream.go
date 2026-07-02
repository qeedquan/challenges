/*

Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Implement KthLargest class:

KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of integers nums.
int add(int val) Appends the integer val to the stream and returns the element representing the kth largest element in the stream.


Example 1:

Input
["KthLargest", "add", "add", "add", "add", "add"]
[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
Output
[null, 4, 5, 5, 8, 8]

Explanation
KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
kthLargest.add(3);   // return 4
kthLargest.add(5);   // return 5
kthLargest.add(10);  // return 5
kthLargest.add(9);   // return 8
kthLargest.add(4);   // return 8


Constraints:

1 <= k <= 10^4
0 <= nums.length <= 10^4
-10^4 <= nums[i] <= 10^4
-10^4 <= val <= 10^4
At most 10^4 calls will be made to add.
It is guaranteed that there will be at least k elements in the array when you search for the kth element.

*/

package main

import (
	"container/heap"
	"sort"
)

func main() {
	z := NewKthLargest(3, []int{4, 5, 8, 2})
	assert(z.Add(3) == 4)
	assert(z.Add(5) == 5)
	assert(z.Add(10) == 5)
	assert(z.Add(9) == 8)
	assert(z.Add(4) == 8)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

type KthLargest struct {
	k      int
	stream IntHeap
}

func NewKthLargest(k int, nums []int) *KthLargest {
	z := &KthLargest{
		k:      k,
		stream: IntHeap{},
	}

	sort.Slice(nums, func(i, j int) bool {
		return nums[i] > nums[j]
	})

	heap.Init(&z.stream)
	for _, v := range nums[:k] {
		heap.Push(&z.stream, v)
	}

	return z
}

func (z *KthLargest) Add(val int) int {
	if len(z.stream) < z.k {
		heap.Push(&z.stream, val)
	} else if z.stream[0] <= val {
		heap.Pop(&z.stream)
		heap.Push(&z.stream, val)
	}
	return z.stream[0]
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
