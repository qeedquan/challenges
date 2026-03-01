/*

You are given a node that is the beginning of a linked list. This list always contains a tail and a loop. Your objective is to determine the length of the loop.


// Use the `getNext' method or 'next' property to get the following node.
node.getNext()
node.next
Note: do NOT mutate the nodes!

Thanks to shadchnev, I broke all of the methods from the Hash class.

Don't miss dmitry's article in the discussion after you pass the Kata !! 

*/

class Node {
	constructor(next=null) {
		this.next = next;
	}

	getNext() {
		return this.next;
	}
}

function loopsize(node) {
	let counter = [];
	while (node && !counter.includes(node)) {
		counter.push(node);
		node = node.getNext();
	}
	return counter.length - counter.indexOf(node);
}

var node1 = new Node();
var node2 = new Node();
var node3 = new Node();
var node4 = new Node();
node1.next = node2;
node2.next = node3;
node3.next = node4;
node4.next = node2;
console.log(loopsize(node1));

