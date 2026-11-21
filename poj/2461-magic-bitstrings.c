/*

Description

A bitstring, whose length is one less than a prime, might be magic. 1001 is one such string. In order to see the magic in the string let us append a non-bit x to it, regard the new thingy as a cyclic string, and make this square matrix of bits
each bit	  1001
every 2nd bit	  0110
every 3rd bit	  0110
every 4th bit	  1001

This matrix has the same number of rows as the length of the original bitstring. The m-th row of the matrix has every m-th bit of the original string starting with the m-th bit. Because the enlarged thingy has prime length, the appended x never gets used.

If each row of the matrix is either the original bitstring or its complement, the original bitstring is magic.

Input

Each line of input (except last) contains a prime number p <= 100000. The last line contains 0 and this line should not be processed.

Output

For each prime number from the input produce one line of output containing the lexicographically smallest, non-constant magic bitstring of length p-1, if such a string exists, otherwise output Impossible.

Sample Input

5
3
17
47
2
79
0

Sample Output

0110
01
0010111001110100
0000100001101010001101100100111010100111101111
Impossible
001001100001011010000001001111001110101010100011000011011111101001011110011011

Source

Waterloo local 2005.06.11

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
bitstring(int p, char *b)
{
	int i;

	if (p < 1 || p == 2) {
		sprintf(b, "Impossible");
		return b;
	}

	for (i = 1; i < p; i++)
		b[i - 1] = '1';

	for (i = 1; i < p; i++)
		b[((i * i) % p) - 1] = '0';

	b[p - 1] = '\0';

	return b;
}

void
test(int p, const char *r)
{
	char b[128];

	bitstring(p, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test(5, "0110");
	test(3, "01");
	test(17, "0010111001110100");
	test(47, "0000100001101010001101100100111010100111101111");
	test(2, "Impossible");
	test(79, "001001100001011010000001001111001110101010100011000011011111101001011110011011");

	return 0;
}
