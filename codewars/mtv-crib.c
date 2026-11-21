/*

Task
Given n representing the number of floors build a beautiful multi-million dollar mansions like the ones in the example below:

     /\
    /  \
   /    \
  /______\  number of floors 3
  |      |
  |      |
  |______|

     /\
    /  \
   /____\
   |    |   2 floors
   |____|

     /\
    /__\    1 floor
    |__|
Note: whitespace should be preserved on both sides of the roof. Number of floors will go up to 30. There will be no tests with invalid input.

Good luck!

*/

#include <stdio.h>

void
repeat(const char *s, int n)
{
	int i;

	for (i = 0; i < n; i++)
		printf("%s", s);
}

void
crib(int n)
{
	int i;

	printf("n=%d\n", n);
	if (n < 1)
		return;

	for (i = 0; i < n; i++) {
		repeat(" ", n - i);
		printf("/");
		repeat(" ", i * 2);
		printf("\\");
		repeat(" ", n - 1);
		printf("\n");
	}

	printf("/");
	repeat("_", n * 2);
	printf("\\\n");

	for (i = 0; i < n - 1; i++) {
		printf("|");
		repeat(" ", n * 2);
		printf("|\n");
	}

	printf("|");
	repeat("_", n * 2);
	printf("|\n");
	printf("\n");
}

int
main()
{
	int i;

	for (i = 1; i <= 4; i++)
		crib(i);
	return 0;
}
