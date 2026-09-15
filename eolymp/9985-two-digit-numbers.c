/*

List all two-digit numbers with distinct digits whose digits add up to m.

Input
A natural number m, 0≤m≤20.

Output
Display the numbers in ascending order on a single line, or print No if no such numbers exist.

Examples

Input #1
4

Answer #1
13 31 40

Input #2
20

Answer #2
No

*/

#include <stdio.h>
#include <string.h>

int
uds(int n, int *r)
{
	int d[10];
	int i;

	memset(d, 0, sizeof(d));
	do {
		d[n % 10] += 1;
		n /= 10;
	} while (n > 0);

	*r = 0;
	for (i = 0; i < 10; i++) {
		if (d[i] > 1)
			return 0;
		*r += d[i] * i;
	}
	return 1;
}

void
solve(int n)
{
	int f, i, r;

	f = 0;
	for (i = 10; i < 100; i++) {
		if (!uds(i, &r))
			continue;

		if (r == n) {
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
	solve(4);
	solve(20);

	return 0;
}
