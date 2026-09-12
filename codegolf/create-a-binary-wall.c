/*

Given an array of positive integers in base 10, where n > 0, output their representation of a binary wall.

How does this work?

Convert each number to it's binary representation.
Pad the representation with leading zeroes to the length of the longest one i.e. 1, 2 -> 1, 10 -> 01, 10.
Create a wall where the 1s are bricks and 0s are missing bricks.
A wall is a block of characters where any printable character represents a brick and a space (32) represents a missing brick. You may choose any character for the brick, it need not be distinct across the wall as long as it isn't a white space character. The missing brick character must be a space. For the example below I have used * for the bricks.

Example

Input:

[ 15, 7, 13, 11 ]
[ 1111, 111, 1101, 1011 ]
[ 1111, 0111, 1101, 1011 ]
Output:

****
 ***
** *
* **
Rules

Input must be taken in base 10, if your language accepts other bases you may not use them.
Leading and trailing new lines are allowed.
Input may be taken as a list of integers, separate arguments or any reasonable format.
Output may be in any reasonable format: new line separated string, array of lines, 2d array etc.
Standard loopholes are disallowed.

Test Cases

Note that in the first test case all of layers have an empty brick at the end.

[ 14, 4, 6, 2 ]

***
 *
 **
  *

[ 1, 2, 4, 8, 16 ]

    *
   *
  *
 *
*

[ 15, 11, 15, 15 ]

****
* **
****
****

[ 11, 10, 9, 8 ]

* **
* *
*  *
*

This is code golf so shortest code wins!

*/

#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define max(a, b) (((a) > (b)) ? (a) : (b))

unsigned
ispow2(unsigned n)
{
	return n > 0 && !(n & (n - 1));
}

void
binwall(unsigned *a, size_t n)
{
	unsigned j, l;
	size_t i;

	for (i = l = 0; i < n; i++)
		l = max(l, a[i]);

	if (l)
		l = ceil(log2(l)) + ispow2(l);

	for (i = 0; i < n; i++) {
		for (j = 0; j < l; j++) {
			if (a[i] & (1u << (l - j - 1)))
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
	printf("\n");
}

int
main(void)
{
	unsigned a1[] = { 14, 4, 6, 2 };
	unsigned a2[] = { 1, 2, 4, 8, 16 };
	unsigned a3[] = { 15, 11, 15, 15 };
	unsigned a4[] = { 11, 10, 9, 8 };

	binwall(a1, nelem(a1));
	binwall(a2, nelem(a2));
	binwall(a3, nelem(a3));
	binwall(a4, nelem(a4));

	return 0;
}
