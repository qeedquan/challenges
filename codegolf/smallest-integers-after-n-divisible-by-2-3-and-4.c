/*

Give credit to whom credit is due.
https://chat.stackexchange.com/transcript/message/29674708#29674708

Objective Given an integer N > 0, out the smallest integers A, B, and C so that:

All of A, B, and C are strictly greater than N;
2 divides A;
3 divides B;
and 4 divides C.
This is a code-golf, so the shortest answer in bytes wins.

Test cases
N => A, B, C
1 => 2, 3, 4
4 => 6, 6, 8
43 => 44, 45, 44
123 => 124, 126, 124
420 => 422, 423, 424
31415 => 31416, 31416, 31416
1081177 => 1081178, 1081179, 1081180

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

void
fill(long n, long r[3])
{
	long i, j;

	j = 0;
	for (i = 2; i < 5; i++)
		r[j++] = n + i - (n % i);
}

void
test(long n, long r[3])
{
	long x[3];

	fill(n, x);
	printf("%ld %ld %ld\n", x[0], x[1], x[2]);
	assert(!memcmp(r, x, sizeof(x)));
}

int
main(void)
{
	long r1[] = {2, 3, 4};
	long r2[] = {6, 6, 8};
	long r3[] = {44, 45, 44};
	long r4[] = {124, 126, 124};
	long r5[] = {422, 423, 424};
	long r6[] = {31416, 31416, 31416};
	long r7[] = {1081178, 1081179, 1081180};

	test(1, r1);
	test(4, r2);
	test(43, r3);
	test(123, r4);
	test(420, r5);
	test(31415, r6);
	test(1081177, r7);

	return 0;
}
