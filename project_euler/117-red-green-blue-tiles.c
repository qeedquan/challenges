/*

Using a combination of grey square tiles and oblong tiles chosen from: red tiles (measuring two units), green tiles (measuring three units), and blue tiles (measuring four units), it is possible to tile a row measuring five units in length in exactly fifteen different ways.

https://projecteuler.net/resources/images/0117.png?1678992052

How many ways can a row measuring fifty units in length be tiled?

NOTE: This is related to Problem 116.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef long long vlong;

#define max(a, b) (((a) > (b)) ? (a) : (b))

vlong
sumto(vlong *a, vlong i, vlong j)
{
	vlong r;

	for (r = 0; i < j; i++)
		r += a[i];
	return r;
}

vlong
solve(vlong n)
{
	vlong i, r, *w;

	if (n < 0)
		return 0;

	w = calloc(n + 1, sizeof(*w));
	if (!w)
		return -1;

	w[0] = 1;
	for (i = 1; i <= n; i++)
		w[i] = sumto(w, max(i - 4, 0), i);

	r = w[n];
	free(w);
	return r;
}

int
main(void)
{
	assert(solve(5) == 15);
	printf("%lld\n", solve(50));

	return 0;
}
