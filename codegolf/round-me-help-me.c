/*

Given an input n, your program or function must output the smallest positive integer k such that n rounded to the nearest multiple of k is greater than n.

Example.
Given an input 20, the output value should be 3:

The nearest multiple of 1 is 20, which is not greater than 20.

The nearest multiple of 2 is 20, which is not greater than 20.

The nearest multiple of 3 is 21, which is greater than 20, so it is output.

Test Cases
#Input  #Output
2       3
4       5
6       4
8       3
10      4
12      7
14      3
16      6
18      4
20      3
22      4
24      5
26      3
28      5
30      4
32      3
34      4
36      8
38      3
40      6
42      4
44      3
46      4
48      5
50      3
52      6
54      4
56      3
58      4
60      7
62      3
64      5
66      4
68      3
70      4
72      11
74      3
76      6
78      4
80      3
82      4
84      5
86      3
88      5
90      4
92      3
94      4
96      7
98      3
1000    6

The output given any odd input should be 2.

Rules
n is a positive integer less than 2^32
rounding is performed such that if two multiples of k are equally distant from n, the greater one is chosen ("round halves up"). In this way, every odd n yields an output of 2.
This is code-golf, so shortest code in each language wins.

*/

#include <assert.h>
#include <stdio.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
multiple(int n)
{
	int i;

	for (i = 2; i < INT_MAX; i++) {
		if (((n % i) << 1) >= i)
			return i;
	}
	return -1;
}

int
main()
{
	static const int tab[][2] = {
	    {2, 3},
	    {4, 5},
	    {6, 4},
	    {8, 3},
	    {10, 4},
	    {12, 7},
	    {14, 3},
	    {16, 6},
	    {18, 4},
	    {20, 3},
	    {22, 4},
	    {24, 5},
	    {26, 3},
	    {28, 5},
	    {30, 4},
	    {32, 3},
	    {34, 4},
	    {36, 8},
	    {38, 3},
	    {40, 6},
	    {42, 4},
	    {44, 3},
	    {46, 4},
	    {48, 5},
	    {50, 3},
	    {52, 6},
	    {54, 4},
	    {56, 3},
	    {58, 4},
	    {60, 7},
	    {62, 3},
	    {64, 5},
	    {66, 4},
	    {68, 3},
	    {70, 4},
	    {72, 11},
	    {74, 3},
	    {76, 6},
	    {78, 4},
	    {80, 3},
	    {82, 4},
	    {84, 5},
	    {86, 3},
	    {88, 5},
	    {90, 4},
	    {92, 3},
	    {94, 4},
	    {96, 7},
	    {98, 3},
	    {1000, 6},
	};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(multiple(tab[i][0]) == tab[i][1]);

	return 0;
}
