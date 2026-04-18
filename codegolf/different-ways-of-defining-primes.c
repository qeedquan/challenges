/*

One of my favorite definitions of the prime numbers goes as follows:

2 is the smallest prime.

Numbers larger than 2 are prime if they are not divisible by a smaller prime.

However this definition seems arbitrary, why 2? Why not some other number? Well lets try some other numbers will define n-prime such that

n is the smallest n-prime.

Numbers larger than n are n-prime if they are not divisible by a smaller n-prime.

Task
The task here is to write a program that takes two inputs, a positive integer n and a positive integer a. It will then decide if a is n-prime. Your program should output two distinct values one for "yes, it is n-prime" and one for "no, it is not n-prime".

This is a code-golf question so answers will be scored in bytes with less bytes being better.

Tests
Here are lists of the first 31 primes for n=2 to n=12 (1 is the only 1-prime number)

n=2: [2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127]
n=3: [3,4,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127]
n=4: [4,5,6,7,9,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113]
n=5: [5,6,7,8,9,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113]
n=6: [6,7,8,9,10,11,13,15,17,19,23,25,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107]
n=7: [7,8,9,10,11,12,13,15,17,19,23,25,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107]
n=8: [8,9,10,11,12,13,14,15,17,19,21,23,25,29,31,35,37,41,43,47,49,53,59,61,67,71,73,79,83,89,97]
n=9: [9,10,11,12,13,14,15,16,17,19,21,23,25,29,31,35,37,41,43,47,49,53,59,61,67,71,73,79,83,89,97]
n=10: [10,11,12,13,14,15,16,17,18,19,21,23,25,27,29,31,35,37,41,43,47,49,53,59,61,67,71,73,79,83,89]
n=11: [11,12,13,14,15,16,17,18,19,20,21,23,25,27,29,31,35,37,41,43,47,49,53,59,61,67,71,73,79,83,89]
n=12: [12,13,14,15,16,17,18,19,20,21,22,23,25,27,29,31,33,35,37,41,43,47,49,53,55,59,61,67,71,73,77]

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
nprime(int n, int k)
{
	int i;

	if (k < n)
		return false;

	for (i = n; i < k; i++) {
		if (!(k % i))
			return false;
	}
	return true;
}

size_t
gen(int n, int *r, size_t nr)
{
	size_t i, k;

	i = 0;
	for (k = 1; k < INT_MAX && i < nr; k++) {
		if (nprime(n, k))
			r[i++] = k;
	}
	return i;
}

void
test(int n, int *r, size_t nr)
{
	int p[128];
	size_t np;

	np = gen(n, p, nr);
	assert(np == nr);
	assert(!memcmp(p, r, sizeof(*r) * nr));
}

int
main()
{
	int p2[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127};
	int p3[] = {3, 4, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127};
	int p4[] = {4, 5, 6, 7, 9, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113};
	int p5[] = {5, 6, 7, 8, 9, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113};
	int p6[] = {6, 7, 8, 9, 10, 11, 13, 15, 17, 19, 23, 25, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107};
	int p7[] = {7, 8, 9, 10, 11, 12, 13, 15, 17, 19, 23, 25, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107};
	int p8[] = {8, 9, 10, 11, 12, 13, 14, 15, 17, 19, 21, 23, 25, 29, 31, 35, 37, 41, 43, 47, 49, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
	int p9[] = {9, 10, 11, 12, 13, 14, 15, 16, 17, 19, 21, 23, 25, 29, 31, 35, 37, 41, 43, 47, 49, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
	int p10[] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 21, 23, 25, 27, 29, 31, 35, 37, 41, 43, 47, 49, 53, 59, 61, 67, 71, 73, 79, 83, 89};
	int p11[] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 23, 25, 27, 29, 31, 35, 37, 41, 43, 47, 49, 53, 59, 61, 67, 71, 73, 79, 83, 89};
	int p12[] = {12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 25, 27, 29, 31, 33, 35, 37, 41, 43, 47, 49, 53, 55, 59, 61, 67, 71, 73, 77};

	test(2, p2, nelem(p2));
	test(3, p3, nelem(p3));
	test(4, p4, nelem(p4));
	test(5, p5, nelem(p5));
	test(6, p6, nelem(p6));
	test(7, p7, nelem(p7));
	test(8, p8, nelem(p8));
	test(9, p9, nelem(p9));
	test(10, p10, nelem(p10));
	test(11, p11, nelem(p11));
	test(12, p12, nelem(p12));

	return 0;
}
