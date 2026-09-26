/*

Once upon a time, the inhabitants of Earth discovered a new inhabited planet and named it TTV.
They sent one rabbit to this planet by spaceship.
The rabbit liked the climate and, after a month, gave birth to another rabbit.
It is known that every rabbit on the planet gives birth to another rabbit every month.

However, a monster appeared on the planet. At the beginning of each month, if the number of rabbits is more than k, the monster eats k rabbits.

You are to determine how many rabbits will be on the planet n months after the first rabbit arrived.

Input
The first line contains the number of months n (0≤n≤100).

The second line contains the number k (0≤k≤10000), the number of rabbits the monster eats.

Output
Output the number of rabbits on planet TTV n months after the first rabbit arrived.

The result will not exceed 2×10^9 for any test case.

Examples

Input #1
0
10

Answer #1
1

*/

#include <assert.h>

int
solve(int n, int k)
{
	int i, r;

	if (n < 0 || k < 0)
		return 0;

	r = 1;
	for (i = 1; i <= n; i++) {
		if (r > k)
			r -= k;
		r *= 2;
	}
	return r;
}

int
main()
{
	assert(solve(0, 10) == 1);

	return 0;
}
