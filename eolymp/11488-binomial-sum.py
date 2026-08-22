#!/usr/bin/env python3

"""

Given a positive integer n. Find the value of the following sum

1*C(n, 0) + 2*C(n, 1) + 3*C(n, 2) + ... + (n+1)*C(n, n)


Input
One positive integer n(n≤30).

Output
Print the sum value.

Examples

Input #1
3

Answer #1
20

"""

from math import comb

# https://oeis.org/A001792
def solve(n):
    if n < 0:
        return 0
    return 2**(n - 1) * (n + 2)

def solvebf(n):
    r = 0
    for i in range(n + 1):
        r += (i + 1) * comb(n, i)
    return r

def main():
    tab = [
        1, 3, 8, 20, 48, 112, 256, 576, 1280, 2816, 6144, 13312, 28672, 61440,
        131072, 278528, 589824, 1245184, 2621440, 5505024, 11534336, 24117248,
        50331648, 104857600, 218103808, 452984832, 939524096, 1946157056,
        4026531840, 8321499136, 17179869184, 35433480192
    ]

    assert(solve(3) == 20)

    for i in range(len(tab)):
        assert(solve(i) == tab[i])

    for i in range(100):
        assert(solve(i) == solvebf(i))

main()
