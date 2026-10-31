/*

What is the minimum number of matches required to construct n squares on a plane, where each square has sides of length equal to one match?
Matches cannot be broken or placed on top of each other.
The vertices of the squares are the points where the ends of the matches meet, and the sides of the squares are formed by the matches themselves.

Write a program that, given the number of squares n, determines the minimum number of matches needed to construct them.

Input
The input consists of a single integer n (1≤n≤10^9).

Output
Output a single integer — the minimum number of matches required to construct n squares.

Examples
Input #1
4

Answer #1
12

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

// https://oeis.org/A078633
int
solve(int n)
{
	if (n < 1)
		return 0;
	return (2 * n) + ceil(2 * sqrt(n));
}

int
main()
{
	static const int tab[] = {
		4, 7, 10, 12, 15, 17, 20, 22, 24, 27, 29, 31, 34, 36, 38, 40, 43, 45,
		47, 49, 52, 54, 56, 58, 60, 63, 65, 67, 69, 71, 74, 76, 78, 80, 82,
		84, 87, 89, 91, 93, 95, 97, 100, 102, 104, 106, 108, 110, 112, 115,
		117, 119, 121, 123, 125, 127, 130, 132, 134, 136, 138, 140, 142
	};

	size_t i;

	assert(solve(4) == 12);

	for (i = 0; i < nelem(tab); i++)
		assert(solve(i + 1) == tab[i]);

	return 0;
}
