/*

According to Nicomachus' Theorem, the sum of the first n cubes is equal to the square of the nth triangular number. See this question for a visualisation.

Your task is to take an integer and determine if it is in the sequence of the sum of the first n cubes.

I take the opportunity to say Happy New Year for 2025! because 2025 is the 9th number in this sequence:

 n             1  2   3    4    5    6    7     8     9    10  ...
 sum(1..n^3)   1  9  36  100  225  441  784  1296  2025  3025  ...
Input

An integer greater than zero. Your answer should be able to handle inputs at least up to 2^31-1 unless your language's maximum type size does not support this.

Output

Either of two distinct values: one if the number is in the sequence, another if it isn't.

*/

#include <cstdio>
#include <cmath>

typedef unsigned long long uvlong;

/*

https://oeis.org/A000537

@Eonema

Explanation:

The nth square triangle number is:
x = (n*(n+1) / 2)^2

so
2*sqrt(x) = n^2 + n

giving n:
n = (-1 + sqrt(1 + 8*sqrt(x))) / 2

Since n has to be an integer, that means sqrt(1 + 8*sqrt(x)) has to be an odd integer, i.e.,
sqrt(1 + 8*sqrt(x)) mod 2 = 1

*/

bool seq(uvlong n)
{
	double x = sqrt(1 + (8 * sqrt(n)));
	return fmod(x, 2) == 1;
}

int main()
{
	for (uvlong i = 0; i <= 10000; i++)
	{
		if (seq(i))
			printf("%llu\n", i);
	}
	return 0;
}
