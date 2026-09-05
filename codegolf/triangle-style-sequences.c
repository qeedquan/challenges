/*

Consider the triangular numbers and their forward differences:

T=1,3,6,10,15,21,...
ΔT=2,3,4,5,6,...

If we alter ΔT so that it begins with a different integer, we get a different, yet similar sequence (assuming that it begins with T′1=1):

ΔT′=3,4,5,6,7,8,...T′=1,4,8,13,19,26,34,...

This can be extended to begin with negative numbers:

ΔT′=−2,−1,0,1,2,3,...T′=1,−1,−2,−2,−1,1,4,...

More generally, for a given integer n, we can define a "triangle-style" sequence T′ as a sequence whose forward differences form the sequence n,n+1,n+2,n+3,..., and that has 1 as its first term

You should take an integer n and do one of:

Take a positive integer m and output the first m integers of the "triangle-style" sequence for n
Take an integer m and output the mth integer in the "triangle-style" sequence for n. You may use either 0 or 1 indexing
Output all integers in the "triangle-style" sequence for n
This is code-golf, so the shortest code in bytes wins

Test cases
These are the first 10 outputs for each provided n:

 n -> out
-4 -> 1, -3, -6, -8, -9, -9, -8, -6, -3, 1
-3 -> 1, -2, -4, -5, -5, -4, -2, 1, 5, 10
-2 -> 1, -1, -2, -2, -1, 1, 4, 8, 13, 19
-1 -> 1, 0, 0, 1, 3, 6, 10, 15, 21, 28
 0 -> 1, 1, 2, 4, 7, 11, 16, 22, 29, 37
 1 -> 1, 2, 4, 7, 11, 16, 22, 29, 37, 46
 2 -> 1, 3, 6, 10, 15, 21, 28, 36, 45, 55
 3 -> 1, 4, 8, 13, 19, 26, 34, 43, 53, 64
 4 -> 1, 5, 10, 16, 23, 31, 40, 50, 61, 73
39 -> 1, 40, 80, 121, 163, 206, 250, 295, 341, 388
68 -> 1, 69, 138, 208, 279, 351, 424, 498, 573, 649
48 -> 1, 49, 98, 148, 199, 251, 304, 358, 413, 469

*/

#include <assert.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
tss(int n, int m, int *r)
{
	int i, x;

	x = 1;
	for (i = 0; i < m; i++) {
		r[i] = x;
		x += n;
		n += 1;
	}
}

void
test(int n, int *r, size_t nr)
{
	int p[128];

	tss(n, nr, p);
	assert(!memcmp(p, r, sizeof(*r) * nr));
}

int
main(void)
{
	int r1[] = {1, -3, -6, -8, -9, -9, -8, -6, -3, 1};
	int r2[] = {1, -2, -4, -5, -5, -4, -2, 1, 5, 10};
	int r3[] = {1, -1, -2, -2, -1, 1, 4, 8, 13, 19};
	int r4[] = {1, 0, 0, 1, 3, 6, 10, 15, 21, 28};
	int r5[] = {1, 1, 2, 4, 7, 11, 16, 22, 29, 37};
	int r6[] = {1, 2, 4, 7, 11, 16, 22, 29, 37, 46};
	int r7[] = {1, 3, 6, 10, 15, 21, 28, 36, 45, 55};
	int r8[] = {1, 4, 8, 13, 19, 26, 34, 43, 53, 64};
	int r9[] = {1, 5, 10, 16, 23, 31, 40, 50, 61, 73};
	int r10[] = {1, 40, 80, 121, 163, 206, 250, 295, 341, 388};
	int r11[] = {1, 69, 138, 208, 279, 351, 424, 498, 573, 649};
	int r12[] = {1, 49, 98, 148, 199, 251, 304, 358, 413, 469};

	test(-4, r1, nelem(r1));
	test(-3, r2, nelem(r2));
	test(-2, r3, nelem(r3));
	test(-1, r4, nelem(r4));
	test(0, r5, nelem(r5));
	test(1, r6, nelem(r6));
	test(2, r7, nelem(r7));
	test(3, r8, nelem(r8));
	test(4, r9, nelem(r9));
	test(39, r10, nelem(r10));
	test(68, r11, nelem(r11));
	test(48, r12, nelem(r12));

	return 0;
}
