/*

Here's a very simple little problem that I don't believe has been asked before.

Challenge
Write a program or a function that takes in four positive integers that represents the lengths of movable but unbreakable and unbendable straight fences. Output the area of the largest rectangular yard that can be fully encompassed with these fences.

The fences can be moved and rotated in increments of 90°, but can't overlap or be cut. Fences that just touch at a yard corner still count as encompassing the yard at that corner.

For example, given fence lengths 2, 8, 5, and 9, the best you can do is to make the 2 and 5 sides parallel, and the 8 and 9 sides parallel for a yard that is 2 by 8:

 888888885
2yyyyyyyy5
2yyyyyyyy5
9999999995
         5
Make any one side longer and the fences won't fully surround the yard. Thus the output here, the area of the yard, would be 16.

As another example, given 1, 1, 2, 2, the largest area yard that can be made is 2:

 22
1yy1
 22
A yard with area 1 like

22
1y1
 22
is a valid yard since it's perimeter is fully fenced, but 1 is an invalid output since it's not maximal.

This is code-golf so the shortest program wins!

You may not assume the 4 integer inputs to your program are in any particular order.

Here are some more test cases:

Inputs -> Output
1,1,1,1 -> 1
1,2,3,4 -> 3
4,3,2,1 -> 3
90,1,2,1 -> 2
1,90,1,1 -> 1
44,51,50,36 -> 1800
3,3,3,3 -> 9
3,3,3,4 -> 9
3,4,3,4 -> 12
4,4,3,4 -> 12
4,4,4,4 -> 16

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int
cmp(const void *a, const void *b)
{
	int x, y;

	x = *(int *)a;
	y = *(int *)b;
	if (x < y)
		return -1;
	if (x == y)
		return 0;
	return 1;
}

/*

@blaketyro

Unless I'm totally misunderstanding my own problem, I believe it can be solved by sorting the 4 input numbers and taking the smallest times the second biggest, since those sides will be matched parallel with the second smallest and the biggest respectively.

Like if the sorted inputs are a <= b <= c <= d then the biggest rect you can make will have area a * c, where side a is parallel to b and c parallel to d, and some of the b and d fences may have to be wasted.

*/

int
yardarea(int a, int b, int c, int d)
{
	int x[] = {a, b, c, d};

	qsort(x, 4, sizeof(*x), cmp);
	return x[0] * x[2];
}

int
main(void)
{
	assert(yardarea(1, 1, 1, 1) == 1);
	assert(yardarea(1, 2, 3, 4) == 3);
	assert(yardarea(4, 3, 2, 1) == 3);
	assert(yardarea(90, 1, 2, 1) == 2);
	assert(yardarea(1, 90, 1, 1) == 1);
	assert(yardarea(44, 51, 50, 36) == 1800);
	assert(yardarea(3, 3, 3, 3) == 9);
	assert(yardarea(3, 3, 3, 4) == 9);
	assert(yardarea(3, 4, 3, 4) == 12);
	assert(yardarea(4, 4, 3, 4) == 12);
	assert(yardarea(4, 4, 4, 4) == 16);

	return 0;
}
