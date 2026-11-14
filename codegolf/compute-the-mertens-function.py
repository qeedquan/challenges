#!/usr/bin/env python3

"""

Given a positive integer n, compute the value of the Mertens function M(n) where:

M(n)=Σ[k=1, n, μ(k)]

and μ(k) is the Möbius function where μ(k)=1 if k has an even number of distinct prime factors, -1 if k has an odd number of distinct prime factors, and 0 if the prime factors are not distinct.

This is code-golf so create the shortest code for a function or program that computes the Mertens function for an input integer n > 0.
This is the OEIS sequence A002321.

Test Cases
n M(n)
1 1
2 0
3 -1
4 -1
5 -2
6 -1
7 -2
8 -2
9 -2
10 -1
117 -5
5525 5
7044 -25
8888 4
10000 -23

"""

from sympy import *

# https://oeis.org/A002321
def mertens(n):
    r = 0
    for i in range(1, n + 1):
        r += mobius(i)
    return r

def main():
    assert(mertens(1) == 1)
    assert(mertens(2) == 0)
    assert(mertens(3) == -1)
    assert(mertens(4) == -1)
    assert(mertens(5) == -2)
    assert(mertens(6) == -1)
    assert(mertens(7) == -2)
    assert(mertens(8) == -2)
    assert(mertens(9) == -2)
    assert(mertens(10) == -1)
    assert(mertens(117) == -5)
    assert(mertens(5525) == 5)
    assert(mertens(7044) == -25)
    assert(mertens(8888) == 4)
    assert(mertens(10000) == -23)

main()
