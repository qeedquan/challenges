#!/usr/bin/env python3

"""

Define the infinite sequence A as follows:

A[0] = 1
A[i] = A[i/p] + A[i/q], i >= 1

Input
Three integers n, p and q (0≤n≤10^12, 2≤p,q≤10^9).

Output
Print the value of A[n].

Examples

Input #1
0 2 3

Answer #1
1

Input #2
10000000 3 3

Answer #2
32768

"""

from functools import lru_cache

@lru_cache(maxsize=None)
def f(n, p, q):
    if n < 0:
        return 0
    if n == 0:
        return 1
    return f(n//p, p, q) + f(n//q, p, q)

def solve(n, p, q):
    return f(n, p, q)

def main():
    assert(solve(0, 2, 3) == 1)
    assert(solve(10000000, 3, 3) == 32768)

main()

