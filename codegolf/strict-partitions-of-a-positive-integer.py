#!/usr/bin/env python3

"""

OEIS A000009 counts the number of strict partitions of the integers. A strict partition of a nonnegative integer n is a set of positive integers (so no repetition is allowed, and order does not matter) that sum to n.

For example, 5 has three strict partitions: 5, 4, 1, and 3, 2.

10 has ten partitions:

10
9,1
8,2
7,3
6,4
7,2,1
6,3,1
5,4,1
5,3,2
4,3,2,1
Challenge
Given a nonnegative integer n<1000, output the number of strict partitions it has.

Test cases:
0 -> 1

42 -> 1426

Here is a list of the strict partition numbers from 0 to 55, from OEIS:

[1,1,1,2,2,3,4,5,6,8,10,12,15,18,22,27,32,38,46,54,64,76,89,104,122,142,165,192,222,256,296,340,390,448,512,585,668,760,864,982,1113,1260,1426,1610,1816,2048,2304,2590,2910,3264,3658,4097,4582,5120,5718,6378]
This is code-golf, so the shortest solution in bytes wins.

"""

from functools import lru_cache
from math import isqrt

# https://oeis.org/A010815
def eptcoeff(n):
    m = isqrt(24*n + 1)
    if m**2 != 24*n + 1:
        return 0
    if m%6 == 1:
        return (-1)**((m - 1) // 6)
    return (-1)**((m + 1) // 6)

# https://oeis.org/A000009
@lru_cache(maxsize=None)
def partition(n):
    if n == 0:
        return 1

    r = 0
    for k in range(1, isqrt(n) + 1):
        r += (-1)**(k+1) * partition(n - k**2)
    return eptcoeff(n) + 2*r

def main():
    tab = [
        1, 1, 1, 2, 2, 3, 4, 5, 6, 8, 10, 12, 15, 18, 22, 27, 32, 38, 46, 54,
        64, 76, 89, 104, 122, 142, 165, 192, 222, 256, 296, 340, 390, 448, 512,
        585, 668, 760, 864, 982, 1113, 1260, 1426, 1610, 1816, 2048, 2304, 2590,
        2910, 3264, 3658, 4097, 4582, 5120, 5718, 6378
    ]

    for i in range(len(tab)):
        assert(partition(i) == tab[i])

main()
