/*

A permutation of a set S={s1,s2,…,sn} is a bijective function π:S→S. For example, if S={1,2,3,4} then the function π:x↦ 1 + (x + 1 mod 4) is a permutation:

π(1)=3
π(2)=4
π(3)=1
π(4)=2

We can also have permutations on infinite sets, let's take N as an example: The function π:x -> x-1+2*(x mod 2) is a permutation, swapping the odd and even integers in blocks of two.

The first elements are as follows:

2,1,4,3,6,5,8,7,10,9,12,11,14,13,16,15,…

Challenge
Your task for this challenge is to write a function/program implementing any1 permutation on the positive natural numbers. The score of your solution is the sum of codepoints after mapping them with the implemented permutation.

Example
Suppose we take the above permutation implemented with Python:

def pi(x):
    return x - 1 + 2*(x % 2)

The character d has codepoint 100, pi(100)=99. If we do this for every character, we get:

99,102,101,31,111,106,39,119,42,57,9,31,31,31,31,113,102,115,118,113,109,31,119,31,46,31,50,31,44,31,49,41,39,119,31,38,31,49,42

The sum of all these mapped characters is 2463, this would be the score for that function.

Rules
You will implement a permutation π either as a function or program given an natural number x, return/output π(x) for the purpose of this challenge N does not contain 0 the permutation must non-trivially permute an infinite subset of N your function/program is not allowed to read its own source

Scoring
The score is given by the sum of all codepoints (zero bytes may not be part of the source code) under that permutation (the codepoints depend on your language2, you're free to use SBCS, UTF-8 etc. as long as your language supports it).

The submission with the lowest score wins, ties are broken by earliest submission.

Except for permutations which only permute a finite subset of N, meaning that the set {x|π(x)≠x} must be infinite.

If it improves your score, you can for example use a UTF-8 encoded Jelly submission instead of the usual SBCS.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
mod(int x, int m)
{
	x %= m;
	if (x < 0)
		x += m;
	return x;
}

// https://oeis.org/A103889
int
pi(int x)
{
	return x - 1 + (2 * mod(x, 2));
}

int
main(void)
{
	static const int tab[] = {2, 1, 4, 3, 6, 5, 8, 7, 10, 9, 12, 11, 14, 13, 16, 15, 18, 17, 20, 19, 22, 21, 24, 23, 26, 25, 28, 27, 30, 29, 32, 31, 34, 33, 36, 35, 38, 37, 40, 39, 42, 41, 44, 43, 46, 45, 48, 47, 50, 49, 52, 51, 54, 53, 56, 55, 58, 57, 60, 59, 62, 61, 64, 63, 66, 65, 68, 67, 70, 69, 72, 71};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(pi(i + 1) == tab[i]);

	return 0;
}
