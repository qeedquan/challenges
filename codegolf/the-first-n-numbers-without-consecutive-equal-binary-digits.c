/*

The sequence contains the decimal representation of the binary numbers of the form: 10101..., where the n-th term has n bits.

The sequence is probably easiest to explain by just showing the relationships between the binary and decimal representations of the numbers:

0       ->  0
1       ->  1
10      ->  2
101     ->  5
1010    ->  10
10101   ->  21
101010  ->  42
Challenge:
Take an input integer n, and return the first n numbers in the sequence. You may choose to have the sequence 0-indexed or 1-indexed.

Test cases:
n = 1   <- 1-indexed
0

n = 18
0, 1, 2, 5, 10, 21, 42, 85, 170, 341, 682, 1365, 2730, 5461, 10922, 21845, 43690, 87381
Explanations are encouraged, as always.

This is OEIS A000975.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long long uvlong;

// https://oeis.org/A000975
void
gen(size_t n, uvlong *r)
{
	size_t i;

	for (i = 0; i < n; i++)
		r[i] = ((1ull << (i + 1)) - 1) / 3;
}

int
main(void)
{
	static const uvlong tab[] = {0, 1, 2, 5, 10, 21, 42, 85, 170, 341, 682, 1365, 2730, 5461, 10922, 21845, 43690, 87381, 174762, 349525, 699050, 1398101, 2796202, 5592405, 11184810, 22369621, 44739242, 89478485, 178956970, 357913941, 715827882, 1431655765, 2863311530, 5726623061, 11453246122};

	uvlong x[128];

	gen(nelem(tab), x);
	assert(!memcmp(x, tab, nelem(tab)));

	return 0;
}
