#!/usr/bin/env python3

"""

Find the largest positive integer whose product of digits equals the positive integer m, or print −1 if there is no such number.
Numbers that contain digits 0 and 1 are not considered.

Input
One integer m (2 ≤ m ≤ 10^3).

Output
Print the largest positive integer whose product of digits equals m. Print −1 if such number does not exist.

Examples

Input #1
12

Answer #1
322

"""

from sympy import factorint

# https://oeis.org/A084796
def solve(n):
    if n < 0:
        return -1
    if n == 0:
        return 0
    if n == 1:
        return 1

    r = []
    f = factorint(n)
    for p in f:
        for i in range(f[p]):
            r.append(p)
    r = sorted(r, reverse=True)
    return int(''.join(map(str, r)))

def main():
    tab = [
        1, 2, 3, 22, 5, 32, 7, 222, 33, 52, 11, 322, 13, 72, 53, 2222, 17, 332,
        19, 522, 73, 112, 23, 3222, 55, 132, 333, 722, 29, 532, 31, 22222, 113,
        172, 75, 3322, 37, 192, 133, 5222, 41, 732, 43, 1122, 533, 232, 47,
        32222, 77, 552, 173, 1322, 53, 3332, 115, 7222, 193, 292
    ]

    assert(solve(12) == 322)

    for i in range(len(tab)):
        assert(solve(i + 1) == tab[i])

main()
