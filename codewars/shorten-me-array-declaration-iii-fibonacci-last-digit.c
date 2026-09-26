/*

Shorten Me: Array Declaration III (Fibonacci Last Digit)

Task
You have to write an array() function returning an array object with elements as follow:

[ 1, 1, 2, 3, 5, 8, 3, 1, 4, 5, 9, 4, 3,
  7, 0, 7, 7, 4, 1, 5, 6, 1, 7, 8, 5, 3,
  8, 1, 9, 0, 9, 9, 8, 7, 5, 2, 7, 9, 6 ]

Coding Limitation:
Less than 70 characters

*/

#include <stdio.h>

size_t
gen(int *r)
{
	static const char nums[] = "112358314594370774156178538190998752796";

	size_t i;

	for (i = 0; nums[i]; i++)
		r[i] = nums[i] - '0';
	return i - 1;
}

int
main()
{
	int x[64];

	gen(x);
	return 0;
}
