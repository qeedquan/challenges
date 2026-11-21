#!/usr/bin/env python3

from sympy import tribonacci

# https://oeis.org/A050231
def solve(n):
    return 2**n - tribonacci(n + 2)

def main():
    tab = [
        0, 0, 1, 3, 8, 20, 47, 107, 238, 520, 1121, 2391, 5056, 10616, 22159,
        46023, 95182, 196132, 402873, 825259, 1686408, 3438828, 6999071, 14221459,
        28853662, 58462800, 118315137, 239186031, 483072832, 974791728, 1965486047,
        3960221519, 7974241118, 16047432332, 32276862265
    ]

    assert(solve(4) == 3)
    assert(solve(5) == 8)

    for i in range(len(tab)):
        assert(solve(i + 1) == tab[i])

main()

