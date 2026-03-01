/*

Given the head of a linked list, rotate the list to the right by k places.

Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]

Example 2:
Input: head = [0,1,2], k = 4
Output: [2,0,1]


Constraints:

The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 10^9

*/

package main

import "fmt"

func main() {
	show(rotate(mklist(1, 2, 3, 4, 5), 2))
	show(rotate(mklist(0, 1, 2), 4))
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

func rotate[T Elem](h *Node[T], k int) *Node[T] {
	if h == nil || k < 1 {
		return h
	}

	n := 1
	p := h
	for ; p.next != nil; n++ {
		p = p.next
	}
	p.next = h

	for range n - (k % n) {
		p = p.next
	}

	h = p.next
	p.next = nil
	return h
}
