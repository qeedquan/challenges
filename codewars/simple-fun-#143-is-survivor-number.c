/*

Task
Changu and Mangu are great buddies. Once they found an infinite paper which had 1,2,3,4,5,6,7,8,......... till infinity, written on it.

Both of them did not like the sequence and started deleting some numbers in the following way.

First they deleted every 2nd number.

So remaining numbers on the paper: 1,3,5,7,9,11..........till infinity.

Then they deleted every 3rd number.

So remaining numbers on the paper: 1,3,7,9,13,15..........till infinity..

Then they deleted every 4th number.

So remaining numbers on the paper: 1,3,7,13,15..........till infinity.

Then kept on doing this (deleting every 5th, then every 6th ...) untill they got old and died.

It is obvious that some of the numbers will never get deleted(E.g. 1,3,7,13..) and hence are know to us as survivor numbers.

Given a number n, check whether its a survivor number or not.

Input/Output
[input] integer n
0 < n <= 10^8

[output] a boolean value
true if the number is a survivor else false.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

// https://oeis.org/A000960
bool
survivor(int n)
{
	int i;

	if (n < 1)
		return false;

	for (i = 2; n >= i; i++) {
		if (!(n % i))
			return false;
		n -= n / i;
	}
	return true;
}

int
main()
{
	static const int tab[] = {
		1, 3, 7, 13, 19, 27, 39, 49, 63, 79, 91, 109, 133, 147, 181, 207, 223,
		253, 289, 307, 349, 387, 399, 459, 481, 529, 567, 613, 649, 709, 763,
		807, 843, 927, 949, 1009, 1093, 1111, 1189, 1261, 1321, 1359, 1471,
		1483, 1579, 1693, 1719, 1807, 1899, 1933, 2023
	};

	size_t i;
	int n;

	n = 0;
	for (i = 0; i < nelem(tab); n++) {
		if (n == tab[i]) {
			assert(survivor(n) == true);
			i += 1;
		} else
			assert(survivor(n) == false);
	}

	return 0;
}
