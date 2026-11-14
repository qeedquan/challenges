/*

Create the function prefill that returns an array of n elements that all have the same value v. See if you can do this without using a loop.

You have to validate input:

v can be anything (primitive or otherwise)
if v is ommited, fill the array with undefined
if n is 0, return an empty array
if n is anything other than an integer or integer-formatted string (e.g. '123') that is >=0, throw a TypeError
When throwing a TypeError, the message should be n is invalid, where you replace n for the actual value passed to the function.

Code Examples

    prefill(3,1) --> [1,1,1]
    
    prefill(2,"abc") --> ['abc','abc']
    
    prefill("1", 1) --> [1]
    
    prefill(3, prefill(2,'2d'))
      --> [['2d','2d'],['2d','2d'],['2d','2d']]
      
    prefill("xyz", 1)
      --> throws TypeError with message "xyz is invalid"

*/

function prefill(n, v) {
	if (parseInt(n) != Math.abs(n))
		throw new TypeError(n + ' is invalid');
	
	let m = Number(n);
	if (m == 0)
		return [];
	return arrayFill(m, v);
}

function arrayFill(n, v) {
	if (n < 1)
		return [];

	let r = [v];
	if (n == 1)
		return r;
	
	r = r.concat(arrayFill(n - 1, v));
	return r;
}

console.log(prefill(3, 1));
console.log(prefill(2, "abc"));
console.log(prefill("1", 1));
console.log(prefill(3, prefill(2, "2d")));
try {
	prefill("xyz", 1);
} catch (error) {
	console.log(error);
}
