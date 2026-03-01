/*

From the infinite triangular array of positive integers, suppose we repeatedly select all numbers at Euclidean distance of sqrt(3), starting from 1:

                  [1]
                 2  3
               4 [5] 6
             [7] 8 9 [10]
          11 12 [13] 14 15
         16 [17] 18 19 [20] 21
       [22] 23 24 [25] 26 27 [28]

Alternatively, you may think of it as "leave centers of a honeycomb pattern and cross out boundaries".

The resulting sequence (not yet on OEIS, unlike the polkadot numbers) is as follows:

1, 5, 7, 10, 13, 17, 20, 22, 25, 28, 31, 34, 38, 41, 44, 46, 49, 52, 55, 58, 61, 64,
68, 71, 74, 77, 79, 82, 85, 88, 91, 94, 97, 100, 103, 107, 110, 113, 116, 119,
121, 124, 127, 130, 133, 136, 139, 142, 145, 148, 151, 155, 158, 161, 164, 167, 170,
172, 175, 178, 181, 184, 187, 190, ...

The task is to output this sequence. sequence I/O rules apply. You can choose to implement one of the following:

Given the index n (0- or 1-based), output the n
th term of the sequence.
Given a positive integer n, output the first n terms of the sequence.
Take no input and output the entire sequence by printing infinitely or returning a lazy list or a generator.
Standard code-golf rules apply. The shortest code in bytes wins.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

/*

@dingledooper Takes as input an integer n, and outputs the n-th term of the sequence (0-indexed).

lambda n:3*n-~((n*24+1)**.5%6%5<1)

*/

int
honeycomb(int n)
{
	int d, s;

	s = sqrt((n * 24) + 1);
	s = (s % 6) % 5;
	d = (s < 1) ? 2 : 1;
	return (3 * n) + d;
}

int
main(void)
{
	static const int tab[] = {1, 5, 7, 10, 13, 17, 20, 22, 25, 28, 31, 34, 38, 41, 44, 46, 49, 52, 55, 58, 61, 64, 68, 71, 74, 77, 79, 82, 85, 88, 91, 94, 97, 100, 103, 107, 110, 113, 116, 119, 121, 124, 127, 130, 133, 136, 139, 142, 145, 148, 151, 155, 158, 161, 164, 167, 170, 172, 175, 178, 181, 184, 187, 190};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(honeycomb(i) == tab[i]);

	return 0;
}
