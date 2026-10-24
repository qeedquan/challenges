/*

Given an integer  N>3, you have to find the minimum number of bits that need to be inverted in N to turn it into a square number.
You are only allowed to invert bits below the most significant one.

Examples
N=4 already is a square number (22), so the expected output is  0.
N=24 can be turned into a square number by inverting 1 bit:  11000→11001 (25=52), so the expected output is 1.
N=22 cannot be turned into a square number by inverting a single bit (the possible results being  23, 20, 18 and 30) but it can be done by inverting 2 bits:  10110→10000 (16=42), so the expected output is 2.

Rules
It is fine if your code is too slow or throws an error for the bigger test-cases, but it should at least support  3<N<10000 in less than 1 minute.
This is code-golf!
Test cases
    Input | Output
----------+--------
        4 | 0
       22 | 2
       24 | 1
       30 | 3
       94 | 4
      831 | 5
      832 | 1
     1055 | 4
     6495 | 6
     9999 | 4
    40063 | 6
   247614 | 7        (smallest N for which the answer is 7)
  1049310 | 7        (clear them all!)
  7361278 | 8        (smallest N for which the answer is 8)
100048606 | 8        (a bigger "8")

Or in copy/paste friendly format:

[4,22,24,30,94,831,832,1055,6495,9999,40063,247614,1049310,7361278,100048606]

*/

#include <assert.h>
#include <stdio.h>
#include <stdbit.h>

typedef unsigned long long uvlong;
typedef long long vlong;

vlong
bits(uvlong n)
{
	uvlong b, c, i, r, x;

	if (n < 4)
		return -1;

	r = 0;
	b = stdc_bit_width(n);
	for (i = 0; i < n; i++) {
		x = (i * i) ^ n;
		if (stdc_bit_width(x) < b) {
			c = stdc_count_ones(x);
			if (r == 0 || c < r)
				r = c;
		}
	}
	return r;
}

int
main()
{
	assert(bits(4) == 0);
	assert(bits(22) == 2);
	assert(bits(24) == 1);
	assert(bits(30) == 3);
	assert(bits(94) == 4);
	assert(bits(831) == 5);
	assert(bits(832) == 1);
	assert(bits(1055) == 4);
	assert(bits(6495) == 6);
	assert(bits(9999) == 4);
	assert(bits(40063) == 6);
	assert(bits(247614) == 7);
	assert(bits(1049310) == 7);
	assert(bits(7361278) == 8);
	assert(bits(100048606) == 8);

	return 0;
}
