/*

Given a non-negative integer skyline height list, answer how many uninterrupted 1-unit-high horizontal brush strokes are needed to cover it.

[1,3,2,1,2,1,5,3,3,4,2], visualised as:

      5
      5  4
 3    5334
 32 2 53342
13212153342
needs nine brush strokes:

      1
      2  3
 4    5555
 66 7 88888
99999999999
Examples
[1,3,2,1,2,1,5,3,3,4,2] → 9

[5,8] → 8

[1,1,1,1] → 1

[] → 0

[0,0] → 0

[2] → 2

[2,0,2] → 4

[10,9,8,9] → 11

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define max(a, b) (((a) > (b)) ? (a) : (b))

/*

@Arnauld

How?
This is using the algorithm that was first found by @tsh. If you like this answer, make sure to upvote their answer as well!

Each time a skyscraper is lower than or as high as the previous one, it can be painted 'for free' by simply extending the brushstrokes.

For instance, painting skyscrapers B and C in the figure below costs nothing.
On the other hand, we need 2 new brushstrokes to paint skyscraper E, no matter if they're going to be reused after that or not.

[][]  --  ()
[][]  --  ()
[][][]--[][]
[][][]--[][]
[][][]--[][]
A B C   D E

For the first skyscraper, we always need as many brushstrokes as there are floors in it.

Turning this into maths:

S = h0 + Sum[1, n] (max(h[i] - h[i-1], 0))

If we prepend 0 to the list, this can be simplified to:

S = Sum[1, n] (max(h[i] - h[i-1], 0))

*/

int
brushstrokes(int *h, size_t n)
{
	size_t i;
	int r;

	if (n == 0)
		return 0;

	r = h[0];
	for (i = 1; i < n; i++)
		r += max(h[i] - h[i - 1], 0);
	return r;
}

void
test(int *h, size_t n, int r)
{
	int s;

	s = brushstrokes(h, n);
	printf("%d\n", s);
	assert(s == r);
}

int
main()
{
	int h1[] = {1, 3, 2, 1, 2, 1, 5, 3, 3, 4, 2};
	int h2[] = {5, 8};
	int h3[] = {1, 1, 1, 1};
	int h4[] = {0, 0};
	int h5[] = {2};
	int h6[] = {2, 0, 2};
	int h7[] = {10, 9, 8, 9};

	test(h1, nelem(h1), 9);
	test(h2, nelem(h2), 8);
	test(h3, nelem(h3), 1);
	test(NULL, 0, 0);
	test(h4, nelem(h4), 0);
	test(h5, nelem(h5), 2);
	test(h6, nelem(h6), 4);
	test(h7, nelem(h7), 11);

	return 0;
}
