/*

Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.

Example 1:
Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]

Example 2:
Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]

Constraints:

The number of nodes in the linked list is in the range [0, 10^4].
-10^6 <= Node.val <= 10^6

*/

package main

import "fmt"

func main() {
	show(oddeven(mklist(1, 2, 3, 4, 5)))
	show(oddeven(mklist(2, 1, 3, 5, 6, 4, 7)))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

type Elem interface{ int }

type Node[T Elem] struct {
	value T
	next  *Node[T]
}

func mklist[T Elem](x ...T) *Node[T] {
	var h, t *Node[T]
	for _, v := range x {
		n := &Node[T]{value: v}
		if h == nil {
			h, t = n, n
		} else {
			t.next, t = n, n
		}
	}
	return h
}

func show[T Elem](h *Node[T]) {
	for p := h; p != nil; p = p.next {
		fmt.Printf("%v ", p.value)
	}
	fmt.Println()
}

func oddeven[T Elem](h *Node[T]) *Node[T] {
	if h == nil {
		return h
	}

	var (
		p1 = h
		p2 = h.next
		p3 *Node[T]
	)
	for p2 != nil && p2.next != nil {
		p3 = p2.next
		p2.next = p3.next
		p3.next = p1.next
		p1.next = p3

		p2 = p2.next
		p1 = p1.next
	}

	return h
}
