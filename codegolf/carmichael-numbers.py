#!/usr/bin/env python3

"""

Write a program to print Carmichael numbers. The challenge is to print the maximum number of them in less than 5 secs. The numbers should be in increasing order. Please do not use built in functions. Also please don't store the carmichael numbers in any form. To keep a common time measurement use Ideone. The program to print the maximum number of Carmichael number wins.

Sample Output
561
1105
1729
2465
2821
6601
8911
.
.
.
OEIS A002997

"""

from sympy import *

# https://oeis.org/A002997
def gen(n):
    r, p, q = [], 3, 5
    while len(r) < n:
        for i in range(p + 2, q, 2):
            f = factorint(i)
            if max(f.values()) == 1 and not any((i - 1) % (p - 1) for p in f):
                r.append(i)
        p, q = q, nextprime(q)
    return r

def main():
    tab = [
        561, 1105, 1729, 2465, 2821, 6601, 8911, 10585, 15841, 29341, 41041,
        46657, 52633, 62745, 63973, 75361, 101101, 115921, 126217, 162401, 172081,
        188461, 252601, 278545, 294409, 314821, 334153, 340561, 399001, 410041,
        449065, 488881, 512461
    ]

    assert(gen(len(tab)) == tab)

main()
