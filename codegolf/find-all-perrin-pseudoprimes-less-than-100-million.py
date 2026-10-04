#!/usr/bin/env python3

"""

Simply put, the Perrin sequence has the following recurrence relation:

P(n) = P(n-2) + P(n-3);

P(0) = 3; P(1) = 0; P(2) = 2;

But wait!! There's more!!

The Perrin sequence has a very bizarre property:

If N is prime, then P(N) mod N = 0.

Furthermore, there are very few composite numbers which have this property. This can serve as a simple primality test which gives very few false positives.

There are 5761462 numbers under 100 million which satisfy this congruence. Out of those, 5761455 (99.9999%) are prime numbers.

Your mission is to compute those 7 numbers which pass the test but which are not prime. To be specific, your program must output these numbers in a reasonable format:

271441, 904631, 16532714, 24658561, 27422714, 27664033, 46672291
You can find more perrin pseudo primes (all of them up to 10^16) with factorization here. For this challenge only the first 7 are important, since they are the only one smaller than 100 million.

(Your program must compute these numbers without having them pre-made, or accessing the internet, or similar stuff.)

Also, your program should not produce integer overflows. This may at first seem difficult because the 100 millionth Perrin number is really, really big. Algorithms do exist, however, which would not cause overflows.

This is code golf, shorter solutions are better.

"""

from sympy import *

# https://oeis.org/A001608
def perrin(n):
    if n < 0:
        return 0

    a, b, c = 3, 0, 2
    for i in range(n):
        a, b, c = b, c, a + b
    return a

# https://oeis.org/A013998
def perrin_pseudoprime(n):
    if n < 1:
        return False
    return not isprime(n) and perrin(n)%n == 0

def main():
    tab = [271441, 904631, 16532714, 24658561, 27422714, 27664033, 46672291]
    for v in tab:
        assert(perrin_pseudoprime(v) == True)

main()
