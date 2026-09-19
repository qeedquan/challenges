/*

Activation Functions: ReLU
The ReLU (Rectified Linear Unit) activation function is a widely used non-linear activation function in neural networks.

It introduces non-linearity to the network by outputting the input directly if it is positive, and zero otherwise.

Formula:
The formula for the ReLU activation function is:

f(x) = max(0, x)

Where:
x is the input to the function.
f(x) is the output of the function.
Your Job:
Write a function that takes in a value (x) and computes its ReLU activation.

*/

function relu(x) {
	return Math.max(0, x);
}

function main() {
	for (let x = -1; x <= 1; x += 0.01) {
		console.log(x, relu(x));
	}
}

main();
