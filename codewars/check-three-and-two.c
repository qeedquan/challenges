/*

Given an array with exactly 5 strings "a", "b" or "c" (chars in Java, characters in Fortran, Chars in Haskell), check if the array contains three and two of the same values.

Examples
["a", "a", "a", "b", "b"] ==> true  // 3x "a" and 2x "b"
["a", "b", "c", "b", "c"] ==> false // 1x "a", 2x "b" and 2x "c"
["a", "a", "a", "a", "a"] ==> false // 5x "a"

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

bool
check(const char *s[5])
{
	size_t p[4];
	size_t i, n;

	n = 0;
	for (i = 1; i < 5; i++) {
		if (strcmp(s[0], s[i]))
			p[n++] = i;
	}
	if (n == 2)
		return !strcmp(s[p[0]], s[p[1]]);
	if (n == 3)
		return !strcmp(s[p[0]], s[p[1]]) && !strcmp(s[p[1]], s[p[2]]);
	return false;
}

int
main()
{
	const char *s1[] = {"a", "a", "a", "b", "b"};
	const char *s2[] = {"a", "b", "c", "b", "c"};
	const char *s3[] = {"a", "a", "a", "a", "a"};
	const char *s4[] = {"y", "y", "x", "y", "x"};
	const char *s5[] = {"x", "x", "t", "t", "t"};
	const char *s6[] = {"x", "t", "t", "x", "t"};

	assert(check(s1) == true);
	assert(check(s2) == false);
	assert(check(s3) == false);
	assert(check(s4) == true);
	assert(check(s5) == true);
	assert(check(s6) == true);

	return 0;
}
