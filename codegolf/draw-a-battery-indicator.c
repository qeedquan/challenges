/*

Given the battery level L in the range 0-5, your code should draw the following ASCII art.

When L=0:

############
#          ###
#          ###
#          ###
############
When L=1:

############
###        ###
###        ###
###        ###
############
When L=2:

############
#####      ###
#####      ###
#####      ###
############
And etc. You can change the character # to any other (except space), it's up to you. Trailing spaces are allowed.

This is a code-golf challenge so the shortest solution wins.

*/

#include <stdio.h>

void
indicator(int n)
{
	int i, j;

	if (n < 0)
		n = 0;
	else if (n > 5)
		n = 5;

	printf("L=%d\n", n);
	puts("############");
	for (i = 0; i < 3; i++) {
		printf("#");
		for (j = 0; j < n; j++)
			printf("##");
		for (; j < 5; j++)
			printf("  ");
		printf("###\n");
	}
	puts("############");
	puts("");
}

int
main(void)
{
	int i;

	for (i = 0; i <= 5; i++)
		indicator(i);

	return 0;
}
