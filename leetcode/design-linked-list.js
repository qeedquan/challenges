/*

Design your implementation of the linked list. You can choose to use a singly or doubly linked list.
A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node.
If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

Implement the MyLinkedList class:

MyLinkedList() Initializes the MyLinkedList object.
int get(int index) Get the value of the indexth node in the linked list. If the index is invalid, return -1.
void addAtHead(int val) Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
void addAtTail(int val) Append a node of value val as the last element of the linked list.
void addAtIndex(int index, int val) Add a node of value val before the indexth node in the linked list. If index equals the length of the linked list, the node will be appended to the end of the linked list. If index is greater than the length, the node will not be inserted.
void deleteAtIndex(int index) Delete the indexth node in the linked list, if the index is valid.


Example 1:

Input
["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", "deleteAtIndex", "get"]
[[], [1], [3], [1, 2], [1], [1], [1]]
Output
[null, null, null, null, 2, null, 3]

Explanation
MyLinkedList myLinkedList = new MyLinkedList();
myLinkedList.addAtHead(1);
myLinkedList.addAtTail(3);
myLinkedList.addAtIndex(1, 2);    // linked list becomes 1->2->3
myLinkedList.get(1);              // return 2
myLinkedList.deleteAtIndex(1);    // now the linked list is 1->3
myLinkedList.get(1);              // return 3


Constraints:

0 <= index, val <= 1000
Please do not use the built-in LinkedList library.
At most 2000 calls will be made to get, addAtHead, addAtTail, addAtIndex and deleteAtIndex.

*/

var assert = require('assert');

class Element {
	constructor(val, next=null) {
		this.val = val;
		this.next = next;
	}
}

class List {
	constructor() {
		this.head = null;
		this.tail = null;
		this.length = 0;
	}
	
	get(index) {
		var node = this.head;
		for (var i = 0; i < index && node != null; i++)
			node = node.next;
		return (node != null) ? node.val : -1;
	}
	
	addAtHead(val) {
		var node = new Element(val);
		if (this.head == null) {
			this.head = this.tail = node;
		} else {
			node.next = this.head;
			this.head = node;
		}
		this.length += 1;
	}

	addAtTail(val) {
		var node = new Element(val);
		if (this.head == null) {
			this.head = this.tail = node;
		} else {
			this.tail.next = node;
			this.tail = node;
		}
		this.length += 1;
	}

	addAtIndex(index, val) {
		if (index > this.length)
			return;

		var node = new Element(val);
		var prev = null;
		var cur = this.head;
		for (var i = 0; i < index; i++) {
			prev = cur;
			cur = cur.next;
		}

		if (prev == null) {
			node.next = this.head;
		} else {
			prev.next = node;
			node.next = cur;
		}

		if (index == 0)
			this.head = node;
		if (index == this.length)
			this.tail = node;

		this.length += 1;
	}

	deleteAtIndex(index) {
		if (index >= this.length)
			return;

		var prev = null;
		var cur = this.head;
		for (var i = 0; i < index; i++) {
			prev = cur;
			cur = cur.next;
		}

		if (prev != null && cur != null)
			prev.next = cur.next;
		else if (prev == null && cur != null) {
			if (this.tail == this.head)
				this.tail = cur.next;

			this.head = cur.next;
		}
		
		if (cur == this.tail)
			this.tail = prev;

		this.length -= 1;
	}

	toArray() {
		var result = [];
		for (var cur = this.head; cur != null; cur = cur.next)
			result.push(cur.val);
		return result;
	}
}

function equal(a, b) {
	if (a.length != b.length)
		return false;
	return a.every((v, i) => v == b[i])
}

function assertEqual(l, a) {
	assert(equal(l.toArray(), a));
}

function testBasic() {
	var l = new List();

	l.addAtHead(1);
	assertEqual(l, [1]);
	
	l.addAtTail(3);
	assertEqual(l, [1, 3]);
	
	l.addAtIndex(1, 2);
	assertEqual(l, [1, 2, 3]);

	assert(l.get(1) == 2);

	l.deleteAtIndex(1);
	assertEqual(l, [1, 3]);

	assert(l.get(1) == 3);
}

function testIndex() {
	var l = new List();

	l.addAtTail(0);
	for (var i = 1; i < 100; i++)
		l.addAtIndex(i, i);

	for (var i = 0; i < 100; i++)
		l.deleteAtIndex(1);

	assertEqual(l, [0]);

	l.deleteAtIndex(0);
	assertEqual(l, []);

	l.addAtHead(3);
	l.addAtHead(2);
	l.addAtHead(1);
	assertEqual(l, [1, 2, 3]);

	l.deleteAtIndex(1);
	assertEqual(l, [1, 3]);

	l.addAtIndex(2, 10);
	assert(l.get(2) == 10);
	assertEqual(l, [1, 3, 10]);
	
	l.deleteAtIndex(0);
	assertEqual(l, [3, 10]);

	l.deleteAtIndex(1);
	assertEqual(l, [3]);

	l.deleteAtIndex(0);
	assertEqual(l, []);

	l.deleteAtIndex(0);
	assertEqual(l, []);

	l.addAtIndex(0, 25);
	assertEqual(l, [25]);

	l.addAtTail(21);
	assertEqual(l, [25, 21]);

	l.addAtIndex(0, 53);
	assertEqual(l, [53, 25, 21]);
	
	l.addAtHead(40);
	assertEqual(l, [40, 53, 25, 21]);
}

function main() {
	testBasic();
	testIndex();
}

main();
