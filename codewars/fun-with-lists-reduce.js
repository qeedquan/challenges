/*

Implement the method reduce, which accepts three arguments:

linked list (head)
bi-function - (accumulated_value, current_element_data)
initial value
This method should return the result of applying the given function on every element with the accumulating result, starting with the initial value.

For example:

Given the list: 1 -> 2 -> 3, the function (acc, curr) => acc + curr and an initial value of 0, reduce should return 6, because:

(0, 1) and the function (acc, curr) => acc + curr gives 1
(1, 2) and the function (acc, curr) => acc + curr gives 3
(3, 3) and the function (acc, curr) => acc + curr gives 6
Another example:

Given the list: 1 -> 2 -> 3 -> 4, the function (acc, curr) => acc * curr and an initial value of 1, reduce should return 24

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

function reduce(node, apply, init) {
	let result = init;
	while (node) {
		result = apply(result, node.data);
		node = node.next;
	}
	return result;
}

function sum(a, b) {
	return a + b;
}

function product(a, b) {
	return a * b;
}

function main() {
	let node = new Node(1, new Node(2, new Node(3)));
	console.log(reduce(node, sum, 0));

	node = new Node(1, new Node(2, new Node(3, new Node(4))));
	console.log(reduce(node, product, 1));
}

main();
