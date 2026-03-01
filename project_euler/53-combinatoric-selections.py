#!/usr/bin/env python3

"""

There are exactly ten ways of selecting three from five, 12345:

123, 124, 125, 134, 135, 145, 234, 235, 245, and 345

In combinatorics, we use the notation, nCr.

In general, nCr = n!/(r!(n-r)!) where r <= n and 0! = 1

It is not until 23, that a value exceeds one-million:
23 choose 10 = 1144066

How many, not necessarily distinct, values of nCr for 1 <= n <= 100, are greater than one-million?

"""

from math import *

def solve():
    c = 0
    for n in range(1, 101):
        for r in range(0, n+1):
            if comb(n, r) > 1000000:
                c += 1
    return c

def main():
    print(solve())

main()
