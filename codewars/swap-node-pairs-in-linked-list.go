/*

You are given the head node of a singly-linked list.
Write a method that swaps each pair of nodes in the list, then returns the head node of the list.
You have to swap the nodes themselves, not their values.

Example:

(A --> B --> C --> D) => (B --> A --> D --> C)

The swapping should be done left to right, so if the list has an odd length, the last node stays in place:

(A --> B --> C) => (B --> A --> C)

The list will be composed of Nodes of the following specification:

class Node:
    def __init__(self, next=None):
        self.next = next

*/

package main

import "fmt"

func main() {
	list0 := mklist()
	list1 := mklist('A')
	list2 := mklist('A', 'B')
	list3 := mklist('A', 'B', 'C')
	list4 := mklist('A', 'B', 'C', 'D')
	list5 := mklist('A', 'B', 'C', 'D', 'E')

	show(swappair(list0))
	show(swappair(list1))
	show(swappair(list2))
	show(swappair(list3))
	show(swappair(list4))
	show(swappair(list5))
}

type Elem interface{ int }

type Node[T Elem] struct {
	value T
	next  *Node[T]
}

func mklist[T Elem](values ...T) *Node[T] {
	var head, tail *Node[T]
	for _, value := range values {
		node := &Node[T]{value: value}
		if head == nil {
			head, tail = node, node
		} else {
			tail.next, tail = node, node
		}
	}
	return head
}

func show[T Elem](node *Node[T]) {
	for ; node != nil; node = node.next {
		fmt.Printf("%c ", node.value)
	}
	fmt.Println()
}

func swappair[T Elem](head *Node[T]) *Node[T] {
	if head == nil || head.next == nil {
		return head
	}

	prev := head
	curr := head.next
	head = curr
	for {
		next := curr.next
		curr.next = prev
		if next == nil || next.next == nil {
			prev.next = next
			break
		}

		prev.next = next.next
		prev = next
		curr = prev.next
	}
	return head
}
