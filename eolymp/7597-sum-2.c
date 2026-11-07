/*

Calculate the sum of a specific sequence of numbers based on the given variant number n.

For each value of n, the sequence is defined as follows:

n=1: 1+8+27+64+125+216+343+512+729+1000

n=2: 1+2+6+24+120+720+5040+40320+362880+3628800

n=3: 2+4+8+16+32+64+128+256+512+1024

n=4: 1+4+9+16+25+36+49+64+81+100

n=5: 2+5+10+17+26+37+50+65+82+101

n=6: 2+6+12+20+30+42+56+72+90+110

Input
A single integer n, where 1≤n≤6.

Output
The sum of the numbers in the sequence corresponding to the given n.

Examples
Input #1
1

Answer #1
3025

*/

#include <assert.h>
#include <stdio.h>

long
solve(long n)
{
	switch (n) {
	case 1:
		return 1 + 8 + 27 + 64 + 125 + 216 + 343 + 512 + 729 + 1000;
	case 2:
		return 1 + 2 + 6 + 24 + 120 + 720 + 5040 + 40320 + 362880 + 3628800;
	case 3:
		return 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256 + 512 + 1024;
	case 4:
		return 1 + 4 + 9 + 16 + 25 + 36 + 49 + 64 + 81 + 100;
	case 5:
		return 2 + 5 + 10 + 17 + 26 + 37 + 50 + 65 + 82 + 101;
	case 6:
		return 2 + 6 + 12 + 20 + 30 + 42 + 56 + 72 + 90 + 110;
	}
	return 0;
}

int
main()
{
	long i;

	assert(solve(1) == 3025);

	for (i = 1; i <= 6; i++)
		printf("%ld %ld\n", i, solve(i));

	return 0;
}
