/*

Given a positive integer N, output a grid with area N and height and width dimensions as close together as possible, so as for the output to be an almost-square.

The output can be a 2d array of characters/numbers/etc. or be a single string of characters separated by newlines. You may use any value for the elements of the grid but every element should have that same value. The value doesn't need to be consistent for different inputs.

The order of the ranks in your output does not matter; the width and height may be swapped arbitrarily.

Here are some examples of almost-squares for various areas:

1
O

24
OOOOOO
OOOOOO
OOOOOO
OOOOOO

8
OOOO
OOOO

17
OOOOOOOOOOOOOOOOO

30
OOOOOO
OOOOOO
OOOOOO
OOOOOO
OOOOOO

40
OOOOOOOO
OOOOOOOO
OOOOOOOO
OOOOOOOO
OOOOOOOO

49
OOOOOOO
OOOOOOO
OOOOOOO
OOOOOOO
OOOOOOO
OOOOOOO
OOOOOOO
This is a modified version of an older challenge which was closed because it included some unclear bonuses.

For brownie points, see if you can beat or match my 15 bytes of Uiua (or 16 with no experimental functions).

*/

#include <stdio.h>
#include <math.h>

void
draw(int n)
{
	int i;

	printf("n=%d\n", n);
	if (n < 1) {
		puts("");
		return;
	}

	i = sqrt(n);
	while (n % i)
		i--;

	for (n /= i; i > 0; i--)
		printf("%0*d\n", n, 0);
	puts("");
}

int
main()
{
	draw(1);
	draw(24);
	draw(8);
	draw(17);
	draw(30);
	draw(40);
	draw(49);

	return 0;
}
