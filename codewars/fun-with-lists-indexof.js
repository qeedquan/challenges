/*

Implement the method indexOf (index_of in PHP), which accepts a linked list (head) and a value, and returns the index (zero based) of the first occurrence of that value if exists, or -1 otherwise.

For example: Given the list: 1 -> 2 -> 3 -> 3, and the value 3, indexOf / index_of should return 2.

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

function indexOf(node, value) {
	let index = 0;
	while (node) {
		if (node.data == value)
			return index;
		index += 1;
		node = node.next;
	}
	return -1;
}

function main() {
	let node = new Node(1, new Node(2, new Node(3, new Node(4))));
	for (let i = 0; i <= 10; i++)
		console.log(indexOf(node, i));
}

main();
