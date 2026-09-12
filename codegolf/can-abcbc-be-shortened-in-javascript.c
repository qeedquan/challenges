/*

So I have the situation where I have one boolean value a and, if that one is true and b<c I want it to end up as true, if a is false and b>c I want it to resolve as true as well. If b=c I want it to be always false, no matter the value b and c are both numbers. My best approach so far is a?b<c:b>c or maybe b^c^a^b<c. Is there any shorter approach? I can’t stop thinking about it, and want confirmation this is the shortest possible way or find the solution...

*/

#include <assert.h>

int
cmp(int a, int b, int c)
{
	return a ? (b < c) : (b > c);
}

/*

@dingledooper

c-b<a^a

*/

int
xcmp(int a, int b, int c)
{
	return (c - b < a) ^ a;
}

int
main(void)
{
	int a, b, c, N;

	N = 10000;
	for (a = 0; a <= 1; a++) {
		for (b = -N; b <= N; b++) {
			for (c = -N; c <= N; c++)
				assert(cmp(a, b, c) == xcmp(a, b, c));
		}
	}
	return 0;
}
