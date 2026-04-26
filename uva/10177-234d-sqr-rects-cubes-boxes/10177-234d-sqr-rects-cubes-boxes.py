#!/usr/bin/env python3

from functools import lru_cache

def triangular(n):
    return (n * (n + 1)) // 2

@lru_cache(maxsize=None)
def solve(n):
    if n < 1:
        return (0, 0, 0, 0, 0, 0)

    s2, r2, s3, r3, s4, r4 = solve(n - 1)

    s2 += n**2
    s3 += n**3
    s4 += n**4
    r2 = triangular(n)**2 - s2
    r3 = triangular(n)**3 - s3
    r4 = triangular(n)**4 - s4
    
    return (s2, r2, s3, r3, s4, r4)

def main():
    assert(solve(1) == (1, 0, 1, 0, 1, 0))
    assert(solve(2) == (5, 4, 9, 18, 17, 64))
    assert(solve(3) == (14, 22, 36, 180, 98, 1198))

main()

