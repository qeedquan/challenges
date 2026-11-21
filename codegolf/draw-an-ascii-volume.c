/*

Given a volume level V in the range 1-10. Your program should draw the following ASCII art.

When V=1:

\
 |
/
When V=2:

  \
\  |
 | |
/  |
  /
When V=3:

    \
  \  |
\  | |
 | | |
/  | |
  /  |
    /
And etc. Trailing spaces are allowed.

This is a code-golf challenge so the shortest solution wins.

*/

#include <stdio.h>
#include <stdlib.h>

void
repeat(const char *s, int n)
{
	int i;

	for (i = 0; i < n; i++)
		printf("%s", s);
}

void
volume(int n)
{
	int d, i;

	printf("n=%d\n", n);
	if (n < 1)
		return;

	for (i = -n; i <= n; i++) {
		d = abs(i);
		repeat(" ", 2 * (d - 1));
		if (i > 0)
			printf("/ ");
		else if (i < 0)
			printf("\\ ");
		repeat(" |", n - d);
		printf("\n");
	}
	printf("\n");
}

int
main()
{
	int i;

	for (i = 1; i <= 10; i++)
		volume(i);

	return 0;
}
