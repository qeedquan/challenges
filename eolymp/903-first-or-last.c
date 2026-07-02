/*

A three-digit number is given. Determine which digit is greater: the first or the last.

Input
A single positive three-digit integer is given on the only line.

Output
Print the greater of the specified digits. If they are equal, print the sign "=".

Examples

Input #1
328

Answer #1
8

Input #2

832
Answer #2
8

*/

#include <assert.h>

int
solve(int n)
{
	int f, l;

	f = n / 100;
	l = n % 10;
	if (f > l)
		return f;
	if (f < l)
		return l;
	return '=';
}

int
main()
{
	assert(solve(328) == 8);
	assert(solve(832) == 8);

	return 0;
}
