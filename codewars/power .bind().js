/*

You probably know about Function.prototype.bind method in JavaScript. It returns a copy of the original function but this function will always be called in the specified context. The problem is that you can't rebind another context any more.

var func = function () {
  return this.prop;
};

var obj1 = {prop: 1},
    obj2 = {prop: 2};
    
func = func.bind(obj1);
func(); // Will produce 1

func = func.bind(obj2);
func(); // Will also produce 1 :(

Your task is override the native Function.prototype.bind method by a new one that will allow you to rebind context multiple times. In this kata you don't need to worry about currying, testing function will never get params.

*/

Function.prototype.bind = function(ctx, ...boundArgs) {
	const fn = this._boundFn || this;
	const boundFn = (...args) => fn.apply(ctx, [...boundArgs, ...args]);
	boundFn._boundFn = fn;
	return boundFn;
};

var func = function () {
	return this.prop;
};

var obj1 = { prop: 1 };
var obj2 = { prop: 2 };
var obj3 = { prop: 3 };

func = func.bind(obj1);
console.log(func());

func = func.bind(obj2);
console.log(func());

func = func.bind(obj3);
console.log(func());
