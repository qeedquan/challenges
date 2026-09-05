/*

Implement the method map, which accepts a linked list (head) and a mapping function, and returns a new linked list (head) where every element is the result of applying the given mapping method to each element of the original list.

For example: Given the list: 1 -> 2 -> 3, and the mapping function x => x * 2, map should return 2 -> 4 -> 6

The linked list is defined as follows:

function Node(data, next = null) {
  this.data = data;
  this.next = next;
}
Note: the list may be null and can hold any type of value.

Good luck!

*/

class Node {
	constructor(data, next=null) {
		this.data = data;
		this.next = next;
	}
}

function twice(x) {
	return x * 2;
}

function map(node, func) {
	if (node)
		return new Node(func(node.data), map(node.next, func));
	return node;
}

list = new Node(1, new Node(2, new Node(3)));
console.log(map(list, twice));

