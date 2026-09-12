/*

Linked Lists - Recursive Reverse

Write a Recursive Reverse() function that recursively reverses a linked list. You may want to use a nested function for the recursive calls.

var list = 2 -> 1 -> 3 -> 6 -> 5 -> null
reverse(list) === 5 -> 6 -> 3 -> 1 -> 2 -> null

*/

package main

import "fmt"

func main() {
	list1 := mklist(1, 2, 2, 3, 3, 6)
	list2 := mklist(1, 3, 4, 5, 6)
	list3 := mklist(2, 1, 3, 6, 5)
	list4 := mklist(10)
	list5 := mklist(33, 44)
	show(reverse(list1))
	show(reverse(list2))
	show(reverse(list3))
	show(reverse(list4))
	show(reverse(list5))
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

func show[T Elem](n *Node[T]) {
	for ; n != nil; n = n.next {
		fmt.Printf("%v ", n.value)
	}
	fmt.Println()
}

func reverse[T Elem](l *Node[T]) *Node[T] {
	if l == nil || l.next == nil {
		return l
	}

	p := reverse(l.next)
	l.next.next = l
	l.next = nil
	return p
}
