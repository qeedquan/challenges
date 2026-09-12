/*

Disarium Dilemma
A Disarium is defined as a number whose:

sum of its digits powered with their respective position is equal to the original number

Your Task:

You have a strange obsession with numbers classified as being a disarium.
The need to follow the ways of disarium is so great in you that you refuse to read any non-disarium numbered pages in any given book.
You have two BIG problems:

Your professor just assigned you to read your textbook from page n to page m
You hit your head really hard last week and can't seem to remember how to programmatically determine if a number is considered to be a disarium.
Time is of the essence so the code to determine the pages you will need to read needs to be as short as possible.

You need to identify all of the disarium within an inclusive range of n through m.

Examples of a disarium:

89 = 81 + 92

135 = 11 + 32 + 53

518 = 51 + 12 + 83

This is code-golf, so the least number of bytes wins!

Here is the full sequence of A032799.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long long uvlong;

// https://oeis.org/A032799
size_t
gen(uvlong n, uvlong m, uvlong *r)
{
	static const uvlong tab[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 89, 135, 175, 518, 598, 1306, 1676, 2427, 2646798ULL, 12157692622039623539ULL};

	size_t i, j;
	uvlong x;

	for (i = j = 0; i < nelem(tab); i++) {
		x = tab[i];
		if (n <= x && x <= m)
			r[j++] = x;
	}
	return j;
}

void
test(uvlong n, uvlong m, uvlong *r, size_t nr)
{
	uvlong p[32];
	size_t np;

	np = gen(n, m, p);
	assert(np == nr);
	assert(!memcmp(p, r, sizeof(*r) * nr));
}

int
main(void)
{
	uvlong r1[] = {9, 89, 135};

	test(9, 135, r1, nelem(r1));
	return 0;
}
