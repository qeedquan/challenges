/*

A sculptor is tasked to creating icicle sculptures for the new museum in Greenland. He has been given specifications by his boss, which consists of two numbers: [s, m] or size and melt. Size must be an odd number. He was given some photos of real icicles:

vvvvv [5, 0]
 vvv
  v


vvvvvvv [7, 0]
 vvvvv
  vvv
   v


vvvvvvv [7, 2]
 vvvvv



vvvvvvv [7, 3]




vvv [3, 1]

He needs a program to help draw. Any language allowed. The program needs to take in S and M, any method of input acceptable. You must then print out an ascii art representation of it.

S is how many vs are on the first layer. M is how many layers are cut out from the bottom.

This is code-golf, so as usual this competition is byte based. White space does count for byte counting. Least bytes wins.

Edit: You will never get a set of numbers that draws nothing, for example [5, 3]. Checking code is not required however.

*/

#include <stdio.h>

void
icicles(int s, int m)
{
	int i, p;

	printf("s=%d m=%d\n", s, m);
	m *= 2;
	p = 0;
	while (s >= m) {
		for (i = 0; i < p; i++)
			printf(" ");
		for (i = 0; i < s; i++)
			printf("v");
		printf("\n");

		p += 1;
		s -= 2;
	}
	printf("\n");
}

int
main(void)
{
	icicles(5, 0);
	icicles(7, 0);
	icicles(7, 2);
	icicles(7, 3);
	icicles(3, 1);

	return 0;
}
