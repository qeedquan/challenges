#!/usr/bin/env python3

from math import sqrt

def solve(n):
    if n < 0:
        return []

    r = []
    s = int(sqrt(n))
    for i in range(s-1, 0, -1):
        x = n - i*i
        if x%i == 0:
            r.append(x)
    return r

def main():
    assert(solve(16) == [12, 15])
    assert(solve(109) == [108])
    assert(solve(33) == [24, 32])

main()
