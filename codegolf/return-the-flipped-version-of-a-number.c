/*

When a number is shown on a calculator, it's possible to consider what various transformations of that number would look like. For example, on a seven-segment display, 2 is shown like this:

https://i.sstatic.net/QZZ8w.png

And when flipped horizontally it looks like this:

https://i.sstatic.net/YA69d.png

As such, the mirror image of 2 is 5.

The task in this challenge is to take a single-digit number, and return the number that's its mirror image (if possible).
If its mirror image does not look like a number, return the number rotated 180 degrees (if possible). If neither of these are the case, return -1.

Here's the full list of inputs and outputs your program needs to handle:

Input   Output
0       0
1       -1
2       5
3       -1
4       -1
5       2
6       9
7       -1
8       8
9       6

As a code-golf challenge, the shortest code wins!

*/

#include <assert.h>

int
flip(int n)
{
	static const int tab[] = {0, -1, 5, -1, -1, 2, 9, -1, 8, 6};

	if (n < 0 || n > 9)
		return -1;
	return tab[n];
}

int
main()
{
	assert(flip(0) == 0);
	assert(flip(1) == -1);
	assert(flip(2) == 5);
	assert(flip(3) == -1);
	assert(flip(4) == -1);
	assert(flip(5) == 2);
	assert(flip(6) == 9);
	assert(flip(7) == -1);
	assert(flip(8) == 8);
	assert(flip(9) == 6);

	return 0;
}
