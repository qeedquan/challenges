/*

Fun with ES6 Classes #4 - Cubes and Setters

Overview
In Fun with ES6 Classes #3 - Cuboids, Cubes and Getters ( http://www.codewars.com/kata/56fbdda707cff41b68000de2 ), we learned that if we knew all the dimensions (i.e. length, width, height) of a cuboid, we could easily work out its corresponding volume and surface area. The way we achieved this in our code was by the use of getters which automatically computed the volume and surface area of the cuboid whenever either one of length, width, height changed. However, in the previouos exercise, one thing we could not do is define setters for surface area or volume of a cuboid because for a given volume/SA, there were an infinite number of possibilities to the dimensions of the cuboid.

However, for cubes (a special type of cuboid), since their length, width and height are always the same, it is possible to figure out the side length of a cube given its surface area and/or volume. Therefore, in this Kata, you will be asked to define setters as well as getters for both the surface area and volume of a cube.

Task
Define a class Cube whose constructor function takes exactly one parameter length and stores the value of the argument into this.length. You will then define both a getter and a setter for the surfaceArea and volume of the cube.

No initial code will be given. You are free to use whatever syntax you like to complete this Kata but it is highly recommended that you use ES6 syntax and features to complete this Kata.

*/

class Cube {
	constructor(a) {
		this.a = a;
	}

	get length() {
		return this.a;
	}

	set length(a) {
		this.a = a;
	}

	get surfaceArea() {
		return 6 * this.a**2;
	}
  
	set surfaceArea(s) {
		this.a = Math.sqrt(s / 6);
	}

	get volume() {
		return this.a**3;
	}

	set volume(v) {
		this.a = v**(1 / 3);
	}
}

let cube = new Cube(10);
console.log(cube.length);
console.log(cube.surfaceArea);
console.log(cube.volume);

