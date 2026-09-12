#!/usr/bin/env python3

from math import sqrt

def solve(x):
    if x < 0:
        return "INVALID"

    s = 1
    n = int(sqrt(x)) + 1
    for i in range(2, n):
        if x%i == 0:
            s += i + x//i

    if x == 1:
        return "DEFICIENT"
    if s == x:
        return "PERFECT"
    if s < x:
        return "DEFICIENT"
    return "ABUNDANT"

def main():
    assert(solve(15) == "DEFICIENT")
    assert(solve(28) == "PERFECT")
    assert(solve(6) == "PERFECT")
    assert(solve(56) == "ABUNDANT")
    assert(solve(60000) == "ABUNDANT")
    assert(solve(22) == "DEFICIENT")
    assert(solve(496) == "PERFECT")

main()
