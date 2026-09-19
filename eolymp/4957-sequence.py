#!/usr/bin/env python3

"""

You are given a recurrent formula for a sequence f:

f(n) = 1 + f(1)g(1) + f(2)g(2) + … +f(n-1)g(n-1),

where g is also a recurrent sequence given by formula:

g(n) = 1 + 2g(1) + 2g(2) + 2g(3) + … + 2g(n−1) - g(n-1)g(n-1).

It is known that f(1)=1, g(1)=1.
Your task is to find f(n) modulo p.

Input
The input consists of several cases. Each case contains two numbers on a single line. These numbers are n (1≤n≤10000) and p (2≤p≤2⋅10^9).
The input is terminated by the case with n=p=0 which should not be processed. The number of cases in the input does not exceed 5000.

Output
Output for each case f(n) modulo p on a separate line.

Examples
Input #1
1 2
2 11
0 0

Answer #1
1
2

"""

from functools import lru_cache

@lru_cache(maxsize=None)
def g(n):
    if n < 1:
        return 0
    if n == 1:
        return 1
    
    r = 1
    for i in range(1, n):
        r += 2 * g(i)
    r -= g(n - 1) * g(n - 1)
    return r

@lru_cache(maxsize=None)
def f(n):
    if n < 1:
        return 0
    if n == 1:
        return 1

    r = 1
    for i in range(1, n):
        r += f(i) * g(i)
    return r

def solvebf(n, p):
    if p < 1:
        return 0
    return f(n) % p

@lru_cache(maxsize=None)
def solve(n, p):
    if n < 1 or p < 1:
        return 0
    if p <= n:
        return 0
    if n == 1:
        return 1
    
    r = 0
    for i in range(2, n + 1):
        r = (i % p) * solve(n - 1, p)
        r %= p
    return r

def main():
    assert(solve(1, 2) == 1)
    assert(solve(2, 11) == 2)

    L = 1000
    for n in range(L):
        for p in range(L):
            assert(solve(n, p) == solvebf(n, p))

main()
