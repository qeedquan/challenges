/*

Let n=42 (Input)

Then divisors are : 1, 2, 3, 6, 7, 14, 21, 42

Squaring each divisor : 1, 4, 9, 36, 49, 196, 441, 1764

Taking sum (adding) : 2500

Since 50×50=2500
 therefore we return a truthy value. If it is not a perfect square, return a falsy value.

Examples :
42  ---> true
1   ---> true
246 ---> true
10  ---> false
16  ---> false
This is code-golf so shortest code in bytes for each language wins

Thanks to @Arnauld for pointing out the sequence : A046655

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long long uvlong;

// https://oeis.org/A046655
uvlong
ss2(uvlong n)
{
	uvlong i, s, r;

	if (n == 0)
		return false;

	r = 0;
	for (i = 1; i <= n; i++) {
		if (!(n % i))
			r += i * i;
	}
	s = sqrt(r);
	return s * s == r;
}

int
main(void)
{
	static const uvlong tab[] = {1, 42, 246, 287, 728, 1434, 1673, 1880, 4264, 6237, 9799, 9855, 18330, 21352, 21385, 24856, 36531, 39990, 46655, 57270, 66815, 92664, 125255, 156570, 182665, 208182, 212949, 242879, 273265, 380511, 391345, 411558, 539560, 627215, 693160, 730145, 741096};

	uvlong i;

	assert(ss2(42) == true);
	assert(ss2(1) == true);
	assert(ss2(246) == true);
	assert(ss2(10) == false);
	assert(ss2(16) == false);

	for (i = 0; i < nelem(tab); i++)
		assert(ss2(tab[i]) == true);

	return 0;
}
