/*

I am trying to golf down some C++. Is it possible to make this condition shorter?

X > 3 & X - Y > 1

(Apart from removing whitespace, of course.)

So, X is at least 4 but X >= Y + 2.

X and Y are integers in the [0,5] interval.

I have tried to find some bitwise formula but failed.

*/

#include <stdio.h>

bool
cmp(int x, int y)
{
	return (x > 3) && (x - y > 1);
}

int
main(void)
{
	int x, y;

	for (x = 0; x <= 5; x++) {
		for (y = 0; y <= 5; y++) {
			if (cmp(x, y))
				printf("(%d, %d)\n", x, y);
		}
	}

	return 0;
}
