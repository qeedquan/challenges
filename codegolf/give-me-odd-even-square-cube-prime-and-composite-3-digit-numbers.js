/*

Given a string which is guaranteed to be either odd, even, square, cube, prime or composite, your program or function must return an integer  100≤N≤999 which meets this description.

Rules
Your code must be deterministic.
The choice of the integers is up to you. However, the six answers must be distinct.
(For instance, if you return  113 for odd, you cannot return  113 for prime.)
You may take the input string in full lower case (odd), full upper case (ODD) or title case (Odd) but it must be consistent.
This is code-golf.

Example
Below is an example of valid I/O:

odd →  501 
even →  140
square →  961( =312)
cube →  343 ( =73)
prime →  113
 
composite →  999 ( =37×3×3×3)
Brownie points
For what it's worth, my own solution in JS is currently 24 bytes. So, brownie points for beating that.

JavaScript (ES6), 24 bytes

MD5: 562703afc8428c7b0a2c271ee7c22aff
Edit: I can now unveil it since it was found by tsh (just with a different parameter name):


s=>parseInt(s,30)%65+204

*/

function solve(s) {
	return parseInt(s, 30)%65 + 204;
}

console.log(solve("odd"));
console.log(solve("even"));
console.log(solve("square"));
console.log(solve("cube"));
console.log(solve("prime"));
console.log(solve("composite"));
