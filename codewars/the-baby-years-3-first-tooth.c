/*

Baby is getting his frst tooth. This means more sleepless nights, but with the fun of feeling round his gums and trying to guess which will be first out!

Probably best have a sweepstake with your friends - because you have the best chance of knowing. You can feel the gums and see where the raised bits are - most raised, most likely tooth to come through first!

Given an array of numbers (t) to represent baby's gums, you need to return the index of the lump that is most pronounced.

The most pronounced lump is the one that has the biggest differential to its surrounding values. e.g.:

[1, 2, 4] = 2

index 0 has a differential of -1 to its right (it is lower so the figure is negative)

index 1 has a differential of +1 to its left, and -2 to its right. Total is -1.

index 2 has a differential of +2 to its left, and nothing to its right,

If there is no distinct highest value (more than one occurence of the largest differential), return -1.

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

ssize_t
firsttooth(int *t, size_t n)
{
	int d, m, p;
	size_t i;

	m = INT_MIN;
	p = -1;
	for (i = 0; i < n; i++) {
		d = 0;
		if (i > 0)
			d += t[i] - t[i - 1];
		if (i + 1 < n)
			d += t[i] - t[i + 1];

		if (d > m) {
			m = d;
			p = i;
		} else if (d == m)
			p = -1;
	}
	return p;
}

int
main()
{
	int t1[] = { 1, 2, 3, 4 };
	int t2[] = { 1, 2, 6, 4 };
	int t3[] = { 1, 2, 5, 7, 1, 0, 9 };
	int t4[] = { 9, 2, 8, 1 };
	int t5[] = { 1, 1, 1, 1 };
	int t6[] = { 20, 9, 16, 19 };
	int t7[] = { 15 };

	assert(firsttooth(t1, nelem(t1)) == 3);
	assert(firsttooth(t2, nelem(t2)) == 2);
	assert(firsttooth(t3, nelem(t3)) == 6);
	assert(firsttooth(t4, nelem(t4)) == 2);
	assert(firsttooth(t5, nelem(t5)) == -1);
	assert(firsttooth(t6, nelem(t6)) == 0);
	assert(firsttooth(t7, nelem(t7)) == 0);

	return 0;
}
