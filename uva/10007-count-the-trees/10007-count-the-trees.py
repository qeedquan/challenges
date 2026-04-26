#!/usr/bin/env python3

from sympy import *

# https://oeis.org/A001761
def solve(n):
    return catalan(n) * factorial(n)

def main():
    assert(solve(1) == 1)
    assert(solve(2) == 4)
    assert(solve(10) == 60949324800)
    assert(solve(25) == 75414671852339208296275849248768000000)

main()

