/*

Linked Lists - Sorted Intersect

Write a SortedIntersect() function which creates and returns a list representing the intersection of two lists that are sorted in increasing order. Ideally, each list should only be traversed once. The resulting list should not contain duplicates.

var first = 1 -> 2 -> 2 -> 3 -> 3 -> 6 -> null
var second = 1 -> 3 -> 4 -> 5 -> -> 6 -> null
sortedIntersect(first, second) === 1 -> 3 -> 6 -> null

*/

package main

import "fmt"

func main() {
	first := mklist(1, 2, 2, 3, 3, 6)
	second := mklist(1, 3, 4, 5, 6)
	show(intersect(first, second))
	show(intersect(first, first))
	show(intersect(second, second))
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

func intersect[T Elem](x, y *Node[T]) *Node[T] {
	var h, t *Node[T]
	for x != nil && y != nil {
		var n *Node[T]
		switch {
		case x.value < y.value:
			x = x.next
		case x.value > y.value:
			y = y.next
		default:
			if t == nil || t.value != x.value {
				n = &Node[T]{value: x.value}
			}
			x = x.next
			y = y.next
		}
		if n == nil {
			continue
		}

		if h == nil {
			h, t = n, n
		} else {
			t.next, t = n, n
		}
	}
	return h
}
