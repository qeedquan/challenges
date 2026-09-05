/*

The aim is to create an algorithm to detect that one of the string in a small list of strings contains %s, %d, %f, or %r. All sub-string will start by '%' and be 2 characters longs. Input string will be from 1 to 500 characters with a median of around 20 characters and contain zero to multiple of the possible sub-strings. the number of string in a batch is small, 2 to 5 strings.

Here's the naive python implementation:

SUBSTRING_TO_SEARCH_FOR = ["%s", "%d", "%f", "%r"]

def any_substring_in_inputs(inputs: list[str]) -> bool:
    for input in inputs:
        for substring in SUBSTRING_TO_SEARCH_FOR:
            if substring in input:
                return True
    return False
The way the values are recovered in inputs isn't important, the algorithm is. The best execution time in a language agnostic environment and in the specified condition win.

There is real world application in pylint, a static analysis tool for python. The best algorithm will be ported to it to detect string with missing formatting parameter automatically.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool
fmtspec(const char *s)
{
	size_t i;

	for (i = 0; s[i]; i++) {
		if (s[i] == '%' && strchr("sdfr", s[i + 1]))
			return true;
	}
	return false;
}

int
main(void)
{
	assert(fmtspec("hello %s") == true);
	assert(fmtspec("pi is %f") == true);
	assert(fmtspec("int is %d which is not %i") == true);
	assert(fmtspec("hex is %x") == false);

	return 0;
}
