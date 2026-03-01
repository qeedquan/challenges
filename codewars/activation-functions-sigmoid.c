/*

Activation Functions: Sigmoid
The sigmoid activation function, often denoted as sigma(x), is a commonly used non-linear activation function in neural networks.

It squashes the input value to the range between 0 and 1, which makes it suitable for binary classification tasks or anywhere where a "yes" or "no" decision needs to be made.

Formula:
The formula for the sigmoid activation function is:

o(x) = 1 / (1 + exp(-x))

Where:
x is the input to the function.
e is the base of the natural logarithm, approximately equal to 2.71828.
sigma(x) is the output of the function.

Your Job
Write a function that takes in a value x and computes its sigmoid activation.

*/

#include <stdio.h>
#include <math.h>

double
sigmoid(double x)
{
	return 1 / (1 + exp(-x));
}

int
main()
{
	double x;

	for (x = 0.0; x <= 6.0; x += 0.01)
		printf("%.2f %.2f\n", x, sigmoid(x));

	return 0;
}
