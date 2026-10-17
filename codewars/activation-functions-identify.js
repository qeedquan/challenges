/*

Activation Functions: Identity
In this coding exercise, you'll implement the linear activation function, a fundamental activation function commonly used in neural networks. The linear activation function simply returns the input value without any transformation.

Formula
The formula for the linear (or “identity”) activation is:

f(x) = x

Where:
x is the input to the function.
f(x) is the output of the function.
Your Job:
Create a function that accepts a value (x) and computes its linear activation.

*/

function identity(x) {
	return x;
}

function main() {
	for (let x = 0; x <= 1; x += 0.01) {
		console.log(x, identity(x));
	}
}

main();
