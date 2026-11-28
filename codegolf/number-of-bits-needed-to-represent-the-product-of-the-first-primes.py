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
    assert(primebits(1) == 2)
    assert(primebits(2) == 3)
    assert(primebits(3) == 5)
    assert(primebits(4) == 8)
    assert(primebits(5) == 12)
    assert(primebits(6) == 15)
    assert(primebits(7) == 19)
    assert(primebits(8) == 24)
    assert(primebits(9) == 28)
    assert(primebits(10) == 33)
    assert(primebits(11) == 38)
    assert(primebits(12) == 43)
    assert(primebits(13) == 49)
    assert(primebits(14) == 54)
    assert(primebits(15) == 60)
    assert(primebits(16) == 65)
    assert(primebits(17) == 71)
    assert(primebits(18) == 77)
    assert(primebits(19) == 83)
    assert(primebits(20) == 89)

main()
