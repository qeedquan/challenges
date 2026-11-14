/*

Your task is to, given two positive integers, x and n, return the first x numbers in the incremental ranges sequence.

The incremental range sequence first generates a range from one to n inclusive. For example, if n was 3, it would generate the list [1,2,3].
It then repeatedly appends the last n values incremented by 1 to the existing list, and continues.

An input of n=3 for example:

n=3
1. Get range 1 to n. List: [1,2,3]
2. Get the last n values of the list. List: [1,2,3]. Last n=3 values: [1,2,3].
3. Increment the last n values by 1. List: [1,2,3]. Last n values: [2,3,4].
4. Append the last n values incremented to the list. List: [1,2,3,2,3,4]
5. Repeat steps 2-5. 2nd time repeat shown below.

2nd repeat:
2. Get the last n values of the list. List: [1,2,3,2,3,4]. Last n=3 values: [2,3,4]
3. Increment the last n values by 1. List: [1,2,3,2,3,4]. Last n values: [3,4,5].
4. Append the last n values incremented to the list. List: [1,2,3,2,3,4,3,4,5]

Test cases:

n,   x,   Output
1,  49,   [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49]
2, 100,   [1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10,11,11,12,12,13,13,14,14,15,15,16,16,17,17,18,18,19,19,20,20,21,21,22,22,23,23,24,24,25,25,26,26,27,27,28,28,29,29,30,30,31,31,32,32,33,33,34,34,35,35,36,36,37,37,38,38,39,39,40,40,41,41,42,42,43,43,44,44,45,45,46,46,47,47,48,48,49,49,50,50,51]
3,  13,   [1,2,3,2,3,4,3,4,5,4,5,6,5]

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

size_t
ranges(int n, int x, int *r)
{
	int i;

	for (i = 0; i < x; i++)
		r[i] = (i / n) + (i % n) + 1;
	return i;
}

void
test(int n, int x, int *r, size_t nr)
{
	int p[128];
	size_t np;

	np = ranges(n, x, p);
	assert(np == nr);
	assert(!memcmp(p, r, sizeof(*r) * nr));
}

int
main(void)
{
	int r1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49};
	int r2[] = {1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9, 10, 10, 11, 11, 12, 12, 13, 13, 14, 14, 15, 15, 16, 16, 17, 17, 18, 18, 19, 19, 20, 20, 21, 21, 22, 22, 23, 23, 24, 24, 25, 25, 26, 26, 27, 27, 28, 28, 29, 29, 30, 30, 31, 31, 32, 32, 33, 33, 34, 34, 35, 35, 36, 36, 37, 37, 38, 38, 39, 39, 40, 40, 41, 41, 42, 42, 43, 43, 44, 44, 45, 45, 46, 46, 47, 47, 48, 48, 49, 49, 50, 50, 51};
	int r3[] = {1, 2, 3, 2, 3, 4, 3, 4, 5, 4, 5, 6, 5};

	test(1, 49, r1, nelem(r1));
	test(2, 100, r2, nelem(r2));
	test(3, 13, r3, nelem(r3));

	return 0;
}
