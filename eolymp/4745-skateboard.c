/*

Beginner skateboarder Den wants to ride his skateboard.
Unfortunately, the road he has chosen is far from even, and due to lack of experience,
Den cannot overcome hills — at the peak of each one, he inevitably falls and scrapes his knees.
Knowing this, his friend Kat sighs, brings an antiseptic with her, and tries to convince Den to put an end to these adventures for her sake,
since it's not hard to guess why he planned this walk ;) But stubborn Den refuses to give up and decides to ride the whole road.

Kat wonders how many times during this ill-fated outing she'll have to give Den first aid.

Input
The first line contains the number N — the number of road kinks (3 ≤ N ≤ 1000).

The next line contains N numbers a[i] (−1000 ≤ a[i] ≤ 1000),
which are the y-coordinates of the kinks from left to right.
The road between two neighboring kinks is a segment connecting them.
No two neighboring numbers are equal (a[1] < a[2], a[N-1] > a[N]).

Output
Output one number — the number of times Den falls.

Examples

Input #1
5
-1 2 7 1 0

Answer #1
1

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

size_t
solve(int *a, size_t n)
{
	size_t i, r;

	r = 0;
	for (i = 2; i < n; i++) {
		if (a[i] < a[i - 1] && a[i - 1] > a[i - 2])
			r++;
	}
	return r;
}

int
main()
{
	int a1[] = { -1, 2, 7, 1, 0 };

	assert(solve(a1, nelem(a1)) == 1);

	return 0;
}
