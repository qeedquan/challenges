/*

I could not think of a better title.

This is a tips question. I'm asking for tips on golfing my code.

I recently took part in a code golf competition in C. The competition ended and I lost. The problem is:

Input a line with a number n.

Then input n lines, each line contains only a set of cards in descending order, e. g. X2AAKKKKQT9765433 or DX22AKKQJTT884443. Figure out if it contains DX or four of the same cards in a row.

Obviously, this is a chameleon challenge (finding DX is essentially the same as checking the second character if it is X,
and to check for four of the same cards you only need to check the first and the last card of the quadruplet, because the cards are in descending order.)

In that competition, the input format is strict, and error-terminating is disallowed.

After the competition, we continued to improve on this problem. We've got this so far (98 bytes):

char*p,s[99];main(){for(gets(s);gets(p=s);puts(s[1]>87?"Yes":"No"))for(;*p;)s[1]|=*p^p++[3]?0:88;}
I'm looking for tips to golf this down further.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
checkcards(const char **s, size_t n)
{
	size_t i, j, k;

	for (i = 0; i < n; i++) {
		if (!strncmp(s[i], "DX", 2))
			return true;

		for (j = 0; s[i][j]; j = k) {
			k = j;
			while (s[i][j] == s[i][k])
				k++;

			if (k - j >= 4)
				return true;
		}
	}
	return false;
}

int
main(void)
{
	const char *s1[] = {"X2AAKKKKQT9765433"};
	const char *s2[] = {"DX22AKKQJTT884443"};
	const char *s3[] = {"444333222", "KQ8886"};
	const char *s4[] = {"DX"};

	assert(checkcards(s1, nelem(s1)) == true);
	assert(checkcards(s2, nelem(s2)) == true);
	assert(checkcards(s3, nelem(s3)) == false);
	assert(checkcards(s4, nelem(s4)) == true);

	return 0;
}
