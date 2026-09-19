/*

David Blaine asked the spectator to conceive two numbers.
Then he asked to multiply two numbers, each of which is greater than the conceived number by one, then to subtract one conceived number from the result,
then to subtract the other, and then to subtract their product, and raise the result to the n-th power.

After that, David carefully looked into the face of the spectator and correctly told the result.
Your task is to repeat David's trick. Given value of n, guess the number obtained by the spectator.

Input
One integer n (0≤n≤1000).

Output
Print one number — the result obtained by the spectator.

Examples
Input #1
3

Answer #1
1

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

int
solve(int n)
{
	return n >= 0;
}

int
solvebf(int n)
{
	int a, b, r;

	if (n < 0)
		return 0;

	a = 1;
	b = 2;
	r = (a + 1) * (b + 1) - a - b - (a * b);
	return pow(r, n);
}

int
main()
{
	int i;

	assert(solve(3) == 1);
	for (i = 0; i <= 100000; i++)
		assert(solve(i) == solvebf(i));

	return 0;
}
