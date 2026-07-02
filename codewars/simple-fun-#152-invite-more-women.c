/*

Task
King Arthur and his knights are having a New Years party. Last year Lancelot was jealous of Arthur, because Arthur had a date and Lancelot did not, and they started a duel.

To prevent this from happening again, Arthur wants to make sure that there are at least as many women as men at this year's party. He gave you a list of integers of all the party goers.

Arthur needs you to return true if he needs to invite more women or false if he is all set.

Input/Output
[input] integer array L ($a in PHP)
An array (guaranteed non-associative in PHP) representing the genders of the attendees, where -1 represents women and 1 represents men.

2 <= L.length <= 50

[output] a boolean value

true if Arthur need to invite more women, false otherwise.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
invite_more_women(int *a, size_t n)
{
	size_t i;
	int r;

	r = 0;
	for (i = 0; i < n; i++)
		r += a[i];
	return r > 0;
}

int
main()
{
	int a1[] = { 1, -1, 1 };
	int a2[] = { -1, -1, -1 };
	int a3[] = { 1, -1 };
	int a4[] = { 1, 1, 1 };

	assert(invite_more_women(a1, nelem(a1)) == true);
	assert(invite_more_women(a2, nelem(a2)) == false);
	assert(invite_more_women(a3, nelem(a3)) == false);
	assert(invite_more_women(a4, nelem(a4)) == true);

	return 0;
}
