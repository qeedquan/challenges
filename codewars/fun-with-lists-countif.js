/*

Implement the method countIf (count_if in PHP), which accepts a linked list (head) and a predicate function, and returns the number of elements which apply to the given predicate.

For example: Given the list: 1 -> 2 -> 3, and the predicate x => x >= 2, countIf / count_if should return 2, since x >= 2 applies to both 2 and 3.

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

function countIf(node, predicate) {
	let count = 0;
	while (node) {
		if (predicate(node.data))
			count += 1;
		node = node.next;
	}
	return count;
}

function iseven(x) {
	return x%2 == 0;
}

function istrue(x) {
	return true;
}

function main() {
	let node = new Node(1, new Node(2, new Node(3, new Node(4))));
	console.log(countIf(node, iseven));
	console.log(countIf(node, istrue));
}

main();
