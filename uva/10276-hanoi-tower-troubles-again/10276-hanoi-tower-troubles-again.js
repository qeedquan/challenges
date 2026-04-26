var assert = require('assert');

/*

Simulation shows that the optimal algorithm is to always pick the existing leftmost peg.
This leads to the following formula that can be proved inductively:
https://oeis.org/A047838

*/

function solve(n) {
	if (n < 1)
		return 0;
	
	n += 1;
	return Math.floor(n*n/2) - 1;
}

assert(solve(4) == 11);
assert(solve(25) == 337);

