/*

Your task is to create a regular expression that matches most binary numbers with an even number of 0s and an odd number of 1s (e.g. "101100011").

The full criteria for the regex are:

matches 90% or more of all binary numbers between 0 and 11111111 with even number of 0s and an odd number of 1s,
doesn't match 90% or more of all binary numbers between 0 and 11111111 with odd number of 0s or an even number of 1s,
works in most common programming languages.
Ideally, it should be short and creative.

The input string always has a length that is greater than 1, less than infinity, and only contains 1s and 0s.

I will upvote any answer that seriously attempts to match the above criteria. Once the activity around this question dies down, I'll accept the highest-voted answer that is at least only 1.333... times the length of the shortest answer.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <pcre.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
check(const char *str)
{
	size_t zero, one;
	size_t i;

	zero = one = 0;
	for (i = 0; str[i]; i++) {
		if (str[i] == '0')
			zero++;
		else if (str[i] == '1')
			one++;
	}
	return !(zero & 1) && (one & 1);
}

/*

@Howard

The following regex

(?=^1*(01*0)*1*$)^.(..)*$
works in many languages. It performs a perfect match for any binary of arbitrary length.

Basically, it consists of two parts which are joined via and by using a lookahead pattern:

^1*(01*0)*1*$ matches if an even number of zeros is provided.
^.(..)*$ tests for an odd number of digits in total.

*/

int
match(const char *str)
{
	pcre *re;
	const char *err;
	int erroff;
	int matches[8];
	int ret;

	re = pcre_compile("(?=^1*(01*0)*1*$)^.(..)*$", 0, &err, &erroff, NULL);
	if (!re)
		return -EINVAL;

	ret = pcre_exec(re, NULL, str, strlen(str), 0, 0, matches, nelem(matches));
	pcre_free(re);
	return ret;
}

int
main(void)
{
	char str[128];
	long i;

	for (i = 0; i <= 0b11111111; i++) {
		snprintf(str, sizeof(str), "%0lb", i);
		if (match(str) >= 0) {
			printf("%s\n", str);
			assert(check(str));
		}
	}

	return 0;
}
