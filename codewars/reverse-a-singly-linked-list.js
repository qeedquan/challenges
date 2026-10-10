/*

Let's say we have a singly linked list.
Empty list is represented by null or equivalent (nil in Ruby).
Non-empty list is represented by 2-element array [value, tail].

So for example list with values 1, 2, 3 would be represented as [1, [2, [3, null]]].

Your job is to develop function reverseList which returns elements of given list in reverse order without modification of the original list.

P.S. Make sure your solution works on huge lists.

*/

function reverseList(list) {
	let result = null;
	while (list) {
		result = [list[0], result];
		list = list[1];
	}
	return result;
}

console.log(reverseList([1, [2, [3, null]]]));
