/*

Linked Lists - Shuffle Merge

Write a ShuffleMerge() function that takes two lists and merges their nodes together to make one list, taking nodes alternately between the two lists. So ShuffleMerge() with 1 -> 2 -> 3 -> null and 7 -> 13 -> 1 -> null should yield 1 -> 7 -> 2 -> 13 -> 3 -> 1 -> null. If either list runs out, all the nodes should be taken from the other list. ShuffleMerge() should return the new list. The solution depends on being able to move nodes to the end of a list.

var first = 3 -> 2 -> 8 -> null
var second = 5 -> 6 -> 1 -> 9 -> 11 -> null
shuffleMerge(first, second) === 3 -> 5 -> 2 -> 6 -> 8 -> 1 -> 9 -> 11 -> null

If one of the argument lists is null, the returned list should be the other linked list (even if it is also null). No errors need to be thrown in ShuffleMerge().

*/

package main

import "reflect"

func main() {
	test([]int{23}, []int{44}, []int{23, 44})

	test([]int{1, 3}, []int{2, 4}, []int{1, 2, 3, 4})
	test([]int{3}, []int{2, 4}, []int{3, 2, 4})
	test([]int{3, 4, 5}, []int{9, 2}, []int{3, 9, 4, 2, 5})
	test([]int{4, 5}, []int{1}, []int{4, 1, 5})

	test([]int{1, 3, 8}, nil, []int{1, 3, 8})
	test([]int{1, 3, 8}, []int{2, 4, 9}, []int{1, 2, 3, 4, 8, 9})
	test([]int{3, 8, 5, 1}, []int{2, 4, 6}, []int{3, 2, 8, 4, 5, 6, 1})
	test([]int{3, 4, 5}, []int{2}, []int{3, 2, 4, 5})

	test([]int{1, 3, 5, 7, 9, 11, 13, 15}, nil, []int{1, 3, 5, 7, 9, 11, 13, 15})

	test([]int{1, 3, 5, 7, 9, 11, 13, 15}, []int{2, 4, 6, 8, 10, 12, 14, 16}, []int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16})
	test([]int{1, 3, 5, 7, 9, 11, 13, 15}, []int{88}, []int{1, 88, 3, 5, 7, 9, 11, 13, 15})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(first, second, res []int) {
	vals := mkvals(shufflemerge(mklist(first...), mklist(second...)))
	assert(reflect.DeepEqual(vals, res))
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

func mkvals[T Elem](n *Node[T]) []T {
	r := []T{}
	for ; n != nil; n = n.next {
		r = append(r, n.value)
	}
	return r
}

func shufflemerge[T Elem](a, b *Node[T]) *Node[T] {
	if a == nil {
		return b
	}
	if b == nil {
		return a
	}

	p := a
	q := b
	for i := 0; p != nil && q != nil; i ^= 1 {
		switch i {
		case 0:
			p.next, p = q, p.next
		case 1:
			q.next, q = p, q.next
		}
	}
	return a
}
