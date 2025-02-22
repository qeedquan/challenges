/*

Introduction
Suppose you have a ruler with numbers from 0 to r-1. You place an ant between any two of the numbers, and it starts to crawl erratically on the ruler. The ruler is so narrow that the ant cannot walk from one position to another without walking on all the numbers in between. As the ant walks on a number for the first time, you record it, and this gives you a permutation of the r numbers. We say that a permutation is antsy if it can be generated by an ant in this way. Alternatively, a permutation p is antsy if every entry p[i] except the first is within distance 1 from some previous entry.

Examples
The length-6 permutation

4, 3, 5, 2, 1, 0
is antsy, because 3 is within distance 1 of 4, 5 is within distance 1 of 4, 2 is within distance 1 from 3, 1 is within distance 1 from 2, and 0 is within distance 1 from 1. The permutation

3, 2, 5, 4, 1, 0
is not antsy, because 5 is not within distance 1 of either 3 or 2; the ant would have to pass through 4 to get to 5.

The task
Given a permutation of the numbers from 0 to r-1 for some 1 ≤ r ≤ 100 in any reasonable format, output a truthy value if the permutation is antsy, and a falsy value if not.

Test cases
[0] -> True
[0, 1] -> True
[1, 0] -> True
[0, 1, 2] -> True
[0, 2, 1] -> False
[2, 1, 3, 0] -> True
[3, 1, 0, 2] -> False
[1, 2, 0, 3] -> True
[2, 3, 1, 4, 0] -> True
[2, 3, 0, 4, 1] -> False
[0, 5, 1, 3, 2, 4] -> False
[6, 5, 4, 7, 3, 8, 9, 2, 1, 0] -> True
[4, 3, 5, 6, 7, 2, 9, 1, 0, 8] -> False
[5, 2, 7, 9, 6, 8, 0, 4, 1, 3] -> False
[20, 13, 7, 0, 14, 16, 10, 24, 21, 1, 8, 23, 17, 18, 11, 2, 6, 22, 4, 5, 9, 12, 3, 15, 19] -> False
[34, 36, 99, 94, 77, 93, 31, 90, 21, 88, 30, 66, 92, 83, 42, 5, 86, 11, 15, 78, 40, 48, 22, 29, 95, 64, 97, 43, 14, 33, 69, 49, 50, 35, 74, 46, 26, 51, 75, 87, 23, 85, 41, 98, 82, 79, 59, 56, 37, 96, 45, 17, 32, 91, 62, 20, 4, 9, 2, 18, 27, 60, 63, 25, 61, 76, 1, 55, 16, 8, 6, 38, 54, 47, 73, 67, 53, 57, 7, 72, 84, 39, 52, 58, 0, 89, 12, 68, 70, 24, 80, 3, 44, 13, 28, 10, 71, 65, 81, 19] -> False
[47, 48, 46, 45, 44, 49, 43, 42, 41, 50, 40, 39, 38, 51, 37, 36, 52, 35, 34, 33, 32, 53, 54, 31, 30, 55, 56, 29, 28, 57, 58, 59, 60, 27, 26, 61, 25, 62, 63, 64, 65, 66, 67, 24, 23, 22, 21, 68, 69, 20, 19, 18, 17, 70, 71, 16, 15, 72, 73, 74, 75, 76, 14, 13, 12, 77, 11, 10, 9, 8, 78, 7, 79, 80, 6, 81, 5, 4, 3, 82, 2, 83, 84, 1, 85, 86, 87, 0, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99] -> True

Fun fact: for r ≥ 1, there are exactly 2^(r-1) antsy permutations of length r.

*/

#include <assert.h>
#include <stdio.h>
#include <limits.h>

typedef unsigned uint;

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

/*

@xnor

Checks whether the vector difference of the running maxima and the running minima is [0,1,2,3...].

Why does this work? For a permutation to be antsy, stepping from 0 to n-1 must consist of going only left, then going only right.
This is because the elements greater than the first element must increase left to right, and those less than it must decrease left to right.

If we mirror the list by putting a reversed copy to its left, this walk now only goes right.

Conversely, any rightward of this mirror list corresponds to a left-then-right walk of the original list.
This rightward just is a sorted subsequence of 0 to n-1.
In an antsy list, this sorted subsequence is unique, except for an arbitrary choice between the two adjacent copies of the original first element.

*/

