/*

Specification
Write the shortest possible code in any language that does the following:

It takes two arguments, x and y, and generates x + y lines of text.

The first x lines should consist of y nested pairs of square brackets separated by a space surrounding a single digit, which cycles from 1 to 9, then 0 to 9, etc. from line to line.
The following y lines have the letter X in place of the digit and successively replace the innermost remaining pair of square brackets with spaces. The last line only contains the X, surrounded by spaces.

All output is ASCII.
You may choose to output a final newline (following a space), but you may also choose not to.
You may use either CR, CRLF, or LF as newline sequences.
The last line must contain an appropriate number of spaces following the central X.

The only valid inputs are positive integers. Zero is not a valid input.
You’re free to impose a reasonable, technically-driven limit on input size, even if the problem is solvable without. For instance, if there’s some function available for 16 bit integers that isn’t for bigints for some reason, and using it makes your program shorter, that’s a valid reason for a input size constraint.
Your code may reject invalid input or simply behave in any way on invalid input.

Examples
Example with x = 12, y = 8:

[ [ [ [ [ [ [ [ 1 ] ] ] ] ] ] ] ]
[ [ [ [ [ [ [ [ 2 ] ] ] ] ] ] ] ]
[ [ [ [ [ [ [ [ 3 ] ] ] ] ] ] ] ]
[ [ [ [ [ [ [ [ 4 ] ] ] ] ] ] ] ]
[ [ [ [ [ [ [ [ 5 ] ] ] ] ] ] ] ]
[ [ [ [ [ [ [ [ 6 ] ] ] ] ] ] ] ]
[ [ [ [ [ [ [ [ 7 ] ] ] ] ] ] ] ]
[ [ [ [ [ [ [ [ 8 ] ] ] ] ] ] ] ]
[ [ [ [ [ [ [ [ 9 ] ] ] ] ] ] ] ]
[ [ [ [ [ [ [ [ 0 ] ] ] ] ] ] ] ]
[ [ [ [ [ [ [ [ 1 ] ] ] ] ] ] ] ]
[ [ [ [ [ [ [ [ 2 ] ] ] ] ] ] ] ]
[ [ [ [ [ [ [   X   ] ] ] ] ] ] ]
[ [ [ [ [ [     X     ] ] ] ] ] ]
[ [ [ [ [       X       ] ] ] ] ]
[ [ [ [         X         ] ] ] ]
[ [ [           X           ] ] ]
[ [             X             ] ]
[               X               ]
                X
Example with x = 5, y = 1

[ 1 ]
[ 2 ]
[ 3 ]
[ 4 ]
[ 5 ]
  X
Example with x = 1, y = 10:

[ [ [ [ [ [ [ [ [ [ 1 ] ] ] ] ] ] ] ] ] ]
[ [ [ [ [ [ [ [ [   X   ] ] ] ] ] ] ] ] ]
[ [ [ [ [ [ [ [     X     ] ] ] ] ] ] ] ]
[ [ [ [ [ [ [       X       ] ] ] ] ] ] ]
[ [ [ [ [ [         X         ] ] ] ] ] ]
[ [ [ [ [           X           ] ] ] ] ]
[ [ [ [             X             ] ] ] ]
[ [ [               X               ] ] ]
[ [                 X                 ] ]
[                   X                   ]
                    X

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
brackets(int x, int y)
{
	int i, j;

	printf("x=%d y=%d\n", x, y);
	i = 0;
	j = 1;
	while (y > 0) {
		i += 1;
		if (i > x)
			y -= 1;
		repeat("[ ", y);
		if (i <= x)
			printf("%d", i % 10);
		else {
			repeat(" ", i - x + j);
			printf("X");
			repeat(" ", i - x + j);
			j += 1;
		}
		repeat(" ]", y);
		printf("\n");
	}
	printf("\n");
}

int
main()
{
	brackets(12, 8);
	brackets(5, 1);
	brackets(1, 10);

	return 0;
}
