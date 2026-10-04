/*

Given two non-negative integers n and m such that 0≤n<30, 0≤m<30, and n=m.

Find the value of 2^n + 2^m using only bit operations.

Input
The input contains two non-negative integers n and m.

Output
Print the value of 2^n + 2^m.

Examples

Input #1
1 2

Answer #1
6

*/

#include <assert.h>

typedef unsigned uint;

uint
solve(uint n, uint m)
{
	return (1 << n) + (1 << m);
}

int
main()
{
	assert(solve(1, 2) == 6);

	return 0;
}
