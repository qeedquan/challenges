/*

Description

What do you do if you need to copy a 560x400mm image onto a standard sheet of US letter-size paper (which is about 216x280mm), while keeping the image as large as possible? You can rotate the image 90 degrees (so that it is in "landscape" mode), then reduce it to 50% of its original size so that it is 200x280mm. Then it will fit on the paper without overlapping any edges. Your job is to solve this problem in general.

Input

The input consists of one or more test cases, each of which is a single line containing four positive integers A, B, C, and D, separated by a space, representing an AxBmm image and a CxDmm piece of paper. All inputs will be less than one thousand. Following the test cases is a line containing four zeros that signals the end of the input.

Output

For each test case, if the image fits on the sheet of paper without changing its size (but rotating it if necessary), then the output is 100%. If the image must be reduced in order to fit, the output is the largest integer percentage of its original size that will fit (rotating it if necessary). Output the percentage exactly as shown in the examples below. You can assume that no image will need to be reduced to less than 1% of its original size, so the answer will always be an integer percentage between 1% and 100%, inclusive.

Sample Input

560 400 218 280
10 25 88 10
8 13 5 1
9 13 10 6
199 333 40 2
75 90 218 280
999 99 1 10
0 0 0 0

Sample Output

50%
100%
12%
66%
1%
100%
1%

Source

Mid-Central USA 2005

*/

#include <assert.h>
#include <stdio.h>

void
swap(int *x, int *y)
{
	int t;

	t = *x;
	*x = *y;
	*y = t;
}

int
scaleratio(int w1, int h1, int w2, int h2)
{
	double r1, r2;
	double w3, h3;

	if (w1 < h1)
		swap(&w1, &h1);
	if (w2 < h2)
		swap(&w2, &h2);

	r1 = (w1 * 1.0) / h1;
	r2 = (w2 * 1.0) / h2;
	if (w2 >= w1 && h2 >= h1)
		return 100;

	if (r1 >= r2) {
		w3 = w2;
		h3 = (w3 * 1.0) / r1;
	} else {
		h3 = h2;
		w3 = h3 * r1;
	}
	return (w3 * 100) / w1;
}

void
test(int w1, int h1, int w2, int h2, int r)
{
	int v;

	v = scaleratio(w1, h1, w2, h2);
	printf("%d\n", v);
	assert(v == r);
}

int
main(void)
{
	test(560, 400, 218, 280, 50);
	test(10, 25, 88, 10, 100);
	test(8, 13, 5, 1, 12);
	test(9, 13, 10, 6, 66);
	test(199, 333, 40, 2, 1);
	test(75, 90, 218, 280, 100);
	test(999, 99, 1, 10, 1);

	return 0;
}
