/*

Task
Find the set of numbers such that the binary representation contains two or more runs of 1 separated by at least one 0.

For example, the for the numbers that are 4 bits long:

 0 0000        (no ones)
 1 0001        (only one run)
 2 0010        (only one run)
 3 0011        (only one run)
 4 0100        (only one run)
 5 0101 Valid
 6 0110        (only one run)
 7 0111        (only one run)
 8 1000        (only one run)
 9 1001 Valid
10 1010 Valid
11 1011 Valid
12 1100        (only one run)
13 1101 Valid
14 1110        (only one run)
15 1111        (only one run)
Input
An integer provided to the application via some input in the range 3 .. 32. This represents the maximum number of bits to count up to.

The input of n indicates that the numbers 0 .. 2n-1 need to be examined.

Output
A delimited (your choice) list of all numbers meeting the criteria. The numbers are to be presented in numeric order. An extra trailing delimiter is acceptable. Data structure enclosures (e.g. [] and similar) are also acceptable.

Example
Input: 3
Output: 5

Input: 4
Output: 5, 9, 10, 11, 13

Input: 5
Output: 5, 9, 10, 11, 13, 17, 18, 19, 20, 21, 22, 23, 25, 26, 27, 29
This is code-golf - the answer with the least amount of bytes wins.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdbit.h>

typedef unsigned long long uvlong;

// https://oeis.org/A101082
size_t
gen(uvlong n, uvlong *r)
{
	uvlong i, x, y;
	size_t l;

	l = 0;
	n = 1ULL << n;
	for (i = 1; i < n; i++) {
		x = i >> (stdc_first_trailing_one(i) - 1);
		y = stdc_first_trailing_one(~x) - 1;
		if (x >> y)
			r[l++] = i;
	}
	return l;
}

int
main()
{
	static const uvlong tab[] = {
		5, 9, 10, 11, 13, 17, 18, 19, 20, 21, 22, 23, 25, 26, 27, 29, 33, 34,
		35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 49, 50, 51, 52,
		53, 54, 55, 57, 58, 59, 61, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74,
		75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92
	};

	uvlong x[128];

	gen(7, x);
	assert(!memcmp(x, tab, sizeof(tab)));

	return 0;
}
