/*

Last summer, schoolboy Vasylko visited Egypt.
Only now he remembered that during his trip, he managed to photograph many interesting things.
While looking through these pictures, Vasylko became especially interested in the views of the pyramids at Giza.
In addition to various hieroglyphs, the pyramids contained unusual symbols: 1, 2, 3, 4, 5, 6, 7, 8, 9, 0.

Upon closer examination, Vasylko noticed that each row of these mysterious symbols represents a power of two.
Specifically, the first row starts with 1, the second with 2, ..., the one hundred twentieth with 120, and so on.
If only Vasylko had used a modern camera, everything would be clear, but his old camera poorly captured the brightest parts of the pyramid,
making not all symbols visible and therefore making it difficult to determine the corresponding exponent of two for each row.

Vasylko decided to restore the symbols and, in the end,
wants someone to write a program (as he is in the 6th grade and does not know programming)
that determines the exponent of two that appears in the n-th row.

Input
The only input is the number n (n≤10^7).

Output
Print the smallest positive integer k such that the decimal representation of 2^k begins with n.
If Vasylko mixed something up and there is no such k, print -1.

Examples

Input #1
12

Answer #1
7

Input #2
134

Answer #2
27

Note
Although Vasylko is still young, he did not make any mistakes; otherwise, the ancient Egyptians would not have carved such symbols on their pyramids!

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

/*

https://stackoverflow.com/questions/60251615/finding-the-minimal-k-that-2k-begins-with-n
https://oeis.org/A018856

@r3mainer

Suppose you want to find a power of 2 that starts with 123.

This is equivalent to finding a multiple of log10(2) whose mantissa lies between 0.089905111439398 and 0.093421685162235
(because log10(123) = 2.089905111439398 and log10(124) = 2.093421685162235).

If you frame the question in this way, there's no need to calculate huge powers of 2. All you need is a bit of floating point arithmetic.

*/

int
solve(int n)
{
	const double log2 = log10(2);

	double logmin, logmax;
	double mink;
	double x, k;

	if (n < 1)
		return -1;
	if (n == 1)
		return 0;

	logmin = log10(n);
	logmax = log10(n + 1);
	logmin -= floor(logmin);
	logmax -= floor(logmax);
	if (logmax < logmin)
		logmax += 1;

	mink = log10(n) / log2;
	x = 1;
	k = 0;
	while (!(logmin <= x && x < logmax && k >= mink)) {
		x += log2;
		if (x >= 1)
			x -= 1;
		k += 1;
	}
	return k;
}

int
main()
{
	static const int tab[] = {
		0, 1, 5, 2, 9, 6, 46, 3, 53, 10, 50, 7, 17, 47, 77, 4, 34, 54, 84, 11,
		31, 51, 61, 81, 8, 18, 38, 48, 68, 78, 98, 5, 25, 35, 45, 55, 75, 85,
		95, 12, 22, 32, 42, 145, 52, 62, 72, 82, 92, 102, 9, 19, 29, 39, 142,
		49, 59, 162, 69, 79, 89, 192, 99, 6, 16, 119, 26
	};

	size_t i;

	assert(solve(12) == 7);
	assert(solve(134) == 27);

	for (i = 0; i < nelem(tab); i++)
		assert(solve(i + 1) == tab[i]);

	return 0;
}
