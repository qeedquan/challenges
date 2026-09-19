/*

Given the input tilesX and tilesY create a method that would make a rectangular ring from the tiles.

The function must order the tiles in a ring like this:

https://i.sstatic.net/Be2zp.jpg

tilesX and tilesY are always positive integer values, cannot be 0
tilesX and tilesY are not always equal, expect values like: 2x5, 6x3 etc.
Checking for invalid input is not necessary
You can use any way to display the tiles, including 2d arrays, ASCII art or printed text.
There's no strict way how the input is passed as long as it's two integers.
Cannot be a line, drawing a rectangle size of tilesX and tilesY pixels is not valid
The shortest code wins

*/

#include <stdio.h>

/*

@Alex A.

We construct an n × m matrix using an array comprehension with a double for loop.
For each index from 1 to n and 1 to m, i.e. each element of the matrix, we set the value to true if n > i > 1 and 1 < j < m.
This is true everywhere but the boundaries, so the resulting array will have trues in the middle and falses around the border.

*/

void
f(int n, int m)
{
	int i, j;

	printf("%dx%d\n", n, m);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			if (n > i && i > 1 && 1 < j && j < m)
				printf("%s", u8"▢");
			else
				printf("%s", u8"▣");
		}
		printf("\n");
	}
	printf("\n");
}

int
main()
{
	int i;

	for (i = 1; i <= 32; i <<= 1)
		f(i, i);
	return 0;
}
