#!/usr/bin/env python3

"""

Consider the fraction, n/d, where n and d are positive integers. If n < d and HCF(n, d) = 1, it is called a reduced proper fraction.

If we list the set of reduced proper fractions for d <= 8 in ascending order of size, we get:

1/8
1/7
1/6
1/5
1/4
2/7
1/3
3/8
2/5
3/7
1/2
4/7
3/5
5/8
2/3
5/7
3/4
4/5
5/6
6/7
7/8

It can be seen that there are 21 elements in this set.

How many elements would be contained in the set of reduced proper fractions for d <= 1000000?

"""

from functools import lru_cache

# https://oeis.org/A015614
@lru_cache(maxsize=None)
def fareylen(n):
    if n < 0:
        return 0

    if n == 0:
        return -1

    c, j, k = 2, 2, n//2
    while k > 1:
        i = n//k + 1
        c += (i - j) * (2*fareylen(k) + 1)
        j, k = i, n//i
    return (n*(n - 1) - c + j) // 2

def main():
    tab = [0, 1, 3, 5, 9, 11, 17, 21, 27, 31, 41, 45, 57, 63, 71, 79, 95, 101, 119, 127, 139, 149, 171, 179, 199, 211, 229, 241, 269, 277, 307, 323, 343, 359, 383, 395, 431, 449, 473, 489, 529, 541, 583, 603, 627, 649, 695, 711, 753, 773, 805, 829, 881, 899, 939, 963]

    for i in range(len(tab)):
        assert(fareylen(i + 1) == tab[i])

    print(fareylen(1000000))

main()
