/*

Challenge :
Given two non-negative integers (X and Y > 1) calculate the sum of digits of their powers . i.e : sum of digits of X ^ Y .

Input :
Two non-negative integers X and Y

Output :
The sum of digits of X raised to power Y X ^ Y.

Examples :
5 , 2                    ---> 7
9 , 4                    ---> 18
3 , 17                   ---> 27
Both numbers will be greater than 1

Restrictions :
This is code-golf so shortest code (in bytes) for each language wins.

Notes :
All input will be valid. i.e : Both inputs will be greater than 1 and will be integers.

*/

#include <assert.h>
#include <math.h>

typedef unsigned long long uvlong;

uvlong
digsum(uvlong n)
{
	uvlong r;

	for (r = 0; n; n /= 10)
		r += n % 10;
	return r;
}

uvlong
digsumpow(uvlong x, uvlong y)
{
	return digsum(pow(x, y));
}

int
main()
{
	assert(digsumpow(5, 2) == 7);
	assert(digsumpow(9, 4) == 18);
	assert(digsumpow(3, 17) == 27);

	return 0;
}
