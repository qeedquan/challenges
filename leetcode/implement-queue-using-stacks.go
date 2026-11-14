/*

Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:

void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.
Notes:

You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.


Example 1:

Input
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 1, 1, false]

Explanation
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false


Constraints:

1 <= x <= 9
At most 100 calls will be made to push, pop, peek, and empty.
All the calls to pop and peek are valid.

Follow-up: Can you implement the queue such that each operation is amortized O(1) time complexity? In other words, performing n operations will take overall O(n) time even if one of those operations may take longer.

*/

package main

func main() {
	var q Queue
	q.Push(1)
	q.Push(2)
	assert(q.Peek() == 1)
	assert(q.Pop() == 1)
	assert(!q.Empty())
	assert(q.Peek() == 2)
	assert(q.Pop() == 2)
	assert(q.Empty())
	for i := 0; i < 100; i++ {
		q.Push(i)
		assert(q.Pop() == i)
	}
	assert(q.Empty())
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

type Queue struct {
	a, b []int
}

func (q *Queue) Push(x int) {
	q.a = append(q.a, x)
}

func (q *Queue) Pop() int {
	r := q.Peek()
	if nb := len(q.b); nb > 0 {
		q.b = q.b[:nb-1]
	}
	return r
}

func (q *Queue) Peek() int {
	if len(q.b) == 0 {
		for {
			na := len(q.a)
			if na == 0 {
				break
			}
			q.b = append(q.b, q.a[na-1])
			q.a = q.a[:na-1]
		}
	}

	r := 0
	if nb := len(q.b); nb > 0 {
		r = q.b[nb-1]
	}
	return r
}

func (q *Queue) Empty() bool {
	return len(q.a) == 0 && len(q.b) == 0
}
