/*

We have a class named 'Foo' with a 'val' attribute.

var foo = new Foo(2);     // foo.val = 2;
var boo = new Foo(3);    // boo.val = 3;

We want to be able to sum two Foo object using the '+' operator.

foo + boo // => must return 5

*/

class Foo {
	constructor(value) {
		this.value = value;
	}

	toString() {
		return this.value;
	}
}

var foo = new Foo(2);
var boo = new Foo(3);
console.log(foo, boo, foo + boo);
