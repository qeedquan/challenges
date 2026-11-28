/*

Challenge
Given a non-empty array of integers, e.g.:

[5, 2, 7, 6, 4, 1, 3]
First sever it into arrays where no item is larger than the previous (i.e. non-ascending arrays):

[5, 2] [7, 6, 4, 1] [3]
Next, reverse each array:

[2, 5] [1, 4, 6, 7] [3]
Finally, concatenate them all together:

[2, 5, 1, 4, 6, 7, 3]
This should be what your program outputs/function returns. Repeat this procedure enough times and the array will be fully sorted.

Rules
Input and output may be given through any standard methods, and may be in any reasonable array format.
The input array will never be empty, but may contain negatives and/or duplicates.
The absolute value of each integer will always be less than 231.
Test cases
Hopefully these cover all edge cases:

[1] -> [1]
[1, 1] -> [1, 1]
[1, 2] -> [1, 2]
[2, 1] -> [1, 2]
[2, 3, 1] -> [2, 1, 3]
[2, 1, 3] -> [1, 2, 3]
[2, 1, 2] -> [1, 2, 2]
[2, 1, 1] -> [1, 1, 2]
[3, 1, 1, 2] -> [1, 1, 3, 2]
[3, 2, 1, 2] -> [1, 2, 3, 2]
[3, 1, 2, 2] -> [1, 3, 2, 2]
[1, 3, 2, 2] -> [1, 2, 2, 3]
[1, 0, 5, -234] -> [0, 1, -234, 5]
[1, 0, 1, 0, 1] -> [0, 1, 0, 1, 1]
[1, 2, 3, 4, 5] -> [1, 2, 3, 4, 5]
[5, 4, 3, 2, 1] -> [1, 2, 3, 4, 5]
[2, 1, 5, 4, 3] -> [1, 2, 3, 4, 5]
[2, 3, 1, 5, 4] -> [2, 1, 3, 4, 5]
[5, 1, 4, 2, 3] -> [1, 5, 2, 4, 3]
[5, 2, 7, 6, 4, 1, 3] -> [2, 5, 1, 4, 6, 7, 3]
[-5, -2, -7, -6, -4, -1, -3] -> [-5, -7, -2, -6, -4, -3, -1]
[14, 5, 3, 8, 15, 7, 4, 19, 12, 0, 2, 18, 6, 11, 13, 1, 17, 16, 10, 9] -> [3, 5, 14, 8, 4, 7, 15, 0, 12, 19, 2, 6, 18, 11, 1, 13, 9, 10, 16, 17]

Scoring
This is code-golf, so the shortest code in bytes wins.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
print(int *a, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void
reverse(int *a, size_t n)
{
	size_t i;
	int t;

	for (i = 0; i < n / 2; i++) {
		t = a[i];
		a[i] = a[n - i - 1];
		a[n - i - 1] = t;
	}
}

void
seversort(int *a, size_t n)
{
	size_t i, j;

	for (i = 0; i < n; i = j) {
		j = i + 1;
		while (j < n && a[j - 1] >= a[j])
			j++;
		reverse(a + i, j - i);
	}
}

void
test(int *a, size_t n, int *r)
{
	seversort(a, n);
	print(a, n);
	assert(!memcmp(a, r, sizeof(*r) * n));
}

int
main()
{
	int a1[] = {1};
	int a2[] = {1, 1};
	int a3[] = {1, 2};
	int a4[] = {2, 1};
	int a5[] = {2, 3, 1};
	int a6[] = {2, 1, 3};
	int a7[] = {2, 1, 2};
	int a8[] = {2, 1, 1};
	int a9[] = {3, 1, 1, 2};
	int a10[] = {3, 2, 1, 2};
	int a11[] = {3, 1, 2, 2};
	int a12[] = {1, 3, 2, 2};
	int a13[] = {1, 0, 5, -234};
	int a14[] = {1, 0, 1, 0, 1};
	int a15[] = {1, 2, 3, 4, 5};
	int a16[] = {5, 4, 3, 2, 1};
	int a17[] = {2, 1, 5, 4, 3};
	int a18[] = {2, 3, 1, 5, 4};
	int a19[] = {5, 1, 4, 2, 3};
	int a20[] = {5, 2, 7, 6, 4, 1, 3};
	int a21[] = {-5, -2, -7, -6, -4, -1, -3};
	int a22[] = {14, 5, 3, 8, 15, 7, 4, 19, 12, 0, 2, 18, 6, 11, 13, 1, 17, 16, 10, 9};

	int r1[] = {1};
	int r2[] = {1, 1};
	int r3[] = {1, 2};
	int r4[] = {1, 2};
	int r5[] = {2, 1, 3};
	int r6[] = {1, 2, 3};
	int r7[] = {1, 2, 2};
	int r8[] = {1, 1, 2};
	int r9[] = {1, 1, 3, 2};
	int r10[] = {1, 2, 3, 2};
	int r11[] = {1, 3, 2, 2};
	int r12[] = {1, 2, 2, 3};
	int r13[] = {0, 1, -234, 5};
	int r14[] = {0, 1, 0, 1, 1};
	int r15[] = {1, 2, 3, 4, 5};
	int r16[] = {1, 2, 3, 4, 5};
	int r17[] = {1, 2, 3, 4, 5};
	int r18[] = {2, 1, 3, 4, 5};
	int r19[] = {1, 5, 2, 4, 3};
	int r20[] = {2, 5, 1, 4, 6, 7, 3};
	int r21[] = {-5, -7, -2, -6, -4, -3, -1};
	int r22[] = {3, 5, 14, 8, 4, 7, 15, 0, 12, 19, 2, 6, 18, 11, 1, 13, 9, 10, 16, 17};

	test(a1, nelem(a1), r1);
	test(a2, nelem(a2), r2);
	test(a3, nelem(a3), r3);
	test(a4, nelem(a4), r4);
	test(a5, nelem(a5), r5);
	test(a6, nelem(a6), r6);
	test(a7, nelem(a7), r7);
	test(a8, nelem(a8), r8);
	test(a9, nelem(a9), r9);
	test(a10, nelem(a10), r10);
	test(a11, nelem(a11), r11);
	test(a12, nelem(a12), r12);
	test(a13, nelem(a13), r13);
	test(a14, nelem(a14), r14);
	test(a15, nelem(a15), r15);
	test(a16, nelem(a16), r16);
	test(a17, nelem(a17), r17);
	test(a18, nelem(a18), r18);
	test(a19, nelem(a19), r19);
	test(a20, nelem(a20), r20);
	test(a21, nelem(a21), r21);
	test(a22, nelem(a22), r22);

	return 0;
}
