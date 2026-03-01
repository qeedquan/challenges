/*

Task:

I know we can all add two numbers the short way, using +. Your task is to create the longest code you can to add two input numbers.

Rules:

All of the code must be on topic (don't fill it with non-addition code to add length)
The count is in characters, but do not count tabs, spaces, or newlines.
Do not use extraneously long variable names
This is code-bowling, so the longest answer wins!

*/

#include <stdio.h>
#include <limits.h>

void
gen(int n, int m)
{
	int x, y;

	printf("int add(int x, int y)\n{\n");
	for (x = n; x < m; x++) {
		for (y = n; y < m; y++) {
			printf("\tif (x == %d && y == %d) return %d;\n", x, y, x + y);
		}
	}
	printf("}\n");
}

int
main(void)
{
	gen(INT_MIN, INT_MAX);
	return 0;
}
