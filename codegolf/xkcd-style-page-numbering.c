/*

Randall Munroe's book "xkcd, volume 0" uses a rather odd number system for the page numbers. The first few page numbers are

1, 2, 10, 11, 12, 20, 100, 101, 102, 110, 111, 112, 120, 200, 1000, 1001, ...
This looks a bit like ternary, but notice that he skips from 20 straight to 100, from 120 to 200 and from 200 to 1000. One way to define this sequence is to say that it enumerates all ternary numbers that contain at most one 2 and no 1 after that 2. You can find this on OEIS in entry A169683. This number system is known as skew binary.

Your task is to find the representation of a given positive integer N in this number system.

You may write a program or function, taking input via STDIN (or closest alternative), command-line argument or function argument and outputting the result via STDOUT (or closest alternative), function return value or function (out) parameter.

Output may be a string, a number with a decimal representation equal to the skew binary representation, or a list of digits (as integers or characters/strings). You must not return leading zeroes.

This is code golf, so the shortest answer (in bytes) wins.

Fun fact: There is actually some merit to this number system. When incrementing a number, you will always change at most two adjacent digits - you'll never have to carry the change through the entire number. With the right representation that allows incrementing in O(1).

Test Cases
1 => 1
2 => 2
3 => 10
6 => 20
7 => 100
50 => 11011
100 => 110020
200 => 1100110
1000 => 111110120
10000 => 1001110001012
100000 => 1100001101010020
1000000 => 1111010000100100100
1048576 => 10000000000000000001

1000000000000000000 => 11011110000010110110101100111010011101100100000000000001102
I will give a bounty to the shortest answer which can solve the last test case (and any other input of similar magnitude, so don't think about hardcoding it) in less than a second.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

typedef unsigned long long uvlong;

// https://oeis.org/A169683
char *
dec2skew(uvlong n, char *b)
{
	uvlong d, f;
	size_t i;

	if (n == 0) {
		strcpy(b, "0");
		return b;
	}

	i = 0;
	f = 0;
	for (d = ULLONG_MAX; d; d >>= 1) {
		b[i] = n / d;
		n -= b[i] * d;
		f |= b[i];
		b[i] += '0';
		if (f)
			i++;
	}
	b[i] = '\0';

	return b;
}

void
test(uvlong n, const char *r)
{
	char b[128];

	dec2skew(n, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test(0ULL, "0");
	test(1ULL, "1");
	test(2ULL, "2");
	test(3ULL, "10");
	test(6ULL, "20");
	test(7ULL, "100");
	test(50ULL, "11011");
	test(100ULL, "110020");
	test(200ULL, "1100110");
	test(1000ULL, "111110120");
	test(10000ULL, "1001110001012");
	test(100000ULL, "1100001101010020");
	test(1000000ULL, "1111010000100100100");
	test(1048576ULL, "10000000000000000001");
	test(1000000000000000000ULL, "11011110000010110110101100111010011101100100000000000001102");

	return 0;
}
