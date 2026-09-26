/*

Two integers a and b are given. Find a / b (integer division). Catch exception if b = 0. Use try-catch in your program.

Input
Each line contains two integers a and b.

Output
If b = 0, print message Division by zero. Otherwise print a / b.

Examples

Input #1
4 0
9 3
7 0
7 1
18 9

Answer #1
Division by zero
3
Division by zero
7
2

*/

#include <stdio.h>

void
solve(int a, int b)
{
	if (b == 0) {
		printf("Division by zero\n");
		return;
	}
	printf("%d\n", a / b);
}

int
main()
{
	solve(4, 0);
	solve(9, 3);
	solve(7, 0);
	solve(7, 1);
	solve(18, 9);

	return 0;
}
