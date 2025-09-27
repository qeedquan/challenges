/*

Assume we have a string, and we want to find the maximum repeated sequence of every letter.

For example, given the sample input:

"acbaabbbaaaaacc"
Output for the sample input can be:

a=5
c=2
b=3
Rules:

Your code can be function or a program - for you to choose
Input can be by stdin, file or function parameter
The output should contain only characters that appear in the input
Input max length is 1024
The output order does not matter, but it has to be printed in the form [char]=[maximum repeated sequence][delimiter]
The string can contain any character

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

void
dump(size_t h[256])
{
	int i;

	for (i = 0; i < 256; i++) {
		if (!h[i])
			continue;

		if (isprint(i))
			printf("%c=%zu\n", i, h[i]);
		else
			printf("%d=%zu\n", i, h[i]);
	}
}

void
msl(const char *s, size_t h[256])
{
	size_t i, j;
	int c;

	memset(h, 0, sizeof(*h) * 256);
	for (i = 0; (c = s[i] & 0xff); i = j) {
		j = i + 1;
		while (s[i] == s[j])
			j++;

		h[c] = max(h[c], j - i);
	}
}

void
test(const char *s, size_t r[256])
{
	size_t h[256];

	msl(s, h);
	dump(h);
	assert(!memcmp(h, r, sizeof(h)));
}

int
main()
{
	size_t r[256] = {
	    ['a'] = 5,
	    ['b'] = 3,
	    ['c'] = 2,
	};

	test("acbaabbbaaaaacc", r);

	return 0;
}
