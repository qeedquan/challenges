/*

Design your implementation of the circular double-ended queue (deque).

Implement the MyCircularDeque class:

    MyCircularDeque(int k) Initializes the deque with a maximum size of k.
    boolean insertFront() Adds an item at the front of Deque. Returns true if the operation is successful, or false otherwise.
    boolean insertLast() Adds an item at the rear of Deque. Returns true if the operation is successful, or false otherwise.
    boolean deleteFront() Deletes an item from the front of Deque. Returns true if the operation is successful, or false otherwise.
    boolean deleteLast() Deletes an item from the rear of Deque. Returns true if the operation is successful, or false otherwise.
    int getFront() Returns the front item from the Deque. Returns -1 if the deque is empty.
    int getRear() Returns the last item from Deque. Returns -1 if the deque is empty.
    boolean isEmpty() Returns true if the deque is empty, or false otherwise.
    boolean isFull() Returns true if the deque is full, or false otherwise.

Example 1:

Input
["MyCircularDeque", "insertLast", "insertLast", "insertFront", "insertFront", "getRear", "isFull", "deleteLast", "insertFront", "getFront"]
[[3], [1], [2], [3], [4], [], [], [], [4], []]
Output
[null, true, true, true, false, 2, true, true, true, 4]

Explanation
MyCircularDeque myCircularDeque = new MyCircularDeque(3);
myCircularDeque.insertLast(1);  // return True
myCircularDeque.insertLast(2);  // return True
myCircularDeque.insertFront(3); // return True
myCircularDeque.insertFront(4); // return False, the queue is full.
myCircularDeque.getRear();      // return 2
myCircularDeque.isFull();       // return True
myCircularDeque.deleteLast();   // return True
myCircularDeque.insertFront(4); // return True
myCircularDeque.getFront();     // return 4

Constraints:

    1 <= k <= 1000
    0 <= value <= 1000
    At most 2000 calls will be made to insertFront, insertLast, deleteFront, deleteLast, getFront, getRear, isEmpty, isFull.

*/

package main

func main() {
	q := NewCircularDeque(3)
	assert(q.InsertLast(1) == true)
	assert(q.InsertLast(2) == true)
	assert(q.InsertFront(3) == true)
	assert(q.InsertFront(4) == false)
	assert(q.GetRear() == 2)
	assert(q.IsFull() == true)
	assert(q.DeleteLast() == true)
	assert(q.InsertFront(4) == true)
	assert(q.GetFront() == 4)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

type CircularDeque struct {
	start int
	size  int
	data  []int
}

func NewCircularDeque(size int) *CircularDeque {
	return &CircularDeque{
		data: make([]int, size),
	}
}

func (c *CircularDeque) InsertFront(value int) bool {
	if c.IsFull() {
		return false
	}
	c.start = (c.start - 1 + len(c.data)) % len(c.data)
	c.data[c.start] = value
	c.size += 1
	return true
}

func (c *CircularDeque) InsertLast(value int) bool {
	if c.IsFull() {
		return false
	}
	c.data[(c.start+c.size)%len(c.data)] = value
	c.size += 1
	return true
}

func (c *CircularDeque) DeleteFront() bool {
	if c.IsEmpty() {
		return false
	}
	c.start = (c.start + 1) % len(c.data)
	c.size -= 1
	return true
}

func (c *CircularDeque) DeleteLast() bool {
	if c.IsEmpty() {
		return false
	}
	c.size -= 1
	return true
}

func (c *CircularDeque) GetFront() int {
	if c.IsEmpty() {
		return -1
	}
	return c.data[c.start]
}

func (c *CircularDeque) GetRear() int {
	if c.IsEmpty() {
		return -1
	}
	return c.data[(c.start+c.size-1)%len(c.data)]
}

func (c *CircularDeque) IsEmpty() bool {
	return c.size == 0
}

func (c *CircularDeque) IsFull() bool {
	return c.size == len(c.data)
}
