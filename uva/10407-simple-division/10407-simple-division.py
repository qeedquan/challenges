#!/usr/bin/env python3

from math import gcd

def solve(a):
    r = 0
    for i in range(1, len(a)):
        r = gcd(r, a[i] - a[0])
    return abs(r)

def main():
    assert(solve([701, 1059, 1417, 2312]) == 179)
    assert(solve([14, 23, 17, 32, 122]) == 3)
    assert(solve([14, -22, 17, -31, -124]) == 3)

main()
