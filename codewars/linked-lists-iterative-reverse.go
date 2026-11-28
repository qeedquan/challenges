/*

Linked Lists - Iterative Reverse

Write an iterative Reverse() function that reverses a linked list. Ideally, Reverse() should only need to make one pass of the list.

var list = 2 -> 1 -> 3 -> 6 -> 5 -> null
reverse(list)
list === 5 -> 6 -> 3 -> 1 -> 2 -> null

The push() and buildOneTwoThree() functions need not be redefined.

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
	if l == nil {
		return l
	}

	var p *Node[T]
	n := l.next
	for {
		l.next = p
		p = l
		l = n
		if n != nil {
			n = n.next
		}
		if l == nil {
			break
		}
	}

	return p
}
