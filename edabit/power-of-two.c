/*

Write a function that returns true if an integer is a power of 2, and false otherwise.

*/

#include <stdio.h>

int
ispow2(int n)
{
	return n > 0 && !(n & (n - 1));
}

int
main(void)
{
	printf("%d\n", ispow2(32));
	printf("%d\n", ispow2(1));
	printf("%d\n", ispow2(-7));
	printf("%d\n", ispow2(18));
	for (int i = 0; i <= (1 << 25); i++) {
		if (ispow2(i))
			printf("%d\n", i);
	}
	return 0;
}
