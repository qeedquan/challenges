/*

In computer science, cycle detection is the algorithmic problem of finding a cycle in a sequence of iterated function values.

For any function f, and any initial value x0 in S, the sequence of iterated function values

x0,x1=f(x0),…,xi=f(xi−1),...

may eventually use the same value twice under some assumptions: S finite, f periodic ... etc. So there will be some i≠j such that xi=xj. 
Once this happens, the sequence must continue by repeating the cycle of values from xi to xj−1.
Cycle detection is the problem of finding i and j, given ƒ and x0 Let μ be the smallest index such that the value associated will reappears and λ the smallest value such that xμ=xλ+μ, λ is the loop length.

Example:

Consider the sequence:

2, 0, 6, 3, 1, 6, 3, 1, 6, 3, 1, ....
The cycle in this value sequence is 6, 3, 1. μ is 2 (first 6) λ is 3 (length of the sequence or difference between position of consecutive 6).

The goal of this kata is to build a function that will return [μ, λ] when given a short sequence. Simple loops will be sufficient. The sequence will be given in the form of an array. All array will be valid sequence associated with deterministic function. It means that the sequence will repeat itself when a value is reached a second time. (So you treat two cases: non repeating [1,2,3,4] and repeating [1,2,1,2], no hybrid cases like [1,2,1,4]). If there is no repetition you should return [].

*/

function cycle(sequence) {
	let end = sequence.findIndex(function(value, index) {
		let slice = sequence.slice(0, index);
		return slice.indexOf(value) > -1;
	});
	
	if (end < 0)
		return [];

	let start = sequence.indexOf(sequence[end]);
	return [start, end - start];
}

console.log(cycle([2, 0, 6, 3, 1, 6, 3, 1, 6, 3, 1]));
console.log(cycle([1, 2, 3, 4, 2, 3, 4]));
console.log(cycle([1, 2, 3, 4]));
