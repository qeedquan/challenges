/*

Create a class Hex which takes a number as an argument.

Adding a hex object to a number (by using valueOf) generates a number, but calling toString or toJSON will show its hexadecimal value starting with "0x". To make hex objects comparable you have to provide a method equals.

Example:

var FF = new Hex(255);
FF.toString() == "0xFF";
FF.valueOf() + 1 == 256;

Also create two methods, plus and minus which will add or subtract a number or Hex object and return a new Hex object.

var a = new Hex(10);
var b = new Hex(5);
a.plus(b).toJSON() == "0xF";

Also, create a parse class method that can parse Hexadecimal numbers and convert them to standard decimal numbers:

Hex.parse("0xFF") == 255;
Hex.parse("FF") == 255;

*/

function Hex(value) {
	this.hexVal = '0x' + value.toString(16).toUpperCase();
	this.decVal = value;

	this.valueOf = function () {
		return this.decVal;
	};

	this.toString = function () {
		return this.hexVal;
	};

	this.toJSON = function () {
		return this.toString();
	};

	this.plus = function (x) {
		return new Hex(value + x);
	};

	this.minus = function (x) {
		return new Hex(value - x);
	};
}

Hex.parse = function (string) {
	return parseInt(string, 16);
};

var FF = new Hex(255);
console.log(FF.toString());
console.log(FF.valueOf() + 1);

var a = new Hex(10);
var b = new Hex(5);
console.log(a.plus(b).toJSON());

console.log(Hex.parse("0xFF"));
console.log(Hex.parse("FF"));
