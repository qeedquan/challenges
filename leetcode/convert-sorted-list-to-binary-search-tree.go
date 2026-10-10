/*

Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height-balanced binary search tree.

Example 1:

Input: head = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.

Example 2:

Input: head = []
Output: []


Constraints:

The number of nodes in head is in the range [0, 2 * 10^4].
-10^5 <= Node.val <= 10^5

*/

package main

import (
	"fmt"
)

func main() {
	printbst(list2bst(mklist(-10, -3, 0, 5, 9)))
	printbst(list2bst(mklist()))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

type Elem interface{ int }

type List[T Elem] struct {
	value T
	next  *List[T]
}

type Tree[T Elem] struct {
	value T
	left  *Tree[T]
	right *Tree[T]
}

func mklist[T Elem](values ...T) *List[T] {
	var head, tail *List[T]
	for _, value := range values {
		node := &List[T]{value: value}
		if head == nil {
			head, tail = node, node
		} else {
			tail.next, tail = node, node
		}
	}
	return head
}

func listsize[T Elem](head *List[T]) int {
	size := 0
	for node := head; node != nil; node = node.next {
		size += 1
	}
	return size
}

func list2bst[T Elem](head *List[T]) *Tree[T] {
	return list2bstrec(&head, 0, listsize(head)-1)
}

func list2bstrec[T Elem](head **List[T], low, high int) *Tree[T] {
	if low > high || head == nil {
		return nil
	}

	mid := low + (high-low)/2
	left := list2bstrec(head, low, mid-1)
	node := &Tree[T]{
		value: (*head).value,
		left:  left,
	}
	*head = (*head).next
	node.right = list2bstrec(head, mid+1, high)

	return node
}

func printbst[T Elem](root *Tree[T]) {
	queue := []*Tree[T]{root}
	for len(queue) > 0 {
		node := queue[0]
		queue = queue[1:]
		if node == nil {
			fmt.Printf("# ")
		} else {
			fmt.Printf("%v ", node.value)
			queue = append(queue, node.left)
			queue = append(queue, node.right)
		}
	}
	fmt.Println()
}
