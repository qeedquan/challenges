/*

Perimeter sequence
The first three stages of a sequence are shown.

https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcTVw-YEuGbD31EB47C7PSi_RpBxr5EJSydV9dj5lOmzsDWFsoAs

The blocksize is a by a and a ≥ 1.

What is the perimeter of the nth shape in the sequence (n ≥ 1) ?

*/

#include <assert.h>

int
perimeter(int a, int n)
{
	return 4 * n * a;
}

int
main()
{
	assert(perimeter(1, 1) == 4);
	assert(perimeter(1, 2) == 8);
	assert(perimeter(1, 3) == 12);
	return 0;
}
