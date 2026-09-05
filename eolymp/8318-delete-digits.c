/*

One positive integer n is given. Remove from this number all digits 3 and 9, keeping the order of the other digits the same.

For example, the number 539013 will be transformed to 501.

Input
The input consists of one positive integer n (1≤n≤10^18).

Output
Print the number obtained by removing from n all digits 3 and 9, while keeping the order of the remaining digits.

Examples

Input #1
539013

Answer #1
501

*/

#include <assert.h>
#include <stdio.h>

typedef unsigned long long uvlong;

uvlong
solve(uvlong n)
{
	uvlong d, p, r;

	p = 1;
	for (r = 0; n > 0; n /= 10) {
		d = n % 10;
		if (!(d == 9 || d == 3)) {
			r += d * p;
			p *= 10;
		}
	}
	return r;
}

int
main()
{
	assert(solve(539013) == 501);
	return 0;
}
