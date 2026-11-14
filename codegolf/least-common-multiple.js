/*

The least common multiple of a set of positive integers A is the smallest postive integer B such that, for each k in A, there exists a positive integer n such that k*n = B.

Given at least two positive integers as input, output their least common multiple.

Rules
Builtins are allowed, but if your solution uses one, you are encouraged to include an alternate solution that does not use GCD/LCM builtins. However, the alternate solution will not count towards your score at all, so it is entirely optional.
All inputs and outputs will be within the natively-representable range for your language. If your language is natively capable of arbitrarily-large integers, then your solution must work with arbitrarily large inputs and outputs.
Test cases
[7, 2] -> 14
[8, 1] -> 8
[6, 4, 8] -> 24
[8, 2, 1, 10] -> 40
[9, 6, 2, 1, 5] -> 90
[5, 5, 7, 1, 1] -> 35
[4, 13, 8, 8, 11, 1] -> 1144
[7, 2, 2, 11, 11, 8, 5] -> 3080
[1, 6, 10, 3, 4, 10, 7] -> 420
[5, 2, 9, 10, 3, 4, 4, 4, 7] -> 1260
[9, 7, 10, 9, 7, 8, 5, 10, 1] -> 2520

*/

var assert = require('assert');

function lcmv(array, number=1) {
	if (array.some(value => number%value))
		return lcmv(array, number + 1);
	return number;
}

assert(lcmv([7, 2]) == 14);
assert(lcmv([8, 1])) == 8;
assert(lcmv([6, 4, 8]) == 24);
assert(lcmv([8, 2, 1, 10]) == 40);
assert(lcmv([9, 6, 2, 1, 5]) == 90);
assert(lcmv([5, 5, 7, 1, 1]) == 35);
assert(lcmv([4, 13, 8, 8, 11, 1]) == 1144);
assert(lcmv([7, 2, 2, 11, 11, 8, 5]) == 3080);
assert(lcmv([1, 6, 10, 3, 4, 10, 7]) == 420);
assert(lcmv([5, 2, 9, 10, 3, 4, 4, 4, 7]) == 1260);
assert(lcmv([9, 7, 10, 9, 7, 8, 5, 10, 1]) == 2520);

