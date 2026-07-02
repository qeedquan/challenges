#!/usr/bin/env python3

"""

Find the sum of the digits of all the numbers from 1 to N (both ends included).

Examples
# N = 4
1 + 2 + 3 + 4 = 10

# N = 10
1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + (1 + 0) = 46

# N = 12
1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + (1 + 0) + (1 + 1) + (1 + 2) = 51

"""

from math import *

# https://oeis.org/A037123
def twisted_sum(n):
    u = n * (n + 1) / 2
    v = 0
    for k in range(1, n + 1):
        for i in range(1, int(ceil(log10(k))) + 1):
            v += floor(k / 10**i)
    return int(u - 9*v)

def main():
    tab = [
        0, 1, 3, 6, 10, 15, 21, 28, 36, 45, 46, 48, 51, 55, 60, 66, 73, 81, 90,
        100, 102, 105, 109, 114, 120, 127, 135, 144, 154, 165, 168, 172, 177,
        183, 190, 198, 207, 217, 228, 240, 244, 249, 255, 262, 270, 279, 289,
        300, 312, 325, 330, 336, 343, 351, 360, 370, 381
    ]

    for i in range(len(tab)):
        assert(twisted_sum(i) == tab[i])

main()
