/*

This kata is about singly-linked lists. A linked list is an ordered set of data elements, each containing a link to its successor (and sometimes its predecessor, known as a double linked list). You are you to implement an algorithm to find the kth to last element.

k will be an integer greater than or equal to 1.
Example

For example given the following linked list: a -> b -> c -> d

    if k = 1 then d should be returned
    if k = 2 then c should be returned
    if k = 3 then b should be returned
    if k = 4 then a should be returned
    if k exceeds the length of the list then None(Python) or null(Java, JavaScript) or false (C) should be returned

Each item in the linked list is a Node containing two fields:

    data - the value of the node
    next - pointing to the next node in the list, or to a null reference (null/NULL/None, depending on your language) for the last Node.

An empty list is represented as a null reference.

*/

var assert = require('assert');

class Node {
	constructor(data, next=null) {
		this.data = data;
		this.next = next;
		return this;
	}
}

function search(list, index) {
	if (index < 1)
		return null;

	let fast = list;
	let slow = list;
	while (index-- > 0 && fast)
		fast = fast.next;
	
	if (index >= 0)
		return null;

	while (fast) {
		fast = fast.next;
		slow = slow.next;
	}
	return (slow) ? slow.data : null;
}

function main() {
	list = new Node(1, new Node(2, new Node(3, new Node(4))));
	assert(search(list, 1) == 4);
	assert(search(list, 2) == 3);
	assert(search(list, 3) == 2);
	assert(search(list, 4) == 1);
	assert(search(list, 5) == null);
	assert(search(list, 6) == null);
}

main();
