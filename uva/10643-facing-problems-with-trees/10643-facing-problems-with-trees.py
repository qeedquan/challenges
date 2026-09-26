#!/usr/bin/env python3

from math import comb

# https://oeis.org/A001700
def solve(n):
    m = n//2 - 1
    if m < 1:
        return 0
    return comb(2*m + 1, m + 1)

def main():
    assert(solve(4) == 3)
    assert(solve(10) == 126)
    assert(solve(14) == 1716)

main()

