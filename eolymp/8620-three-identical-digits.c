/*

Four-digit number is given. Determine if it contains exactly three identical digits.

Input
One four-digit number n.

Output
Print "YES" if number n contains exactly three identical digits, and "NO" otherwise.

Examples
Input #1
2322

Answer #1
YES

Input #2
2234

Answer #2
NO

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

const char *
solve(unsigned n)
{
	size_t d[10];
	size_t i;

	memset(d, 0, sizeof(d));
	for (; n > 0; n /= 10)
		d[n % 10]++;

	for (i = 0; i < 10; i++) {
		if (d[i] == 3)
			return "YES";
	}
	return "NO";
}

void
test(unsigned n, const char *r)
{
	assert(!strcmp(solve(n), r));
}

int
main()
{
	test(2322, "YES");
	test(2234, "NO");

	return 0;
}
