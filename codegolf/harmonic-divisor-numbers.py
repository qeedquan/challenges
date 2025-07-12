#!/usr/bin/env python3

"""

Consider the 4 divisors of 6: 1,2,3,6. We can calculate the harmonic mean of these numbers as

4 / (1/1 + 1/2 + 1/3 + 1/6) = 4 / (12/6) = 4/2 = 2

However, if we take the 6 divisors of 12 (1,2,3,4,6,12) and calculate their harmonic mean, we get

6 / (1/1 + 1/2 + 1/3 + 1/4 + 1/6 + 1/12) = 6 / (28/12) = 18/7

Ore numbers or harmonic divisor numbers are positive integers n where the harmonic mean of n's divisors is an integer, for example 6. They are A001599 in the OEIS.

The first few Ore numbers are

1, 6, 28, 140, 270, 496, 672, 1638, 2970, 6200, 8128, 8190, ...
Point of interest: this sequence contains all the perfect numbers (see Wikipedia for a proof).

This is a standard sequence challenge. You may choose which of the following three options to do:

Take a positive integer n and output the first n Ore numbers.
Take a positive integer n and output the nth Ore number.
You may use 0-indexing (so non-negative input) or 1-indexing, your choice
Take no input, and output the never ending list of Ore numbers.
Note that your answer cannot fail due to floating point errors.

This is code-golf, so the shortest code in bytes wins.

"""

from sympy import *

# https://oeis.org/A001599
def ore(n):
    if n < 1:
        return False
    return ((n*divisor_sigma(n, 0)) % divisor_sigma(n, 1)) == 0

def gen(n):
    r = []
    i = 1
    while len(r) < n:
        if ore(i):
            r.append(i)
        i += 1
    return r

def main():
    tab = [1, 6, 28, 140, 270, 496, 672, 1638, 2970, 6200, 8128, 8190, 18600]

    assert(gen(len(tab)) == tab)

main()
