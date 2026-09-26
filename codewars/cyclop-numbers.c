/*

A cyclops number is a number in binary that is made up of all 1's, with one 0 in the exact middle. That means all cyclops numbers must have an odd number of digits for there to be an exact middle.
A couple examples:
101
11111111011111111
You must take an input, n, that will be in decimal format (base 10), then return True if that number wil be a cyclops number when converted to binary, or False if it won't.
Assume n will be a positive integer.

A test cases with the process shown:

cyclops (5)
"""5 in biinary"""
"0b101"
"""because 101 is made up of all "1"s with a "0" in the middle, 101 is a cyclops number"""
return True

cyclops(13)
"""13 in binary"""
"0b1101"
"""because 1101 has an even number of bits, it cannot be a cyclops"""
return False

cyclops(17)
"""17 in binary"""
"0b10001"
"""Because 10001 has more than 1 "0" it cannot be a cyclops number"""
return False

n will always be > 0.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef long long vlong;

// https://oeis.org/A129868
vlong
cyclops(vlong n)
{
	vlong a, b;

	if (n < 0)
		return 0;

	a = 1 << ((n << 1) + 1);
	b = 1 << n;
	return a - b - 1;
}

bool
iscyclops(vlong n)
{
	vlong i, x;

	for (i = 0; i <= n; i++) {
		x = cyclops(i);
		if (x == n)
			return true;
		if (x > n)
			break;
	}
	return false;
}

int
main()
{
	static const vlong tab[] = {
		0, 5, 27, 119, 495, 2015, 8127, 32639, 130815, 523775, 2096127, 8386559, 33550335
	};

	vlong i, j, n;

	n = tab[nelem(tab) - 1];
	for (i = j = 0; i <= n; i++) {
		if (iscyclops(i))
			assert(i == tab[j++]);
	}
	return 0;
}
