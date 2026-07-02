#!/usr/bin/env python3

"""

Hello. Today our job is to find the Nth Pipi number.

Let us define Pn such that the following expression:

P0 + sqrt(P1 + sqrt(P2 + ... sqrt(P[n])))

is equal to n, if P0 = 0

pipi(0) == 0
because 0 = 0

pipi(1) == 1
because
0 + sqrt(1) = 1

pipi(2) == 9
because
0 + sqrt(1 + sqrt(9 + sqrt(3025))) = 3

Number N range:
From 0 to 22.

"""

from functools import lru_cache

@lru_cache(maxsize=None)
def pipi(n):
    p = n
    for i in range(n):
        p -= pipi(i)
        p *= p
    return p

def main():
    assert(pipi(0) == 0)
    assert(pipi(1) == 1)
    assert(pipi(2) == 9)
    assert(pipi(3) == 3025)

main()
