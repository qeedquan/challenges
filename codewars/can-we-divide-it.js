/*

Your task is to create the functionisDivideBy (or is_divide_by) to check if an integer number is divisible by both integers a and b.

A few cases:


(-12, 2, -6)  ->  true
(-12, 2, -5)  ->  false

(45, 1, 6)    ->  false
(45, 5, 15)   ->  true

(4, 1, 4)     ->  true
(15, -5, 3)   ->  true

*/

var assert = require('assert');

function divisible(n, a, b) {
	return !(n % a) && !(n % b);
}

function main() {
	assert(divisible(-12, 2, -6) == true);
	assert(divisible(-12, 2, -5) == false);
	assert(divisible(45, 1, 6) == false);
	assert(divisible(45, 5, 15) == true);
	assert(divisible(4, 1, 4) == true);
	assert(divisible(15, -5, 3) == true);
}

main();
