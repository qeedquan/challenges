/*

Your objective is to write a program that takes an input, and, when chained together N times, performs "sequential multiplication". What is sequential multiplication, you may ask? It's a sequence with a seed a defined as thus:

f(0) = a
f(n+1) = f(n)*(f(n)-1)
So, let a = 5. Thus, f(0) = 5, f(1) = f(0)*(f(0)-1) = 5*4 = 20, and f(2) = f(1)*(f(1)-1) = 20*19 = 380.

If your program was ABC, then ABC should take input a and output f(1). Program ABCABC should output f(2), etc. Your program series should only take input once and only output once.

This is a code-golf so the shortest program in bytes wins. Standard loopholes are banned.

*/

#include <assert.h>
#include <stdio.h>

int
seqmul(int n, int a)
{
	int i, r;

	if (n < 0)
		return 0;

	r = a;
	for (i = 0; i < n; i++)
		r *= (r - 1);
	return r;
}

int
main()
{
	int i;

	for (i = 0; i <= 2; i++)
		printf("%d\n", seqmul(i, 5));

	return 0;
}
