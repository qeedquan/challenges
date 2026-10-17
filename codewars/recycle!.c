/*

You are having a BBQ, after the BBQ you are left with the rubbish. You have 3 recycling boxes:

Red: Plastics, Green: Glass, Blue: Card.

You will need to sort the rubbish according to the material and return the number of items in each box in the form of an array i.e [2,3,4] where 2 is the number of plastic items, 3 is the number of glass items and 4 is the number of card items. assume:

Plastics > 0, Glass < 0, Card = 0

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
recycle(int *a, size_t n, int b[3])
{
	size_t i;

	b[0] = b[1] = b[2] = 0;
	for (i = 0; i < n; i++) {
		if (a[i] > 0)
			b[0]++;
		else if (a[i] < 0)
			b[1]++;
		else
			b[2]++;
	}
}

void
test(int *a, size_t n, int r[3])
{
	int b[3];

	recycle(a, n, b);
	printf("%d %d %d\n", b[0], b[1], b[2]);
	assert(!memcmp(b, r, sizeof(b)));
}

int
main()
{
	int a1[] = { 5, -9, 0, 6, -84, -95, 15 };
	int a2[] = { 45, -26, -4, -66, -84, -38, 14 };

	int r1[] = { 3, 3, 1 };
	int r2[] = { 2, 5, 0 };

	test(a1, nelem(a1), r1);
	test(a2, nelem(a2), r2);

	return 0;
}
