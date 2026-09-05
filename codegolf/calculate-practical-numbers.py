#!/usr/bin/env python3

"""

Definition
A positive integer n is a practical number (OEIS sequence A005153) iff all smaller positive integers can be represented as sums of distinct divisors of n.

For example, 18 is a practical number: its divisors are 1, 2, 3, 6, 9, and 18, and the other positive integers smaller than 18 can be formed as follows:

 4 = 1 + 3          5 = 2 + 3           7 = 1 + 6
 8 = 2 + 6          10 = 1 + 9         11 = 2 + 9
12 = 3 + 9 = 1 + 2 + 9 = 1 + 2 + 3 + 6
13 = 1 + 3 + 9      14 = 2 + 3 + 9      15 = 6 + 9
16 = 1 + 6 + 9      17 = 2 + 6 + 9
But 14 is not a practical number: its divisors are 1, 2, 7, and 14, and there's no subset of these which adds to 4, 5, 6, 11, 12, or 13.

Challenge
Write a program, function, or verb which takes as input a positive integer x and either returns or prints the xth practical number, indexed from 1 for consistency with OEIS. Your code must be sufficiently efficient that it can handle inputs up to 250000 in less than two minutes on a reasonable desktop computer. (NB my reference implementation in Java manages 250000 in less than 0.5 seconds, and my reference implementation in Python manages it in 12 seconds).

Test cases
Input        Expected output
1            1
8            18
1000         6500
250000       2764000
1000000      12214770
3000000      39258256

"""

from sympy import *

# https://oeis.org/A005153
def practical(n):
    if n < 1:
        return False

    if n&1 != 0:
        return n == 1

    f = factorint(n)
    P = (2 << f.pop(2)) - 1
    for p in f: 
        if p > 1 + P:
            return False
        P *= p**(f[p]+1)//(p-1)
    return True

def gen(n):
    r, i, v = [], 1, 0
    while i <= n:
        if practical(v):
            r.append(v)
            i += 1
        v += 1
    return r

def main():
    tab = [1, 2, 4, 6, 8, 12, 16, 18, 20, 24, 28, 30, 32, 36, 40, 42, 48, 54, 56, 60, 64, 66, 72, 78, 80, 84, 88, 90, 96, 100, 104, 108, 112, 120, 126, 128, 132, 140, 144, 150, 156, 160, 162, 168, 176, 180, 192, 196, 198, 200, 204, 208, 210, 216, 220, 224, 228, 234, 240, 252]

    assert(gen(len(tab)) == tab)

main()
