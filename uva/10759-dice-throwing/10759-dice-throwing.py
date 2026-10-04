#!/usr/bin/env python3

from functools import lru_cache
from math import gcd

@lru_cache(maxsize=None)
def recurse(n, s, x):
    if n < 0:
        return 0

    if n == 0:
        return s >= x
    
    r = 0
    for i in range(1, 7):
        r += recurse(n - 1, s + i, x)
    return r

def solve(n, x):
    a = 6**n
    b = recurse(n, 0, x)
    m = gcd(a, b)
    a //= m
    b //= m
    if b == 0:
        return 0
    if (a == 1):
        return 1
    return (b, a)

def main():
    assert(solve(3, 9) == (20, 27))
    assert(solve(1, 7) == 0)
    assert(solve(24, 24) == 1)
    assert(solve(15, 76) == (11703055, 78364164096))
    assert(solve(24, 56) == (789532654692658645, 789730223053602816))
    assert(solve(24, 143) == (25, 4738381338321616896))
    assert(solve(23, 81) == (1, 2))
    assert(solve(7, 38) == (55, 46656))

main()

