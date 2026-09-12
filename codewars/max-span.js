/*

Consider the leftmost and righmost appearances of the same value in an array. We'll say that the "span" is the number of elements between the the same elements (two inclusive). Return the largest span found in the given array.

[1, 2, 1, 1, 3, 4, 5, 6, 7, 8, 8] → 4  // span is (1, 2, 1, 1)  
[1, 4, 2, 1, 4, 1, 4, 9, 7, 7, 7] → 6  // span is (4, 2, 1, 4, 1, 4)
[1, 4, 6, 1, 4, 4, 4, 8 ,6, 2, 3] → 7  // span is (6, 1, 4, 4, 4, 8, 6)

P.S. Input array includes positive integers, array's length > 10.

*/

var assert = require('assert');

function maxspan(array) {
	let max = 0;
	for (let i = 0; i < array.length; i++) {
		max = Math.max(max, array.lastIndexOf(array[i]) - array.indexOf(array[i]) + 1);
	}
	return max;
}

function main() {
	assert(maxspan([1, 2, 1, 1, 3, 4, 5, 6, 7, 8, 8]) == 4);
	assert(maxspan([1, 4, 2, 1, 4, 1, 4, 9, 7, 7, 7]) == 6);
	assert(maxspan([1, 4, 6, 1, 4, 4, 4, 8, 6, 2, 3]) == 7);
}

main();
