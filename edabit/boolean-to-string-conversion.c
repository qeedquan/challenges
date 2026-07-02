/*

Create a function that takes a boolean variable flag and returns it as a string.

Examples
boolToString(true) ➞ "true"

boolToString(false) ➞ "false"

Notes
Don't forget to return the result.
If you get stuck on a challenge, find help in the Resources tab.
If you're really stuck, unlock solutions in the Solutions tab.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

const char *
bool2str(bool x)
{
	return (x) ? "true" : "false";
}

void
test(bool x, const char *r)
{
	const char *p;

	p = bool2str(x);
	printf("%s\n", p);
	assert(!strcmp(p, r));
}

int
main(void)
{
	test(true, "true");
	test(false, "false");
	return 0;
}
