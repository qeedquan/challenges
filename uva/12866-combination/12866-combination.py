#!/usr/bin/env python3

from functools import lru_cache

# https://oeis.org/A006046
@lru_cache(maxsize=None)
def f(n):
    if n < 0:
        return 0
    if n < 2:
        return n
    if n%2 != 0:
        return 2*f(n//2) + f(n//2 + 1)
    return 3*f(n//2)

def solve(L, R):
    return f(R + 1) - f(L)

def main():
    assert(solve(2, 3) == 6)
    assert(solve(10, 20) == 70)
    assert(solve(100, 200) == 2510)

main()

