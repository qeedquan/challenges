/*

Given a list of integers(can be positive or negative), find the integer with the highest number of 1 bits in its two's complement binary representation.

Example
most_one_bits([[3, 7, 8, 9, 15]) => #Output: 15 (it has 4 '1' bits)

most_one_bits([3, 7, 8, 9, 23, 28]) => #Output: 23 (it has 4 '1' bits)
In case of a tie, return the last integer in the list with the highest number of 1 bits.

most_one_bits([6, 3, 6, 9, 10]) => #Output: 10 (all have 2 '1' bits
but 10 is the last)
Note:
Integers should be represented in 8 bits

For positive numbers, the calculation of 1 bits in the binary representation remains the same but negative integers will have different results.

most_one_bits([-1,-2,-3]) => #Output -1( it has total of 8 '1' bits)

Duplicates

In case of Duplication of integers only the first occurrence will be considered

Example

most_one_bits([85, 120,-23,-15,-23]) =>#Output -15

( first occurrence of -15 is after first occurrence -23)
Input list will Never be empty( [] )

*/

#include <assert.h>
#include <stdbit.h>
#include <stdio.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef long long vlong;

vlong
mob(vlong *a, size_t n)
{
	vlong m, r, v;
	size_t i;

	r = LLONG_MIN;
	m = 0;
	for (i = 0; i < n; i++) {
		v = stdc_count_ones_ull(a[i]);
		if (m < v || (m == v && r < a[i])) {
			r = a[i];
			m = v;
		}
	}
	return r;
}

int
main()
{
	vlong a1[] = { 3, 7, 8, 9, 15 };
	vlong a2[] = { 3, 7, 8, 9, 23, 28 };
	vlong a3[] = { 3, 5, 6, 9, 10 };
	vlong a4[] = { 1 };
	vlong a5[] = { -1, -2, -3 };
	vlong a6[] = { 85, 120, -23, -15, -23 };

	assert(mob(a1, nelem(a1)) == 15);
	assert(mob(a2, nelem(a2)) == 23);
	assert(mob(a3, nelem(a3)) == 10);
	assert(mob(a4, nelem(a4)) == 1);
	assert(mob(a5, nelem(a5)) == -1);
	assert(mob(a6, nelem(a6)) == -15);

	return 0;
}
