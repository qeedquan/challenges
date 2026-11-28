/*

Output/print this text:

0 1 2 3 4 5 6 7 8 9
35 36 37 38 39 40 41 42 43 10
34 63 64 65 66 67 68 69 44 11
33 62 83 84 85 86 87 70 45 12
32 61 82 95 96 97 88 71 46 13
31 60 81 94 99 98 89 72 47 14
30 59 80 93 92 91 90 73 48 15
29 58 79 78 77 76 75 74 49 16
28 57 56 55 54 53 52 51 50 17
27 26 25 24 23 22 21 20 19 18
Acceptable formats include:

Trailing whitespace/newlines
List of lines
List of characters of output, including newlines
Flattened 100-element array
2D array of integers
Padding the first column by a space in start or end
Not writing newlines
In array formats you could also output integers as stringified.

Not allowed:

Function gives number at (x,y)
This is code-golf. Shortest answer in bytes in each language wins. Standard loopholes apply.

*/

#include <stdio.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

void
output()
{
	int size;
	int row;
	int column;
	int distance;
	int base;
	int offset;

	size = 10;
	for (row = 0; row < size; row++) {
		for (column = 0; column < size; column++) {
			distance = min(row, column);
			distance = min(distance, size - row - 1);
			distance = min(distance, size - column - 1);
			base = distance * (38 - (4 * distance));
			if (column < row)
				offset = 36 - (4 * distance) - column - row;
			else
				offset = row + column;
			printf("%d ", base + offset);
		}
		printf("\n");
	}
}

int
main()
{
	output();
	return 0;
}
