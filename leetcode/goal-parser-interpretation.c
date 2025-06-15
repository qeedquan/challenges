/*

You own a Goal Parser that can interpret a string command.
The command consists of an alphabet of "G", "()" and/or "(al)" in some order.
The Goal Parser will interpret "G" as the string "G", "()" as the string "o", and "(al)" as the string "al".
The interpreted strings are then concatenated in the original order.

Given the string command, return the Goal Parser's interpretation of command.

Example 1:

Input: command = "G()(al)"
Output: "Goal"
Explanation: The Goal Parser interprets the command as follows:
G -> G
() -> o
(al) -> al
The final concatenated result is "Goal".

Example 2:

Input: command = "G()()()()(al)"
Output: "Gooooal"

Example 3:

Input: command = "(al)G(al)()()G"
Output: "alGalooG"

Constraints:

    1 <= command.length <= 100
    command consists of "G", "()", and/or "(al)" in some order.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
goal(const char *s, char *b)
{
	char *p;

	for (p = b; *s; s++) {
		if (*s == 'G')
			*p++ = 'G';
		else if (!strncmp(s, "()", 2))
			*p++ = 'o';
		else if (!strncmp(s, "(al)", 4)) {
			*p++ = 'a';
			*p++ = 'l';
		}
	}
	*p = '\0';
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	goal(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("G()(al)", "Goal");
	test("G()()()()(al)", "Gooooal");
	test("(al)G(al)()()G", "alGalooG");

	return 0;
}
