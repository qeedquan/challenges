/*

This is much like my earlier challenge, except, this time, order doesn't matter.

A straight-chain alk*ne is defined as a sequence of carbon atoms connected by single (alkane), double (alkene), or triple bonds (alkyne), (implicit hydrogens are used.) Carbon atoms can only form 4 bonds, so no carbon atom may be forced to have more than four bonds. A straight-chain alk*ne can be represented as a list of its carbon-carbon bonds.

These are some examples of valid (not necessarily distinct) straight-chain alk*nes:

[]       CH4              Methane
[1]      CH3-CH3          Ethane
[2]      CH2=CH2          Ethene
[3]      CH≡CH            Ethyne
[1,1]    CH3-CH2-CH3      Propane
[1,2]    CH3-CH=CH2       Propene
[1,3]    CH3-C≡CH         Propyne
[2,1]    CH2=CH-CH3       Propene
[2,2]    CH2=C=CH2        Allene (Propadiene)
[3,1]    CH≡C-CH3         Propyne
[1,1,1]  CH3-CH2-CH2-CH3  Butane
...

While these are not, as at least one carbon atom would have more than 4 bonds:

[2,3]
[3,2]
[3,3]
...
Two straight-chain alk*nes, p and q are considered equivalent if p is q reversed, or p is q.

[1] = [1]
[1,2] = [2,1]
[1,3] = [3,1]
[1,1,2] = [2,1,1]
[1,2,2] = [2,2,1]
Your task is to create a program/function that, given a positive integer n, outputs/returns the number of valid straight-chain alk*nes of exactly n carbon atoms in length.

Specifications/Clarifications
You must handle 1 correctly by returning 1.
Alk*nes like [1,2] and [2,1] are NOT considered distinct.
Output is the length of a list of all the possible alk*nes of a given length.
You do not have to handle 0 correctly.
Test Cases:
1 => 1
2 => 3
3 => 4
4 => 10
5 => 18
6 => 42
This is code golf, so the lowest byte count wins!

*/

#include <assert.h>

#define nelem(x) sizeof(x) / sizeof(x[0])

typedef unsigned long ulong;

/*

@JungHwan Min

a(n) = 2*a(n-1) + 3*a(n-2) - 5*a(n-3) - a(n-4) - 2a(n-6) + 3*a(n-7) + a(n-8) - a(n-9) with
a(0) = 1, a(1) = 3, a(2) = 4, a(3) = 10, a(4) = 18, a(5) = 42, a(6) = 84, a(7) = 192, a(8) = 409

*/

ulong
alknes(ulong n)
{
	static const ulong tab[] = {0, 1, 3, 4, 10, 18, 42, 84, 192, 409};

	if (n < nelem(tab))
		return tab[n];

	return 2 * alknes(n - 1) +
	       3 * alknes(n - 2) +
	       3 * alknes(n - 7) +
	       alknes(n - 8) -
	       5 * alknes(n - 3) -
	       alknes(n - 4) -
	       2 * alknes(n - 6) -
	       alknes(n - 9);
}

int
main(void)
{
	assert(alknes(1) == 1);
	assert(alknes(2) == 3);
	assert(alknes(3) == 4);
	assert(alknes(4) == 10);
	assert(alknes(5) == 18);
	assert(alknes(6) == 42);
	assert(alknes(15) == 51176UL);
	assert(alknes(20) == 2925209UL);

	return 0;
}
