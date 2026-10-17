/*

Easy; Make a box
Given a number as a parameter (between 2 and 30), return an array containing strings which form a box.

Like this:

n = 5

[
  '-----',
  '-   -',
  '-   -',
  '-   -',
  '-----'
]
n = 3

[
  '---',
  '- -',
  '---'
]

*/

#include <stdio.h>

void
box(int n)
{
	int i, j;

	printf("n=%d\n", n);
	if (n < 2)
		return;

	for (i = 0; i < n; i++)
		printf("-");
	printf("\n");

	for (i = 0; i < n - 2; i++) {
		printf("-");
		for (j = 0; j < n - 2; j++)
			printf(" ");
		printf("-\n");
	}

	for (i = 0; i < n; i++)
		printf("-");
	printf("\n\n");
}

int
main()
{
	int i;

	for (i = 2; i <= 10; i++)
		box(i);
	return 0;
}
