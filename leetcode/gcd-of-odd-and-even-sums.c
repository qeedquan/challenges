/*

You are given an integer n. Your task is to compute the GCD (greatest common divisor) of two values:

sumOdd: the sum of the first n odd numbers.

sumEven: the sum of the first n even numbers.

Return the GCD of sumOdd and sumEven.

Example 1:

Input: n = 4
Output: 4

Explanation:

Sum of the first 4 odd numbers sumOdd = 1 + 3 + 5 + 7 = 16
Sum of the first 4 even numbers sumEven = 2 + 4 + 6 + 8 = 20
Hence, GCD(sumOdd, sumEven) = GCD(16, 20) = 4.

Example 2:

Input: n = 5
Output: 5

Explanation:

Sum of the first 5 odd numbers sumOdd = 1 + 3 + 5 + 7 + 9 = 25
Sum of the first 5 even numbers sumEven = 2 + 4 + 6 + 8 + 10 = 30
Hence, GCD(sumOdd, sumEven) = GCD(25, 30) = 5.

Constraints:

1 <= n <= 1000

*/

#include <assert.h>
#include <stdio.h>

int
gcd(int a, int b)
{
	int t;

	while (b) {
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}

int
sumbf(int n)
{
	int a, b;
	int x, y;
	int i;

	a = 1;
	b = 2;
	x = 0;
	y = 0;
	for (i = 0; i < n; i++) {
		x += a;
		y += b;
		a += 2;
		b += 2;
	}
	return gcd(x, y);
}

/*

gcd((1 + (2*n - 1)) * n/2, (2 + 2*n) * n/2) =
gcd(n*n, n*(n + 1)) =
n * gcd(n, n + 1) =
n

*/

int
sum(int n)
{
	if (n < 1)
		return 0;
	return n;
}

int
main()
{
	int i;

	for (i = -10000; i <= 10000; i++)
		assert(sum(i) == sumbf(i));

	return 0;
}
