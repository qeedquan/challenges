/*

For the given integer n print "YES", if at least one of the following conditions holds and "NO" otherwise.

number n is odd;

number n is positive and three-digit.

Input
One integer n.

Output
Print "YES" or "NO" depending on conditions.

Examples

Input #1
7

Answer #1
YES

Input #2
8

Answer #2
NO

*/

#include <assert.h>
#include <string.h>

const char *
solve(int n)
{
	if ((n % 2) || (100 <= n && n <= 999))
		return "YES";
	return "NO";
}

int
main()
{
	assert(!strcmp(solve(7), "YES"));
	assert(!strcmp(solve(8), "NO"));

	return 0;
}
