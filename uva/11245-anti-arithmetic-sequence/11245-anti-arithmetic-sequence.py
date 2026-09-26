#!/usr/bin/env python3

from functools import lru_cache

@lru_cache(maxsize=None)
def f(n, p):
    if n < 0:
        return 0
    if n == 0:
        return 1
    return p*f(n//(p-1), p) + n%(p-1) - (p-1)

def solve(n, p):
    return f(n-1, p)

def main():
    assert(solve(10, 3) == 29)
    assert(solve(10, 5) == 12)
    assert(solve(100, 7) == 130)

main()

