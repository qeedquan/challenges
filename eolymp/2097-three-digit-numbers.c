/*

Print all three-digit numbers with distinct digits in ascending order within the interval [a,b].

Input
Two three-digit positive integers a and b such that 100≤a≤b≤999.

Output
Print in ascending order all three-digit numbers from the interval [a,b] with distinct digits. Print each number on a separate line.

Examples

Input #1
100 105

Answer #1
102
103
104
105

*/

#include <stdio.h>

void
solve(int a, int b)
{
	int i, x, y, z;

	for (i = a; i <= b; i++) {
		x = (i / 100) % 10;
		y = (i / 10) % 10;
		z = i % 10;
		if (x != y && x != z && y != z)
			printf("%d\n", i);
	}
}

int
main()
{
	solve(100, 105);
	return 0;
}
