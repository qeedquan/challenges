/*

Given an integer n return "odd" if the number of its divisors is odd. Otherwise return "even".

Note: big inputs will be tested.

Examples:
All prime numbers have exactly two divisors (hence "even").

For n = 12 the divisors are [1, 2, 3, 4, 6, 12] – "even".

For n = 4 the divisors are [1, 2, 4] – "odd".

*/

#include <assert.h>
#include <string.h>
#include <math.h>

typedef long long vlong;

// https://oeis.org/A000037 (for even)
// https://oeis.org/A000290 (for odd)
const char *
oddity(vlong n)
{
	vlong s;

	if (n < 0)
		return NULL;

	s = sqrt(n);
	if (s * s == n)
		return "odd";
	return "even";
}

void
test(vlong n, const char *r)
{
	const char *s;

	s = oddity(n);
	assert(!strcmp(s, r));
}

int
main()
{
	test(1, "odd");
	test(4, "odd");
	test(5, "even");
	test(12, "even");
	test(16, "odd");
	test(6437488298980289969, "even");

	return 0;
}
