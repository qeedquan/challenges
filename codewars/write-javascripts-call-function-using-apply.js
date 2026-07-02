/*

Imagine JavaScript didn't natively include the call function. The apply function however still exists.

Using apply, write call.

Note: console.log internally uses the 'call' function, which therefore means you can't debug using console.log as it will either call an empty function or cause an infinite loop.

*/

var assert = require('assert');

Function.prototype.call = function (location, ...args) {
	return this.apply(location, args);
};

function Product(name, price) {
	this.name = name;
	this.price = price;
}

function Food(name, price) {
	Product.call(this, name, price);
	this.category = 'food';
}

function Toy(name, price) {
	Product.call(this, name, price);
	this.category = 'toy';
}

const cheese = new Food('feta', 5);
const fun = new Toy('robot', 40);

assert(cheese.price == 5);
assert(fun.name == 'robot');

