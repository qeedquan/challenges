/*

(Based on this closed challenge, related)

Given an integer n > 1, draw a grid composed of the characters: "-" "+" and "|". However, since I want the grid to look nice, the horizontal component should be 2 wide.

Trailing spaces for each line are not required.

Examples:
n = 2

  |
--+--
  |
n = 3

  |  |
--+--+--
  |  |
--+--+--
  |  |

This is code-golf, so the shortest answer in bytes wins!

*/

#include <stdio.h>

void
asciigrid(int n)
{
	static const char sym[] = "-+ |";

	int i, x, y, w, h;

	w = (3 * n) - 1;
	h = (2 * n) - 1;

	printf("n=%d\n", n);
	for (y = 1; y <= h; y++) {
		for (x = 1; x <= w; x++) {
			i = ((y & 1) << 1) | !(x % 3);
			printf("%c", sym[i]);
		}
		printf("\n");
	}
	printf("\n");
}

int
main(void)
{
	int i;

	for (i = 2; i <= 10; i++)
		asciigrid(i);

	return 0;
}
