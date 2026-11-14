/*

Shorten Me: Mad Mathematician's Algorithm II (Subtraction)

Task
You have to write a madSub(a,b) function returning a value of a - b without - in your code.

Coding Limitation:
Less than 30 characters

Input:
a and b : integer ( 0-10000 )

*/

#include <assert.h>

int
madsub(int a, int b)
{
	return a + ~b + 1;
}

int
main()
{
	int a, b, n;

	n = 10000;
	for (a = -n; a <= n; a++) {
		for (b = -n; b <= n; b++)
			assert(madsub(a, b) == a - b);
	}
	return 0;
}
