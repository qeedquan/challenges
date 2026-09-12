#!/usr/bin/env python3

"""

Write a program that computes the value of the function

f(m, n) = f(m - n, m)  m > n
          n            m = n
          f(n - m, m)  n > m

Input
Two positive integers n and m such that 1≤n,m≤10^18.

Output
Print the value of the function f(m,n).

Examples

Input #1
6 3

Answer #1
3

Input #2
12 12

Answer #2
12

"""

from math import gcd
from functools import lru_cache

@lru_cache(maxsize=None)
def f(m, n):
    if m < 1:
        return n
    if n < 1:
        return m
    if m > n:
        return f(m - n, n)
    if m == n:
        return n
    return f(n - m, m)

def solve(m, n):
    return gcd(m, n)

def main():
    assert(solve(6, 3) == 3)
    assert(solve(12, 12) == 12)

    for m in range(100):
        for n in range(100):
            assert(solve(m, n) == f(m, n))

main()

