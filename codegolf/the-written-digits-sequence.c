/*

Here's a reasonably trivial sequence which is not in the Online Encyclopedia of Integer Sequences.

Start with an empty sequence then define each term as the number of characters required to write out, in English, all of the digits of the sequence so far without spaces.*

For reference the number of characters of all of the (base ten) digits in English are:

zero   one    two    three  four   five   six    seven  eight  nine
4      3      3      5      4      4      3      5      5      4
(Which is the start of both A52360 and A5589.)

This makes the first entry a(0)=0 since there are zero digits present in the empty sequence.

This makes the second entry a(1)=4 as it takes four characters to write "zero", the only digit present so far.

This makes the third entry a(2)=8 as it takes four more characters to write the "four" for a total of eight to write "zerofour".

This makes the fourth entry a(3)=13 as it takes five more characters to write "eight" for a total of thirteen to write "zerofoureight".

This makes the fifth entry a(4)=21 as it takes eight more characters to write "onethree" for a total of twenty-one to write "zerofoureightonethree".

...and so on. Here are the first 100 entries:

0, 4, 8, 13, 21, 27, 35, 44, 52, 59, 67, 75, 84, 93, 102, 112, 121, 130, 142, 152, 162, 171, 182, 193, 205, 216, 225, 235, 247, 259, 270, 282, 293, 305, 318, 331, 344, 357, 371, 384, 398, 412, 422, 432, 444, 456, 467, 479, 492, 503, 516, 526, 536, 548, 561, 571, 583, 597, 610, 620, 630, 642, 652, 662, 671, 682, 693, 705, 718, 731, 744, 757, 771, 784, 798, 812, 823, 836, 849, 862, 873, 888, 903, 916, 926, 936, 948, 961, 971, 983, 997, 1010, 1024, 1038, 1055, 1070, 1086, 1101, 1114, 1127
* We could define it for other languages and/or other bases or with spaces of course

The challenge
Given n output, in as few bytes of code as possible, any of:

The first n terms of the sequence (should work for non-negative integers)
The value of a(n) (should work for non-negative integers)
The nth term of the sequence (should work for positive integers - i.e. value of a(n−1))
This is code-golf so the shortest answer in bytes wins for each language, and the shortest answer in bytes wins. Don't let golfing languages stop you from entering in your favourite language be it a practical one or an esoteric one!

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
diglen(int n)
{
	static const int dig[] = {4, 3, 3, 5, 4, 4, 3, 5, 5, 4};

	int r;

	r = 0;
	do {
		r += dig[n % 10];
		n /= 10;
	} while (n > 0);

	return r;
}

int
recurse(int n)
{
	int x;

	if (n < 0)
		return 0;

	x = recurse(n - 1);
	return x + diglen(x);
}

int
wds(int n)
{
	return (n >= 1) ? recurse(n - 1) : 0;
}

int
main(void)
{
	static const int tab[] = {0, 4, 8, 13, 21, 27, 35, 44, 52, 59, 67, 75, 84, 93, 102, 112, 121, 130, 142, 152, 162, 171, 182, 193, 205, 216, 225, 235, 247, 259, 270, 282, 293, 305, 318, 331, 344, 357, 371, 384, 398, 412, 422, 432, 444, 456, 467, 479, 492, 503, 516, 526, 536, 548, 561, 571, 583, 597, 610, 620, 630, 642, 652, 662, 671, 682, 693, 705, 718, 731, 744, 757, 771, 784, 798, 812, 823, 836, 849, 862, 873, 888, 903, 916, 926, 936, 948, 961, 971, 983, 997, 1010, 1024, 1038, 1055, 1070, 1086, 1101, 1114, 1127};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(wds(i) == tab[i]);

	return 0;
}
