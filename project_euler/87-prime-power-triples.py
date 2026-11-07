#!/usr/bin/env python3

"""

The smallest number expressible as the sum of a prime square, prime cube, and prime fourth power is 28. In fact, there are exactly four numbers below fifty that can be expressed in such a way:

28 = 2^2 + 2^3 + 2^4
33 = 3^2 + 2^3 + 2^4
49 = 5^2 + 2^3 + 2^4
47 = 2^2 + 3^3 + 2^4

How many numbers below fifty million can be expressed as the sum of a prime square, prime cube, and prime fourth power?

"""

from sympy import *
from math import *

def solve(n):
    p2 = []
    p3 = []
    p4 = []
    for x in primerange(2, sqrt(n)):
        if x**2 < n:
            p2.append(x**2)
        if x**3 < n:
            p3.append(x**3)
        if x**4 < n:
            p4.append(x**4)

    m = {}
    for a in p2:
        for b in p3:
            for c in p4:
                x = a + b + c
                if x < n:
                    m[x] = True
    return len(m)

def main():
    print(solve(50000000))

main()
