/*

If you look at the Fibonacci Numbers, you will notice a pattern in their parity: 0, 1 , 1 , 2 , 3 , 5 , 8 , 13 , 21 , 34 , 55 , 89 , 144. Every third number is even, and all the others are odd. This makes sense because an even plus an odd is odd, but an odd plus an odd is even and the sum for a term will always include at least one even number unless the last two terms were odd, which happens every three terms.

In this challenge you will have to look at a generalization of this problem.

Specs
You will be given as input two positive integers describing the Fibonacci integer sequence you will have to look at.
For example, 0, 1 describes the original Fibonacci numbers, and 2, 1 would be the Lucas numbers. The sequence is calculated with the recurrence relation: x(n+2)=x(n+1)+x(n).
You will also take a positive integer n.
Your code has to output the parity of the nth term of the described Fibonacci integer sequence (0 indexed).
The output format can be any two sane, consistent outputs (e.g. 0 for even and 1 for odd).

Test Cases
(Fibonacci numbers) [0, 1], 4  ->  odd
(Lucas numbers) [2, 1], 9  ->  even
[14, 17], 24  ->  even
[3, 9], 15  ->  odd
[2, 4], 10  ->  even

*/

#include <assert.h>
#include <stdio.h>

/*

@xnor

The generalized Fibonacci sequence modulo 2 has cycle length of 3. So, we reduce n mod 3 and take that element of the first three.

*/

int
fibp(int a, int b, int n)
{
	int x[] = {a, b, a + b};

	if (n < 0)
		return 0;
	return x[n % 3] % 2;
}

int
main()
{
	assert(fibp(0, 1, 4) == 1);
	assert(fibp(2, 1, 9) == 0);
	assert(fibp(14, 17, 24) == 0);
	assert(fibp(3, 9, 15) == 1);
	assert(fibp(2, 4, 10) == 0);

	return 0;
}
