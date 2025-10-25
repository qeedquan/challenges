/*

Background
Most everyone is familiar with the Fibonacci numbers F(n):

0,1,1,2,3,5,8,13,21,...

These are formed by the recursion function F(n)=F(n−1)+F(n−2) with F(0)=0 and F(1)=1. A000045

A closely related sequence is the Lucas numbers L(m):

2,1,3,4,7,11,18,29,...

These are formed by the recursion function L(m)=L(m−1)+L(m−2) with L(0)=2 and L(1)=1. A000032

We can alternate between the two sequences based on even/odd indices, with the construction

A(x) = F(x) x ≡ 0 (mod 2)
       L(x) x ≡ 1 (mod 2)

For example, A(4) is equal to F(4) since 4 mod 2≡0.
We'll call this sequence the Lucas-nacci Numbers, A(x):

0, 1, 1, 4, 3, 11, 8, 29, 21, 76 ...

This can be formed by the recursion function A(x)=3*A(x-2)-A(x-4) with A(0)=0,A(1)=1,A(2)=1, and A(3)=4. A005013

Challenge
Given input n, output the sequence of n+1 numbers up to and including A(n) as described above. Fewest bytes (or byte-equivalents, such as for LabVIEW, as determined individually on Meta) wins.

Input
A single non-negative integer n.

Output
A list of numbers that correspond to the subsequence of Lucas-nacci numbers from A(0) to A(n). The list must be in sequential order as described above.

Rules
Standard code-golf rules and loophole restrictions apply.
Standard input/output rules apply.
Input number can be in any suitable format: unary or decimal, read from STDIN, function or command-line argument, etc. - your choice.
Output can be printed to STDOUT or returned as a result of the function call. If printed, suitable delimiters to differentiate the numbers must be included (space-separated, comma-separated, etc.).
Additionally, if output to STDOUT, surrounding whitespace, trailing newline, etc. are all optional.
If the input is a non-integer or a negative integer, the program can do anything or nothing, as behavior is undefined.

Examples
Input -> Output
0 -> 0
5 -> 0, 1, 1, 4, 3, 11
18 -> 0, 1, 1, 4, 3, 11, 8, 29, 21, 76, 55, 199, 144, 521, 377, 1364, 987, 3571, 2584

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef long long vlong;

// https://oeis.org/A005013
vlong
lucasnacci(vlong n)
{
	vlong a[] = {0, 1, 1, 4, 3};
	vlong i;

	for (i = 0; i < n; i++) {
		a[4] = (3 * a[2]) - a[0];
		memmove(a, a + 1, 4 * sizeof(*a));
	}
	return a[0];
}

int
main(void)
{
	static const vlong tab[] = {0, 1, 1, 4, 3, 11, 8, 29, 21, 76, 55, 199, 144, 521, 377, 1364, 987, 3571, 2584, 9349, 6765, 24476, 17711, 64079, 46368, 167761, 121393, 439204, 317811, 1149851, 832040, 3010349, 2178309, 7881196, 5702887, 20633239, 14930352, 54018521, 39088169, 141422324};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(lucasnacci(i) == tab[i]);

	return 0;
}
