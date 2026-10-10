/*

Description
1474 is a pandigital in Roman numerals (MCDLXXIV).
It uses each of the symbols I, V, X, L, C, and M at least once.
Your challenge today is to find the small handful of pandigital Roman numbers up to 2000.

Output Description
A list of numbers. Example:

1 (I), 2 (II), 3 (III), 8 (VIII) (Examples only, these are not pandigital Roman numbers)
Challenge Input
Find all numbers that are pandigital in Roman numerals using each of the symbols I, V, X, L, C, D and M exactly once.

Challenge Input Solution
1444, 1446, 1464, 1466, 1644, 1646, 1664, 1666

See OEIS sequence A105416 for more information.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

// https://oeis.org/A105416
size_t
roman_pandigitals(int *r)
{
	int a, b, c;
	size_t n;

	n = 0;
	for (a = 4; a <= 6; a += 2) {
		for (b = 4; b <= 6; b += 2) {
			for (c = 4; c <= 6; c += 2)
				r[n++] = 1000 + (a * 100) + (b * 10) + c;
		}
	}
	return n;
}

int
main()
{
	static const int tab[] = { 1444, 1446, 1464, 1466, 1644, 1646, 1664, 1666 };

	int x[8];

	assert(roman_pandigitals(x) == nelem(tab));
	assert(!memcmp(x, tab, sizeof(tab)));

	return 0;
}
