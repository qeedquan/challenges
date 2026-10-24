#!/usr/bin/env python3

from math import lcm

def solve(a):
    r = 1
    for x in a:
        r = lcm(r, x)
    return r * 35

def main():
    assert(solve([4, 5, 6]) == 2100)
    assert(solve([10, 14, 15, 35]) == 7350)

main()
