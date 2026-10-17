#!/usr/bin/env python3

"""

Input
An integer n greater than or equal to 1.

Output
The number of bits needed to represent the integer that is the product of the first n primes.

Example
The product of the first two primes is 6. This needs 3 bits to represent it.

Given unlimited memory and time your code should always output the correct value.

"""

from sympy import *

def primebits(n):
    if n < 1:
        return 0

    r = 1
    p = 2
    for i in range(n):
        r *= p
        p = nextprime(p)
    return len(bin(r)[2:])

def main():
    assert(primebits(2) == 3)

main()
