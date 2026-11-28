/*

Learning TypeScript. Classes & Interfaces. Implement interface methods

Overview
One of TypeScript’s core principles is that type-checking focuses on the shape that values have. This is sometimes called “duck typing” or “structural subtyping”. In TypeScript, interfaces fill the role of naming these types, and are a powerful way of defining contracts within your code as well as contracts with code outside of your project.

Task
You are given an interface IGeometricFigure:

interface IGeometricFigure {
  // Calculates area of the figure
  area: () => number;
  // Calculates perimeter of the figure
  perimeter: () => number;
}

Your task is to implement classes Square and Circle:

export class Square implements IGeometricFigure {
  // TODO:
}

export class Circle implements IGeometricFigure {
  // TODO:
}

P.S. Solved this kata? Take a look at other katas in "Learning TypeScript" ( https://www.codewars.com/collections/learning-typescript ) collection.interface IGeometricFigure {
  area: () => number;
  perimeter: () => number;
}

*/

interface IGeometricFigure {
	// Calculates area of the figure
	area: () => number;

	// Calculates perimeter of the figure
	perimeter: () => number;
}

export class Square implements IGeometricFigure {
	a: number;

	area() {
		return this.a**2;
	}

	perimeter() {
		return this.a * 4;
	}

	constructor(a: number) {
		this.a = a;
	}
}

export class Circle implements IGeometricFigure {
	r: number;

	area() {
		return this.r**2 * Math.PI;
	}

	perimeter() {
		return this.r * 2 * Math.PI;
	}

	constructor(r: number) {
		this.r = r;
	}
}

let square = new Square(10);
console.log(square.area());
console.log(square.perimeter());

let circle = new Circle(1);
console.log(circle.area());
console.log(circle.perimeter());

