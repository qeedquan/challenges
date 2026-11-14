/*

List all three-digit numbers where each digit is unique and their sum equals m.

Input
A natural number m, 1≤m≤27.

Output
Display the numbers in ascending order on a single line. If no such numbers exist, output No.

Examples
Input #2
2

Answer #2
No

Input #1
3

Answer #1
102 120 201 210

*/

#include <stdio.h>

void
solve(int m)
{
	int f, i, j, k;

	f = 0;
	for (i = 1; i <= 9; i++) {
		for (j = 0; j <= 9; j++) {
			for (k = 0; k <= 9; k++) {
				if (i != j && j != k && i != k && i + j + k == m) {
					printf("%d%d%d ", i, j, k);
					f = 1;
				}
			}
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
