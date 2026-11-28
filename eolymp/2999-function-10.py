#!/usr/bin/env python3

"""

Let the function be defined as follows:

f(m, n) = 1                        if m = 0
          1                        if m = n
          f(m-1, n-1) + f(m, n-1)  if 0 < m < n


Compute the value of this function.

Input
Two integers n and m (0≤n,m≤20).

Output
Print the value of the function f(m,n).

Examples

Input #1
4 2

Answer #1
6

"""

from functools import lru_cache

@lru_cache(maxsize=None)
def f(m, n):
    if m == 0 or m == n:
        return 1
    if 0 < m and m < n:
        return f(m-1, n-1) + f(m, n-1)
    return 0

def solve(n, m):
    return f(m, n)

def main():
    assert(solve(4, 2) == 6)

main()
