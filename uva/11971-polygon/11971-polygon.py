#!/usr/bin/env python3

from math import gcd

def solve(n, k):
    a = k + 1
    b = 1 << k
    m = gcd(a, b)
    a //= m
    b //= m
    return (b - a, b)

def main():
    assert(solve(1, 1) == (0, 1))
    assert(solve(2, 2) == (1, 4))

main()

