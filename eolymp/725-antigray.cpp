/*

As is known, the English mathematician Frank Gray introduced a clever formula that allows one to determine, given a sequence number,
the corresponding member of a sequence where the binary representation of each subsequent member differs from the previous one by exactly one bit.
If we denote the i-th bit of the binary representation of the ordinal number in the Gray code as Ni,
and Gi as the i-th bit of the binary representation of the corresponding Gray code, the formula is:

G_i = N_i^N_{i+1}
Note that the bits are numbered from right to left, starting from zero.
In C, the function that returns the Gray code for a given integer parameter equal to the number is as follows:

unsigned long long G(long long N)

{ return N ^ (N 1);}

We call the sequence (Gi) the Gray sequence.
The task is: given a Gray code, obtain the number for which this is the Gray code (i.e., the ordinal number of the member of the Gray sequence equal to this code).

Input
The file contains a single line — the Gray code given in hexadecimal form.
The length of the input does not exceed 200 000. For digits with values greater than 9, the first uppercase English letters are used.

Output
The output consists of a single line — the hexadecimal value of the number whose Gray code was given in the input file.
The output should have no leading zeros. For digits greater than 9, uppercase English letters are used.

Examples
Input #1
3F

Answer #1
2A

*/

#include <cassert>

typedef unsigned int uint;

uint bin2gray(uint n)
{
	return n ^ (n >> 1);
}

uint gray2bin(uint n)
{
	auto m = n;
	while (m)
	{
		m >>= 1;
		n ^= m;
	}
	return n;
}

int main()
{
	assert(gray2bin(0x3f) == 0x2a);

	for (uint n = 0; n <= 10000000; n++)
	{
		assert(bin2gray(gray2bin(n)) == n);
		assert(gray2bin(bin2gray(n)) == n);
	}

	return 0;
}
