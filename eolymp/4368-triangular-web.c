/*

In front of you is an infinite triangular grid. It is arranged so that if a vertex is set on fire, then at time 0 that vertex ignites,
after one second all vertices directly adjacent to it catch fire, then all vertices adjacent to the already burning ones, and so on.
Assume that the fire never goes out.

Initially, one vertex is burning. Determine the number of burning vertices after n seconds.

https://static.e-olymp.com/content/10/1028d5fad453d5ed0a658bdcca8d9b82420d222b.jpg

Input

One integer n (0≤n≤10^9).

Output
Print the number of burning vertices after n seconds.

Examples

Input #1
1

Answer #1
7

Input #2
1500

Answer #2
6754501

*/

#include <assert.h>

typedef long long vlong;

#define cube(x) ((x) * (x) * (x))

vlong
solve(vlong n)
{
	if (n < 0)
		return 0;

	return cube(n + 1) - cube(n);
}

int
main()
{
	assert(solve(1) == 7);
	assert(solve(1500) == 6754501);

	return 0;
}
