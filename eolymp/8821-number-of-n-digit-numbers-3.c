/*

The program takes a natural number n as input. Your task is to output the count of n-digit natural numbers that consist solely of even digits.

Input
A natural number n.

Output
The solution to the problem.

Examples
Input #1
1

Answer #1
4

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef long long vlong;

// https://oeis.org/A005054
vlong
solve(vlong n)
{
	if (n < 0)
		return 0;
	if (n == 0)
		return 1;
	return 4 * pow(5, n - 1);
}

int
main()
{
	static const vlong tab[] = {
		1, 4, 20, 100, 500, 2500, 12500, 62500, 312500, 1562500, 7812500,
		39062500, 195312500, 976562500, 4882812500, 24414062500, 122070312500,
		610351562500, 3051757812500, 15258789062500, 76293945312500, 381469726562500,
		1907348632812500, 9536743164062500
	};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(solve(i) == tab[i]);

	return 0;
}
