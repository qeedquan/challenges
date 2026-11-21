/*

Given a positive integer n output the n-th number of the euro-iginal sequence.

Calculating the Sequence
This sequence is equal to OEIS A242491.

A number is part of said sequence if the number can be made up by using as many different euro coins or notes, but only one of each. Note that you don't have to consider cents.

Example:

6 would be in the sequence, as it can consist of a 1-euro coin and a 5-euro-note.

4 would NOT be in the sequence, as it can't be formed with the given requirements.

To give everyone an overview, heres a list with euro values you have to consider:

1€, 2€, 5€, 10€, 20€, 50€, 100€, 200€, 500€

Note that this sequence only ranges from 0 (yes, 0 is included!) to 888.

Here are the first 15 elements of this sequence:

0, 1, 2, 3, 5, 6, 7, 8, 10, 11, 12, 13, 15, 16, 17, ...

Test Cases
Input -> Output

2 -> 1
6 -> 6
21 -> 25
33 -> 50

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

// https://oeis.org/A242491
int
euro(int n)
{
	return n + (n / 4) + ((n / 32) * 10) + ((n / 256) * 100);
}

int
main(void)
{
	static const int tab[] = {1, 2, 3, 5, 6, 7, 8, 10, 11, 12, 13, 15, 16, 17, 18, 20, 21, 22, 23, 25, 26, 27, 28, 30, 31, 32, 33, 35, 36, 37, 38, 50, 51, 52, 53, 55, 56, 57, 58, 60, 61, 62, 63, 65, 66, 67, 68, 70, 71, 72, 73, 75, 76, 77, 78, 80, 81, 82, 83, 85, 86, 87, 88, 100, 101, 102, 103, 105};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(euro(i + 1) == tab[i]);

	return 0;
}
