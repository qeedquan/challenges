/*

Implement vanilla gradient descent to minimize the one-dimensional quadratic

f(x) = a*x^2 + b*x + c

Starting from x0, determine the gradient at the current value of x
and apply the following update exactly steps times:

x <- x - lr*gradient

Return the final value of x as a Python float. Deriving the gradient of the quadratic is part of the task.

Examples
Input: a = 1.0, b = -4.0, c = 3.0, x0 = 0.0, lr = 0.1, steps = 50

Output: 1.999971

Explanation: Repeated updates move x toward the minimum without jumping directly to it.

Input: a = 2.0, b = 8.0, c = 0.0, x0 = 10.0, lr = 0.05, steps = 200

Output: -2.0

Hint 1
Use a loop that performs exactly steps parameter updates.

Hint 2
Compute the gradient at the current x before applying the learning-rate update.

Requirements
Compute the derivative at the current value of x on every iteration
Apply the gradient descent update exactly steps times
Do not return the closed-form minimizer instead of performing the updates
Return the final value as a Python float
Constraints
Time limit: 200 ms; Memory: 64 MB
Pure Python / NumPy (no ML libs)

*/

#include <stdio.h>

double
gradient(double x, double a, double b, double)
{
	return (2 * a * x) + b;
}

double
gradient_descent_quadratic(double a, double b, double c, double x0, double lr, int steps)
{
	double x;
	int i;

	x = x0;
	for (i = 0; i < steps; i++)
		x = x - (lr * gradient(x, a, b, c));
	return x;
}

int
main()
{
	printf("%f\n", gradient_descent_quadratic(1, -4, 3, 0, 0.1, 50));
	printf("%f\n", gradient_descent_quadratic(2, 8, 0, 10, 0.05, 200));
	return 0;
}
