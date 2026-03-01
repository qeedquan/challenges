#!/usr/bin/env python3

"""

I'm surprised that this challenge isn't already here, as it's so obvious. (Or I'm surprised I couldn't find it and anybody will mark it as a duplicate.)

Task
Given a non-negative integer n, calculate the sum of the first n primes and output it.

Example #1
For n=5, the first five primes are:

2
3
5
7
11
The sum of these numbers is 2+3+5+7+11=28, so the program has to output 28.

Example #2
For n=0, the "first zero" primes are none. And the sum of no numbers is - of course - 0.

Rules
You may use built-ins, e.g., to check if a number is prime.
This is code-golf, so the lowest number of bytes in each language wins!

"""

from sympy import *

# https://oeis.org/A007504
def primesum(n):
    if n < 1:
        return 0

    r = 0
    p = 2
    for i in range(n):
        r += p
        p = nextprime(p)
    return r

def main():
    tab = [0, 2, 5, 10, 17, 28, 41, 58, 77, 100, 129, 160, 197, 238, 281, 328, 381, 440, 501, 568, 639, 712, 791, 874, 963, 1060, 1161, 1264, 1371, 1480, 1593, 1720, 1851, 1988, 2127, 2276, 2427, 2584, 2747, 2914, 3087, 3266, 3447, 3638, 3831, 4028, 4227, 4438, 4661, 4888]

    for i in range(len(tab)):
        assert(primesum(i) == tab[i])

main()
