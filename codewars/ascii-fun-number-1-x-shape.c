/*

You will get an odd integer n (>= 3) and your task is to draw an X. Each line is separated with \n.

Use the following characters: ■ □ For Ruby, Crystal and PHP: whitespace and o

Examples

                                     ■□□□■
            ■□■                      □■□■□
  x(3) =>   □■□             x(5) =>  □□■□□
            ■□■                      □■□■□
                                     ■□□□■

*/

#include <stdio.h>

void
xshape(int n)
{
	int x, y;

	printf("n=%d\n", n);
	for (y = 0; y < n; y++) {
		for (x = 0; x < n; x++) {
			if (x == y || y == n - x - 1)
				printf("%s", u8"■");
			else
				printf("%s", u8"□");
		}
		printf("\n");
	}
	printf("\n");
}

int
main()
{
	xshape(3);
	xshape(5);
	return 0;
}
