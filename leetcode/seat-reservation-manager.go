/*

Design a system that manages the reservation state of n seats that are numbered from 1 to n.

Implement the SeatManager class:

SeatManager(int n) Initializes a SeatManager object that will manage n seats numbered from 1 to n. All seats are initially available.
int reserve() Fetches the smallest-numbered unreserved seat, reserves it, and returns its number.
void unreserve(int seatNumber) Unreserves the seat with the given seatNumber.


Example 1:

Input
["SeatManager", "reserve", "reserve", "unreserve", "reserve", "reserve", "reserve", "reserve", "unreserve"]
[[5], [], [], [2], [], [], [], [], [5]]
Output
[null, 1, 2, null, 2, 3, 4, 5, null]

Explanation
SeatManager seatManager = new SeatManager(5); // Initializes a SeatManager with 5 seats.
seatManager.reserve();    // All seats are available, so return the lowest numbered seat, which is 1.
seatManager.reserve();    // The available seats are [2,3,4,5], so return the lowest of them, which is 2.
seatManager.unreserve(2); // Unreserve seat 2, so now the available seats are [2,3,4,5].
seatManager.reserve();    // The available seats are [2,3,4,5], so return the lowest of them, which is 2.
seatManager.reserve();    // The available seats are [3,4,5], so return the lowest of them, which is 3.
seatManager.reserve();    // The available seats are [4,5], so return the lowest of them, which is 4.
seatManager.reserve();    // The only available seat is seat 5, so return 5.
seatManager.unreserve(5); // Unreserve seat 5, so now the available seats are [5].


Constraints:

1 <= n <= 10^5
1 <= seatNumber <= n
For each call to reserve, it is guaranteed that there will be at least one unreserved seat.
For each call to unreserve, it is guaranteed that seatNumber will be reserved.
At most 10^5 calls in total will be made to reserve and unreserve.

Hint 1
You need a data structure that maintains the states of the seats.
This data structure should also allow you to get the first available seat and flip the state of a seat in a reasonable time.

Hint 2
You can let the data structure contain the available seats. Then you want to be able to get the lowest element and erase an element, in a reasonable time.

Hint 3
Ordered sets support these operations.

*/

package main

import "container/heap"

func main() {
	seatManager := NewSeatManager(5)
	assert(seatManager.Reserve() == 1)
	assert(seatManager.Reserve() == 2)
	seatManager.Unreserve(2)
	assert(seatManager.Reserve() == 2)
	assert(seatManager.Reserve() == 3)
	assert(seatManager.Reserve() == 4)
	assert(seatManager.Reserve() == 5)
	seatManager.Unreserve(5)
	assert(seatManager.Reserve() == 5)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

type SeatManager struct {
	idle IntHeap
}

func NewSeatManager(n int) *SeatManager {
	s := &SeatManager{}
	heap.Init(&s.idle)
	for i := 1; i <= n; i++ {
		heap.Push(&s.idle, i)
	}
	return s
}

func (s *SeatManager) Reserve() int {
	i := heap.Pop(&s.idle)
	return i.(int)
}

func (s *SeatManager) Unreserve(n int) {
	heap.Push(&s.idle, n)
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
