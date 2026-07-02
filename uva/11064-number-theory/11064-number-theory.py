#!/usr/bin/env python3

from sympy import divisor_count, totient

# https://oeis.org/A045763
def solve(n):
    if n < 1:
        return 0
    return n + 1 - divisor_count(n) - totient(n)

def main():
    tab = [
        0, 0, 0, 0, 0, 1, 0, 1, 1, 3, 0, 3, 0, 5, 4, 4, 0, 7, 0, 7, 6, 9, 0, 9,
        3, 11, 6, 11, 0, 15, 0, 11, 10, 15, 8, 16, 0, 17, 12, 17, 0, 23, 0, 19,
        16, 21, 0, 23, 5, 25, 16, 23, 0, 29, 12, 25, 18, 27, 0, 33, 0, 29, 22,
        26, 14, 39, 0, 31, 22, 39, 0, 37, 0, 35, 30, 35, 14, 47, 0, 39, 23, 39,
        0, 49
    ]

    assert(solve(1) == 0)
    assert(solve(2) == 0)
    assert(solve(6) == 1)
    assert(solve(2147000000) == 1340599805)

    for i in range(len(tab)):
        assert(solve(i + 1) == tab[i])

main()
