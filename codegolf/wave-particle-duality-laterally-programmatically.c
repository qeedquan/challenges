/*

Write a program or function that takes in a nonempty single-line string. The string will either be zero or more spaces followed by one period (a particle), such as . or          ., or the string will be a sequence of one or more alternating forward and back slashes (a wave) that could start with either one, such as \ or /\/ or \/\/\/\/\/\/.

In either case, propagate the particle/wave to the right by one unit.

Specifically, in the particle case, insert a space before the ., moving it one place to the right, then output the resulting string. For example:

. →  .
 . →   .
  . →    .
   . →     .
    . →      .
     . →       .
      . →        .
       . →         .

In the wave case, append either / or \ appropriately so the wave keeps alternating and it's length increases by one, then output the resulting string. For example:

/ → /\
\ → \/
/\ → /\/
\/ → \/\
/\/ → /\/\
\/\ → \/\/
/\/\ → /\/\/
\/\/ → \/\/\

In either case, the output may not have trailing spaces but an optional trailing newline is allowed.

The shortest code in bytes wins.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool
isparticle(const char *s)
{
	while (isspace(*s))
		s++;
	if (*s++ != '.')
		return false;
	return *s == '\0';
}

bool
iswave(const char *s)
{
	char c[2];
	size_t i;

	if (*s == '/') {
		c[0] = '/';
		c[1] = '\\';
	} else if (*s == '\\') {
		c[0] = '\\';
		c[1] = '/';
	} else
		return false;

	for (i = 0; s[i]; i++) {
		if (s[i] != c[i & 1])
			return false;
	}
	return i > 0;
}

char *
waveparticle(const char *s, char *b)
{
	int n;

	if (isparticle(s))
		sprintf(b, " %s", s);
	else if (iswave(s)) {
		n = sprintf(b, "%s/", s);
		if (b[n - 2] == '/')
			b[n - 1] = '\\';
	} else
		return NULL;
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	assert(waveparticle(s, b) != NULL);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test(".", " .");
	test(" .", "  .");
	test("  .", "   .");
	test("   .", "    .");
	test("    .", "     .");
	test("     .", "      .");
	test("      .", "       .");
	test("       .", "        .");

	test("/", "/\\");
	test("\\", "\\/");
	test("/\\", "/\\/");
	test("\\/", "\\/\\");
	test("/\\/", "/\\/\\");
	test("\\/\\", "\\/\\/");
	test("/\\/\\", "/\\/\\/");
	test("\\/\\/", "\\/\\/\\");

	return 0;
}
