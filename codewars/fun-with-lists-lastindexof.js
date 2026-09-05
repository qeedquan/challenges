/*

Implement the method lastIndexOf (last_index_of in PHP and Python), which accepts a linked list (head) and a value, and returns the index (zero based) of the last occurrence of that value if exists, or -1 otherwise.

For example: Given the list: 1 -> 2 -> 3 -> 3, and the value 3, lastIndexOf / last_index_of should return 3.

The linked list is defined as follows:

function Node(data, next = null) {
  this.data = data;
  this.next = next;
}

Note: the list may be null/None and can hold any type of value.

Good luck!

*/

class Node {
	constructor(data, next=null) {
		this.data = data;
		this.next = next;
	}
}

function lastIndexOf(node, value) {
	let result = -1;
	let index = 0;
	while (node) {
		if (node.data == value)
			result = index;
		index += 1;
		node = node.next;
	}
	return result;
}

function main() {
	let node = new Node(1, new Node(2, new Node(3, new Node(3))));
	console.log(lastIndexOf(node, 3));
}

main();
