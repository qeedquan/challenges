/*

Double each digit of the given three-digit number.

Input
A three-digit integer.

Output
The result after doubling each digit of the input number.

Examples
Input #1
123

Answer #1
112233

*/

#include <assert.h>
#include <stdio.h>

typedef long long vlong;

vlong
solve(vlong n)
{
	vlong d, r, p, s;

	s = 1;
	p = 1;
	if (n < 0) {
		s = -1;
		n = -n;
	}
	for (r = 0; n; n /= 10) {
		d = (n % 10) * p;
		r += d + (d * 10);
		p *= 100;
	}
	return r * s;
}

int
main()
{
	assert(solve(123) == 112233);
	assert(solve(456) == 445566);
	assert(solve(999) == 999999);

	return 0;
}
