/*

A drug comes in 5mg, 2.5mg, and 1mg sized pills. The drug is taken once a day. The total daily dose will be only one of the following (all in mg):

1, 2, 3, ... 20, 22.5, 25, 27.5, 30, 32.5, 35, 37.5, 40, 42.5, 45, 47.5, 50

In words: any whole number less or equal to 20, then at 2.5mg increments up to 50.

Your task is to determine how many pills of each size the patient should take to get to their total dose, minimizing the total number of pills they have to take.

Input: the total daily dose

Output: the respective number of 5mg, 2.5mg, and 1mg the patient needs to take, in any consistent format.

This is code golf. Fewest number of bytes wins.

Examples: (output is number of 1, 2.5, and 5 mg pills)

1 => [1, 0, 0]
4 => [4, 0, 0]
7 => [2, 0, 1]
19 => [4, 0, 3]
22.5 => [0, 1, 4]
40 => [0, 0, 8]

Irrelevant: this is based on a true story. The drug is prednisone and I wrote a program to automate the production of a calendar for patients to use to titrate their doses, which is a challenging task for many elderly patients to do safely even if you give them written instructions. This challenge was part of the programming task.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

/*

@xnor:

An improvement to Manish Kundu's Python 3 solution.

The new part is x*6%5 for the last entry. The idea is to take the value mod 5 for whole x, but to give 0 for the non-integer doses, which are multiples of 2.5. To do this, we multiply by 6 before reducing mod 5. Because 6≡1
 modulo 5, multiplying by 6 leaves integers unchanged mod 5, but it turns multiples of 2.5 into multiples of 5, which then reduce to 0.

In the second entry, x%1*2 could also be x*2%2 as an equal-length alternative. This may be useful for porting, if a language's mod operation only works on whole numbers.

*/

void
dose(double x, int r[3])
{
	r[0] = (int)(x * 6) % 5;
	r[1] = (int)(x * 2) % 2;
	r[2] = x / 5;
}

void
test(double x, int r[3])
{
	int p[3];

	dose(x, p);
	printf("%d %d %d\n", p[0], p[1], p[2]);
	assert(!memcmp(p, r, sizeof(p)));
}

int
main(void)
{
	int r1[] = {1, 0, 0};
	int r2[] = {4, 0, 0};
	int r3[] = {2, 0, 1};
	int r4[] = {4, 0, 3};
	int r5[] = {0, 1, 4};
	int r6[] = {0, 0, 8};

	test(1, r1);
	test(4, r2);
	test(7, r3);
	test(19, r4);
	test(22.5, r5);
	test(40, r6);

	return 0;
}
