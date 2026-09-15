/*

Input
A list of between 1 and 255 positive integers (inclusive), each in the range 1 to 232 - 1 (inclusive).
Your input format does not need to be identical to the test cases.
Input without leading zeroes is required to be accepted.
Input with leading zeroes is not required to be accepted.
You may use whatever delimiter you wish between the integers.
An integer may be represented by a string but the individual digits of a specific integer must be contiguous.
You may choose to use any base for the input (including binary and unary), provided the output is also in that base.
Output
A single integer.
The output must have no leading zeroes.
The output must be in the same base as the input.
The output can be calculated in whatever way you wish but must match the result of the following calculation:
Calculating biplex
The bits of a binary representation are numbered from the right starting from zero, so bit i is in the column representing 2i.
The i th bitsum is the sum of the i th bits of the binary representations of each of the input numbers.
The bitsum maximum is the highest value taken by the bitsums.
The bitsum minimum is the lowest non-zero value taken by the bitsums.
The i th digit of the binary representation of the output is:
1 if the i th bitsum is equal to the bitsum maximum or the bitsum minimum.
0 otherwise.
Worked example
This example uses binary for input and output.

Input:    100110
         1101110
         1100101
         _______
Bitsums: 2301321

Output:   101101
The bitsum maximum is 3 and the bitsum minimum is 1, so the output has 1s everywhere that the bitsum is 3 or 1, and 0s everywhere else.

Test cases
Test cases are in the form:

Input => Output
The test cases in binary:

[1] => 1
[10] => 10
[1, 10, 101] => 111
[11111111111111111111111111111111] => 11111111111111111111111111111111
[10010010010010010010010010010010, 10101010101010101010101010101010, 11011011011011011011011011011011] => 11100011100011100011100011100011
[10001011100010100110100101001001, 10110000111110010000111110111010, 1101110001101101011010010100101, 1010101010001011101001001010101] => 11
The same test cases in decimal:

[1] => 1
[2] => 2
[1, 2, 5] => 7
[4294967295] => 4294967295
[2454267026, 2863311530, 3681400539] => 3817748707
[2341103945, 2969112506, 1849078949, 1430639189] => 3

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

uint32_t
biplex(uint32_t *a, size_t n)
{
	uint32_t lo, hi;
	uint32_t b[32];
	uint32_t r;
	size_t i, j;

	memset(b, 0, sizeof(b));
	for (i = 0; i < n; i++) {
		for (j = 0; j < nelem(b); j++) {
			if (a[i] & (1 << j))
				b[j]++;
		}
	}

	lo = UINT32_MAX;
	hi = 0;
	for (i = 0; i < nelem(b); i++) {
		if (b[i])
			lo = min(lo, b[i]);
		hi = max(hi, b[i]);
	}

	r = 0;
	for (i = 0; i < nelem(b); i++) {
		if (b[i] == lo || b[i] == hi)
			r |= (1 << i);
	}
	return r;
}

int
main(void)
{
	uint32_t a1[] = {38, 110, 101};
	uint32_t a2[] = {1};
	uint32_t a3[] = {2};
	uint32_t a4[] = {1, 2, 5};
	uint32_t a5[] = {4294967295};
	uint32_t a6[] = {2454267026, 2863311530, 3681400539};
	uint32_t a7[] = {2341103945, 2969112506, 1849078949, 1430639189};

	assert(biplex(a1, nelem(a1)) == 45);
	assert(biplex(a2, nelem(a2)) == 1);
	assert(biplex(a3, nelem(a3)) == 2);
	assert(biplex(a4, nelem(a4)) == 7);
	assert(biplex(a5, nelem(a5)) == 4294967295);
	assert(biplex(a6, nelem(a6)) == 3817748707);
	assert(biplex(a7, nelem(a7)) == 3);

	return 0;
}
