/*

Implement the method length, which accepts a linked list (head), and returns the length of the list.

For example: Given the list: 1 -> 2 -> 3 -> 4, length should return 4.

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

function length(node) {
	let len = 0;
	while (node) {
		node = node.next;
		len += 1;
	}
	return len;
}

function main() {
	let node = new Node(1, new Node(2, new Node(3, new Node(4))));
	console.log(length(node));
	console.log(length(null));
}

main();
