#!/usr/bin/env python3

"""

A046386 is the sequence of all natural numbers that are the product of exactly 4 distinct primes.

Write the shortest program, function, or code snippet, that, when given a natural number, outputs truthy if it is a product of exactly 4 primes, and falsy if not.

Test Cases
210 => truthy (2×3×5×7)
1110 => truthy (2×3×5×37)
1974 => truthy (2×3×7×47)
3899919746694739 => truthy (7883×7901×7907×7919)
0 => falsy
1 => falsy
2 => falsy
7919 => falsy
255 => falsy
36 => falsy (factorization has exactly 4 primes, but only 2 unique: 2×2×3×3)
420 => falsy (factorization has 4 unique primes, but not exactly 4 primes: 2x2x3x5x7)

"""

from sympy import factorint

# https://oeis.org/A046386
def four_unique_primes(n):
    f = factorint(n)
    if len(f) != 4:
        return False
    for i in f:
        if f[i] != 1:
            return False
    return True

def main():
    tab = [
        210, 330, 390, 462, 510, 546, 570, 690, 714, 770, 798, 858, 870, 910,
        930, 966, 1110, 1122, 1155, 1190, 1218, 1230, 1254, 1290, 1302, 1326,
        1330, 1365, 1410, 1430, 1482, 1518, 1554, 1590, 1610, 1722, 1770, 1785,
        1794, 1806, 1830, 1870, 1914, 1938, 1974
    ]

    for i in range(max(tab) + 1):
        if i in tab:
            assert(four_unique_primes(i) == True)
        else:
            assert(four_unique_primes(i) == False)

    assert(four_unique_primes(210) == True)
    assert(four_unique_primes(1110) == True)
    assert(four_unique_primes(1974) == True)
    assert(four_unique_primes(3899919746694739) == True)
    assert(four_unique_primes(0) == False)
    assert(four_unique_primes(1) == False)
    assert(four_unique_primes(2) == False)
    assert(four_unique_primes(7919) == False)
    assert(four_unique_primes(255) == False)
    assert(four_unique_primes(36) == False)
    assert(four_unique_primes(420) == False)

main()
