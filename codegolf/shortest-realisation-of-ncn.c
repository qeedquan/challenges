/*

The task is to find the shortest solution to the following problem:

Given an integer n (0<n<1e7) find n+C(n), where C(n) is the count of set bits in a binary representation of n.

Whitespace must not be included in the final count.

My current solution (78 bytes, C++14):

#include"iostream"
int n;
main() {
  std::cin>>n;
  std::cout<<n+__builtin_popcount(n);
}

*/

#include <assert.h>
#include <stdio.h>
#include <stdbit.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

// https://oeis.org/A092391
unsigned
ncn(unsigned n)
{
	return n + stdc_count_ones(n);
}

int
main()
{
	static const unsigned tab[] = {
		0, 2, 3, 5, 5, 7, 8, 10, 9, 11, 12, 14, 14, 16, 17, 19, 17, 19, 20, 22,
		22, 24, 25, 27, 26, 28, 29, 31, 31, 33, 34, 36, 33, 35, 36, 38, 38, 40,
		41, 43, 42, 44, 45, 47, 47, 49, 50, 52, 50, 52, 53, 55, 55, 57, 58, 60,
		59, 61, 62, 64, 64, 66, 67, 69, 65, 67, 68, 70, 70, 72, 73, 75
	};

	unsigned i;

	for (i = 0; i < nelem(tab); i++)
		assert(ncn(i) == tab[i]);

	return 0;
}
