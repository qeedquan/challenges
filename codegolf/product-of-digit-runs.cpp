/*

We seem to quite like digit runs lately, so here's a fairly simple challenge.

Given a positive integer, split it into it's digit runs, and return the product.

For example:

11122333 would become 111, 22, 333, the product of which is 813186

Input may be taken as an integer, string, or list/array of digits/characters. Your entry must work for any number within it's representable range. I have tested this for 32-bit integers (2^32-1 max value) and the largest possible result I have found is 1099999989 from 1199999999, which is also within the 32-bit integer range. I have yet to find a number who's output is larger than the input.

For the purposes of this challenge, runs of length 1 are not counted.

If there is only 1 run, return the run. If there are no runs, do anything (undefined behaviour)

Standard I/O rules apply, output can be given as an integer or string.

Testcases
11122333 -> 813186
1112333 -> 36963
1122855098 -> 13310
98776543 -> 77
1000000 -> 0
123456789 -> undefined
1 -> undefined
99445662 -> 287496
1199999999 -> 1099999989
999999999 -> 999999999

Scoring
This is code-golf so fewest bytes in each language wins!

*/

#include <cassert>
#include <cstdio>

int pdr(int n)
{
	if (n < 1)
		return 0;

	auto r = 1;
	auto d = 1;
	auto p = n % 10;
	for (n /= 10; n > 0; n /= 10)
	{
		if (p % 10 != n % 10)
		{
			if (d > 1)
				r *= p;
			d = p = 0;
		}

		d += 1;
		p = (p * 10) + (n % 10);
	}
	if (d > 1)
		r *= p;

	return r;
}

int main()
{
	assert(pdr(11122333) == 813186);
	assert(pdr(1112333) == 36963);
	assert(pdr(1122855098) == 13310);
	assert(pdr(98776543) == 77);
	assert(pdr(1000000) == 0);
	assert(pdr(123456789) == 1);
	assert(pdr(1) == 1);
	assert(pdr(99445662) == 287496);
	assert(pdr(1199999999) == 1099999989);
	assert(pdr(999999999) == 999999999);

	return 0;
}
