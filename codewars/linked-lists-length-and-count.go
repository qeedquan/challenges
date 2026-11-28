/*

Linked Lists - Length & Count

Implement Length() to count the number of nodes in a linked list.

length(null) => 0
length(1 -> 2 -> 3 -> null) => 3
Implement Count() to count the occurrences of an integer in a linked list.

count(null, 1) => 0
count(1 -> 2 -> 3 -> null, 1) => 1
count(1 -> 1 -> 1 -> 2 -> 2 -> 2 -> 2 -> 3 -> 3 -> null, 2) => 4
I've decided to bundle these two functions within the same Kata since they are both very similar.

The push()/Push() and buildOneTwoThree()/BuildOneTwoThree() functions do not need to be redefined.

*/

package main

func main() {
	assert(length(mklist()) == 0)
	assert(length(mklist(1, 2, 3)) == 3)

	assert(count(mklist(), 1) == 0)
	assert(count(mklist(1, 2, 3), 1) == 1)
	assert(count(mklist(1, 1, 1, 2, 2, 2, 2, 3, 3), 2) == 4)
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

func length[T Elem](l *Node[T]) int {
	c := 0
	for ; l != nil; l = l.next {
		c++
	}
	return c
}

func count[T Elem](l *Node[T], v T) int {
	c := 0
	for ; l != nil; l = l.next {
		if l.value == v {
			c++
		}
	}
	return c
}
