/*

Your task is to implement integer sequence A130826:

an is the smallest positive integer such that an - n is an entire multiple of 3 and twice the number of divisors of (an - n) / 3 gives the nth term in the first differences of the sequence produced by the Flavius Josephus sieve.

Lost yet? Well, it's actually quite easy.

The Flavius Josephus sieve defines an integer sequence as follows.

Start with the sequence of positive integers and set k = 2.

Remove every kth integer of the sequence, starting with the kth.

Increment k and go back to step 2.

fn is the nth integer (1-indexed) that never gets removed.

If – as usual – σ0(k) denotes the number of positive divisors of the integer k, we can define an as the smallest positive integer such that 2σ0((an - n) / 3) = fn+1 - fn.

Challenge
Write a program or function that takes a positive integer n as input and prints or returns an.

Standard code-golf rules apply. May the shortest code win!

Worked examples
If we remove every second element of the positive integers, we are left with

 1  3  5  7  9 11 13 15 17 19 21 23 25 27 29 31 33 35 37 39 ...
After removing every third element of the remainder, we get

 1  3  7  9 13 15 19 21 25 27 31 33 37 39 ...
Now, removing every fourth, then fifth, then sixth element gets us

 1  3  7 13 15 19 25 27 31 37 39 ...
 1  3  7 13 19 25 27 31 39 ...
 1  3  7 13 19 27 31 39 ...
 1  3  7 13 19 27 39 ...
The last row shows the terms f1 to f7.

The differences of the consecutive elements of the these terms are

 2  4  6  6  8 12
Dividing these forward differences by 2, we get

 1  2  3  3  4  6
These are the target divisor counts.

4 is the first integer k such that σ0((k - 1) / 3) = 1. In fact, σ0(1) = 1.
8 is the first integer k such that σ0((k - 2) / 3) = 2. In fact, σ0(2) = 2.
15 is the first integer k such that σ0((k - 3) / 3) = 3. In fact, σ0(4) = 3.
16 is the first integer k such that σ0((k - 4) / 3) = 3. In fact, σ0(4) = 3.
23 is the first integer k such that σ0((k - 5) / 3) = 4. In fact, σ0(6) = 4.
42 is the first integer k such that σ0((k - 6) / 3) = 6. In fact, σ0(12) = 6.
Test cases
   n     a(n)

   1        4
   2        8
   3       15
   4       16
   5       23
   6       42
   7       55
   8      200
   9       81
  10       46
  11      119
  12      192
  13      205
  14   196622
  15    12303
  16       88
  17      449
  18      558
  19      127
  20     1748
  21   786453
  22       58
  23     2183
  24     3096
  25     1105
  26   786458
  27 12582939
  28      568
  29     2189
  30     2730

*/

#include <assert.h>
#include <stdio.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

long
divisors(long s, long N)
{
	if (s < 1)
		return N + 1;
	return divisors(s - 1, N + (N / s));
}

/*

https://oeis.org/A130826

ported from @Bobas_Pett solution

*/

long
seq(long n)
{
	long i, u, v, x;

	u = 0;
	for (x = 1; x < LONG_MAX; x++) {
		v = (divisors(n, n) - divisors(n, n - 1)) / 2;
		if (u == v)
			break;

		u = 0;
		for (i = 1; i <= x; i++) {
			if ((x % i) < 1)
				u++;
		}
	}
	return (3 * x) + n - 3;
}

int
main()
{
	static const long tab[] = {4, 8, 15, 16, 23, 42, 55, 200, 81, 46, 119, 192, 205, 196622, 12303, 88, 449, 558, 127, 1748};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(seq(i + 1) == tab[i]);

	return 0;
}
