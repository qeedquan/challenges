/*

I've been really interested with sequences that follow the property

a(n+1) = a(n - a(n))
recently, so here's another question about these sequences. In particular we are concerned with sequences from the integers to the natural numbers.

A periodic sequence with the above property is an n-Juggler if and only if it contains exactly n distinct values. For example the following sequence is a 2 juggler

... 2,2,1,2,2,1,2,2,1,2,2,1,2,2,1,2,2,1,2,2,1,2,2,1,2,2,1,2,2,1,2,2,1,2,2,1 ...
because it only contains the numbers 1 and 2.

An example of a three juggler would be

... 3,5,3,5,1,5,3,5,3,5,1,5,3,5,3,5,1,5,3,5,3,5,1,5,3,5,3,5,1,5,3,5,3,5,1,5 ...
because it juggles 1, 3, and 5.

Task
Given n > 1 as input, output any n-Juggler.

You may output a sequence in a number of ways, you can

output a function that indexes it.

take an additional input of the index and output the value at that index.

output a continuous subsection of the sequence that, with the given property uniquely determines the sequence.

This is code-golf so answers are scored in bytes with less bytes being better.

*/

#include <stdio.h>

/*

@Mr. Xcoder

Receives two numbers, N and I, separated by a newline and in this order. I is the index into the sequence.

This uses a quite simple formula: N - 1 + N * (I % N). Its validity was confirmed by the OP.

*/

int
nj(int n, int i)
{
	if (n < 1)
		return 0;
	return ((i % n) * n) + n - 1;
}

int
main()
{
	int n, i;

	for (n = 0; n <= 10; n++) {
		printf("n = %2d | ", n);
		for (i = 0; i <= 4 * n; i++)
			printf("%d ", nj(n, i));
		printf("\n");
	}

	return 0;
}
