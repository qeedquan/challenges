var assert = require('assert');

function fib(n) {
	var a = 0;
	var b = 1;
	for (var i = 0; i < n; i++) {
		var c = a + b;
		a = b;
		b = c;
	}
	return a;
}

const chants = (n) => fib(n + 2);

assert(chants(3) == 5);
assert(chants(1) == 2);
