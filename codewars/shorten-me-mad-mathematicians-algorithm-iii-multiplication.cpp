/*

Shorten Me: Mad Mathematician's Algorithm III (Multiplication)

Task
You have to write a madMul(a,b) function returning a value of a * b without * in your code.

Coding Limitation:
Less than 30 characters

Input:
a and b : integer ( 0-10000 )

Note: Avoid using Math.imul()

*/

#include <cassert>
#include <cstdlib>

int sign(int x)
{
	return (x >= 0) ? 1 : -1;
}

int madmul(int a, int b)
{
	auto sa = sign(a);
	auto sb = sign(b);
	
	a = abs(a);
	b = abs(b);

	auto r = 0;
	for (auto i = 0; i < b; i++)
		r += a;

	if (sa != sb && (sa < 0 || sb < 0))
		r = -r;

	return r;
}

int main()
{
	auto N = 1000;
	for (auto a = -N; a <= N; a++)
	{
		for (auto b = -N; b <= N; b++)
		{
			assert(madmul(a, b) == a * b);
		}
	}
	return 0;
}
