#!/usr/bin/env python3

"""

Given an array of numbers, calculate the sum of each number raised to its own power. For example, given 4,6,7, the code needs to return 870455.

This is code-golf, so shortest code wins.

"""

def sse(a):
    r = 0
    for x in a:
        r += x**x
    return r

def main():
    assert(sse([4, 6, 7]) == 870455)

main()
