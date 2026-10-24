/*

As a couple of people may have noticed lately, I've largely abandoned development of Braingolf because it's boring and uninspired, and moved on to 2Col which is a little more interesting, and not designed to be a golfing language.

The defining feature of 2Col is that every line of code must be exactly 2 characters long, excluding the newline. This means that the length of a 2Col program can always be calculated as 3n-1 where n is the number of lines in the program.

So here's my challenge: Given 2Col code as a string, output truthy if it is valid 2Col code (Every line is exactly 2 characters and it conforms with the 3n-1 formula), and falsey otherwise.

Input
Input should be taken as a single string, or an array of characters.

Output
A truthy value if the input string is valid layout, and a falsey value otherwise.

Your code should be consistent in which truthy/falsey values it uses

Testcases
======
F!
$^
----
truthy
======


======
*8
+1
Sq
----
truthy
======


======
nop
xt
----
falsey
======


======
+1
+1
#^

----
falsey
======


======
<empty string>
----
falsey
======


======
ye
----
truthy
======


======
no<space>
----
falsey
======


======
test
----
falsey
======


======
puzzle
----
falsey
======

Scoring
This is code-golf so fewest bytes wins!

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
is2col(const char **s, size_t n)
{
	const char *p;
	size_t i;

	for (i = 0; i < n; i++) {
		p = s[i];
		if (!(p[0] && p[1] && !p[2]))
			return false;
	}
	return true;
}

int
main(void)
{
	const char *s1[] = {"F!", "$^"};
	const char *s2[] = {"*8", "+1", "Sq"};
	const char *s3[] = {"nop", "xt"};
	const char *s4[] = {"+1", "+1", "#^", ""};
	const char *s5[] = {""};
	const char *s6[] = {"ye"};
	const char *s7[] = {"no "};
	const char *s8[] = {"test"};
	const char *s9[] = {"puzzle"};

	assert(is2col(s1, nelem(s1)) == true);
	assert(is2col(s2, nelem(s2)) == true);
	assert(is2col(s3, nelem(s3)) == false);
	assert(is2col(s4, nelem(s4)) == false);
	assert(is2col(s5, nelem(s5)) == false);
	assert(is2col(s6, nelem(s6)) == true);
	assert(is2col(s7, nelem(s7)) == false);
	assert(is2col(s8, nelem(s8)) == false);
	assert(is2col(s9, nelem(s9)) == false);

	return 0;
}
