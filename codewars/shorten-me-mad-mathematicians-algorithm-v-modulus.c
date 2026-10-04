/*

Shorten Me: Mad Mathematician's Algorithm V (Modulus)

Task
You have to write a madMod(a,b) function returning a value of a % b without % in your code.

Coding Limitation:
Less than 35 characters

Input:
a and b : integer ( 0-10000 )

*/

#include <assert.h>

int
madmod(int a, int b)
{
	return a - ((a / b) * b);
}

int
main()
{
	int a, b, n;

	n = 10000;
	for (a = 0; a <= n; a++) {
		for (b = 1; b <= n; b++)
			assert(madmod(a, b) == a % b);
	}
	return 0;
}
