/*

Petya only gets twos and fives in school. Determine which grade he has more of.

Input
One single string contains Petya’s grades.
It is known that Petya only receives twos and fives.
The grades are written consecutively without spaces, and the total number of grades does not exceed 1000.

Output
Print:

5 if there are more fives than twos;

2 if there are more twos than fives;

the equality symbol '=' if the number of twos and fives is equal.

Examples

Input #1
255222

Answer #1
2

Input #2
555522

Answer #2
5

Input #3
525522

Answer #3
=

*/

#include <assert.h>
#include <stdio.h>

size_t
solve(const char *s)
{
	size_t c2, c5;

	for (c2 = c5 = 0; *s; s++) {
		c2 += (*s == '2');
		c5 += (*s == '5');
	}
	if (c2 == c5)
		return '=';
	if (c2 < c5)
		return '5';
	return '2';
}

int
main()
{
	assert(solve("255222") == '2');
	assert(solve("555522") == '5');
	assert(solve("525522") == '=');

	return 0;
}
