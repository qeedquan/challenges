#!/usr/bin/env python3

"""

Sexy Primes are pairs of numbers (n,n+6) such as n and n+6 are both prime

You need to create a function which will take an integer, check for sexy primes from 0 to that integer, and return an array of arrays.

For example, listSexy(30) must return [[5,11], [7,13], [11,17], [13,19], [17,23], [23,29]] or some equivalent.

This is code-golf so the program with the shortest bytecount wins!

"""

from sympy import *

# https://oeis.org/A023201
# https://oeis.org/A046117
def gen(n):
    r = []
    p = list(primerange(n))
    for x in p:
        if x - 6 in p:
            r.append([x - 6, x])
    return r

def main():
    assert(gen(30) == [[5, 11], [7, 13], [11, 17], [13, 19], [17, 23], [23, 29]])

main()
