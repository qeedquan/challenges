/*

Natural numbers ≡ N≡{0,1,2,...}

The submission can be either a program or a function, both cases will henceforth be referred to as "function".

The task is to golf the shortest function N^n -> N, i.e. a function that maps n natural numbers (with n>0 being a number of your choosing) to a natural number, such that the function is not primitive recursive, that is, a function that is not composable from only the following functions (each variable being a natural number):

(from https://en.wikipedia.org/wiki/Primitive_recursive_function)

Zero
Z()=0

Successor
S(x)=x+1

Projection
Pni(x0,x1,…,xn−1)=xi

Composition
h(x0,x1,…,xm)=f(g1(x0,x1,…,xm),…,gk(x0,x1,…,xm))

Primitive recursion

h(0,x0,…,xk)h(S(y),x0,…,xk)=f(x0,…,xk)=g(y,h(y,x0,…,xk),x0,…,xk)

From the above five functions/operations, we can get many functions like the constant function, addition, multiplication, exponentiation, factorial, primality test, etc.

A (total) function that is not primitive recursive could be one that grows faster than any primitive recursive function, like the Ackermann function. Its proof of not being primitive recursive is on Wikipedia.

Or a function could be non primitive recursive due to contradictions that would arise otherwise; examples are provided in the answers to this Math Stack Exchange question as pointed out by Bubbler.

The submissions are free to use any radix as long as the same radix is used for each of the input and output numbers.

Your submission can take input as a list of numbers, a list of strings representing numbers, a string containing (constant) delimiter-separated numbers, or the like.
In the case of using a string or equivalent, your submissions are free to use any character to represent each digit of the radix chosen, as long the choice is consistent throughout all inputs and output.

The function will always be called with the same number of inputs.

The submission should always terminate and return a result, that is, it cannot loop indefinitely.

The function should always give deterministic output.

The submission should theoretically work for any input, including those outside of the used numeric data types.

A proof accompanying your answer is appreciated, but not required.

This challenge was drafted thanks to the helpful commenters at its Sandbox.

*/

#include <stdio.h>

typedef unsigned long long uvlong;

// https://en.wikipedia.org/wiki/Sudan_function
uvlong
sudan(uvlong n, uvlong x, uvlong y)
{
	if (n == 0)
		return x + y;
	if (y == 0)
		return x;
	return sudan(n - 1, sudan(n, x, y - 1), sudan(n, x, y - 1) + y);
}

void
table(uvlong n, uvlong nx, uvlong ny)
{
	uvlong x, y;

	for (y = 0; y <= ny; y++) {
		for (x = 0; x <= nx; x++)
			printf("%8llu", sudan(n, x, y));
		printf("\n");
	}
	printf("\n");
}

int
main()
{
	uvlong n;

	for (n = 0; n <= 1; n++)
		table(n, 10, 10);

	return 0;
}
