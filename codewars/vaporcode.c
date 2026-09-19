/*

Write a function that converts any sentence into a V A P O R W A V E sentence. a V A P O R W A V E sentence converts all the letters into uppercase, and adds 2 spaces between each letter (or special character) to create this V A P O R W A V E effect.

Note that spaces should be ignored in this case.

Examples
"Lets go to the movies"       -->  "L  E  T  S  G  O  T  O  T  H  E  M  O  V  I  E  S"
"Why isn't my code working?"  -->  "W  H  Y  I  S  N  '  T  M  Y  C  O  D  E  W  O  R  K  I  N  G  ?"

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *
vaporcode(const char *s, char *b)
{
	size_t i;
	char *p;

	*b = '\0';
	p = b;
	for (i = 0; s[i]; i++) {
		if (isspace(s[i]))
			continue;

		*p++ = toupper(s[i]);
		*p++ = ' ';
		*p++ = ' ';
	}
	if (p != b)
		p[-2] = '\0';
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	vaporcode(s, b);
	printf("'%s'\n", b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("Lets go to the movies", "L  E  T  S  G  O  T  O  T  H  E  M  O  V  I  E  S");
	test("Why isn't my code working?", "W  H  Y  I  S  N  '  T  M  Y  C  O  D  E  W  O  R  K  I  N  G  ?");
	return 0;
}
