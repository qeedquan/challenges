/*

This question is probably harder than all of those "generate a sequence of numbers" tasks, because this requires TWO sequences working in unison.

Really looking forward to the answers!

In his book "Gödel, Escher, Bach: An Eternal Golden Braid", Douglas Hofstadter has a quite few sequences of numbers inside, all of them rely on the previous term in some way. For information on all of the sequences, see this Wikipedia page.

One pair of sequences that's really interesting is the Female and Male sequences, which are defined like so:

F(0) = 1, M(0) = 0
F(n) = n - M(F(n - 1))
M(n) = n - F(M(n - 1))

for n > 0.

Here's the Female sequence and the Male sequence.

Your task is, when given an integer n as input, return a list of the Female sequence and the Male sequence, with the amount of terms equal to n, in two lines of output, with the Female sequence on the first line and the Male sequence on the second.

Sample inputs and outputs: Input: 5 Output: [1, 1, 2, 2, 3] [0, 0, 1, 2, 2]

Input: 10 Output: [1, 1, 2, 2, 3, 3, 4, 5, 5, 6] [0, 0, 1, 2, 2, 3, 4, 4, 5, 6]

NOTE: The separation between lists signifies a line break.

This is code-golf, so shortest code in bytes wins. Also, put an explanation in as well for your code.

*/

#include <assert.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int female(int n);
int male(int n);

int
female(int n)
{
	if (n < 0)
		return 0;
	if (n == 0)
		return 1;
	return n - male(female(n - 1));
}

int
male(int n)
{
	if (n < 1)
		return 0;
	return n - female(male(n - 1));
}

int
main(void)
{
	static const int ftab[] = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6};
	static const int mtab[] = {0, 0, 1, 2, 2, 3, 4, 4, 5, 6};

	size_t i;

	for (i = 0; i < nelem(ftab); i++) {
		assert(female(i) == ftab[i]);
		assert(male(i) == mtab[i]);
	}

	return 0;
}
