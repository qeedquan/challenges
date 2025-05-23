/*

Write a generator sequence_gen ( sequenceGen in JavaScript) that, given the first terms of a sequence will generate a (potentially) infinite amount of terms, where each subsequent term is the sum of the previous x terms where x is the amount of initial arguments (examples of such sequences are the Fibonacci, Tribonacci and Lucas number sequences).

##Examples

fib = sequenceGen(0, 1)
fib.next().value = 0 // first term (provided)
fib.next().value = 1 // second term (provided)
fib.next().value = 1 // third term (sum of first and second terms)
fib.next().value = 2 // fourth term (sum of second and third terms)
fib.next().value = 3 // fifth term (sum of third and fourth terms)
fib.next().value = 5 // sixth term (sum of fourth and fifth terms)
fib.next().value = 8 // seventh term (sum of fifth and sixth terms)

trib = sequenceGen(0,1,1)
trib.next().value = 0 // first term (provided)
trib.next().value = 1 // second term (provided)
trib.next().value = 1 // third term (provided)
trib.next().value = 2 // fourth term (sum of first, second and third terms)
trib.next().value = 4 // fifth term (sum of second, third and fourth terms)
trib.next().value = 7 // sixth term (sum of third, fourth and fifth terms)

lucas = sequenceGen(2,1);
arr = [];
for(i = 0;i < 10;i++){
  arr.push(lucas.next().value);
}
arr === [2, 1, 3, 4, 7, 11, 18, 29, 47, 76]
Note: You can assume you will get at least one argument and any arguments given will be valid (positive or negative integers) so no error checking is needed.

**Note for Ruby users: ** sequence_gen should return an Enumerator object.

Any feedback/suggestions would much appreciated.

*/

var assert = require('assert');

function* sequenceGen() {
	let length = arguments.length;
	let sequence = [...arguments];
	let index = 0;
	for (;;) {
		if (index === sequence.length) {
			let slice = sequence.slice(sequence.length - length);
			let value = slice.reduce((sum, n) => sum + n);
			sequence.push(value);
		}
		index += 1;
		yield sequence[index - 1];
	}
}

fib = sequenceGen(0, 1);
assert(fib.next().value == 0);
assert(fib.next().value == 1);
assert(fib.next().value == 1);
assert(fib.next().value == 2);
assert(fib.next().value == 3);
assert(fib.next().value == 5);
assert(fib.next().value == 8);

trib = sequenceGen(0, 1, 1);
assert(trib.next().value == 0);
assert(trib.next().value == 1);
assert(trib.next().value == 1);
assert(trib.next().value == 2);
assert(trib.next().value == 4);
assert(trib.next().value == 7);

