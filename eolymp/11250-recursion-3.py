#!/usr/bin/env python3

"""

Three integers a,b,c are given. For a given integer n, compute the value of the function:

f(a) = 0                       n < 0
       a                       n = 0
       f(n-1) + b*f(n-2) + c   n > 0

Input
Four integers a,b,c (∣a∣,∣b∣,∣c∣≤1000),n (0≤n≤1000).

Output
Print the value of f(n) modulo 10^9 + 7.

Examples

Input #1
4 2 -3 10

Answer #1
84

"""

from functools import lru_cache

@lru_cache(maxsize=None)
def f(a, b, c, n):
    if n < 0:
        return 0
    if n == 0:
        return a
    return f(a, b, c, n-1) + b*f(a, b, c, n-2) + c

def solve(a, b, c, n):
    return f(a, b, c, n) % 1_000_000_007

def main():
    assert(solve(4, 2, 3, 3) == 35)

main()
