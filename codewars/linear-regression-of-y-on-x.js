/*

Background:

https://upload.wikimedia.org/wikipedia/commons/thumb/3/3a/Linear_regression.svg/438px-Linear_regression.svg.png

A linear regression line has an equation in the form
Y = a + bX, where X is the explanatory variable and Y is the dependent variable.
The parameter b represents the slope of the line, while a is called the intercept (the value of y when x=0).

For more details visit the related wikipedia page.

Task:
The function that you have to write accepts two list/array, x and y, representing the coordinates of the points to regress (so that, for example, the first point has coordinates (x[0], y[0])).

Your function should return a tuple (in Python) or an array (any other language) of two elements: a (intercept) and b (slope) in this order.

You must round your result to the first 4 decimal digits

Examples:
regressionLine([25,30,35,40,45,50], [78,70,65,58,48,42]) == (114.381, -1.4457)

regressionLine([56,42,72,36,63,47,55,49,38,42,68,60], [147,125,160,118,149,128,150,145,115,140,152,155]) == (80.7777, 1.138)

*/

function regressionLine(x, y) {
	let n = Math.min(x.length, y.length);
	let X = 0;
	let Y = 0;
	let XX = 0;
	let XY = 0;
	for (let i = 0; i < n; i++) {
		X += x[i];
		Y += y[i];
		XX += x[i]*x[i];
		XY += x[i]*y[i];
	}

	let d = n*XX - X*X;
	let a = XX*Y - X*XY;
	let b = n*XY - X*Y;
	return [a/d, b/d];
}

function main() {
	console.log(regressionLine([25, 30, 35, 40, 45, 50], [78, 70, 65, 58, 48, 42]));
	console.log(regressionLine([56, 42, 72, 36, 63, 47, 55, 49, 38, 42, 68, 60], [147, 125, 160, 118, 149, 128, 150, 145, 115, 140, 152, 155]));
}

main();
