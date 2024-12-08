/*

I am learning Ruby and wrote my first nontrivial code to solve this problem.

The challenge is to generate the first n elements of the Stöhr sequence, S, which is defined as follows:

S[0] = 1

S[n] is the smallest number that cannot be expressed as the sum of two distinct previous elements in the sequence.

Thus the sequence begins with 1, 2, 4, 7, and 10. The next element is 13, because 11 (=1+10) and 12 (=2+10) are sums of previous elements, but 13 is not.

I am looking for the shortest code. My own, in Ruby, is 108 characters long, but maybe I'll wait to see what others come up with before posting it?

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define max(a, b) (((a) > (b)) ? (a) : (b))

// https://oeis.org/A033627
int
stohr(int n)
{
	if (n <= 2)
		return max(n, 0);
	return (3 * n) - 5;
}

int
main()
{
	static const int tab[] = {1, 2, 4, 7, 10, 13, 16, 19, 22, 25, 28, 31, 34, 37, 40, 43, 46, 49, 52, 55, 58, 61, 64, 67, 70, 73, 76, 79, 82, 85, 88, 91, 94, 97, 100, 103, 106, 109, 112, 115, 118, 121, 124, 127, 130, 133, 136, 139, 142, 145, 148, 151, 154, 157, 160, 163, 166, 169, 172, 175};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(stohr(i + 1) == tab[i]);

	return 0;
}
