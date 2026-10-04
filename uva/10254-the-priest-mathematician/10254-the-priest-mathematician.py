#!/usr/bin/env python3

from math import sqrt

# https://oeis.org/A007664
def solve(n):
    if n < 1:
        return 0
    m = (n + 1) << 1
    k = int(sqrt(m))
    r = k + (m >= (k * (k + 1) + 1)) - 1
    return (1 << r) * (n - 1 - (r * (r - 1) >> 1)) + 1

def solvebf(n):
    if n < 1:
        return 0

    p = [0] * (n + 1)
    e = 1
    c = 1
    i = 1
    while i <= n:
        j = c
        while i <= n and j > 0:
            p[i] = p[i - 1] + e
            i += 1
            j -= 1
        c += 1
        e <<= 1
    return p[n]

def main():
    tab = [
        0, 1, 3, 5, 9, 13, 17, 25, 33, 41, 49, 65, 81, 97, 113, 129, 161, 193,
        225, 257, 289, 321, 385, 449, 513, 577, 641, 705, 769, 897, 1025, 1153,
        1281, 1409, 1537, 1665, 1793, 2049, 2305, 2561, 2817, 3073, 3329, 3585,
        3841, 4097, 4609, 5121, 5633
    ]

    assert(solve(1) == 1)
    assert(solve(2) == 3)
    assert(solve(28) == 769)
    assert(solve(64) == 18433)

    for i in range(1000):
        assert(solve(i) == solvebf(i))

    for i in range(len(tab)):
        assert(solve(i) == tab[i])

main()
