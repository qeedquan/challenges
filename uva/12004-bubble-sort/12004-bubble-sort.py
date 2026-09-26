#!/usr/bin/env python3

from math import gcd

def solve(n):
    a = n*(n - 1)
    b = 4
    m = gcd(a, b)
    return (a//m, b//m)

def main():
    assert(solve(1) == (0, 1))
    assert(solve(2) == (1, 2))

main()
