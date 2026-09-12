/*

Given a singly linked list, return a random node's value from the linked list. Each node must have the same probability of being chosen.

Implement the Solution class:

Solution(ListNode head) Initializes the object with the head of the singly-linked list head.
int getRandom() Chooses a node randomly from the list and returns its value. All the nodes of the list should be equally likely to be chosen.

Example 1:

Input
["Solution", "getRandom", "getRandom", "getRandom", "getRandom", "getRandom"]
[[[1, 2, 3]], [], [], [], [], []]
Output
[null, 1, 3, 2, 2, 3]

Explanation
Solution solution = new Solution([1, 2, 3]);
solution.getRandom(); // return 1
solution.getRandom(); // return 3
solution.getRandom(); // return 2
solution.getRandom(); // return 2
solution.getRandom(); // return 3
// getRandom() should return either 1, 2, or 3 randomly. Each element should have equal probability of returning.


Constraints:

The number of nodes in the linked list will be in the range [1, 10^4].
-10^4 <= Node.val <= 10^4
At most 10^4 calls will be made to getRandom.


Follow up:

What if the linked list is extremely large and its length is unknown to you?
Could you solve this efficiently without using extra space?

*/

package main

import (
	"fmt"
	"math/rand"
)

func main() {
	l := mklist(1, 2, 3, 4, 5, 6, 7, 8, 9, 10)
	for range 10 {
		fmt.Println(random(l))
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

type List[T Elem] struct {
	head   *Node[T]
	length int
}

type Elem interface{ int }

type Node[T Elem] struct {
	value T
	next  *Node[T]
}

func mklist[T Elem](x ...T) *List[T] {
	var h, t *Node[T]
	for _, v := range x {
		n := &Node[T]{value: v}
		if h == nil {
			h, t = n, n
		} else {
			t.next, t = n, n
		}
	}
	return &List[T]{
		head:   h,
		length: len(x),
	}
}

func random[T Elem](l *List[T]) T {
	if l.length < 1 {
		return 0
	}

	p := l.head
	n := rand.Intn(l.length)
	for ; n > 0; n-- {
		p = p.next
	}
	return p.value
}
