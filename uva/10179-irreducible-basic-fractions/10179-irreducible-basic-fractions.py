#!/usr/bin/env python3

from math import gcd
from sympy import totient

# https://oeis.org/A000010
def solve(n):
    if n < 1:
        return 0
    return totient(n)

def solvebf(n):
    r = 0
    for i in range(n):
        if gcd(i, n) == 1:
            r += 1
    return r

def main():
    assert(solve(12) == 4)
    assert(solve(123456) == 41088)
    assert(solve(7654321) == 7251444)
    for i in range(1000):
        assert(solve(i) == solvebf(i))

main()

