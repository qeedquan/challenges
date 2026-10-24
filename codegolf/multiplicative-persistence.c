/*

Multiplicative Persistence
Multiply all the digits in a number
Repeat until you have a single digit left
As explained by Numberphile:

Numberphile "What's special about 277777788888899?"
Numberphile "Multiplicative Persistence (extra footage)"
Example
277777788888899 → 2x7x7x7x7x7x7x8x8x8x8x8x8x9x9 = 4996238671872
4996238671872 → 4x9x9x6x2x3x8x6x7x1x8x7x2 = 438939648
438939648 → 4x3x8x9x3x9x6x4x8 = 4478976
4478976 → 4x4x7x8x9x7x6 = 338688
338688 → 3x3x8x6x8x8 = 27648
27648 → 2x7x6x4x8 = 2688
2688 → 2x6x8x8 = 768
768 → 7x6x8 = 336
336 → 3x3x6 = 54
54 → 5x4 = 20
20 → 2x0 = 0
This is the current record, by the way: the smallest number with the largest number of steps.

Golf
A program that takes any whole number as input and then outputs the result of each step, starting with the input itself, until we hit a single digit. For 277777788888899 the output should be

277777788888899
4996238671872
438939648
4478976
338688
27648
2688
768
336
54
20
0
(Counting the number of steps is left as an exercise to the user).

More Examples
From A003001:

25
10
0
From A003001 as well:

68889
27648
2688
768
336
54
20
0
From the Numberphile video, showing that the single digit doesn't have to be 0:

327
42
8
So there has been a question about Additive Persistence, but this is Multiplicative Persistence. Also, that question asks for the number of steps as output, while I'm interested in seeing the intermediate results.

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long long uvlong;

uvlong
digmul(uvlong n)
{
	uvlong r;

	r = 1;
	do {
		r *= n % 10;
		n /= 10;
	} while (n);

	return r;
}

// https://oeis.org/A003001
void
vis(uvlong n)
{
	uvlong m;

	for (;;) {
		printf("%llu\n", n);
		m = digmul(n);
		if (n == m)
			break;
		n = m;
	}
	printf("\n");
}

int
main()
{
	static const uvlong tab[] = {
		0, 10, 25, 39, 77, 679, 6788, 68889, 2677889, 26888999, 3778888999, 277777788888899
	};

	uvlong i;

	for (i = 0; i < nelem(tab); i++)
		vis(tab[i]);

	return 0;
}
