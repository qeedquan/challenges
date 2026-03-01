/*

A parity bit, or check bit, is a bit added to a string of bits to ensure that the total number of 1-bits in the string is even or odd. Parity bits are used as the simplest form of error detecting code.

You have two parameters, one being the wanted parity (always "even" or "odd"), and the other being the binary representation of the number you want to check.

Your task is to return an integer (0 or 1), whose parity bit you need to add to the binary representation so that the parity of the resulting string is as expected.

Example:

  Parity: "even"
  Bin: '0101010'
  Result: 1

Because there is an odd number of 1-bits (3) you need to put another 1 to it to get an even number of 1-bits.

For more information: https://en.wikipedia.org/wiki/Parity_bit

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

int
checkparity(const char *parity, const char *bin)
{
	int ones, mod;
	size_t i;

	ones = 0;
	for (i = 0; bin[i]; i++) {
		if (bin[i] == '1')
			ones ^= 1;
	}

	mod = 0;
	if (strcmp(parity, "even"))
		mod = 1;
	return ones ^ mod;
}

int
main()
{
	assert(checkparity("even", "101010") == 1);
	assert(checkparity("odd", "101010") == 0);
	assert(checkparity("even", "101011") == 0);
	assert(checkparity("odd", "101011") == 1);
	return 0;
}
