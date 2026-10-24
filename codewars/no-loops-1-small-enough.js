/*

*** No Loops Allowed ***

You will be given an array (a) and a limit value (limit). You must check that all values in the array are below or equal to the limit value. If they are, return true. Else, return false.

You can assume all values in the array are numbers.

Do not use loops. Do not modify input array.

Looking for more, loop-restrained fun? Check out the other kata in the series:

https://www.codewars.com/kata/no-loops-2-you-only-need-one

https://www.codewars.com/kata/no-loops-3-copy-within

*/

var assert = require('assert');

function smallEnough(array, limit) {
	if (array.length == 0)
		return true;
	if (array[0] > limit)
		return false;
	return smallEnough(array.slice(1), limit);
}

function main() {
	assert(smallEnough([66, 101], 200) == true);
	assert(smallEnough([78, 117, 110, 99, 104, 117, 107, 115], 100) == false);
	assert(smallEnough([101, 45, 75, 105, 99, 107], 107) == true);
	assert(smallEnough([80, 117, 115, 104, 45, 85, 112, 115], 120) == true);
}

main();
