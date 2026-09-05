/*

Functional programming thrives from the reuse of functions. One core feature to extend the reuse is the concatenation of functions.

You probably know this feature from your favorite shell: ls -la | sort | head lists the top lines of the sorted result of ls -la

Build a function pipe to achieve this with JS. An example use could be:

var addOne = function(e) {
    return e + 1;
};

var square = function(e) {
    return e * e;
};

var result = [1,2,3,4,5].map(addOne.pipe(square)) //-> [4,9,16,25,36]
Since a function only can return one value it is absolutely sufficient to only support functions that consume only one parameter. Build your pipe function in a way, that one can pipe an arbitrary number of functions.

*/

function addOne(n) {
	return n + 1;
}

function square(n) {
	return n * n;
}

Function.prototype.pipe = function(func) {
	return (function(arg) {
		return func(this(arg));
	}).bind(this);
}

var result = [1, 2, 3, 4, 5].map(addOne.pipe(square))
console.log(result);
