/*

I challenge you to generate the following sequence till 100 terms through any programming language in shortest characters possible.
The sequence is like this :-

1 2 3 4 5 10 20 30 40 50 100 200 300 400 500 ........
The output needs to be like this (above) only, nothing extra.

Remember, You can use + and - only and for mathematical calculations only (++ and -- are also allowed) and no other mathematical function like tan(), log(), pow(), ......etc.

Also, You cannot use any character variables in your code.

*/

#include <stdio.h>

void
gen(int n, int m)
{
	int i, j, k;

	for (i = 0; i < n; i++) {
		for (j = 1; j < m; j++) {
			printf("%d", j);
			for (k = 0; k < i; k++)
				printf("0");
			printf("\n");
		}
	}
}

int
main(void)
{
	gen(20, 6);
	return 0;
}
