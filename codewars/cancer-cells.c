/*

Your task is to write a function which cuts cancer cells from the body.

Cancer cells are divided into two types:
Advance stage,described as letter C
Initial stage,described as letter c
Rest cells are divided as follows:

Normal cell,described as lowercase letter
Important cell,described as uppercase letter
Prerequisites:
Important cell,cannot be cut out.
Advance cancer cell,should be cut out with adjacent cells if it can be done.
Function input is a string (representing a body), remove "cancer" characters (based on the described rules) and return the body cured of those "cancer" characters.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *
cure(const char *s, char *b)
{
	size_t i, j;

	for (i = j = 0; s[i]; i++) {
		switch (s[i]) {
		case 'c':
			break;

		case 'C':
			if (i > 0 && !islower(s[i - 1]))
				b[j++] = s[i];
			else if (s[i + 1] && !islower(s[i + 1]))
				b[j++] = s[i];
			break;

		default:
			b[j++] = s[i];
			break;
		}
	}
	b[j] = '\0';

	return b;
}

void
test(const char *s, const char *r)
{
	char b[64];

	cure(s, b);
	puts(b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("ACbc", "ACb");
	test("xyCcz", "xyz");
	return 0;
}
