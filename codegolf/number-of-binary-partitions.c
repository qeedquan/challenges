/*

We all know that any positive integer can be represented as the sum of powers of two.
This is how binary representations work. However there's not just one way to do this.
The canonical method, used in binary representations represents it as the sum of unique powers of two.
For example 5=2^0+2^2. However since 2^0=1 we can write any number just adding 2^0.
For example 5=2^0+2^0+2^0+2^0+2^0.

How many ways are there to write a given number as the sum of powers of two? Let's write a program to see.
We don't want to double count methods that are equivalent under associativity or commutativity, so 2^0+2^2 and 2^2+2^0 count as the same way because we've just changed the order.

Since this is sequence you may use any of the following IO formats where f(n) is the number of ways to write n:

Take n as input and output f(n).
Take n as input and output f(x) for x up to n in order.
Output all f(x) for every positive integer x in order.
You may optionally choose to also include f(0).

This is code-golf so the goal is to minimize the size of your source code as measured in bytes.

Test cases
Here are the first 60 values:

1, 2, 2, 4, 4, 6, 6, 10, 10, 14, 14, 20, 20, 26, 26, 36, 36, 46, 46, 60, 60, 74, 74, 94, 94, 114, 114, 140, 140, 166, 166, 202, 202, 238, 238, 284, 284, 330, 330, 390, 390, 450, 450, 524, 524, 598, 598, 692, 692, 786, 786, 900, 900, 1014, 1014, 1154, 1154, 1294, 1294, 1460

More can be found at OEIS A018819

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

// https://oeis.org/A018819
int
binpart(int n)
{
	if (n < 1)
		return n == 0;
	if (n % 2)
		return binpart(n - 1);
	return binpart(n / 2) + binpart(n - 1);
}

int
main(void)
{
	static const int tab[] = {
		1, 1, 2, 2, 4, 4, 6, 6, 10, 10, 14, 14, 20, 20, 26, 26, 36, 36, 46, 46,
		60, 60, 74, 74, 94, 94, 114, 114, 140, 140, 166, 166, 202, 202, 238,
		238, 284, 284, 330, 330, 390, 390, 450, 450, 524, 524, 598, 598, 692,
		692, 786, 786, 900, 900, 1014, 1014, 1154, 1154, 1294, 1294
	};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(binpart(i) == tab[i]);

	return 0;
}
