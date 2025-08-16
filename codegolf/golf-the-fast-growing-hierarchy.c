/*

The fast growing hierarchy is a way of categorizing how fast functions are growing, defined the following way (for finite indices):

f0(n)=n+1
fk(n)=f[k-1, n](n) with f[n] meaning repeated application of the function f

Examples
f0(5) = 6
f1(3) = f0(f0(f0(3))) = 3+1+1+1= 6
f2(4) = f1(f1(f1(f1(4)))) = 2*(2*(2*(2*4))) = 2⁴*4 = 64
f2(5) = f1(f1(f1(f1(f1(5))))) = ... = 2⁵*5 = 160
f2(50) = f1⁵⁰(50) = ... = 2⁵⁰*50 = 56294995342131200
f3(2) = f2(f2(2)) = f2(f2(2^2*2))) = f2(8) = 2^8*8 = 2048
f3(3) = f2(f2(f2(3))) = f2(f2(2³*3)) = f2(2²⁴*24)=2⁴⁰²⁶⁵³¹⁸⁴*402653184 = ...
f4(1) = f3(1) = f2(1) = f1(1) = f0(1) = 2
f4(2) = f3(f3(2)) = f3(2048) = f2²⁰⁴⁸(2048) = ...
...
shortcuts:

f1(n) = f0(...f0(n))) = n+n*1 = 2*n
f2(n) = f1(... f1(n)...)  = 2^n * n
Your goal is to write a program of function that given two positive integers k and n outputs fk(n)

Rules
Given unlimited time and using unbounded integer types the algorithm you program is using should compute the correct result of f_k(n) for arbitrarily large n and k (even if the program will not finish in the lifetime of the universe)
You program only has to work for values that fit in a signed 32-bit integer
Supporting the case k=0 is optional
This is code-golf, the shortest solution in bytes wins

*/

#include <assert.h>

typedef unsigned long long uvlong;

uvlong
f(uvlong k, uvlong n)
{
	uvlong i, r;

	if (k == 0)
		return n + 1;

	r = n;
	for (i = 0; i < n; i++)
		r = f(k - 1, r);
	return r;
}

int
main(void)
{
	assert(f(0, 5) == 6);
	assert(f(1, 3) == 6);
	assert(f(2, 4) == 64);
	assert(f(2, 5) == 160);
	assert(f(3, 2) == 2048);
	assert(f(4, 1) == 2);

	return 0;
}
