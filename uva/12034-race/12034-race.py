#!/usr/bin/env python3

from math import factorial
from sympy.functions.combinatorial.numbers import stirling

# https://oeis.org/A000670
def solve(n):
    r = 0
    for k in range(n + 1):
        r += factorial(k) * stirling(n, k)
    return r % 10056

def main():
    tab = [
        1, 1, 3, 13, 75, 541, 4683, 47293, 545835, 7087261, 102247563, 1622632573,
        28091567595, 526858348381, 10641342970443, 230283190977853, 5315654681981355,
        130370767029135901, 3385534663256845323, 92801587319328411133,
        2677687796244384203115, 81124824998504073881821
    ]

    for i in range(len(tab)):
        assert(solve(i) == tab[i]%10056)

    assert(solve(1) == 1)
    assert(solve(2) == 3)
    assert(solve(3) == 13)

main()

