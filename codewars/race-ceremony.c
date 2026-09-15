/*

The national go-kart racing competition is taking place at your local town and you've been called for building the winners podium with the available wooden blocks. Thankfully you are in a wood-rich area, number of blocks are always at least 6.

Remember a classic racing podium has three platforms for first, second and third place. First place is the highest and second place is higher than third. Also notice that platforms are arranged as 2nd - 1st - 3rd.

The organizers want a podium that satisfies:

The first place platform has the minimum height possible
The second place platform has the closest height to first place
All platforms have heights greater than zero.

Task
Given the numbers of blocks available, return an array / tuple or another data structure depending on the language (refer sample tests) with the heights of 2nd, 1st, 3rd places platforms.

Examples (input -> output)
11 ->   [4, 5, 2]
6  ->   [2, 3, 1]
10 ->   [4, 5, 1]

*/

#include <assert.h>
#include <string.h>
#include <math.h>

void
racepodium(int n, int r[3])
{
	int p1, p2, p3;

	p1 = ceil(n / 3.0) + 1;
	p2 = p1 - 1;
	p3 = n - p1 - p2;

	r[0] = p2;
	r[1] = p1;
	r[2] = p3;
	if (!p3) {
		r[0] -= 1;
		r[2] = 1;
	}
}

void
test(int n, int r[3])
{
	int p[3];

	racepodium(n, p);
	assert(!memcmp(p, r, sizeof(p)));
}

int
main()
{
	int r1[] = { 4, 5, 2 };
	int r2[] = { 2, 3, 1 };
	int r3[] = { 4, 5, 1 };

	test(11, r1);
	test(6, r2);
	test(10, r3);

	return 0;
}
