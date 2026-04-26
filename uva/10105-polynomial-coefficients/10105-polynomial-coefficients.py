#!/usr/bin/env python3

from math import factorial

def solve(n, a):
    p = 1
    for x in a:
        p *= factorial(x)
    return factorial(n) // p

def main():
    assert(solve(2, [1, 1]) == 2)
    assert(solve(2, [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0]) == 2)

main()
