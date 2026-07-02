/*

Input a non-empty array of positive (greater than 0) integers. Output another non-empty array of positive integers which encode the input array. Output array does not use any numbers used in the input array.

Rules
Output array should not contain any numbers used in the input array.
Both input and output array may contain duplicate numbers.
Output array may have same length, may be longer, may be shorter than the original one.
It should be able to decode the original array from the output array.
You only need to decode arrays your encoder output. You are not required to implement a one-to-one mapping.
Your decoder may only use any info encoded with numbers in the array and its length. You are not allowed to pass extra info by using other properties of the array (whenever your language support it).
Input array is not sorted. And after decode, you should keep the order of input numbers. [3, 2, 1], and [1, 2, 3] are two different arrays.
You may implement your decoder in a different language.
Encoding to a single integer is allowed. If your encoder always encode to a single integer, it may output an integer instead of an array.
The word "array" talked in this post does not include SparseArray (in case your language support it). SparseArray is a special kind of array while there may be gaps between array items.
You may output integers as strings of their decimal representation, if your output integers are too large, or you just prefer so.
Leading zeros in the output strings are allowed. But if there are any, after removing leading zeros or padding more leading zeros, your decoder should still output the original array. Or in the other words, your decoder should not relay on the number of leading zeros to work.
Your program should at least support any array of 100 numbers, while every number in 1~100.
The word "support" here means it should be able to decode the original array without any errors introduced by integer overflow or floating point precision. Your program may however timeout on TIO as long as it will output correct result when given enough resources.
Your encode algorithm should in theory work for any size array with any large numbers.
Task is code-golf the encoder program. The decoder does not contribute to your byte count. But you should also include the decoder program for a reference, so we can verify it. (Please include it in the post directly, not only in TIO link.)

Testcases
The output array may vary from answer to answer. So we only include input array here. You can verify your answer by checking if decoder(encoder(input)) may result the original input, and encoder(input) does not contain any numbers in input.

[1]
[10]
[1,2]
[2,1]
[1,1]
[11]
[1,11]
[11,1]
[1,2,3,4,5,6,7,8,9,10]
[93,29,47,3,29,84,19,70]

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned int uint;

uint
maxs(uint *a, size_t n)
{
	size_t i;
	uint m;

	m = 0;
	for (i = 0; i < n; i++) {
		if (m < a[i])
			m = a[i];
	}
	return m;
}

/*

@xnor

Just adds the list maximum to each element, producing values greater than any in the original list.
The max of the resulting list is double the original max, so we can invert by lowering each element by half the new max.

*/

void
enc(uint *a, size_t n, uint *r)
{
	size_t i;
	uint m;

	m = maxs(a, n);
	for (i = 0; i < n; i++)
		r[i] = a[i] + m;
}

void
dec(uint *a, size_t n, uint *r)
{
	size_t i;
	uint m;

	m = maxs(a, n);
	for (i = 0; i < n; i++)
		r[i] = a[i] - (m / 2);
}

void
test(uint *a, size_t n)
{
	uint b[32], c[32];
	size_t i, j;

	enc(a, n, b);
	dec(b, n, c);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			assert(a[i] != b[j]);
	}
	assert(!memcmp(a, c, sizeof(*a) * n));
}

int
main()
{
	uint a1[] = { 1 };
	uint a2[] = { 10 };
	uint a3[] = { 1, 2 };
	uint a4[] = { 2, 1 };
	uint a5[] = { 1, 1 };
	uint a6[] = { 11 };
	uint a7[] = { 1, 11 };
	uint a8[] = { 11, 1 };
	uint a9[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	uint a10[] = { 93, 29, 47, 3, 29, 84, 19, 70 };

	test(a1, nelem(a1));
	test(a2, nelem(a2));
	test(a3, nelem(a3));
	test(a4, nelem(a4));
	test(a5, nelem(a5));
	test(a6, nelem(a6));
	test(a7, nelem(a7));
	test(a8, nelem(a8));
	test(a9, nelem(a9));
	test(a10, nelem(a10));

	return 0;
}
