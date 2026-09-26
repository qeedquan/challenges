/*

Given two integers as input in an array, draw a rectangle, using the first integer as width and second as height.

Or, if your language supports it, the two integers can be given as separate inputs.

Assume the width and height will never be less than 3, and they will always be given.

Example Outputs:

[3, 3]

|-|
| |
|-|
[5, 8]

|---|
|   |
|   |
|   |
|   |
|   |
|   |
|---|
[10, 3]

|--------|
|        |
|--------|

This is code-golf, so the answer with the lowest amount of bytes wins.

*/

#include <cstdio>

void rectangle(int w, int h)
{
	for (auto y = 0; y < h; y++)
	{
		for (auto x = 0; x < w; x++)
		{
			if (x == 0 || x + 1 == w)
				printf("|");
			else if (y == 0 || y + 1 == h)
				printf("-");
			else
				printf(" ");
		}
		printf("\n");
	}
	printf("\n");
}

int main()
{
	rectangle(3, 3);
	rectangle(5, 8);
	rectangle(10, 3);

	return 0;
}
