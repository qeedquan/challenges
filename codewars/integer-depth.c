/*

The depth of an integer n is defined to be how many multiples of n it is necessary to compute before all 10 digits have appeared at least once in some multiple.

example:

let see n=42

Multiple         value         digits     comment
42*1              42            2,4
42*2              84             8         4 existed
42*3              126           1,6        2 existed
42*4              168            -         all existed
42*5              210            0         2,1 existed
42*6              252            5         2 existed
42*7              294            9         2,4 existed
42*8              336            3         6 existed
42*9              378            7         3,8 existed
Looking at the above table under digits column you can find all the digits from 0 to 9, Hence it required 9 multiples of 42 to get all the digits. So the depth of 42 is 9. Write a function named computeDepth which computes the depth of its integer argument.Only positive numbers greater than zero will be passed as an input.

*/

#include <assert.h>
#include <stdio.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef long long vlong;

// https://oeis.org/A202296
vlong
depth(vlong n)
{
	static const vlong mask = 0x3ff;

	vlong f, i, x;

	if (n < 1)
		return -1;

	f = 0;
	for (i = 1; i < LLONG_MAX; i++) {
		for (x = i * n; x > 0; x /= 10)
			f |= (1 << (x % 10));

		if (f == mask)
			break;
	}
	return (f == mask) ? i : -1;
}

int
main()
{
	static const vlong tab[] = {
		10, 45, 10, 23, 18, 15, 10, 12, 10, 9, 10, 13, 8, 17, 12, 16, 7,
		5, 10, 45, 9, 9, 9, 19, 36, 15, 7, 17, 7, 9, 10, 18, 10, 27, 16,
		11, 10, 5, 10, 23, 9, 9, 7, 9, 8, 11, 10, 12, 10, 18, 9, 18, 8,
		11, 9, 12, 10, 5, 10, 15, 9, 9, 8, 9, 11, 11, 7, 14, 5, 8, 10, 11
	};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(depth(i + 1) == tab[i]);

	assert(depth(125) == 72);
	assert(depth(1234567890) == 1);

	return 0;
}
