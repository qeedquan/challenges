/*

In this Kata, we will check if a string contains consecutive letters as they appear in the English alphabet and if each letter occurs only once.

Rules are: (1) the letters are adjacent in the English alphabet, and (2) each letter occurs only once.

For example:
solve("abc") = True, because it contains a,b,c
solve("abd") = False, because a, b, d are not consecutive/adjacent in the alphabet, and c is missing.
solve("dabc") = True, because it contains a, b, c, d
solve("abbc") = False, because b does not occur once.
solve("v") = True

All inputs will be lowercase letters.

More examples in test cases. Good luck!

*/

#include <assert.h>
#include <string.h>
#include <limits.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

bool
solve(const char *input)
{
	char seen[256];
	int symbol;
	int start;
	int end;

	memset(seen, 0, sizeof(seen));
	start = INT_MAX;
	end = INT_MIN;
	for (; *input; input++) {
		symbol = *input & 0xff;
		if (!('a' <= symbol && symbol <= 'z'))
			return false;

		seen[symbol] += 1;
		if (seen[symbol] >= 2)
			return false;

		start = min(start, symbol);
		end = max(end, symbol);
	}

	for (symbol = start; symbol <= end; symbol++) {
		if (!seen[symbol])
			return false;
	}

	return true;
}

int
main()
{
	assert(solve("abc") == true);
	assert(solve("abd") == false);
	assert(solve("dabc") == true);
	assert(solve("abbc") == false);
	assert(solve("v") == true);

	return 0;
}
