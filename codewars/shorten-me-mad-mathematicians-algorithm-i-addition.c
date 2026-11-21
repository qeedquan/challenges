/*

Shorten Me: Mad Mathematician's Algorithm I (Addition)

Task
You have to write a madAdd(a,b) function returning a value of a + b without + in your code.

Coding Limitation:
Less than 30 characters

Input:
a and b : integer ( 0-10000 )

*/

#include <assert.h>

int
madadd(int a, int b)
{
	return a - -b;
}

int
main()
{
	int a, b, n;

	n = 10000;
	for (a = -n; a <= n; a++) {
		for (b = -n; b <= n; b++)
			assert(madadd(a, b) == a + b);
	}
	return 0;
}
