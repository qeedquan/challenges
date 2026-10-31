/*

Your task: make a hexagonal triangle with side length n, where n is a positive whole number or 0.

First, let me define a hexagon:

 / \
|   |
 \ /
(Amazing ASCII art, right?)

Hexagons can be linked together by sharing sides:

 / \ / \
|   |   |
 \ / \ /

   / \
  |   |
 / \ /
|   |
 \ /
A hexagonal triangle is the following:

   / \
  |   |
 / \ / \
|   |   |
 \ / \ /
That hexagonal triangle has a side length of 2-- 2 hexagons are required to make one side. A hexagonal triangle with side-length 1 is just a single hexagon, and a hexagon with side-length 0 is empty.

More formally, a hexagonal triangle is a triangle made of hexagons linked by their sides. The top hexagon links to the two below it on its bottom two sides. The triangle in the bottom left links to the one to its right and top-right, and the one in the bottom right links to the ones on its left and upper left. There are hexagons in between the corner ones, connected by their opposite sides, and their number is n-2. The triangles are not filled.

More examples:

Side length 3:
     / \
    |   |
   / \ / \
  |   |   |
 / \ / \ / \
|   |   |   |
 \ / \ / \ /

Side length 4:
       / \
      |   |
     / \ / \
    |   |   |
   / \ / \ / \
  |   |   |   |
 / \ / \ / \ / \
|   |   |   |   |
 \ / \ / \ / \ /
(This triangle isn't really filled, the borders make it look like there is a hexagon in the middle, but there is not.)

Side length 5:
         / \
        |   |
       / \ / \
      |   |   |
     / \ / \ / \
    |   |   |   |
   / \ /     \ / \
  |   |       |   |
 / \ / \ / \ / \ / \
|   |   |   |   |   |
 \ / \ / \ / \ / \ /

Side length 6:
           / \
          |   |
         / \ / \
        |   |   |
       / \ / \ / \
      |   |   |   |
     / \ /     \ / \
    |   |       |   |
   / \ /         \ / \
  |   |           |   |
 / \ / \ / \ / \ / \ / \
|   |   |   |   |   |   |
 \ / \ / \ / \ / \ / \ /

*/

#include <stdio.h>

/*

@Arnauld

How it works
In the outer loop, y iterates from n*2-1 to -1. In the inner loop, x iterates from n*4-1 to -1. We set k = (x+y) & 3, which is the underlying pattern that is used to generate the hexagons.

Below is the resulting grid for n = 4:

     15 14 13 12 11 10  9  8  7  6  5  4  3  2  1  0 -1
   +---------------------------------------------------
 7 |  2  1  0  3  2  1  0  3  2  1  0  3  2  1  0  3  2
 6 |  1  0  3  2  1  0  3  2  1  0  3  2  1  0  3  2  1
 5 |  0  3  2  1  0  3  2  1  0  3  2  1  0  3  2  1  0
 4 |  3  2  1  0  3  2  1  0  3  2  1  0  3  2  1  0  3
 3 |  2  1  0  3  2  1  0  3  2  1  0  3  2  1  0  3  2
 2 |  1  0  3  2  1  0  3  2  1  0  3  2  1  0  3  2  1
 1 |  0  3  2  1  0  3  2  1  0  3  2  1  0  3  2  1  0
 0 |  3  2  1  0  3  2  1  0  3  2  1  0  3  2  1  0  3
-1 |  2  1  0  3  2  1  0  3  2  1  0  3  2  1  0  3  2
On even rows, a cell is filled with a pipe character when k = 3, and a space otherwise. The pipe is the 5th character in our reference string " \ /|", so the correct index is given by (k+1) & 4.

On odd rows, each cell is filled directly with the corresponding character in the reference string:

k = 0 → space
k = 1 → "\"
k = 2 → space
k = 3 → "/"
Below is our updated example (spaces replaced with dots):

     15 14 13 12 11 10  9  8  7  6  5  4  3  2  1  0 -1
   +---------------------------------------------------
 7 |  .  \  .  /  .  \  .  /  .  \  .  /  .  \  .  /  .
 6 |  .  .  |  .  .  .  |  .  .  .  |  .  .  .  |  .  .
 5 |  .  /  .  \  .  /  .  \  .  /  .  \  .  /  .  \  .
 4 |  |  .  .  .  |  .  .  .  |  .  .  .  |  .  .  .  |
 3 |  .  \  .  /  .  \  .  /  .  \  .  /  .  \  .  /  .
 2 |  .  .  |  .  .  .  |  .  .  .  |  .  .  .  |  .  .
 1 |  .  /  .  \  .  /  .  \  .  /  .  \  .  /  .  \  .
 0 |  |  .  .  .  |  .  .  .  |  .  .  .  |  .  .  .  |
-1 |  .  \  .  /  .  \  .  /  .  \  .  /  .  \  .  /  .
In the following formulas, we define N = n*4 for readability (although the same variable is used in the code).

The triangle shape is obtained by testing:

x > y - 2 → removes the right corner
AND x < N - y → removes the left corner
And the inner part is removed by testing:

x > N - y - 6 → keeps only the left edge
OR x < y + 4 → keeps only the right edge
OR y < 2 → keeps only the bottom edge

*/

void
draw(int n)
{
	int c, k, x, y, N;

	printf("n=%d\n", n);
	N = n * 4;
	for (y = (n * 2) - 1; y >= -1; y--) {
		for (x = N - 1; x >= -1; x--) {
			k = (x + y) & 3;
			c = ' ';
			if (y % 2 == 0) {
				if (k == 3)
					c = '|';
			} else {
				if (k == 1)
					c = '\\';
				else if (k == 3)
					c = '/';
			}

			if (!(x > y - 2 && x < N - y))
				c = ' ';
			if (!(x > N - y - 6 || x < y + 4 || y < 2))
				c = ' ';

			printf("%c", c);
		}
		printf("\n");
	}
	printf("\n");
}

int
main()
{
	int i;

	for (i = 3; i <= 7; i++)
		draw(i);
	return 0;
}
