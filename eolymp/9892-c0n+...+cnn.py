#!/usr/bin/env python3

"""

Given a non-negative integer n, find the sum of binomial coefficients:

C(n, 0) + C(n, 1) + … + C(n, n)

Input
One non-negative integer n (n≤60).

Output
Print the value of the sum.

Examples
Input #1
2

Answer #1
4

"""

from math import comb

def solve(n):
    return 1 << n

def solvebf(n):
    r = 0
    for i in range(n + 1):
        r += comb(n, i)
    return r

def main():
    assert(solve(2) == 4)
    
    for i in range(500):
        assert(solve(i) == solvebf(i))

main()
