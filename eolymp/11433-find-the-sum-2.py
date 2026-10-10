#!/usr/bin/env python3

"""

For the given natural number n find the sum

1/sin(1) + 1/[sin(1) + sin(2)] + ... + 1/[sin(1) + sin(2) + ... sin(n)]

Input
One natural number n(n≤1000).

Output
Print the value of the sum with 6 decimal digits.

Examples
Input #1
3

Answer #1
2.288145

"""

from math import *

def solve(n):
    return 1/tan(0.5) - 1/tan((n + 1) * 0.5)

def solvebf(n):
    r = 0
    for i in range(1, n + 1):
        s = 0
        for j in range(1, i + 1):
            s += sin(j)
        r += 1/s
    return r

def main():
    print(solve(3))

    for i in range(500):
        assert(abs(solve(i) - solvebf(i)) < 1e-8)

main()
