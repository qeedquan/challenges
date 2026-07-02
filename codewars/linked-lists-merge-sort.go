/*

Linked Lists - Merge Sort

Write a MergeSort() function which recursively sorts a list in ascending order. Note that this problem requires recursion. Given FrontBackSplit() and SortedMerge(), you can write a classic recursive MergeSort(). Split the list into two smaller lists, recursively sort those lists, and finally merge the two sorted lists together into a single sorted list. Return the list.

var list = 4 -> 2 -> 1 -> 3 -> 8 -> 9 -> null
mergeSort(list) === 1 -> 2 -> 3 -> 4 -> 8 -> 9 -> null
FrontBackSplit() and SortedMerge() need not be redefined. You may call these functions in your solution.

These function names will depend on the accepted naming conventions of language you are using. In Python, FrontBackSplit() is actually front_back_split(). In JavaScript, it is frontBackSplit(), etc.

*/

package main

import "math/rand"

func main() {
	for i := range 1000 {
		list := mklist(rand.Perm(i)...)
		assert(sorted(mergesort(list)))
	}
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

func sorted[T Elem](l *Node[T]) bool {
	for ; l != nil && l.next != nil; l = l.next {
		if l.value > l.next.value {
			return false
		}
	}
	return true
}

// https://www.geeksforgeeks.org/dsa/merge-sort-for-linked-list/
func mergesort[T Elem](head *Node[T]) *Node[T] {
	if head == nil || head.next == nil {
		return head
	}

	second := split(head)

	head = mergesort(head)
	second = mergesort(second)
	return merge(head, second)
}

func merge[T Elem](first, second *Node[T]) *Node[T] {
	if first == nil {
		return second
	}

	if second == nil {
		return first
	}

	if first.value < second.value {
		first.next = merge(first.next, second)
		return first
	}

	second.next = merge(first, second.next)
	return second
}

func split[T Elem](head *Node[T]) *Node[T] {
	fast := head
	slow := head

	for fast != nil && fast.next != nil {
		fast = fast.next.next
		if fast != nil {
			slow = slow.next
		}
	}

	temp := slow.next
	slow.next = nil
	return temp
}
