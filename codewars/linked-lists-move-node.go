/*

Linked Lists - Move Node

Write a MoveNode() function which takes the node from the front of the source list and moves it to the front of the destintation list. You should throw an error when the source list is empty. For simplicity, we use a Context object to store and return the state of the two linked lists. A Context object containing the two mutated lists should be returned by moveNode.

MoveNode() is a handy utility function to have for later problems.

JavaScript
var source = 1 -> 2 -> 3 -> null
var dest = 4 -> 5 -> 6 -> null
moveNode(source, dest).source === 2 -> 3 -> null
moveNode(source, dest).dest === 1 -> 4 -> 5 -> 6 -> null

Python
source = 1 -> 2 -> 3 -> None
dest = 4 -> 5 -> 6 -> None
move_node(source, dest).source == 2 -> 3 -> None
move_node(source, dest).dest == 1 -> 4 -> 5 -> 6 -> None

Ruby
source = 1 -> 2 -> 3 -> nil
dest = 4 -> 5 -> 6 -> nil
move_node(source, dest).source == 2 -> 3 -> nil
move_node(source, dest).dest == 1 -> 4 -> 5 -> 6 -> nil

The push() and buildOneTwoThree() functions need not be redefined.

*/

package main

import "fmt"

func main() {
	source := mklist(1, 2, 3)
	dest := mklist(4, 5, 6)
	show(moveNode(source, dest).source)
	show(moveNode(source, dest).dest)
}

type Elem interface{ int }

type Node[T Elem] struct {
	value T
	next  *Node[T]
}

type Context[T Elem] struct {
	source *Node[T]
	dest   *Node[T]
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

func moveNode[T Elem](source, dest *Node[T]) *Context[T] {
	if source == nil {
		panic("An empty source!")
	}

	return &Context[T]{
		source.next,
		&Node[T]{source.value, dest},
	}
}
