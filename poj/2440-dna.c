/*

Description

A kind of virus has attacked the X planet, and many lives are infected. After weeks of study, The CHO (Creature Healthy Organization) of X planet finally finds out that this kind of virus has two kind of very simple DNA, and can be represented by 101 and 111. Unfortunately, the lives on the planet also have DNA formed by 0s and 1s. If a creature's DNA contains the virus' DNA, it will be affected; otherwise it will not. Given an integer L, it is clear that there will be 2 ^ L different lives, of which the length of DNA is L. Your job is to find out in the 2 ^ L lives how many won't be affected?

Input

The input contains several test cases. For each test case it contains a positive integer L (1 <= L <= 10 ^ 8). The end of input is indicated by end-of-file.

Output

For each test case, output K mod 2005, here K is the number of lives that will not be affected.

Sample Input

4

Sample Output

9

Source

POJ Monthly,Static

*/

#include <assert.h>
#include <stdio.h>
#include <threads.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
lives(int n)
{
	static thread_local int lut[256];
	static thread_local int once;
	static const int loop = 200;
	static const int mod = 2005;

	size_t i;

	if (!once) {
		lut[0] = 1;
		lut[1] = 2;
		for (i = 2; i < nelem(lut); i++)
			lut[i] = (lut[i - 1] + lut[i - 2]) % mod;
		once = 1;
	}

	if (n < 0)
		return 0;
	return (lut[((n >> 1) + (n & 1)) % loop] * lut[(n >> 1) % loop]) % mod;
}

int
main(void)
{
	assert(lives(4) == 9);

	return 0;
}
