/*

Linked Lists - Insert Sort

Write an InsertSort() function which rearranges nodes in a linked list so they are sorted in increasing order. You can use the SortedInsert() function that you created in the "Linked Lists - Sorted Insert" kata below. The InsertSort() function takes the head of a linked list as an argument and must return the head of the linked list.

var list = 4 -> 3 -> 1 -> 2 -> null
insertSort(list) === 1 -> 2 -> 3 -> 4 -> null
If the passed in head node is null or a single node, return null or the single node, respectively. You can assume that the head node will always be either null, a single node, or a linked list consisting of multiple nodes.

The push(), buildOneTwoThree(), and sortedInsert() functions need not be redefined.

*/

package main

import "fmt"

func main() {
	list := mklist(4, 3, 1, 2)
	list = insertsort(list)
	show(list)
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

func show[T Elem](list *Node[T]) {
	for ; list != nil; list = list.next {
		fmt.Printf("%v ", list.value)
	}
	fmt.Println()
}

func insertsort[T Elem](list *Node[T]) *Node[T] {
	if list == nil || list.next == nil {
		return list
	}

	var head *Node[T]
	for list != nil {
		current := list
		list = list.next
		if head == nil || current.value < head.value {
			current.next = head
			head = current
			continue
		}

		p := head
		for p != nil {
			if p.next == nil || current.value < p.next.value {
				current.next = p.next
				p.next = current
				break
			}
			p = p.next
		}
	}
	return head
}
