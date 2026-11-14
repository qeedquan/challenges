/*

The Fibonacci numbers are the numbers in the integer sequence:

0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, ...

Defined by the recurrence relation

  Fib(0) = 0
  Fib(1) = 1
  Fib(2) = 1
  Fib(i) = Fib(i-1) + Fib(i-2)

For any integer n, the sequence of Fibonacci numbers Fib(i) taken modulo n is periodic. The Pisano period, denoted Pisano(n), is the length of the period of this sequence.

For example, the sequence of Fibonacci numbers modulo 3 begins:

0, 1, 1, 2, 0, 2, 2, 1, 0, 1, 1, 2, 0, 2, 2, 1, 0, 1, 1, 2, 0, 2, 2, 1, ...

This sequence has period 8. The repeating patter is 0, 1, 1, 2, 0, 2, 2, 1 So Pisano(3) = 8

Your task is to write the Pisano function that takes an integer n and outputs the length of pisano period.

Once you've been able to solve this kata, a performance version ( https://www.codewars.com/kata/65de16794ccda6356de32bfa ) of this problem is awaiting you.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

// https://oeis.org/A001175
int
pisano(int n)
{
	int a, b, c, r;

	if (n < 1)
		return 0;
	if (n == 1)
		return 1;

	a = b = r = 1;
	while (a != 0 || b != 1) {
		r += 1;
		c = (a + b) % n;
		a = b;
		b = c;
	}
	return r;
}

int
main()
{
	static const int tab[] = {
		1, 3, 8, 6, 20, 24, 16, 12, 24, 60, 10, 24, 28, 48, 40, 24, 36, 24, 18,
		60, 16, 30, 48, 24, 100, 84, 72, 48, 14, 120, 30, 48, 40, 36, 80, 24,
		76, 18, 56, 60, 40, 48, 88, 30, 120, 48, 32, 24, 112, 300, 72, 84, 108,
		72, 20, 48, 72, 42, 58, 120, 60, 30, 48, 96, 140, 120, 136
	};

	unsigned i;

	for (i = 0; i < nelem(tab); i++)
		assert(pisano(i + 1) == tab[i]);

	return 0;
}
