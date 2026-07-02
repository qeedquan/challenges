/*

Task
Given n, output position of the last odd digit in the decimal representation of 2^n (counting from the end).

Rules
There are no odd digits for n=1,2,3,6,11 (2,4,8,64,2048) - you may output anything that is not a positive integer for them (no need to be consistent).
You choose whether to handle n=0.
Standard sequence I/O rules.
This is code-golf.
Test-cases
    n answer   (2^n)
    1     NA       2
    2     NA       4
    3     NA       8
    4      2      16
    5      2      32
    6     NA      64
    7      3     128
    8      2     256
    9      2     512
   10      4    1024
   11     NA    2048
   12      2    4096
   13      2    8192
   14      3   16384
   15      3   32768
   16      2   65536
   17      2  131072
   18      3  262144
   19      6  524288
   20      2 1048576
Inspired by this Mathematics SE post and comments on OEIS A068994.

*/

#include <assert.h>

typedef unsigned long long uvlong;

uvlong
lodp2(uvlong n)
{
	uvlong r;

	n = 1ULL << n;
	for (r = 0; n; r++) {
		if ((n % 10) & 1)
			return r + 1;
		n /= 10;
	}
	return 0;
}

int
main(void)
{
	assert(lodp2(1) == 0);
	assert(lodp2(2) == 0);
	assert(lodp2(3) == 0);
	assert(lodp2(4) == 2);
	assert(lodp2(5) == 2);
	assert(lodp2(6) == 0);
	assert(lodp2(7) == 3);
	assert(lodp2(8) == 2);
	assert(lodp2(9) == 2);
	assert(lodp2(10) == 4);
	assert(lodp2(11) == 0);
	assert(lodp2(12) == 2);
	assert(lodp2(13) == 2);
	assert(lodp2(14) == 3);
	assert(lodp2(15) == 3);
	assert(lodp2(16) == 2);
	assert(lodp2(17) == 2);
	assert(lodp2(18) == 3);
	assert(lodp2(19) == 6);
	assert(lodp2(20) == 2);

	return 0;
}
