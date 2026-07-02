/*

The HR manager was disappointed again. The last applicant failed the interview the same way as 24 previous ones. "Do I give such a hard task?" — the HR manager thought. "Just raise number 5 to the power of n and get last two digits of the number. Yes, of course, n can be rather big, and one cannot find the power using a calculator, but we need people who are able to think, not just follow the instructions."

Could you pass the interview in the machine vision company in IT City?

Input
The only line of the input contains a single integer n (2 ≤ n ≤ 2·10^18) — the power in which you need to raise number 5.

Output
Output the last two digits of 5n without spaces between them.

Examples

input
2
output
25

*/

#include <assert.h>
#include <math.h>

typedef unsigned long long uvlong;

uvlong
last2digit(uvlong n)
{
	if (n == 0)
		return 1;
	if (n == 1)
		return 5;
	return 25;
}

int
main(void)
{
	uvlong i, v;

	for (i = 0; i <= 20; i++) {
		v = pow(5, i);
		assert((v % 100) == last2digit(i));
	}

	return 0;
}
