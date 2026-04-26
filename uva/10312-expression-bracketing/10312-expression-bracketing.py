#!/usr/bin/env python3

from functools import *
from sympy import catalan

# https://oeis.org/A001003
@lru_cache(maxsize=None)
def super_catalan(n):
    if n <= 2:
        return 1
    if n == 3:
        return 3
    return ((6*n - 9)*super_catalan(n - 1) - (n - 3)*super_catalan(n - 2)) // n

def solve(n):
    return super_catalan(n) - catalan(n - 1)

def main():
    assert(solve(3) == 1)
    assert(solve(4) == 6)
    assert(solve(5) == 31)
    assert(solve(10) == 98187)

main()

