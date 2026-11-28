/*

Complete the function that accepts a valid string and returns an integer.

Wait, that would be too easy! Every character of the string should be converted to the hex value of its ascii code, then the result should be the sum of the numbers in the hex strings (ignore letters).

Examples
"Yo" ==> "59 6f" ==> 5 + 9 + 6 = 20
"Hello, World!"  ==> 91
"Forty4Three"    ==> 113

*/

#include <assert.h>
#include <stdio.h>

int
hexhash(const char *s)
{
	size_t i;
	int lo, hi;
	int r;

	r = 0;
	for (i = 0; s[i]; i++) {
		lo = s[i] & 0xf;
		hi = (s[i] >> 4) & 0xf;
		if (lo < 0xa)
			r += lo;
		if (hi < 0xa)
			r += hi;
	}
	return r;
}

int
main()
{
	assert(hexhash("Yo") == 20);
	assert(hexhash("Hello, World!") == 91);
	assert(hexhash("Forty4Three") == 113);
	return 0;
}
