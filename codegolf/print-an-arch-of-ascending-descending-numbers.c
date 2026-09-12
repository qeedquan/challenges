/*

I figured an "arch" was the best way to describe this pattern of numbers:

1234567887654321
1234567  7654321
123456    654321
12345      54321
1234        4321
123          321
12            21
1              1
Formally defined, each line consists of the numbers 1 through 9-n, (n-1)*2 spaces, and the numbers 9-n through 1 (where n is the current line).

Your task is to write, using the shortest code possible, a small script/program that prints the above pattern subject to the following restrictions:

You may not hardcode the entire pattern. You may only hardcode a single line of the pattern at most.
Your program must print a newline (any combination of \n or \r) at the end of each line.
Ready... set.... go!

*/

#include <stdio.h>

void
arch(int n)
{
	int i, j;

	for (i = 0; i <= n; i++) {
		for (j = 1; j <= n - i; j++)
			printf("%d", j);
		for (j = 0; j < i; j++)
			printf("  ");
		for (j = n - i; j >= 1; j--)
			printf("%d", j);
		printf("\n");
	}
}

int
main(void)
{
	int i;

	for (i = 0; i < 10; i++)
		arch(i);

	return 0;
}
