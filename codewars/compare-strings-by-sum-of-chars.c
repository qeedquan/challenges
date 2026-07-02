/*

Compare two strings by comparing the sum of their values (ASCII character code).

For comparing treat all letters as UpperCase
null/NULL/Nil/None should be treated as empty strings
If the string contains other characters than letters, treat the whole string as it would be empty
Your method should return true, if the strings are equal and false if they are not equal.

Examples:
"AD", "BC"  -> equal
"AD", "DD"  -> not equal
"gf", "FG"  -> equal
"zz1", ""   -> equal (both are considered empty)
"ZzZz", "ffPFF" -> equal
"kl", "lz"  -> not equal
null, ""    -> equal

*/

#include <assert.h>
#include <stdio.h>
#include <ctype.h>

int
sum(const char *s)
{
	int c, r;

	if (!s)
		return 0;

	for (r = 0; *s; s++) {
		c = toupper(*s);
		if (!('A' <= c && c <= 'Z'))
			return 0;
		r += c;
	}
	return r;
}

bool
sumcmp(const char *s, const char *t)
{
	return sum(s) == sum(t);
}

int
main()
{
	assert(sumcmp("AD", "BC") == true);
	assert(sumcmp("AD", "DD") == false);
	assert(sumcmp("gf", "FG") == true);
	assert(sumcmp("zz1", "") == true);
	assert(sumcmp("ZzZz", "ffPFF") == true);
	assert(sumcmp("kl", "lz") == false);
	assert(sumcmp(NULL, "") == true);
	return 0;
}
