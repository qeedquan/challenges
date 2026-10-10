/*

The task is simple, divide, get the quotient and the remainder, and if the remainder is not 1 or 0, do the same thing (quotient divmod remainder) until the remainder is 1 or 0, then get the remainder. If the last input number is 1 or 0, output it.

If the input is [15, 4], then the output would be 0, because the divmod of 15 and 4 is [3, 3] which if you do it again, you get [1, 0], and you can't divmod further, then get the last element, and you got 0.

Another example would be [102, 7], which if you divmod, you get [14, 4], which if you do again, you get [3, 2], which if you divmod again, you get [1, 1], and you get the last element 1, which is the output.

Both input numbers are assumed to be less than 1000.

This is code-golf, so the shortest program/function in bytes wins.

Testcases:
[15, 4] => 0
[102, 7] => 1
[20, 2] => 0
[10, 0] => 0
[11, 1] => 1
[99, 7] => 1
[45, 45] => 0
[31, 30] => 1
[999, 7] => 0
[999, 6] => 1
[88, 7] => 0
[1, 999] => 1
[98, 7] => 0
[999, 998] => 1

*/

#include <assert.h>
#include <stdlib.h>

int
divmod(int a, int b)
{
	div_t r;

	if (a < 0 || b < 0)
		return -1;

	if (b == 0)
		return 0;

	if (b == 1)
		return 1;

	for (;;) {
		r = div(a, b);
		if (r.rem < 2)
			break;
		a = r.quot;
		b = r.rem;
	}
	return r.rem;
}

int
main(void)
{
	assert(divmod(15, 4) == 0);
	assert(divmod(102, 7) == 1);
	assert(divmod(20, 2) == 0);
	assert(divmod(10, 0) == 0);
	assert(divmod(11, 1) == 1);
	assert(divmod(99, 7) == 1);
	assert(divmod(45, 45) == 0);
	assert(divmod(31, 30) == 1);
	assert(divmod(999, 7) == 0);
	assert(divmod(999, 6) == 1);
	assert(divmod(88, 7) == 0);
	assert(divmod(1, 999) == 1);
	assert(divmod(98, 7) == 0);
	assert(divmod(999, 998) == 1);

	return 0;
}
