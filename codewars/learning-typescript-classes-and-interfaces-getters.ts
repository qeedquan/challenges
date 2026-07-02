/*

Learning TypeScript. Classes & Interfaces. Getters
N.B.: To solve this kata you need to choose "2.4/ES6" target.

Task
Define the following classes:

I. Cuboid
The object constructor for the class Cuboid should receive exactly three arguments in the following order: length, width, height and store these three values in this.length, this.width and this.height respectively.

The class Cuboid should then have a getter surfaceArea which returns the surface area of the cuboid and a getter volume which returns the volume of the cuboid.

II. Cube
Class Cube is a subclass of class Cuboid. The constructor function of Cube should receive one argument only, its length, and use that value passed in to set this.length, this.width and this.height.

Hint: Make a call to super, passing in the correct arguments, to make life easier ;)

Articles of Interest
Below are some articles of interest that may help you complete this Kata:

Stack Overflow - What are getters and setters in ES6? ( http://stackoverflow.com/questions/28222276/what-are-getters-and-setters-for-in-ecmascript-6-classes )
getter - Javascript | MDN ( https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Functions/get )

Credits
This is TypeScript version of kata "Fun with ES6 Classes #3 - Cuboids, Cubes and Getters" ( http://www.codewars.com/kata/56fbdda707cff41b68000de2 )by @donaldsebleung

P.S. Solved this kata? Take a look at other katas in "Learning TypeScript" ( https://www.codewars.com/collections/learning-typescript ) collection.

*/

export class Cuboid {
	length: number;
	width: number;
	height: number;
	constructor(length: number, width: number, height: number) {
		this.length = length;
		this.width = width;
		this.height = height;
	}

	// https://oeis.org/A033581
	get surfaceArea() {
		return 2 * (this.length*this.width + this.width*this.height + this.length*this.height);
	}

	// https://oeis.org/A000578
	get volume() {
		return this.length * this.width * this.height;
	}
}

export class Cube extends Cuboid {
	constructor(a: number) {
		super(a, a, a);
	}
}

for (let i = 0; i <= 10; i++) {
	let cube = new Cube(i);
	console.log(cube.surfaceArea, cube.volume);
}
