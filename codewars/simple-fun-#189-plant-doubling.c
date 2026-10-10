/*

Task
Lonerz got some crazy growing plants and he wants to grow them nice and well.

Initially, the garden is completely barren.

Each morning, Lonerz can put any number of plants into the garden to grow.

And at night, each plant mutates into two plants.

Lonerz really hopes to see n plants in his garden.

Your task is to find the minimum number of plants Lonerz has to plant to get exactly n plants one day.

Example
For n = 5, the output should be 2.

Lonerz hopes to see 5 plants. He adds 1 plant on the first morning and on the third morning there would be 4 plants in the garden. He then adds 1 more and sees 5 plants.

So, Lonerz only needs to add 2 plants to his garden.

For n = 8, the output should be 1.

Lonerz hopes to see 8 plants. Thus, he just needs to add 1 plant in the beginning and wait for it to double till 8.

Input/Output
The number of plant lonerz hopes to see in his garden.

[input] integer n

1 <= n <= 10^7

[output] an integer

The number of plants Lonerz needs to plant.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

// https://oeis.org/A105062
long
plantdoubling(long n)
{
	long c, i;

	for (c = 0; n > 0; c++) {
		if (n & 1)
			n -= 1;
		else {
			for (i = 1; i <= n; i *= 2) {
				if (i * 2 > n)
					n -= i;
			}
		}
	}
	return c;
}

int
main()
{
	static const long tab[] = {
		1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4, 1, 2, 2, 3, 2, 3, 3, 4, 2,
		3, 3, 4, 3, 4, 4, 5, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2,
		3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 1, 2, 2, 3, 2, 3, 3, 4, 2,
		3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 2,
		3, 3, 4, 3, 4, 4, 5, 3, 4
	};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(plantdoubling(i + 1) == tab[i]);

	assert(plantdoubling(536870911) == 29);

	return 0;
}
