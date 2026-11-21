/*

Your task is to output a spaceship of size n with shooters/guns and n bullets of character - (with spaces in between each bullet) for each gun

Rules
If n is odd, you must output the guns every even numbered row

If n is even, you must output the guns every odd numbered row

All rows with guns must have n+1 # characters

The spaceship is 3 characters tall for all inputs

n must be greater than 0

Testcases
1
->
#
## -
#

2
->
### - -
##
### - -

3
->
###
#### - - -
###
Trailing spaces are allowed

This is code-golf, so shortest code wins!

*/

#include <stdio.h>

void
pattern(int n)
{
	int i, j, k;

	printf("n=%d\n", n);
	for (i = 3; i > 0; i--) {
		k = (n + i) & 1;
		for (j = 0; j < n + k; j++)
			printf("#");
		for (j = 0; k && j < n; j++)
			printf(" -");
		printf("\n");
	}
	printf("\n");
}

int
main()
{
	int i;

	for (i = 1; i <= 5; i++)
		pattern(i);

	return 0;
}
