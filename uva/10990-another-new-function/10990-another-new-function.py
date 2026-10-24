#!/usr/bin/env python3

from sympy import totient

# https://oeis.org/A003434
def depthphi(n):
    if n < 1:
        return 0

    c = 0
    while n != 1:
        n = totient(n)
        c += 1
    return c

# https://oeis.org/A060606
def sodf(m, n):
    r = 0
    for i in range(m, n + 1):
        r += depthphi(i)
    return r

def main():
    tab = [
        0, 1, 3, 5, 8, 10, 13, 16, 19, 22, 26, 29, 33, 36, 40, 44, 49, 52, 56,
        60, 64, 68, 73, 77, 82, 86, 90, 94, 99, 103, 108, 113, 118, 123, 128,
        132, 137, 141, 146, 151, 157, 161, 166, 171, 176, 181, 187, 192, 197,
        202, 208, 213, 219, 223, 229, 234, 239, 244, 250, 255
    ]

    assert(sodf(2, 10) == 22)
    assert(sodf(100000, 200000) == 1495105)
    for i in range(len(tab)):
        assert(sodf(0, i + 1) == tab[i])

main()

