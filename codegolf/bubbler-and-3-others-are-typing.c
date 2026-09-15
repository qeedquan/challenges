/*

Task
Implement a kind of "some users are typing" system, which can be found in Discord and some other chat clients.

If 1 user (say, Bubbler) is typing, output Bubbler is typing...
If 2 users (say, Bubbler and user) are typing, output Bubbler and user are typing...
If 3 or more users are typing (say, Bubbler, randomuser1, randomuser2, randomuser3), output Bubbler and 3 others are typing...
The input is a list of usernames (list of strings); single string with delimiters (symbols or newlines) is also allowed. The output is a single string. Always respect the order of the input usernames. A username can contain upper/lowercase letters, digits, and spaces. Both usernames and the entire input list are never empty.

Standard code-golf rules apply. The shortest code in bytes wins.

Test cases
["Bubbler"] -> "Bubbler is typing..."
["no one"] -> "no one is typing..."
["HyperNeutrino", "user"] -> "HyperNeutrino and user are typing..."
["emanresu A", "lyxal", "Jo King"] -> "emanresu A and 2 others are typing..."
["pxeger", "null", "null", "null", "null", "null", "null", "null", "null", "null", "null"]
-> "pxeger and 10 others are typing..."
["10", "null", "null", "null", "null", "null", "null", "null", "null", "null", "null"]
-> "10 and 10 others are typing..."
["and", "are"] -> "and and are are typing..."
["is"] -> "is is typing..."
["Bubbler is typing", "is", "are", "and"]
-> "Bubbler is typing and 3 others are typing..."

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

char *
typing(const char **s, size_t n, char *b)
{
	switch (n) {
	case 0:
		*b = '\0';
		break;

	case 1:
		sprintf(b, "%s is typing...", s[0]);
		break;

	case 2:
		sprintf(b, "%s and %s are typing...", s[0], s[1]);
		break;

	default:
		sprintf(b, "%s and %zu others are typing...", s[0], n - 1);
		break;
	}
	return b;
}

void
test(const char **s, size_t n, const char *r)
{
	char b[128];

	typing(s, n, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	const char *s1[] = {"Bubbler"};
	const char *s2[] = {"no one"};
	const char *s3[] = {"HyperNeutrino", "user"};
	const char *s4[] = {"emanresu A", "lyxal", "Jo King"};
	const char *s5[] = {"pxeger", "null", "null", "null", "null", "null", "null", "null", "null", "null", "null"};
	const char *s6[] = {"10", "null", "null", "null", "null", "null", "null", "null", "null", "null", "null"};
	const char *s7[] = {"and", "are"};
	const char *s8[] = {"is"};
	const char *s9[] = {"Bubbler is typing", "is", "are", "and"};

	test(s1, nelem(s1), "Bubbler is typing...");
	test(s2, nelem(s2), "no one is typing...");
	test(s3, nelem(s3), "HyperNeutrino and user are typing...");
	test(s4, nelem(s4), "emanresu A and 2 others are typing...");
	test(s5, nelem(s5), "pxeger and 10 others are typing...");
	test(s6, nelem(s6), "10 and 10 others are typing...");
	test(s7, nelem(s7), "and and are are typing...");
	test(s8, nelem(s8), "is is typing...");
	test(s9, nelem(s9), "Bubbler is typing and 3 others are typing...");

	return 0;
}
