/*

One positive integer n is given. Print the strip with n symbols '#' as shown in the sample.

Input
One positive integer n.

Output
Print the strip with n symbols '#'.

Examples

Input #1
7

Answer #1
#######

*/

#include <stdio.h>

void
strip(int n)
{
	int i;

	for (i = 0; i < n; i++)
		printf("#");
	printf("\n");
}

int
main()
{
	strip(7);
	return 0;
}
