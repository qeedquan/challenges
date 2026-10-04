#!/usr/bin/env python3

"""

Calculate the function:

f(n) = 1                                 if n <= 2
       f(floor(6*n/7)) + f(floor(2*n/3)) if n mod 2 = 1
       f(n-1) + f(n-3)                   if n mod 2 = 0

Input
The input contains one positive integer n (1≤n≤10^12).

Output
Print the value of f(n) modulo 2^32.

Examples
Input #1
7

Answer #1
10

"""

from functools import lru_cache

@lru_cache(maxsize=None)
def f(n):
    if n <= 2:
        return 1
    if n%2 != 0:
        return f(6*n // 7) + f(2*n // 3)
    return f(n - 1) + f(n - 3)

def solve(n):
    return f(n) % 4294967296

def main():
    assert(solve(7) == 10)

main()

