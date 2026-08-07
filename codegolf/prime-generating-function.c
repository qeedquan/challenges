/*

Background
The Python code

((((((((n%35)^11)*195)|53)&181)+n)%168)*n)+83 produces 74 distinct primes for 0≤n≤73. This code also works in Java. The operators are as follows:

+ is addition
* is multiplication
% is modulus
& is bitwise AND
| is bitwise OR
^ is bitwise XOR
The produced primes are: 83, 97, 113, 251, 311, 173, 197, 503, 571, 281, 313, 787, 863, 421, 461, 1103, 547, 593, 1361, 1451, 743, 797, 1733, 1831, 1931, 1033, 1097, 2243, 1231, 1301, 1373, 2687, 1523, 1601, 3041, 3163, 1847, 1933, 3541, 3671, 2203, 2297, 4073, 4211, 2591, 2693, 4637, 4783, 3011, 3121, 5233, 3347, 3463, 5701, 5861, 3823, 3947, 6353, 6521, 6691, 4463, 4597, 7213, 4871, 5011, 5153, 7937, 5443, 5591, 8501, 8693, 6047, 6203, 9281.

Task
Given an input integer n output one of the primes from the above list, such that every output is distinct.

Rules
n will be between 0 and 73, inclusive.
You can receive input through any of the standard IO methods.
Leading zeroes are not allowed in output.
This is code-golf, so shortest code in bytes wins!

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
f(int n)
{
	return ((((((((n % 35) ^ 11) * 195) | 53) & 181) + n) % 168) * n) + 83;
}

int
main(void)
{
	static const int tab[] = {83, 97, 113, 251, 311, 173, 197, 503, 571, 281, 313, 787, 863, 421, 461, 1103, 547, 593, 1361, 1451, 743, 797, 1733, 1831, 1931, 1033, 1097, 2243, 1231, 1301, 1373, 2687, 1523, 1601, 3041, 3163, 1847, 1933, 3541, 3671, 2203, 2297, 4073, 4211, 2591, 2693, 4637, 4783, 3011, 3121, 5233, 3347, 3463, 5701, 5861, 3823, 3947, 6353, 6521, 6691, 4463, 4597, 7213, 4871, 5011, 5153, 7937, 5443, 5591, 8501, 8693, 6047, 6203, 9281};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(f(i) == tab[i]);

	return 0;
}
