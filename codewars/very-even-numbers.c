/*

Task
Write a function that returns true if the number is a "Very Even" number.

If a number is a single digit, then it is simply "Very Even" if it itself is even.

If it has 2 or more digits, it is "Very Even" if the sum of its digits is "Very Even".

Examples
number = 88 => returns false -> 8 + 8 = 16 -> 1 + 6 = 7 => 7 is odd

number = 222 => returns true -> 2 + 2 + 2 = 6 => 6 is even

number = 5 => returns false

number = 841 => returns true -> 8 + 4 + 1 = 13 -> 1 + 3 => 4 is even
Note: The numbers will always be 0 or positive integers!

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long long uvlong;

uvlong
digsum(uvlong n)
{
	uvlong r;

	for (r = 0; n > 0; n /= 10)
		r += n % 10;
	return r;
}

// https://oeis.org/A262773
bool
veryeven(uvlong n)
{
	while (n >= 10)
		n = digsum(n);
	return !(n & 1);
}

int
main()
{
	static const uvlong tab[] = {
		0, 2, 4, 6, 8, 11, 13, 15, 17, 20, 22, 24, 26, 29, 31,
		33, 35, 38, 40, 42, 44, 47, 49, 51, 53, 56, 58, 60, 62,
		65, 67, 69, 71, 74, 76, 78, 80, 83, 85, 87, 89, 92, 94,
		96, 98, 101, 103, 105, 107, 110, 112, 114, 116, 119,
		121, 123, 125, 128, 130, 132, 134, 137, 139
	};

	uvlong i, j, n;

	n = tab[nelem(tab) - 1];
	for (i = j = 0; i <= n; i++) {
		if (i == tab[j]) {
			assert(veryeven(i) == true);
			j += 1;
		} else
			assert(veryeven(i) == false);
	}

	assert(veryeven(0) == true);
	assert(veryeven(4) == true);
	assert(veryeven(12) == false);
	assert(veryeven(222) == true);
	assert(veryeven(5) == false);
	assert(veryeven(45) == false);
	assert(veryeven(4554) == false);
	assert(veryeven(1234) == false);
	assert(veryeven(88) == false);
	assert(veryeven(24) == true);
	assert(veryeven(400000220) == true);

	return 0;
}
