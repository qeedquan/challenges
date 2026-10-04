/*

List all two-digit numbers where both digits share the same parity and their sum equals m.

Input
A natural number m, where 0≤m≤20.

Output
Display the numbers in ascending order on a single line, or print No if no such numbers exist.

Examples

Input #1
2

Answer #1
11 20

Input #2
3

Answer #2
No

*/

#include <stdio.h>

void
solve(int m)
{
	int a, b, f, i;

	f = 0;
	for (i = 10; i < 100; i++) {
		a = i / 10;
		b = i % 10;
		if ((a & 1) == (b & 1) && a + b == m) {
			printf("%d ", i);
			f = 1;
		}
	}
	if (!f)
		printf("No");
	printf("\n");
}

int
main()
{
	solve(2);
	solve(3);

	return 0;
}
