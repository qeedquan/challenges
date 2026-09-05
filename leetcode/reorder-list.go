/*

You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

Example 1:
Input: head = [1,2,3,4]
Output: [1,4,2,3]

Example 2:
Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]


Constraints:

The number of nodes in the list is in the range [1, 5 * 10^4].
1 <= Node.val <= 1000

*/

package main

import "fmt"

func main() {
	show(reorder(mklist(1, 2, 3, 4)))
	show(reorder(mklist(1, 2, 3, 4, 5)))
	show(reorder(mklist(22)))
	show(reorder(mklist(22, 53)))
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
		fmt.Print(p.value, " ")
	}
	fmt.Println()
}

func reorder[T Elem](h *Node[T]) *Node[T] {
	m := middle(h)
	m = reverse(m)
	merge(h, m)
	return h
}

func middle[T Elem](h *Node[T]) *Node[T] {
	var (
		p0 *Node[T]
		p1 = h
		p2 = h
	)
	for p1 != nil && p2 != nil && p2.next != nil {
		p0 = p1
		p1 = p1.next
		p2 = p2.next.next
	}
	if p0 != nil {
		p0.next = nil
	}
	return p1
}

func reverse[T Elem](h *Node[T]) *Node[T] {
	var l *Node[T]
	for h != nil {
		p := h
		h = h.next
		p.next = l
		l = p
	}
	return l
}

func merge[T Elem](h1, h2 *Node[T]) {
	p1 := h1
	p2 := h2
	for p1 != nil && p2 != nil {
		p1nxt := p1.next
		p2nxt := p2.next

		p1.next = p2
		p2.next = p1nxt

		if p1nxt == nil {
			p2.next = p2nxt
			break
		}
		p1 = p1nxt
		p2 = p2nxt
	}
}
