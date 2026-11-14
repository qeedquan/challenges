#!/usr/bin/env python

from math import prod
from sympy import primerange, prime
import sys

"""

The trick is to notice that the primes 2 and 5 is inside the product.
2*5 = 10, so the equation becomes 10*(P1 * P2 * ...).
Hence the last digit will be 0.

"""
def solve(n):
    return prod(primerange(2, prime(n) + 1)) % 10

def main():
    sys.set_int_max_str_digits(10000)
    assert(solve(2000) == 0)

main()
