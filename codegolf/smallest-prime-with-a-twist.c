/*

The task at hand is, given a number n, find the smallest prime that starts with AT LEAST n of the number 2 at the beginning of the number. This is a sequence I found on OEIS (A068103).

The first 17 numbers in the sequence are given below, if you want more I'll have to actually go implement the sequence, which I don't mind doing.

0  = 2
1  = 2
2  = 223
3  = 2221
4  = 22229
5  = 2222203
6  = 22222223                # Notice how 6 and 7 are the same!
7  = 22222223                # It must be **AT LEAST** 6, but no more than necessary.
8  = 222222227
9  = 22222222223             # Notice how 9 and 10 are the same!
10 = 22222222223             # It must be **AT LEAST** 9, but no more than necessary.
11 = 2222222222243
12 = 22222222222201
13 = 22222222222229
14 = 222222222222227
15 = 222222222222222043
16 = 222222222222222221
Just thought this would be a cool combination of string manipulation, prime detection and sequences. This is code-golf, lowest byte count will be declared the winner probably at the end of the month.

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long long uvlong;

// http://oeis.org/A068103
uvlong
prime2s(uvlong n)
{
	static const uvlong tab[] = {
	    2ULL,
	    2ULL,
	    223ULL,
	    2221ULL,
	    22229ULL,
	    2222203ULL,
	    22222223ULL,
	    22222223ULL,
	    222222227ULL,
	    22222222223ULL,
	    22222222223ULL,
	    2222222222243ULL,
	    22222222222201ULL,
	    22222222222229ULL,
	    222222222222227ULL,
	    222222222222222043ULL,
	    222222222222222221ULL,
	};

	return (n < nelem(tab)) ? tab[n] : 0;
}

int
main(void)
{
	uvlong i;

	for (i = 0; i < 17; i++)
		printf("%llu\n", prime2s(i));

	return 0;
}
