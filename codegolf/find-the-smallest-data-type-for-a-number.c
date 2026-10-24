/*

Recently I had to implement this problem in c#, and thought it would make for a good code golf.

Your goal is to output the smallest unsigned data-type a 64 bit unsigned number can fit into.

Input: An unsigned 64-bit number (or the closest builtin equivalent in your chosen language)

Output: A number representing the bytes of the smallest unsigned data-type the input value can fit into (1, 2, 4, or 8)

Data Type Max Values:

byte => 255
ushort => 65535
uint => 4294967295
ulong => 18446744073709551615
Examples:

0 => 1 (byte)
255 => 1 (byte)
256 => 2 (ushort)
500 => 2 (ushort)
60000 => 2 (ushort)
4294967295 => 4 (uint)
4294967296 => 8 (ulong)
18446744073709551615 => 8 (ulong)
This can be done using lzcnt, if statements, regex, bit manipulation, etc. (creative solutions & languages encouraged!)

This is a code-golf, so shortest solution wins!

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long long uvlong;

int
typefit(uvlong n)
{
	static const struct {
		int size;
		uvlong limit;
	} tab[] = {
		{ 1, 255ULL },
		{ 2, 65535ULL },
		{ 4, 4294967295ULL },
		{ 8, 18446744073709551615ULL },
	};

	size_t i;

	for (i = 0; i < nelem(tab); i++) {
		if (n <= tab[i].limit)
			return tab[i].size;
	}
	return -1;
}

int
main()
{
	assert(typefit(0ULL) == 1);
	assert(typefit(255ULL) == 1);
	assert(typefit(256ULL) == 2);
	assert(typefit(500ULL) == 2);
	assert(typefit(60000ULL) == 2);
	assert(typefit(4294967295ULL) == 4);
	assert(typefit(4294967296ULL) == 8);
	assert(typefit(18446744073709551615ULL) == 8);

	return 0;
}
