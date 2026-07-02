/*

Given a natural number n write a program or function to get a list of all the possible two factors multiplications that can be used to achieve n. To understand better what is pretended you can go to http://factornumber.com/?page=16777216 to see when n is 16777216 we get the following list:

   2 × 8388608
   4 × 4194304
   8 × 2097152
  16 × 1048576
  32 ×  524288
  64 ×  262144
 128 ×  131072
 256 ×   65536
 512 ×   32768
1024 ×   16384
2048 ×    8192
4096 ×    4096
No need to pretty print things like here. The requirement is that each entry (pair of factors) is well distinguished from each other and inside each pair, the first factor is also well distinguished from the other. If you choose to return a list/array, the inside element can be a list/array with two elements, or some structure of your language that supports a pair of things like C++ std::pair.

Do not print the multiplication by 1 entry, nor repeat entries with the first factor commuted by the second, as they are pretty useless.

No winner; it will be a per language basis code golf.

*/

#include <stdio.h>
#include <math.h>

typedef unsigned long ulong;

void
factor2(ulong n)
{
	ulong i, s;
	int l;

	s = ceil(sqrt(n));
	l = log10(n + 1);
	printf("n = %lu\n", n);
	for (i = 2; i <= s; i++) {
		if (!(n % i))
			printf("%*lu x %-*lu\n", l, i, l, n / i);
	}
	printf("\n");
}

int
main()
{
	factor2(16777216);
	factor2(100);
	factor2(1023);

	return 0;
}
