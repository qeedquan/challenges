#!/usr/bin/env python3

"""

Find the value of the function:

f(n) = 1                              n = 0
       f(floor(n/2)) + f(floor(n/3))  n > 0

Input
One positive integer n (1≤n≤10^18).

Output
Print the value of f(n).

Examples

Input #1
5

Answer #1
5

"""

from functools import lru_cache

# https://oeis.org/A088468
@lru_cache(maxsize=None)
def f(n):
    if n < 0:
        return 0
    if n == 0:
        return 1
    return f(n//2) + f(n//3)

def solve(n):
    return f(n)

def main():
    tab = [
        1, 2, 3, 4, 5, 5, 7, 7, 8, 9, 9, 9, 12, 12, 12, 12, 13, 13, 16, 16, 16,
        16, 16, 16, 20, 20, 20, 21, 21, 21, 21, 21, 22, 22, 22, 22, 28, 28, 28,
        28, 28, 28, 28, 28, 28, 28, 28, 28, 33, 33, 33, 33, 33, 33, 37, 37, 37,
        37, 37, 37, 37, 37, 37, 37, 38, 38, 38, 38, 38, 38, 38, 38, 48
    ]

    assert(solve(5) == 5)

    for i in range(len(tab)):
        assert(solve(i) == tab[i])

main()

