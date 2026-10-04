/*

Given a rational fraction n/m.
Write its decimal representation with k digits after the decimal point.

Input
The input contains three integers m, n, and k (0<m,n≤100, 0≤k≤1000) given in one line.

Output
Print k digits after the decimal point of the given number.

Examples
Input #1
1 2 3

Answer #1
0.500

*/

#include <stdio.h>

void
solve(int m, int n, int k)
{
	int curk, curm;

	if (n == 0)
		return;

	printf("%d", m / n);
	if (k > 0)
		printf(".");

	curm = (m % n) * 10;
	for (curk = 0; curk < k; curk++) {
		if (curm == 0) {
			printf("0");
		} else if (curm < n) {
			printf("0");
			curm *= 10;
		} else if (curm >= n) {
			printf("%d", curm / n);
			curm %= n;
			curm *= 10;
		}
	}
	printf("\n");
}

int
main()
{
	solve(1, 2, 3);
	solve(1, 3, 10);
	solve(5, 6, 20);
	solve(1, 7, 5);
	solve(22, 7, 8);

	return 0;
}
