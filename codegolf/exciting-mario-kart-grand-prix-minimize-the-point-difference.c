/*

Introduction
When playing Mario Kart the other day, an interesting question popped up when a Grand Prix with my 2 roommates, 9 AI drivers and myself seemed to be fairly close and therefore exciting until the very end.

We asked ourselves: How close can the point difference between first and last place (#1 and #12) after exactly N races be?

This Code Golf challenge occured to me after the underlying problem for the distribution of the minimum difference in points was answered here by user mlk.

Challenge
Mario Kart races consist of 12 racers which in every race receive the points represented in this 1-indexed array: [15, 12, 10, 8, 7, 6, 5, 4, 3, 2, 1, 0].

In a Grand Prix, the points for each driver from every of the N races are simply added up to form the final point distribution. The difference between the lowest and the highest number of points in this final point distribution is called point difference (alas between places #1 and #12).

Your task is to write a program which takes as input the number of races N (1 <= N <= 32) and outputs the corresponding point difference.

The first 13 correct inputs and outputs can be found below. You will find that after the special cases N = 1 and N = 2, the correct answer will be 0 if N is divisible by 12 and 1if not.

Example Input and Output
As the desired output is correctly defined for every natural number, here are the input/output examples until the repeating pattern described above begins:

1 -> 15
2 -> 4
3 -> 1
4 -> 1
5 -> 1
6 -> 1
7 -> 1
8 -> 1
9 -> 1
10 -> 1
11 -> 1
12 -> 0
13 -> 1

Goal
This is Code Golf, so shortest answer in bytes wins!

Standard loopholes apply.

*/

#include <assert.h>
#include <math.h>

/*

@Arnauld

We compute floor(14/n^n + 1), which is
floor(14/1 + 1) = 15 for n = 1
floor(14/4 + 1) = 4  for n = 2
or 1 for n > 2

We then XOR the result with 1 if n mod 12 = 0

*/

int
pd(int n)
{
	int r;

	r = (14 / pow(n, n)) + 1;
	r ^= !(n % 12);
	return r;
}

int
main(void)
{
	assert(pd(1) == 15);
	assert(pd(2) == 4);
	assert(pd(3) == 1);
	assert(pd(4) == 1);
	assert(pd(5) == 1);
	assert(pd(6) == 1);
	assert(pd(7) == 1);
	assert(pd(8) == 1);
	assert(pd(9) == 1);
	assert(pd(10) == 1);
	assert(pd(11) == 1);
	assert(pd(12) == 0);
	assert(pd(13) == 1);

	return 0;
}