bool
antsy(uint *a, size_t n)
{
	size_t i;
	uint x, y;

	x = UINT_MAX;
	y = 0;
	for (i = 0; i < n; i++) {
		x = min(x, a[i]);
		y = max(y, a[i]);
		if (y - x != i)
			return false;
	}
	return true;
}

int
main()
{
	uint a1[] = {0};
	uint a2[] = {0, 1};
	uint a3[] = {1, 0};
	uint a4[] = {0, 1, 2};
	uint a5[] = {0, 2, 1};
	uint a6[] = {2, 1, 3, 0};
	uint a7[] = {3, 1, 0, 2};
	uint a8[] = {1, 2, 0, 3};
	uint a9[] = {2, 3, 1, 4, 0};
	uint a10[] = {2, 3, 0, 4, 1};
	uint a11[] = {0, 5, 1, 3, 2, 4};
	uint a12[] = {6, 5, 4, 7, 3, 8, 9, 2, 1, 0};
	uint a13[] = {4, 3, 5, 6, 7, 2, 9, 1, 0, 8};
	uint a14[] = {5, 2, 7, 9, 6, 8, 0, 4, 1, 3};
	uint a15[] = {20, 13, 7, 0, 14, 16, 10, 24, 21, 1, 8, 23, 17, 18, 11, 2, 6, 22, 4, 5, 9, 12, 3, 15, 19};
	uint a16[] = {34, 36, 99, 94, 77, 93, 31, 90, 21, 88, 30, 66, 92, 83, 42, 5, 86, 11, 15, 78, 40, 48, 22, 29, 95, 64, 97, 43, 14, 33, 69, 49, 50, 35, 74, 46, 26, 51, 75, 87, 23, 85, 41, 98, 82, 79, 59, 56, 37, 96, 45, 17, 32, 91, 62, 20, 4, 9, 2, 18, 27, 60, 63, 25, 61, 76, 1, 55, 16, 8, 6, 38, 54, 47, 73, 67, 53, 57, 7, 72, 84, 39, 52, 58, 0, 89, 12, 68, 70, 24, 80, 3, 44, 13, 28, 10, 71, 65, 81, 19};
	uint a17[] = {47, 48, 46, 45, 44, 49, 43, 42, 41, 50, 40, 39, 38, 51, 37, 36, 52, 35, 34, 33, 32, 53, 54, 31, 30, 55, 56, 29, 28, 57, 58, 59, 60, 27, 26, 61, 25, 62, 63, 64, 65, 66, 67, 24, 23, 22, 21, 68, 69, 20, 19, 18, 17, 70, 71, 16, 15, 72, 73, 74, 75, 76, 14, 13, 12, 77, 11, 10, 9, 8, 78, 7, 79, 80, 6, 81, 5, 4, 3, 82, 2, 83, 84, 1, 85, 86, 87, 0, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99};

	assert(antsy(a1, nelem(a1)) == true);
	assert(antsy(a2, nelem(a2)) == true);
	assert(antsy(a3, nelem(a3)) == true);
	assert(antsy(a4, nelem(a4)) == true);
	assert(antsy(a5, nelem(a5)) == false);
	assert(antsy(a6, nelem(a6)) == true);
	assert(antsy(a7, nelem(a7)) == false);
	assert(antsy(a8, nelem(a8)) == true);
	assert(antsy(a9, nelem(a9)) == true);
	assert(antsy(a10, nelem(a10)) == false);
	assert(antsy(a11, nelem(a11)) == false);
	assert(antsy(a12, nelem(a12)) == true);
	assert(antsy(a13, nelem(a13)) == false);
	assert(antsy(a14, nelem(a14)) == false);
	assert(antsy(a15, nelem(a15)) == false);
	assert(antsy(a16, nelem(a16)) == false);
	assert(antsy(a17, nelem(a17)) == true);

	return 0;
}
