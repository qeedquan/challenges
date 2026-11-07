/*

One string is given.

If the letter 'f' occurs in the string only once, print its index (indexing starts from 0).

If the letter 'f' occurs two or more times, print the indices of its first and last occurrences.

If the letter 'f' does not appear in the string, print nothing.

Input
One single string with a length not exceeding 255 characters.

Output
Print the result based on the number of occurrences of the letter 'f' in the string.

Examples

Input #1
comfort

Answer #1
3

Input #2
office

Answer #2
1 2

*/

#include <stdio.h>
#include <string.h>

void
solve(const char *s)
{
	const char *p1, *p2;

	p1 = strchr(s, 'f');
	if (!p1)
		return;

	p2 = strrchr(s, 'f');
	if (p1 == p2)
		printf("%zu\n", p1 - s);
	else
		printf("%zu %zu\n", p1 - s, p2 - s);
}

int
main()
{
	solve("comfort");
	solve("office");
	return 0;
}
