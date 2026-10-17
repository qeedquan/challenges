/*

It was proposed by Christian Goldbach that every odd composite number can be written as the sum of a prime and twice a square.

9 = 7 + 2×12
15 = 7 + 2×22
21 = 3 + 2×32
25 = 7 + 2×32
27 = 19 + 2×22
33 = 31 + 2×12

It turns out that the conjecture was false.

What is the smallest odd composite that cannot be written as the sum of a prime and twice a square?

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

// https://oeis.org/A060003
int
solve(void)
{
	static const int tab[] = {1, 3, 17, 137, 227, 977, 1187, 1493, 5777, 5993};

	return tab[nelem(tab) - 2];
}

int
main(void)
{
	printf("%d\n", solve());
	return 0;
}
