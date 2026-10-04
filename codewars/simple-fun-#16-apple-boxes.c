/*

Task
There're k square apple boxes full of apples. If a box is of size m, then it contains m × m apples. You noticed two interesting properties about the boxes:

The smallest box is of size 1,
the next one is of size 2,...,
all the way up to size k.

Boxes that have an odd size contain only yellow apples.
Boxes that have an even size contain only red apples.

Your task is to calculate the difference between the number of red apples and the number of yellow apples.

Example
For k = 5, the output should be -15

There are 1 + 3 × 3 + 5 × 5 = 35 yellow apples and 2 × 2 + 4 × 4 = 20 red apples, thus the answer is 20 - 35 = -15.

Input/Output
[input] integer k

A positive integer.

Constraints: 1 ≤ k ≤ 40

[output] an integer

The difference between the two types of apples.

*/

#include <assert.h>
#include <stdio.h>

int
triangular(int n)
{
	return n * (n + 1) / 2;
}

int
appleboxesbf(int n)
{
	int i, x, y;

	x = y = 0;
	for (i = 1; i <= n; i++) {
		if (!(i & 1))
			x += i * i;
		else
			y += i * i;
	}
	return x - y;
}

int
appleboxes(int n)
{
	int r;

	r = triangular(n);
	if (n & 1)
		r = -r;
	return r;
}

int
main()
{
	int i;

	assert(appleboxes(5) == -15);
	assert(appleboxes(15) == -120);
	assert(appleboxes(36) == 666);
	assert(appleboxes(1) == -1);

	for (i = 0; i <= 1000; i++)
		assert(appleboxes(i) == appleboxesbf(i));

	return 0;
}
