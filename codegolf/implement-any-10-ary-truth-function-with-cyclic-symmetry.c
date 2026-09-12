/*

Implement a function f that takes 10 boolean inputs and returns a boolean.

The only requirement on f is that it satisfies the identity

f(x1,x2,x3,x4,x5,x6,x7,x8,x9,x10)=f(x2,x3,x4,x5,x6,x7,x8,x9,x10,x1)

and the 9 other cyclic-permutation identities (including the trivial one) that follow from this, and does not satisfy any other identities corresponding to permutations of the input tuple. (Please justify this in your answer.)

The spirit of the challenge is to find and golf a function with the required symmetry group, not to golf a brute-force search through all 2^1024 10-ary truth functions. Therefore, your program should run for at most 1 minute on each input.

*/

#include <assert.h>

int
ror(int x)
{
	return ((x >> 1) & 0x1ff) | ((x & 1) << 9);
}

/*

@xnor

If input may be taken as a 10-bit number, we can simply check if it's a multiple of 11.
This is preserved by cycling because 2**10-1 = 1023 is a multiple of 11.
And to satisfy an identity, a permutation would have to once again preserve cycles of 0000001101 up to cycling.

*/

int
f(int x)
{
	return (x % 11) < 1;
}

int
main()
{
	int x;

	for (x = 0; x < 1024; x++)
		assert(f(x) == f(ror(x)));
	return 0;
}
