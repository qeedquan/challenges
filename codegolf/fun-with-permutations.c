/*

Who doesn't absolutely love permutations, right? I know, they are amazing––so much fun!

Well, why not take this fun and make it funner?

Here's the challenge:

Given an input in the exact form: nPr, where n is the pool taken from and r is the number of selections from that pool (and n and r are integers), output/return the exact number of permutations. For those of you that are a bit rusty with the terminology: Permutation, def. 2a.

However, this is where the challenge comes into play (makes it not too easy):

You may not use any built in library, framework, or method for your permutation function. You may not use a factorial method, permutation method, or anything of the sort; you must write everything yourself.

If further clarification is needed, please, do not hesitate to tell me in the comments and I will promptly act accordingly.


Here is an I/O example:

Sample function is permute(String) -> int

Input:

permute("3P2")
Output:

6

This is code-golf, so shortest code wins!

*/

#include <assert.h>

typedef unsigned long long uvlong;

uvlong
permutes(uvlong n, uvlong k)
{
	uvlong i, r;

	r = 1;
	for (i = n; i > n - k; i--)
		r *= i;
	return r;
}

int
main(void)
{
	assert(permutes(3, 2) == 6);
	assert(permutes(7, 4) == 840);
	assert(permutes(14, 5) == 240240);
	assert(permutes(10, 2) == 90);
	assert(permutes(0, 0) == 1);

	return 0;
}
