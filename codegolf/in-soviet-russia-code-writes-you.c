/*

Input
Two words separated by a space. It is assumed that the first is a verb.

Output
The "Soviet counterpoint" to the input phrase, in the form of a punchline to an "in Soviet Russia" joke.

"break law" --> "In Soviet Russia, law break you!"
Accounting for correct grammar is unimportant.

Shortest program wins!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *
counterpoint(const char *s, char *b)
{
	int i, j;

	i = 0;
	while (!isspace(s[i]))
		i++;

	j = i + 1;
	while (isspace(s[j]))
		j++;

	sprintf(b, "In Soviet Russia, %s %.*s you!", s + j, i, s);
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	counterpoint(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("break law", "In Soviet Russia, law break you!");

	return 0;
}
