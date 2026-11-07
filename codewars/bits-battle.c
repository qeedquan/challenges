/*

The odd and even numbers are fighting against each other!

You are given a list of positive integers. The odd numbers from the list will fight using their 1 bits from their binary representation, while the even numbers will fight using their 0 bits. If present in the list, number 0 will be neutral, hence not fight for either side.

You should return:

odds win if number of 1s from odd numbers is larger than 0s from even numbers
evens win if number of 1s from odd numbers is smaller than 0s from even numbers
tie if equal, including if list is empty
Please note that any prefix that might appear in the binary representation, e.g. 0b, should not be counted towards the battle.

Example:
For an input list of [5, 3, 14]:

odds: 5 and 3 => 101 and 11 => four 1s
evens: 14 => 1110 => one 0
Result: odds win the battle with 4-1

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdbit.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned int uint;

const char *
battle(uint *array, size_t length)
{
	uint evens, odds;
	uint value, mask;
	size_t index;

	evens = odds = 0;
	for (index = 0; index < length; index++) {
		value = array[index];
		if (!value)
			continue;

		if (value & 1)
			odds += stdc_count_ones(value);
		else {
			mask = (1u << stdc_bit_width(value)) - 1;
			value = ~value & mask;
			evens += stdc_count_ones(value);
		}
	}
	if (evens == odds)
		return "tie";
	if (evens > odds)
		return "evens win";
	return "odds win";
}

void
test(uint *array, size_t length, const char *expected)
{
	const char *result;

	result = battle(array, length);
	puts(result);
	assert(!strcmp(result, expected));
}

int
main()
{
	uint array1[] = { 5, 3, 14 };
	uint array2[] = { 3, 8, 22, 15, 78 };
	uint array3[] = { 1, 13, 16 };
	uint array4[] = { 0 };
	uint array5[] = { 0, 1, 2 };

	test(array1, nelem(array1), "odds win");
	test(array2, nelem(array2), "evens win");
	test(NULL, 0, "tie");
	test(array3, nelem(array3), "tie");
	test(array4, nelem(array4), "tie");
	test(array5, nelem(array5), "tie");

	return 0;
}
