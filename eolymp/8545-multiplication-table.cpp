/*

Print an n×n multiplication table with alignment.

Input
One integer n (1≤n≤9).

Output
Print an n×n multiplication table, formatted as shown in the example.

Examples
Input #1
5

Answer #1
 1  2  3  4  5
 2  4  6  8 10
 3  6  9 12 15
 4  8 12 16 20
 5 10 15 20 25

Input #2
7

Answer #2
 1  2  3  4  5  6  7
 2  4  6  8 10 12 14
 3  6  9 12 15 18 21
 4  8 12 16 20 24 28
 5 10 15 20 25 30 35
 6 12 18 24 30 36 42
 7 14 21 28 35 42 49

*/

#include <cstdio>
#include <cmath>

typedef unsigned int uint;

void gen(uint n)
{
	uint p = (n) ? log2(n + 1) : 1;
	for (uint i = 1; i <= n; i++)
	{
		for (uint j = 1; j <= n; j++)
			printf("%*u", p + 1, i * j);
		printf("\n");
	}
	printf("\n");
}

int main()
{
	gen(5);
	gen(7);

	return 0;
}
