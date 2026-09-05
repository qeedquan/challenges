/*

Many people choose to obfuscate their email address when displaying it on the Web. One common way of doing this is by substituting the @ and . characters for their literal equivalents in brackets.

Example 1:

user_name@example.com
=> user_name [at] example [dot] com
Example 2:

af5134@borchmore.edu
=> af5134 [at] borchmore [dot] edu
Example 3:

jim.kuback@ennerman-hatano.com
=> jim [dot] kuback [at] ennerman-hatano [dot] com
Using the examples above as a guide, write a function that takes an email address string and returns the obfuscated version as a string that replaces the characters @ and . with [at] and [dot], respectively.

Notes

Input (email) will always be a string object. Your function should return a string.
Change only the @ and . characters.
Email addresses may contain more than one . character.
Note the additional whitespace around the bracketed literals in the examples!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
obfuscate(const char *email, char *output)
{
	char *buffer;

	for (buffer = output; *email; email++) {
		switch (*email) {
		case '@':
			buffer += sprintf(buffer, " [at] ");
			break;
		case '.':
			buffer += sprintf(buffer, " [dot] ");
			break;
		default:
			*buffer++ = *email;
			break;
		}
	}
	*buffer = '\0';

	return output;
}

void
test(const char *email, const char *expected)
{
	char output[128];

	obfuscate(email, output);
	puts(output);
	assert(!strcmp(output, expected));
}

int
main()
{
	test("user_name@example.com", "user_name [at] example [dot] com");
	test("af5134@borchmore.edu", "af5134 [at] borchmore [dot] edu");
	test("jim.kuback@ennerman-hatano.com", "jim [dot] kuback [at] ennerman-hatano [dot] com");
	test("test@123.com", "test [at] 123 [dot] com");
	test("Code_warrior@foo.ac.uk", "Code_warrior [at] foo [dot] ac [dot] uk");

	return 0;
}
