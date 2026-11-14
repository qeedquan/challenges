/*

Write a function that contains five lines.

If you run the function as-is, it should return 0.

If you remove any one of the five lines and run the function, it should tell you which of the lines has been removed (e.g., if you remove the final line it should return 5).

Brevity, novelty, and elegance all deserve consideration. Highest upvoted solution (after a reasonable amount of time) wins.

*/

#include <stdio.h>

void
f(int *r)
{
	*r -= 1;
	*r -= 2;
	*r -= 3;
	*r -= 4;
	*r -= 5;
}

int
main(void)
{
	int r;

	r = 15;
	f(&r);
	printf("%d\n", r);
	return 0;
}
