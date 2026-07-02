/*

Description
Most everyone who programs is familiar with the factorial - n! - of a number, the product of the series from n to 1. One interesting aspect of the factorial operation is that it's also the number of permutations of a set of n objects.

Today we'll look at the subfactorial, defined as the derangement of a set of n objects, or a permutation of the elements of a set, such that no element appears in its original position. We denote it as !n.

Some basic definitions:

!1 -> 0 because you always have {1}, meaning 1 is always in it's position.

!2 -> 1 because you have {2,1}.

!3 -> 2 because you have {2,3,1} and {3,1,2}.

And so forth.

Today's challenge is to write a subfactorial program. Given an input n, can your program calculate the correct value for n?

Input Description
You'll be given inputs as one integer per line. Example:

5
Output Description
Your program should yield the subfactorial result. From our example:

44
(EDIT earlier I had 9 in there, but that's incorrect, that's for an input of 4.)

Challenge Input
6
9
14
Challenge Output
!6 -> 265
!9 -> 133496
!14 -> 32071101049
Bonus
Try and do this as code golf - the shortest code you can come up with.

Double Bonus
Enterprise edition - the most heavy, format, ceremonial code you can come up with in the enterprise style.

Notes
This was inspired after watching the Mind Your Decisions video about the "3 3 3 10" puzzle, where a subfactorial was used in one of the solutions.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long long uvlong;

// https://oeis.org/A000166
uvlong
derangement(uvlong n)
{
	uvlong i, r;

	if (n == 0)
		return 1;
	if (n == 1)
		return 0;
	if (n == 2)
		return 1;
	if (n == 3)
		return 2;

	r = 2;
	i = 3;
	while (i < n) {
		i += 1;
		r *= i;
		if (!(i & 1))
			r += 1;
		else
			r -= 1;
	}
	return r;
}

int
main()
{
	static const uvlong tab[] = {
		1,
		0,
		1,
		2,
		9,
		44,
		265,
		1854,
		14833,
		133496,
		1334961,
		14684570,
		176214841,
		2290792932,
		32071101049,
		481066515734,
		7697064251745,
		130850092279664,
		2355301661033953,
		44750731559645106,
		895014631192902121,
	};

	uvlong i;

	for (i = 0; i < nelem(tab); i++)
		assert(derangement(i) == tab[i]);

	return 0;
}
