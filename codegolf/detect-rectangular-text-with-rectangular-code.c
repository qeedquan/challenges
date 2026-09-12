/*

Given a string of printable ASCII text (including newlines and spaces) that contains at least one character that is neither a newline nor a space, output a truthy value if the string is rectangular, and a falsey value otherwise. Additionally, the source code for your solution must be rectangular.

A string is rectangular if it meets all of the following conditions:

The first line and the last line contain no spaces.
The first and last character of each line is not a space.
All lines have the same number of characters.
For example, the following text is rectangular:

abcd
e fg
hijk
This text, however, is not rectangular (requirement #3):

1234
567
8900

Test Cases
Truthy:

sdghajksfg
asdf
jkl;
qwerty
u i op
zxcvbn
1234
5  6
7890
abcd
e fg
hijk

Falsey:

a b c
123
456
7 9
12
345
qwerty
 uiop
zxcvnm
1234
567
8900
This is code-golf, so the shortest solution in bytes wins.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
rectangular(const char **s, size_t n)
{
	size_t i, l;

	l = (n) ? strlen(s[0]) : 0;
	for (i = 1; i < n; i++) {
		if (l != strlen(s[i]))
			return false;
	}
	if (l == 0)
		return true;

	for (i = 0; i < n; i++) {
		if (isspace(s[i][0]) || isspace(s[i][l - 1]))
			return false;
	}

	for (i = 0; i < l; i++) {
		if (isspace(s[0][i]) || isspace(s[n - 1][i]))
			return false;
	}

	return true;
}

int
main()
{
	const char *s1[] = {
	    "abcd",
	    "e fg",
	    "hijk",
	};

	const char *s2[] = {
	    "1234",
	    "567 ",
	    "8900",
	};

	const char *s3[] = {
	    "sdghajksfg",
	};

	const char *s4[] = {
	    "asdf",
	    "jkl;",
	};

	const char *s5[] = {
	    "qwerty",
	    "u i op",
	    "zxcvbn",
	};

	const char *s6[] = {
	    "1234",
	    "5  6",
	    "7890",
	};

	const char *s7[] = {
	    "abcd",
	    "e fg",
	    "hijk",
	};

	const char *s8[] = {
	    "a b c"};

	const char *s9[] = {
	    "123",
	    "456",
	    "7 9",
	};

	const char *s10[] = {
	    "12 ",
	    "345",
	};

	const char *s11[] = {
	    "qwerty",
	    "uiop ",
	    "zxcvnm",
	};

	const char *s12[] = {
	    "1234",
	    "567 ",
	    "8900",
	};

	assert(rectangular(s1, nelem(s1)) == true);
	assert(rectangular(s2, nelem(s2)) == false);
	assert(rectangular(s3, nelem(s3)) == true);
	assert(rectangular(s4, nelem(s4)) == true);
	assert(rectangular(s5, nelem(s5)) == true);
	assert(rectangular(s6, nelem(s6)) == true);
	assert(rectangular(s7, nelem(s7)) == true);
	assert(rectangular(s8, nelem(s8)) == false);
	assert(rectangular(s9, nelem(s9)) == false);
	assert(rectangular(s10, nelem(s10)) == false);
	assert(rectangular(s11, nelem(s11)) == false);
	assert(rectangular(s12, nelem(s12)) == false);

	return 0;
}
