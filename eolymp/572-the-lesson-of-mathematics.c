/*

At the beginning of each lesson, the mathematics teacher Olga Petrivna writes a positive integer n on the board.
During the lesson, the students try to find as many prime factors of this number as possible.
At the end of the lesson, the generous Olga Petrivna rewards all students who found the maximum number of prime factors with a candy.

Vasya, a student who loves sweets, asks for your help to receive a candy from Olga Petrivna.
For the given number n, output all its prime factors and the powers with which they occur in the number.

Input
A single positive integer n, where n≤10^9.

Output
Output all the prime factors of the number n in ascending order.
For each factor, specify the power with which it occurs in n, if the power is greater than one.
The output format must match the example.

Examples

Input #1
3240

Answer #1
2^3*3^4*5

*/

#include <stdio.h>

typedef unsigned int uint;

void
solve(uint n)
{
	uint f, i, p;

	if (n < 2) {
		puts("");
		return;
	}

	f = 0;
	for (i = 2; n > 1; i++) {
		for (p = 0; !(n % i); p++)
			n /= i;

		if (p) {
			if (f)
				printf("*");
			printf("%u", i);
			if (p > 1)
				printf("^%u", p);
			f = 1;
		}
	}
	printf("\n");
}

int
main()
{
	solve(3240);
	solve(5);
	solve(10);
	solve(11 * 13 * 17);
	solve(2048);
	solve(10000);

	return 0;
}
