/*

In this kata you have to find whether same elements of the string are grouped together.

Example

Input	Output
112233	true
11223311	false

Explanation
In first example same elements are grouped together: (11)(22)(33), hence it should return true
In the second example there are two different groups of 1's: (11)2233(11), hence it should return false

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

bool
consecutive(const char *s)
{
	bool h[256];
	size_t i, j;
	int c;

	memset(h, 0, sizeof(h));
	for (i = 0; s[i]; i = j) {
		c = s[i] & 0xff;
		if (h[c])
			return false;
		h[c] = true;

		j = i + 1;
		while (s[i] == s[j])
			j++;
	}
	return true;
}

int
main()
{
	assert(consecutive("112233") == true);
	assert(consecutive("11223311") == false);

	return 0;
}
