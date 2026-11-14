/*

The Easter Bunnies are back, and they are on the hunt for Easter eggs once more. This time, the eggs can be found in an array of length 666666, and there are between -100 (?!) and +100 eggs at each position in the array.
The Easter Bunnies can choose any subarray. What’s the most eggs that they can collect?

Input: A single integer X0 that is used as the seed for the Linear Congruential Generator introduced in problem 25, use A=445, C=700001 and M=2097152. Generate the first 666666 values from this sequence, and transform each value via value % 201 - 100 to the desired range from -100 to +100.

Output: The maximum number of eggs the Easter Bunnies can get.

Example: Let’s look at a shorter array of length 8. Using the seed value X0=0, the first 8 numbers of the LCG sequence are

700001 1821950 1967079 1537772 1336989 68938 2017283 809880
(see also problem 83). These values are transformed to

19 -14 -7 22 38 96 -53 -49
and the largest subarray sum is 156.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define maxi(a, b) (((a) > (b)) ? (a) : (b))

typedef struct {
	long a;
	long c;
	long m;
	long x;
} LCG;

long
next(LCG *l)
{
	l->x = ((l->a * l->x) + l->c) % l->m;
	return l->x;
}

long
eggs(LCG *l)
{
	return (next(l) % 201) - 100;
}

long
solve(long x0, long len)
{
	LCG lcg = {
		.a = 445,
		.c = 700001,
		.m = 2097152,
		.x = x0,
	};

	long i, val, max, res;

	if (len < 1)
		return 0;

	res = eggs(&lcg);
	max = res;
	for (i = 1; i < len; i++) {
		val = eggs(&lcg);
		max = maxi(max + val, val);
		res = maxi(res, max);
	}
	return res;
}

int
main()
{
	assert(solve(0, 8) == 156);
	printf("%ld\n", solve(0, 666666));

	return 0;
}
