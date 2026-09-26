/*

You know what a monotonic sequence is: each element is bigger than its predecessor (monotonically rising) or as its successor (monotonically falling).

Bitonic means you have two arms of the sequence, one monotonically rising, the other falling.

For example, 1,3,5,7,6,4,2 is bitonic (rising until 7, then falling until the end; 99,4,8,16 is as well (falling until 4, then rising until the end).

The task is to test, whether a sequence is bitonic, but not monotonic as short as possible in your language of choice.

Input: A list of positive integer numbers without duplicates in a form that suits your language.

Output: Truthy/falsy

Test data:

True:
1,3,5,7,6,4,2
99,4,8,16
100000,10000,1000,100,10,1,11,111,1111,11111,111111
2,1,3,4,5,6

False:
1,2,3,4,5,6,7
7,6,5,4,3,2,1
1,4,7,6,2,3,5
99,88,66,77,55,44,33,22,11
1,9,2,8,3,7,4,6,5

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
bitonic(long *a, size_t n)
{
	size_t i;
	int f;

	f = 0;
	for (i = 1; i < n && a[i] > a[i - 1]; i++)
		f |= 1;

	for (; i < n && a[i] < a[i - 1]; i++)
		f |= 2;

	if (f == 2) {
		for (; i < n && a[i] > a[i - 1]; i++)
			f |= 1;
	}

	return f == 3 && i == n;
}

int
main(void)
{
	long t1[] = {1, 3, 5, 7, 6, 4, 2};
	long t2[] = {99, 4, 8, 16};
	long t3[] = {100000, 10000, 1000, 100, 10, 1, 11, 111, 1111, 11111, 111111};
	long t4[] = {2, 1, 3, 4, 5, 6};
	long t5[] = {1, 3, 2};
	long t6[] = {2, 1, 2};

	long f1[] = {1, 2, 3, 4, 5, 6, 7};
	long f2[] = {7, 6, 5, 4, 3, 2, 1};
	long f3[] = {1, 4, 7, 6, 2, 3, 5};
	long f4[] = {99, 88, 66, 77, 55, 44, 33, 22, 11};
	long f5[] = {1, 9, 2, 8, 3, 7, 4, 6, 5};
	long f6[] = {0, 0, 0};
	long f7[] = {1, 2};
	long f8[] = {2, 1, 1};

	assert(bitonic(t1, nelem(t1)) == true);
	assert(bitonic(t2, nelem(t2)) == true);
	assert(bitonic(t3, nelem(t3)) == true);
	assert(bitonic(t4, nelem(t4)) == true);
	assert(bitonic(t5, nelem(t5)) == true);
	assert(bitonic(t6, nelem(t6)) == true);

	assert(bitonic(f1, nelem(f1)) == false);
	assert(bitonic(f2, nelem(f2)) == false);
	assert(bitonic(f3, nelem(f3)) == false);
	assert(bitonic(f4, nelem(f4)) == false);
	assert(bitonic(f5, nelem(f5)) == false);
	assert(bitonic(f6, nelem(f6)) == false);
	assert(bitonic(f7, nelem(f7)) == false);
	assert(bitonic(f8, nelem(f8)) == false);

	return 0;
}
