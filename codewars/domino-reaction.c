/*

You're given a string of dominos. For each slot, there are 3 options:

"|" represents a standing domino

"/" represents a knocked over domino

" " represents a space where there is no domino

For example:

"||| ||||//| |/"
Tipping a domino will cause the next domino to its right to fall over as well, but if a domino is already tipped over, or there is a domino missing, the reaction will stop.
What you must do is find the resulting string if the first domino is pushed over. So in out example above, the result would be:

"/// ||||//| |/"
since the reaction would stop as soon as it gets to a space.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

void
act(const char *src, char *dst)
{
	char *ptr;

	strcpy(dst, src);

	ptr = strchr(dst, '|');
	if (!ptr)
		return;

	while (*ptr == '|')
		*ptr++ = '/';
}

void
test(const char *src, const char *res)
{
	char dst[128];

	act(src, dst);
	puts(dst);
	assert(!strcmp(dst, res));
}

int
main()
{
	test("||| ||||//| |/", "/// ||||//| |/");
	test("|||||", "/////");
	test(" ///", " ///");

	return 0;
}
